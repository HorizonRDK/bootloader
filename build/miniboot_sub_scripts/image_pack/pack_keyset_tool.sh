#!/bin/bash

set -e

utils_dir=${HR_KEY_MANAGEMENT_TOOLKITS_PATH}

if [ ! -d "$utils_dir" ]; then
  echo "${utils_dir} directory not exist"
  exit -1
fi

export PATH=$PATH:${utils_dir}

KEY_SETS_PATH=${utils_dir}/fallback_key_sets
debug_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"keyset/debug"
mkdir -p $debug_loc

#$1 input
#$2 count
gen_pub_bin_from_pub_pem()
{
    openssl rsa -pubin -inform PEM -in $1 -outform DER -out customer_pub.der
    if [  $? -ne 0 ];then
        echo "generete customer_pub.der error"
    fi
    dd if=customer_pub.der of=customer_pub.bin bs=1 count=$2 skip=33
}

#1 input
#2 count
gen_pub_bin_from_pri_pem()
{
    openssl rsa -in $1 -pubout -outform DER -out customer_pub.der
    openssl rsa -in $1 -pubout -out customer_pub.pem
    gen_pub_bin_from_pub_pem customer_pub.pem $2

}

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

    #echo $mod
    #echo $img_size
    #echo $img_size_align
    #echo $pad_image_name
    pad_image_name=$1.pad

    dd if=/dev/zero of=$pad_image_name bs=1 count=$img_size_align           status=none
    dd if=$1 of=$pad_image_name bs=1 count=$img_size_align conv=notrunc     status=none

}

#generate rsa hash error
rsa_hash_error()
{
    echo "invalid uboot private key or generate key hash failed"
    echo "invalid uboot private key or generate key hash failed" >efuse_hash_data
    mv efuse_hash_data $TARGET_DEPLOY_DIR/ddr/
    exit 1
}

dd if=/dev/zero of=./key_set.bin bs=1 count=288 status=none
if [ -f "$KEY_SETS_PATH/spl_aes_uboot_img.key" ]; then
    dd if=$KEY_SETS_PATH/spl_aes_uboot_img.key of=./key_set.bin bs=1 count=16 conv=notrunc status=none
fi
if [ -f "$KEY_SETS_PATH/spl_aes_uboot_img.iv" ]; then
    dd if=$KEY_SETS_PATH/spl_aes_uboot_img.iv of=./key_set.bin bs=1 count=16 seek=16 conv=notrunc status=none
fi
if [ -f "$KEY_SETS_PATH/spl_rsa_uboot_img_pub.pem" ]; then

    openssl rsa -pubin -inform PEM -in $KEY_SETS_PATH/spl_rsa_uboot_img_pub.pem -outform DER -out $KEY_SETS_PATH/spl_rsa_uboot_img_pub.der
    if [  $? -ne 0 ];then
        rsa_hash_error
    fi
    dd if=$KEY_SETS_PATH/spl_rsa_uboot_img_pub.der of=$KEY_SETS_PATH/spl_rsa_uboot_img_pub.bin bs=1 count=256 skip=33
    rm $KEY_SETS_PATH/spl_rsa_uboot_img_pub.der
    dd if=$KEY_SETS_PATH/spl_rsa_uboot_img_pub.bin of=./key_set.bin bs=1 count=256 seek=32 conv=notrunc status=none
    if [  $? -ne 0 ];then
        rsa_hash_error
    fi
else
    rsa_hash_error
fi
pad_image key_set.bin 64
util_auth.sh -i ./key_set.bin.pad -o key_set.bin -h
hexdump -v -e '"0x%08x;\n"' key_set.bin_hash.bin | sed "s/^/hash[bnk_num] = /"  > efuse_hash_bnk
bn=0
while read LINE
do
    echo $LINE | sed "s/bnk_num/$bn/" >>efuse_hash_data
    bn=$(($bn+1))
done <efuse_hash_bnk
rm efuse_hash_bnk
mkdir -p ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/
mv efuse_hash_data ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/
mv ./key_set.bin.pad ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/$KEY_IMAGE_NAME
mv key_set.bin* $debug_loc
