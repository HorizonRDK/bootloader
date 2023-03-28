export PATH=$PATH:$PWD/utils
JQ_EXEC=`which jq`
output_loc="out/bpu"
key_set_loc="out/bpu/key_set"
debug_loc="out/bpu/debug"

get_rom_key=0
fallback_key=0

while getopts "rtbi:j:" opt; do
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
       j)
           FILE_PATH=$OPTARG
	   echo $json_file
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

#$1 hex data
hex2dec(){
    printf "%d" $1
}


#$1 $get_rom_key
#$2 $fallback_key
#$3: number of rsa key
sign_header()
{
    image_size=$(wc -c < bpu_hbm.bin) 

	cat bpu.bin.sign             > bpu_header_tmp
	cat bpu_header_except_sig.bin   >>bpu_header_tmp
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
# tmp function
#$1: image $2
#$2: pad size
pad_image()
{
    img_size=$(wc -c < $1)

    mod=$(($2-$((($img_size%$2)))))
    if [ "$mod" -eq "$2" ]; then
        img_size_align=$img_size
    else
        img_size_align=$(($img_size + $mod))
    fi

    pad_image_name=$1.pad

    dd if=/dev/zero of=$pad_image_name bs=1 count=$img_size_align           status=none
    dd if=$1 of=$pad_image_name bs=1 count=$img_size_align conv=notrunc     status=none

}

#$1 json file name
pack_mul_hbm()
{

	name=$(cat $1 | ${JQ_EXEC} .summary.file_name | sed 's/\"//g')
	if [ $name != "null" ]&& [ $name != "" ]; then
		#encrypt bpu image, shall be delete in future  #1
		pad_image $name 64
		util_auth.sh -i $name.pad -o $name.tmp -h

		# sign bpu image hash
		util_auth.sh -i $name.tmp_hash.bin -k spl_rsa_bpu_img_priv.pem -o $name.tmp.sign -s
		rm $name.tmp_*
		cat $name.pad > $name-with_sign
		cat $name.tmp.sign >> $name-with_sign
	fi

	
}

#sign_mul_bpu_hbm()
sign_mul_bpu_hbm()
{
	ifs_old=$IFS
	IFS=$','
	for i in $(echo "${1}")
	do
		pack_mul_hbm $i
	done
	IFS=$ifs_old
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
   	
	#pack all hbm file to one file
	sign_mul_bpu_hbm $1
	mv spl_aes_bpu_img.* spl_rsa_bpu_img_p* $key_set_loc


}
pack_bpu $FILE_PATH
