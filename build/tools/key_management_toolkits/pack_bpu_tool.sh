export PATH=$PATH:$PWD/utils

output_loc="out/bpu"
key_set_loc="out/bpu/key_set"
debug_loc="out/bpu/debug"

get_rom_key=0
fallback_key=0

bpu_image_load_addr=0x40000000
bpu_header_size=320
bpu0_fetch_only_start=0x60000000
bpu0_fetch_only_sz=0x10000
bpu1_fetch_only_start=0x60010000
bpu1_fetch_only_sz=0x20000
bpu_range_start=0x60000000
bpu_range_sz=0x100000

while getopts "rtbi:" opt; do
  case $opt in
       r)  # get key from kms with real rom key
           get_rom_key=1
           fallback_key=0
           ;;
       t)  # get key from kms with test key
           get_rom_key=0
           fallback_key=0
           ;;
       b)  # use fallback key directlly
           get_rom_key=0
           fallback_key=1
           ;;
       i)
           fallback_key_loc=$OPTARG
           ;;
       h)
           helper
           exit
           ;;
      \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

get_key()
{
    # check if use rom key
    if [ "$1" -eq "1" ]; then
        echo use real key
        util_key_access.sh -r -S # -r means use real key; -S means get spl aes/pub key
    # check if use test key
    elif [ "$2" -eq "0" ]; then
        echo use test key
        util_key_access.sh -t -S # -t means use test key; -S means get spl aes/pub key
    # use local fallback key
    else
        echo use fallback key
        util_key_access.sh -b $3 -B # -b means use fallback key; -B means get bpu aes/pub key
    fi
}

#$1 $get_rom_key
#$2 $fallback_key
#$3: number of rsa key
enc_and_sign_key_bank()
{
    cat spl_aes_spl_img.key >		spl_key_bank_tmp
    cat spl_aes_spl_img.iv >>		spl_key_bank_tmp
    cat spl_rsa_spl_img_pub.bin >>	spl_key_bank_tmp
	cat spl_aes_bpu_img.key >>		spl_key_bank_tmp
	cat spl_aes_bpu_img.iv >>		spl_key_bank_tmp
	cat spl_rsa_bpu_img_pub.bin >>	spl_key_bank_tmp

    dd if=/dev/zero of=spl_key_bank_img bs=1 count=$keybank_size                        status=none
    dd if=spl_key_bank_tmp of=spl_key_bank_img bs=1 count=$keybank_size conv=notrunc    status=none
        
    util_auth.sh -i spl_key_bank_img -k efuse_aes.key -v efuse_aes.iv -p 64 -e
    util_auth.sh -i spl_key_bank_img.pad -o spl_key_bank_img -h 

    # check if use rom key
    if [ "$1" -eq "1" ]; then
        echo use real key
    # check if use test key
    elif [ "$2" -eq "0" ]; then
        echo use test key
    # use local fallback key
    else
        echo use fallback key
        util_auth.sh -i spl_key_bank_img_hash.bin -k rom_rsa${3}_priv.pem -o spl_key_bank_img.sign -s
    fi
}

#$1 $get_rom_key
#$2 $fallback_key
enc_and_sign_spl()
{
    # encrypt spl image
    util_auth.sh -i bpu.bin -k spl_aes_bpu_img.key -v spl_aes_bpu_img.iv -p 64 -e

    # hash spl image
    util_auth.sh -i bpu.bin.pad -o bpu.bin -h 

    # check if use rom key
    if [ "$1" -eq "1" ]; then
        echo use real key
    # check if use test key
    elif [ "$2" -eq "0" ]; then
        echo use test key
    # use local fallback key
    else
        echo use fallback key

        # sign spl hash
        util_auth.sh -i bpu.bin_hash.bin -k spl_rsa_bpu_img_priv.pem -o bpu.bin.sign -s
    fi
}

#$1 $get_rom_key
#$2 $fallback_key
#$3: number of rsa key
sign_header()
{
    image_size=$(wc -c < bpu.bin.pad.enc)
    
    hex2bin.sh $bpu_image_load_addr 	bpu_image_load_addr.bin
    hex2bin.sh $image_size 				bpu_image_size.bin
    hex2bin.sh $bpu0_fetch_only_start	bpu0_fetch_only_start.bin
    hex2bin.sh $bpu0_fetch_only_sz		bpu0_fetch_only_sz.bin
    hex2bin.sh $bpu1_fetch_only_start	bpu1_fetch_only_start.bin
    hex2bin.sh $bpu1_fetch_only_sz		bpu1_fetch_only_sz.bin
    hex2bin.sh $bpu_range_start			bpu_range_start.bin
    hex2bin.sh $bpu_range_sz			bpu_range_sz.bin

    cat bpu.bin.sign       			 > bpu_header_tmp
    cat bpu_image_load_addr.bin     >> bpu_header_tmp
    cat bpu_image_size.bin          >> bpu_header_tmp
    cat bpu0_fetch_only_start.bin   >> bpu_header_tmp
    cat bpu0_fetch_only_sz.bin   	>> bpu_header_tmp
    cat bpu1_fetch_only_start.bin   >> bpu_header_tmp
    cat bpu1_fetch_only_sz.bin   	>> bpu_header_tmp
    cat bpu_range_start.bin			>> bpu_header_tmp
	cat bpu_range_sz.bin			>> bpu_header_tmp

    dd if=/dev/zero of=bpu_header_tmp.pad bs=1 count=$bpu_header_size                   status=none
    dd if=bpu_header_tmp of=bpu_header_tmp.pad bs=1 count=$bpu_header_size conv=notrunc status=none

    util_auth.sh -i bpu_header_tmp.pad -o bpu_header_tmp -h

    # check if use rom key
    if [ "$1" -eq "1" ]; then
        echo use real key
    # check if use test key
    elif [ "$2" -eq "0" ]; then
        echo use test key
    # use local fallback key
    else
        echo use fallback key
        util_auth.sh -i bpu_header_tmp_hash.bin -k spl_rsa_bpu_img_priv.pem -o bpu_header_tmp.sign -s
    fi

    cat bpu_header_tmp.sign      > bpu_header_with_sign
    cat bpu_header_tmp.pad      >> bpu_header_with_sign
}

rm $output_loc/  -rf
rm $key_set_loc/ -rf
rm $debug_loc/   -rf

pack_bpu()
{
    mkdir -p $output_loc
    mkdir -p $key_set_loc
    mkdir -p $debug_loc

    # get rom/efuse/spl keys
    get_key $get_rom_key $fallback_key $fallback_key_loc
    
    # sign Key bank: the first key is spl_aes_key to decrypt spl iamge, the second is spl_rsa_key to verfiy spl image
    # in this keybank we reserve $keybank_size, that is to say: we can put about 6 aes/rsa key sets into it
    #keybank_size=1664
    #enc_and_sign_key_bank $get_rom_key $fallback_key #$1
    
    # sign BPU Image
    cp in/bpu.bin .
    enc_and_sign_spl $get_rom_key $fallback_key 
    rm bpu.bin
    
    # sign Header
    sign_header $get_rom_key $fallback_key #$1
    
    # cat image / key bank / header together
    #spl_header_off=$(($keybank_size + $image_size))
    #hex2bin.sh $spl_header_off spl_header_off.bin
    #hex2bin.sh 0 spl_header_off_pad.bin
    # we put spl_header_off.bin (4 bytes) to the top of spl.img and pad 12 bytes by using spl_header_off_pad.bin
    #cat spl_header_off.bin           > spl.img${1}.bin
    #cat spl_header_off_pad.bin      >> spl.img${1}.bin
    #cat spl_header_off_pad.bin      >> spl.img${1}.bin
    #cat spl_header_off_pad.bin      >> spl.img${1}.bin
    cat bpu_header_with_sign         > bpu.img.bin
    cat bpu.bin.pad.enc             >> bpu.img.bin
    #cat spl_key_bank_img.pad.enc    >> spl.img${1}.bin
    #cat rom_rsa4_pub.bin            >> spl.img${1}.bin
    
    # move all key to $key_set_loc and debug image to $debug_loc
    #mv spl_aes_spl_img.* spl_rsa_spl_img_p* $key_set_loc
	mv spl_aes_bpu_img.* spl_rsa_bpu_img_p* $key_set_loc
    #mv rom_aes.* rom_rsa*_pub.bin $key_set_loc
    #mv efuse_aes.* efuse_rom_rsa4_pub.bin.hash $key_set_loc
    #mv spl_key_bank_img* spl_key_bank_tmp $debug_loc
    mv bpu.bin* $debug_loc
    mv bpu_header_tmp bpu_header_tmp.pad bpu_image_load_addr.bin bpu_image_size.bin $debug_loc
	mv bpu0_fetch_only_start.bin bpu0_fetch_only_sz.bin bpu1_fetch_only_start.bin bpu1_fetch_only_sz.bin $debug_loc
    mv bpu_header_tmp* bpu_header_with_sign $debug_loc
    #mv spl_header_off.bin spl_header_off_pad.bin $debug_loc
    mv bpu.img.bin $output_loc/
    #if [ "$fallback_key" -eq "1" ]; then
    #    mv rom_rsa*_priv.pem $key_set_loc
    #fi
	mv bpu_range_start.bin  bpu_range_sz.bin $debug_loc
}

pack_bpu
