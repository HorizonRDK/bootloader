#!/bin/bash

output=$TARGET_TARGET_DIR/deploy/usb_uart_pkg
image_path=$SRC_SCRIPTS_DIR/usb_boot/image
spl_image=$UBOOT_SPL_NAME
ddr_image=$DDR_IMAGE_NAME

function build_kernel_with_cpio()
{
    kernel_path=$SRC_KERNEL_DIR
    cd kernel_path

    # compile kernel
    KERNEL_WITH_CPIO=true ./build.sh

    # copy file to output
    cp -rf $kernel_path/arch/arm64/boot/Image $output
    cp -rf $kernel_path/arch/arm64/boot/dts/hobot/*.dtb $output
}

# copy image to temp file
function image_copy_kernel()
{
    bl31_path=$TARGET_TARGET_DIR/deploy/bl31
    spl_path=$TARGET_TARGET_DIR/deploy/sbl
    uboot_path=$TARGET_TARGET_DIR/deploy/uboot
    ddr_path=$TARGET_TARGET_DIR/deploy/ddr

    # kernel and dtb
    cp -rf $kernel_path/recovery.gz $image_path/
    gunzip $image_path/recovery.gz
    mv $image_path/recovery $image_path/Image
    # cp -rf $kernel_path/*.dtb $image_path/
    cp -rf $dtb_image_path/hobot-xj3-dtb.img $image_path/

    # bl31 image
    cp -rf $bl31_path/$BL31_IMAGE_NAME $image_path/

    # spl image
    cp -rf $spl_path/$spl_image $image_path/

    # ddr image
    cp -rf $ddr_path/$ddr_image $image_path/

    # uboot image
    cp -rf $uboot_path/$UBOOT_IMAGE_NAME $image_path/$UBOOT_IMAGE_NAME
}

function image_copy_uart()
{
    kernel_path=$TARGET_TARGET_DIR/deploy/boot
    dtb_image_path=$TARGET_TARGET_DIR/boot
    bl31_path=$SRC_BL31_DIR
    spl_path=$SRC_SPL_DIR
    if [ x"$SECURE_CHIP" = x"true" ]; then
        uboot_path=$TARGET_TARGET_DIR/deploy/uboot
    else
        uboot_path=$TARGET_UBOOT_DIR
    fi
    ddr_path=$SRC_BOOT_DDR_DIR

    # bl31 image
    cp -rf $bl31_path/bl31.bin $image_path/$BL31_IMAGE_NAME

    # spl image
    cp -rf $spl_path/$spl_image $image_path/
    cp -rf $spl_path/*uart*.bin $output/

    # ddr image
    cp -rf $ddr_path/*uart_img.bin $output/
    rm -rf $output/$DDR_IMAGE_NAME

    # uboot image
    if [ x$SECURE_CHIP = x"true" ]; then
        cp -rf $uboot_path/$UBOOT_IMAGE_NAME $image_path/$UBOOT_IMAGE_NAME
    else
        cp -rf $uboot_path/u-boot.bin $image_path/$UBOOT_IMAGE_NAME
    fi

}

function xj3_boot_pkg_gain()
{
    local spl_img=$1
    local boot_mode=$2
    cd usb_boot

    if [ x"$boot_mode" = x"uart" ];then
        # uart boot pkg
        bash x3-img-pkg.sh -i $spl_img -o $output/boot_uart.pkg -l 0 -t uart
    elif [ x"$boot_mode" = x"kernel" ];then
        # usb: boot kernel
        bash x3-img-pkg.sh -i $spl_img -o $output/boot_usb.pkg -l 0 -t usb
    fi

    cd -
}

echo "***********************"
echo "**  Create boot.pkg  **"

# mkdir file
mkdir -p $output
mkdir -p $image_path

# copy spl, uboot, spl, image and dtb to temp file
image_copy_uart

# build uart boot.pkg
xj3_boot_pkg_gain $image_path/$spl_image uart

if [ "$BOOT_MODE" == "emmc" ];then
    # image_copy_uart
    image_copy_kernel

    # build usb kernel boot.pkg
    xj3_boot_pkg_gain $image_path/$spl_image kernel
fi

# clean temp file
rm -rf $image_path

echo "**  boot.pkg done!!  **"
echo "***********************"
