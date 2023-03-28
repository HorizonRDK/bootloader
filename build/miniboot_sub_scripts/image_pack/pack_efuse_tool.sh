#!/bin/bash

set -e

utils_dir=${HR_KEY_MANAGEMENT_TOOLKITS_PATH}
 
if [ ! -d "$utils_dir" ]; then
  echo "${utils_dir} directory not exist"
  exit -1
fi
 
export PATH=$PATH:${utils_dir}

output_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"efuse"
key_set_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"efuse/key_set"
debug_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"efuse/debug"

get_rom_key=0
fallback_key=0
output_file=efuse.bin
input_file=efuse-origin.bin
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

#$1 hex data
hex2dec(){
    printf "%d" $1
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

    pad_image_input_file=$1.pad

    dd if=/dev/zero of=$pad_image_input_file bs=1 count=$img_size_align           status=none
    dd if=$1 of=$pad_image_input_file bs=1 count=$img_size_align conv=notrunc     status=none

}



rm -rf $output_loc
rm -rf $key_set_loc
rm -rf $debug_loc

sign_efuse()
{
	mkdir -p $output_loc
	mkdir -p $key_set_loc
	mkdir -p $debug_loc
	cp ${MINIBOOT_SOURCE_DIR}/ddr/efuse/$input_file ./
	# get rom/efuse/spl keys
	get_key $get_rom_key $fallback_key $fallback_key_loc
	pad_image $input_file 64
	util_auth.sh -i $input_file.pad -o $input_file.tmp -h

	# sign bpu image hash
	util_auth.sh -i $input_file.tmp_hash.bin -k spl_rsa_bpu_img_priv.pem -o $input_file.tmp.sign -s
	rm $input_file.tmp_*
	cat $input_file.pad > $output_file
	cat $input_file.tmp.sign >> $output_file
	mv spl_aes_bpu_img.* spl_rsa_bpu_img_p* $key_set_loc
	mv $output_file $output_loc
	rm $input_file.* $input_file
}
sign_efuse
mkdir -p ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr
cp  $output_loc/$output_file  ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/$EFUSE_IMAGE_NAME
