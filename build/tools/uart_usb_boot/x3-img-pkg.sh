#!/bin/bash
set -e

if [ ! $HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH ];then
    HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH=$(cd $(dirname $0); pwd)
fi

cal_pos() {
	alignment=4096
	file=$1
	# convert to decimal
	start_off=$((16#$2))
	if [ ! -f ${file} ];then
		# Padding
		file_size=$alignment
	else
		file_size=$(du -b ${file} | awk '{print $1}')
	fi
	result_off=$((((${start_off} + ${file_size}) / ${alignment} + 1) * ${alignment}))
	echo $(echo "obase=16; $result_off" | bc)
}

set_pos() {
	# image position in pkg file
	spl_pos=$1
	ddr_pos=$(cal_pos ${spl_img} ${spl_pos})
	bl31_pos=$(cal_pos ${ddr_img} ${ddr_pos})
	warmspl_pos=$(cal_pos ${bl31_img} ${bl31_pos})
	uboot_pos=$(cal_pos ${warmspl_img} ${warmspl_pos})
	dtb_pos=$(cal_pos ${uboot_img} ${uboot_pos})
	linux_pos=$(cal_pos ${dtb_img} ${dtb_pos})
	bpu_pos=$(cal_pos ${linux_img} ${linux_pos})
	if [ $BUILD_LINUX -eq 1 ]; then
		echo "gen pkg with Linux image!"
		bl31_jump_entry=80000
	else
		echo "gen pkg with u-boot image!"
		bl31_jump_entry=2100000
	fi
}

image_path_handle() {
	file_path=$1
	echo $file_path

	if [ ! -z $file_path ]; then
		linux_img=$file_path/Image
		dtb_img=$file_path/hobot-xj3-dtb.img
		bl31_img=$file_path/$BL31_IMAGE_NAME
		uboot_img=$file_path/$UBOOT_IMAGE_NAME
		warmspl_img=$file_path/warm_spl.pkg
		bpu_img=$file_path/bpu.img.bin
		ddr_img=$file_path/$DDR_IMAGE_NAME
	fi
}

mk_nor() {
	set_pos 30000
	${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 1 --bi $spl_img --ba0 $spl_pos --bload $SPL_LOAD_ADDR -o $output.orig --bl31imgf $bl31_img --bl31a0 $bl31_pos --imgf3 $warmspl_img --img3 $warmspl_pos --imgf $uboot_img --img0 $uboot_pos --imgf1 $linux_img --img1 $linux_pos --bimgf ./images/bpu.img.bin --bpia0 $bpu_pos --iload $bl31_jump_entry
	dd if=/dev/zero of=$output bs=1 count=$size
	dd if=$output.orig of=$output oflag=seek_bytes conv=notrunc seek=65536
	rm $output.orig
}

mk_emmc() {
	set_pos 200
	${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 2 --bi $spl_img --ba0 $spl_pos --bload $SPL_LOAD_ADDR -o $output --bl31imgf $bl31_img --bl31a0 $bl31_pos --imgf $uboot_img --img0 $uboot_pos --imgf1 $linux_img --img1 $linux_pos --imgf2 $dtb_img --img2 $dtb_pos --iload $bl31_jump_entry

	# --imgf3 $warmspl_img --img3 $warmspl_pos
	# --img2 $dtb_pos --bimgf ./images/bpu.img.bin --bpia0 $bpu_pos --iload $bl31_jump_entry
}

mk_nand_2k() {
	set_pos 80000
	${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 3 --bi $spl_img --ba0 $spl_pos --bload $SPL_LOAD_ADDR -o $output --bl31imgf $bl31_img --bl31a0 $bl31_pos --imgf3 $warmspl_img --img3 $warmspl_pos --imgf $uboot_img --img0 $uboot_pos --imgf1 $linux_img --img1 $linux_pos --imgf2 $dtb_img --img2 $dtb_pos --bimgf ./images/bpu.img.bin --bpia0 $bpu_pos --iload $bl31_jump_entry
}

mk_nand_4k() {
	set_pos 100000
	${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 4 --bi $spl_img --ba0 $spl_pos --bload $SPL_LOAD_ADDR -o $output --bl31imgf $bl31_img --bl31a0 $bl31_pos --imgf3 $warmspl_img --img3 $warmspl_pos --imgf $uboot_img --img0 $uboot_pos --imgf1 $linux_img --img1 $linux_pos --imgf2 $dtb_img --img2 $dtb_pos --bimgf ./images/bpu.img.bin --bpia0 $bpu_pos --iload $bl31_jump_entry
}

mk_usb() {
	set_pos 200
	if [ $BUILD_LINUX -eq 1 ]; then
		echo gen USB pkg with Linux image!
		bl31_jump_entry=280000
	else
		echo gen USB pkg with u-boot image!
		bl31_jump_entry=$UBOOT_IMAGE_LOAD_ADDR
	fi
	${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 5 --bi $spl_img --ba0 $spl_pos --bload $SPL_LOAD_ADDR --d1if $ddr_img --dt1a0 $ddr_pos --dt2a0 $ddr_pos -o $output --bl31imgf $bl31_img --bl31a0 $bl31_pos --imgf $uboot_img --img0 $uboot_pos --imgf1 $linux_img --img1 $linux_pos --imgf2 $dtb_img --img2 $dtb_pos --iload $bl31_jump_entry

	# --imgf3 $warmspl_img --img3 $warmspl_pos
	# --bimgf ./images/bpu.img.bin --bpia0 $bpu_pos
}

mk_uart() {
	set_pos 200
	if [ $BUILD_LINUX -eq 1 ]; then
		echo "gen uart pkg with Linux image!"
		${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 5 -o $output --bl31imgf $bl31_img --bl31a0 200 --imgf $uboot_img --img0 20200 --imgf2 $dtb_img --img2 90200 --imgf1 $linux_img --img1 b0200 --iload 80000
	else
		echo "gen uart pkg with u-boot image!"
		${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 5 -o $output --bl31imgf $bl31_img --bl31a0 200 --imgf $uboot_img --img0 30200 --iload 2100000
	fi

	# --imgf3 $warmspl_img --img3 80200
	# --imgf3 $warmspl_img --img3 a0200
}

mk_warm_spl() {
	${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-imgpkg -d 5 --bi $spl_img --ba0 200 --bload $SPL_LOAD_ADDR -o $output
}

boardid="0"

#UBOOT_HOME=$PWD/..
SPL_LOAD_ADDR=80000000
size=262144
BUILD_LINUX=0

# image file path
linux_img=./images/Image
dtb_img=./images/hobot-xj3-dtb.img
bl31_img=./images/$BL31_IMAGE_NAME
uboot_img=./images/$UBOOT_IMAGE_NAME
warmspl_img=./images/warm_spl.pkg
bpu_img=./images/bpu.img.bin
ddr_img=./images/$ddr_img_NAME

while getopts "b:u:i:o:t:l:" opt; do
	case $opt in
	t)
		build_type=$OPTARG
		echo "**************************"
		echo "**  Building ${build_type} pkg  **"
		build_cmd="mk_"${build_type}
		;;
	i)
		spl_img=$OPTARG
		echo $spl_img

		file_path=${spl_img%/*}

		image_path_handle $file_path
		;;
	o)
		output=$OPTARG
		;;
	l)
		BUILD_LINUX=$OPTARG
		;;
	b)
		bl31_img=$OPTARG
		;;
	u)
		uboot_img=$OPTARG
		;;
	\?)
		echo "Invalid option: -$OPTARG" >&2
		;;
	esac
done

$build_cmd

[ -z $BOARD_ID ] && BOARD_ID="0"

if [ $boardid = "0" -a $BOARD_ID != "0" ]; then
	boardid=$BOARD_ID
fi

echo "boardid: $boardid BOARD_ID: $BOARD_ID"

if [ $boardid != "0" ]; then
	echo -n -e "\\x${BOARD_ID:6:2}\\x${BOARD_ID:4:2}\\x${BOARD_ID:2:2}\\x${BOARD_ID:0:2}" | dd of=$output bs=4 seek=48 conv=notrunc >/dev/null 2>&1
	csum=0

	for i in {0..511}; do
		if [ $i -lt 12 -o $i -gt 15 ]; then
			cur_hex=0x$(xxd -p -l 1 -s $i $output)
			csum=$(($csum + $cur_hex))
		fi
	done

	csum=$(printf "%08x" $csum)
	echo -n -e "\\x${csum:6:2}\\x${csum:4:2}\\x${csum:2:2}\\x${csum:0:2}" | dd of=$output bs=4 seek=3 conv=notrunc >/dev/null 2>&1
fi

echo "***  ${build_type} pkg done!  ***"
echo "**************************"
