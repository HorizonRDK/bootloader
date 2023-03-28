#!/bin/bash

set -e

utils_dir=${HR_KEY_MANAGEMENT_TOOLKITS_PATH}

if [ ! -d "$utils_dir" ]; then
  echo "${utils_dir} directory not exist"
  exit -1
fi

export PATH=$PATH:${utils_dir}

output_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"cr5"
key_set_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"cr5/key_set"
debug_loc=${MINIBOOT_TARGET_DEPLOY_DIR}/"cr5/debug"

get_rom_key=0
fallback_key=1
fallback_key_loc="${utils_dir}/fallback_key_sets"

# aes/rsa keys
cr5_rsa_pub="spl_rsa_uboot_img_pub.bin"
cr5_rsa_priv="spl_rsa_uboot_img_priv.pem"
cr5_aes_key="spl_aes_uboot_img.key"
cr5_aes_iv="spl_aes_uboot_img.iv"

# cr5 image
cr5_image="cr5.bin"
cr5_image_load_addr=0x"$CR5_IMAGE_LOAD_ADDR"
cr5_header_size=320
cr5_magic="0x35524248"
USER_PRODUCT_ID=0
USER_CUSTOMER_ID=0
image_magic="0x35524248"

function get_key()
{
    # use local fallback key
    echo "using fall back key"
    cp -rf $fallback_key_loc/$cr5_rsa_pub  ./
    cp -rf $fallback_key_loc/$cr5_rsa_priv ./
    cp -rf $fallback_key_loc/$cr5_aes_key  ./
    cp -rf $fallback_key_loc/$cr5_aes_iv   ./
}

function enc_and_sign_cr5()
{
    # encrypt cr5 image
    util_auth.sh -i $cr5_image -k $cr5_aes_key -v $cr5_aes_iv -p 64 -e

    # hash cr5 image
    util_auth.sh -i ${cr5_image}.pad -o $cr5_image -h 

    # sign cr5 hash
    util_auth.sh -i ${cr5_image}_hash.bin -k $cr5_rsa_priv -o ${cr5_image}.sign -s
}

function sign_header()
{
    local header_tmp="cr5_header_tmp"
    local header_sign="cr5_header_with_sign"

    image_size=$(wc -c < ${cr5_image}.pad)
    echo "image size = $image_size"

    hex2bin.sh $cr5_magic cr5_magic.bin
    hex2bin.sh $cr5_image_load_addr cr5_image_load_addr.bin
    hex2bin.sh $image_size cr5_image_size.bin
    cat ${cr5_image}.sign            > $header_tmp
    cat cr5_magic.bin               >> $header_tmp
    cat cr5_image_load_addr.bin     >> $header_tmp
    cat cr5_image_size.bin          >> $header_tmp
    hex2bin.sh $USER_PRODUCT_ID product_id.bin
    cat product_id.bin                >> $header_tmp
    rm product_id.bin
    hex2bin.sh $USER_CUSTOMER_ID customer_id.bin
    cat customer_id.bin                >> $header_tmp
    rm customer_id.bin

    hex2bin.sh $image_magic image_magic.bin
    cat image_magic.bin                >> $header_tmp
    rm image_magic.bin

    dd if=/dev/zero of=${header_tmp}.pad bs=1 count=$cr5_header_size status=none
    dd if=$header_tmp of=${header_tmp}.pad bs=1 count=$cr5_header_size conv=notrunc status=none

    util_auth.sh -i ${header_tmp}.pad -o $header_tmp -h
    util_auth.sh -i ${header_tmp}_hash.bin -k $cr5_rsa_priv -o ${header_tmp}.sign -s

    cat ${header_tmp}.sign      > $header_sign
    cat ${header_tmp}.pad      >> $header_sign
}

rm -rf $output_loc
rm -rf $key_set_loc
rm -rf $debug_loc

function pack_cr5()
{
    local cr5_sign_image="cr5.img.bin"

    mkdir -p $output_loc
    mkdir -p $key_set_loc
    mkdir -p $debug_loc

    # get cr5 keys
    get_key

    # sign cr5 Image
    cp "$SRC_CR5_DIR/$cr5_image" ./
    enc_and_sign_cr5
    rm $cr5_image

    # sign Header
    sign_header

    # cat image / header together
    cat cr5_header_with_sign        >> $cr5_sign_image

    cat ${cr5_image}.pad            >> $cr5_sign_image

    # move all key to $key_set_loc
    mv $cr5_rsa_pub $cr5_rsa_priv $key_set_loc
    mv $cr5_aes_key $cr5_aes_iv $key_set_loc

    # move debug image to $debug_loc
    mv ${cr5_image}* $debug_loc
    mv cr5_header_tmp cr5_header_tmp.pad $debug_loc
    mv cr5_image_load_addr.bin cr5_image_size.bin $debug_loc
    mv cr5_header_tmp* cr5_header_with_sign $debug_loc
    mv cr5.img.bin $output_loc
    mv cr5_magic.bin $output_loc
}

# pack encrypt and sign cr5 image
pack_cr5

# cp file to out
mkdir -p ${MINIBOOT_TARGET_DEPLOY_DIR}/cr5
cp -rf $output_loc/cr5.img.bin  ${MINIBOOT_TARGET_DEPLOY_DIR}/cr5/$CR5_IMAGE_NAME
