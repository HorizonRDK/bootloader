####################################
# Set you own environment here
####################################
MULTI_FILES="-DMULTI_FILES"
DDR_PKG="-DSPL_DDR_PKG"
target_file="hb_parameter"
BOOT_DEFINE=" "
UART_DDR_BIN=0
DDR_CUSTOMER=" "
src_file=" hb_ddrp_parameter.c hb_ddrc_parameter.c hb_pie_parameter.c hb_dmem_parameter.c hb_imem_parameter.c hb_addrmap_parameter.c hb_ddr_dqmap.c"
DDR_SETTING=" "
BASE_BOARD="-DBASE_BOARD_TYPE=0"
UART_IMG_DIR="uart_ddr_img"
BOOT_TYPE_DEFINE=" "
####################################
# function define
####################################
mk_ddr_bin()
{
    rm -f *.bin hb_parameter
    if [ -d $UART_IMG_DIR ]; then
	    rm -rf $UART_IMG_DIR
    fi
    mkdir -p $UART_IMG_DIR
    if [ "$IMAGE_TYPE" = "nand" ]; then
        BOOT_TYPE_DEFINE="-DBOOT_NAND"
    fi
    echo "gcc -g -o $target_file $DDR_SETTING $DDR_PKG $BOOT_DEFINE $MULTI_FILES $DDR_CUSTOMER $src_file $BASE_BOARD $BOOT_TYPE_DEFINE"
    gcc -g -o $target_file $DDR_SETTING $DDR_PKG $BOOT_DEFINE $MULTI_FILES $DDR_CUSTOMER $src_file $BASE_BOARD $BOOT_TYPE_DEFINE
    ./hb_parameter
	if [ $UART_DDR_BIN = 0 ]; then
            dd if=spl_ddr_img.bin of=spl_ddr_img_header.bin bs=512 seek=5 conv=notrunc,sync status=none
            rm -rf spl_ddr_img.bin
            mv spl_ddr_img_header.bin spl_ddr_img.bin
	else
            dd if=ddr4_micron_uart_img.bin of=ddr4_micron_uart_img_header.bin bs=512 seek=1 conv=notrunc,sync status=none
            rm -rf ddr4_micron_uart_img.bin
            mv ddr4_micron_uart_img_header.bin ddr4_micron_uart_img.bin

            dd if=ddr4_samsung_uart_img.bin of=ddr4_samsung_uart_img_header.bin bs=512 seek=1 conv=notrunc,sync status=none
            rm -rf ddr4_samsung_uart_img.bin
            mv ddr4_samsung_uart_img_header.bin ../../../spl/ddr4_samsung_uart_img.bin

            dd if=lpddr4_micron_uart_img.bin of=lpddr4_micron_uart_img_header.bin bs=512 seek=1 conv=notrunc,sync status=none
            rm -rf lpddr4_micron_uart_img.bin
            mv lpddr4_micron_uart_img_header.bin lpddr4_micron_uart_img.bin

            dd if=lpddr4_hynix_uart_img.bin of=lpddr4_hynix_uart_img_header.bin bs=512 seek=1 conv=notrunc,sync status=none
            rm -rf lpddr4_hynix_uart_img.bin
            mv lpddr4_hynix_uart_img_header.bin lpddr4_hynix_uart_img.bin
	fi
}

helper()
{
	echo
	echo ---------------------------------------------------------------------
	echo "Usage:  "
	echo "  sh mk_ddr_bin.sh [option]"
	echo "    -c: enable customer ddr settings"
	echo "    -b: dqmap value,[dvb/cvb/sdb]"
	echo "    -h: helper prompt"
	echo
}
####################################
# main logic from here
####################################
while getopts "cs:b:h" opt; do
	case $opt in
		s)
			DDR_SETTING=$OPTARG
			;;
		c)
			DDR_CUSTOMER="-DENABLE_DDR_CUSTOMER_SETTINGS"
			;;
		b)
			if [ $OPTARG = "dvb" ]; then
			    BASE_BOARD="-DBASE_BOARD_TYPE=1"
			elif [ $OPTARG = "cvb" ]; then
			    BASE_BOARD="-DBASE_BOARD_TYPE=3"
			elif [ $OPTARG = "sdb" ]; then
			    BASE_BOARD="-DBASE_BOARD_TYPE=4"
			else
			    echo "invalid base board type"
			fi
			echo "base board type:$BASE_BOARD"
			;;

		h)
			helper
			exit
			;;
	esac
done

mk_ddr_bin
