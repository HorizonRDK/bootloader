#!/bin/bash
###
 # COPYRIGHT NOTICE
 # Copyright 2023 Horizon Robotics, Inc.
 # All rights reserved.
 # @Date: 2023-01-30 11:27:41
 # @LastEditTime: 2023-03-28 20:15:25
### 

set -e

utils_dir=${HR_KEY_MANAGEMENT_TOOLKITS_PATH}

if [ ! -d "$utils_dir" ]; then
  echo "${utils_dir} directory not exist"
  exit -1
fi

export PATH=$PATH:${utils_dir}

UBOOT_SRC_DIR=${HR_TOP_DIR}/uboot

UBOOT_TARGET_IMAGE_NAME=uboot.img

output_loc="${IMAGE_DEPLOY_DIR}/uboot"
key_set_loc="${output_loc}/key_set"
debug_loc="${output_loc}/debug"

get_rom_key=0
fallback_key=1
fallback_key_loc="${utils_dir}/fallback_key_sets"

# aes/rsa keys
uboot_rsa_pub="spl_rsa_uboot_img_pub.bin"
uboot_rsa_priv="spl_rsa_uboot_img_priv.pem"
uboot_aes_key="spl_aes_uboot_img.key"
uboot_aes_iv="spl_aes_uboot_img.iv"

# uboot image
uboot_image="u-boot.bin"
uboot_image_load_addr=0x"${HR_UBOOT_IMAGE_LOAD_ADDR}"
uboot_header_size=320
uboot_magic="0x544F4248"
USER_PRODUCT_ID=0
USER_CUSTOMER_ID=0
#use image magic "BL33" to distinguish other imgs
image_magic="0x33334C42"

function get_key()
{
    # use local fallback key
    echo "using fall back key"
    cp -rf $fallback_key_loc/$uboot_rsa_pub  ./
    cp -rf $fallback_key_loc/$uboot_rsa_priv ./
    cp -rf $fallback_key_loc/$uboot_aes_key  ./
    cp -rf $fallback_key_loc/$uboot_aes_iv   ./
}

function enc_and_sign_uboot()
{
    # encrypt uboot image
    util_auth.sh -i $uboot_image -k $uboot_aes_key -v $uboot_aes_iv -p 64 -e

    # hash uboot image
    util_auth.sh -i ${uboot_image}.pad -o $uboot_image -h 

    # sign uboot hash
    util_auth.sh -i ${uboot_image}_hash.bin -k $uboot_rsa_priv -o ${uboot_image}.sign -s
}

function sign_header()
{
    local header_tmp="uboot_header_tmp"
    local header_sign="uboot_header_with_sign"

    image_size=$(wc -c < ${uboot_image}.pad)
    echo "image size = $image_size"

    hex2bin.sh $uboot_magic uboot_magic.bin
    hex2bin.sh $uboot_image_load_addr uboot_image_load_addr.bin
    hex2bin.sh $image_size uboot_image_size.bin
    cat ${uboot_image}.sign            > $header_tmp
    cat uboot_magic.bin               >> $header_tmp
    cat uboot_image_load_addr.bin     >> $header_tmp
    cat uboot_image_size.bin          >> $header_tmp
    hex2bin.sh $USER_PRODUCT_ID product_id.bin
    cat product_id.bin                >> $header_tmp
    rm product_id.bin
    hex2bin.sh $USER_CUSTOMER_ID customer_id.bin
    cat customer_id.bin                >> $header_tmp
    rm customer_id.bin

    hex2bin.sh $image_magic image_magic.bin
    cat image_magic.bin                >> $header_tmp
    rm image_magic.bin

    dd if=/dev/zero of=${header_tmp}.pad bs=1 count=$uboot_header_size status=none
    dd if=$header_tmp of=${header_tmp}.pad bs=1 count=$uboot_header_size conv=notrunc status=none

    util_auth.sh -i ${header_tmp}.pad -o $header_tmp -h
    util_auth.sh -i ${header_tmp}_hash.bin -k $uboot_rsa_priv -o ${header_tmp}.sign -s

    cat ${header_tmp}.sign      > $header_sign
    cat ${header_tmp}.pad      >> $header_sign
}

function pack_uboot()
{
    local uboot_sign_image="uboot.img.bin"

    # get uboot keys
    get_key

    # sign uboot Image
    cp "${UBOOT_SRC_DIR}/${uboot_image}" ./
    enc_and_sign_uboot
    rm ${uboot_image}

    # sign Header
    sign_header

    # cat image / header together
    cat uboot_header_with_sign        >> $uboot_sign_image

    if [ x"$ENCRYPT_FLAG" = x"true" ];then
        cat ${uboot_image}.pad.enc            >> $uboot_sign_image
    else
        cat ${uboot_image}.pad            >> $uboot_sign_image
    fi

    # move all key to $key_set_loc
    mv $uboot_rsa_pub $uboot_rsa_priv $key_set_loc
    mv $uboot_aes_key $uboot_aes_iv $key_set_loc

    # move debug image to $debug_loc
    mv ${uboot_image}* $debug_loc
    mv uboot_header_tmp uboot_header_tmp.pad $debug_loc
    mv uboot_image_load_addr.bin uboot_image_size.bin $debug_loc
    mv uboot_header_tmp* uboot_header_with_sign $debug_loc
    # mv uboot_magic.bin $output_loc
}

# clear
rm -rf $output_loc

# create outpur dir
mkdir -p $output_loc
mkdir -p $key_set_loc
mkdir -p $debug_loc

cd ${output_loc}

# pack encrypt and sign uboot image
pack_uboot

# cp file to out
echo "cp -rf uboot.img.bin  ${IMAGE_DEPLOY_DIR}/${UBOOT_TARGET_IMAGE_NAME}"
cp -rf uboot.img.bin  ${IMAGE_DEPLOY_DIR}/${UBOOT_TARGET_IMAGE_NAME}
cd -

rm -rf ${output_loc}

