#!/bin/bash

set -xe

######## setting utils_funcs ###################
source ${HR_LOCAL_DIR}/utils_funcs.sh

function usage() {
	echo "genNandOrNorImg OPTIONS"
	echo "Options:"
	echo "        -h display this help message"
	echo "        -c partition config file to be used"
}

function cal_leb() {
	avail_size=$1
	#calculate the leb available for the nand size passed in
	avail_peb=$(($avail_size / $peb_size))
	peb_reserved=$(($avail_peb / 50 + 1))
	ubi_overhead=$((4 * ($avail_peb - $peb_reserved - 4) / 128 + 1 + ($peb_reserved + 4)))
	avail_leb=$((($avail_peb - $ubi_overhead) * 128 / 124))
	echo $avail_leb
}

function gen_nand() {
	local env_line=$(awk '/ubootenv.img/ {a=$0} END{print a}' $config)
	local env_arr=(${env_line//:/ })
	if [ ! -z "${env_arr[5]}" ];then
		local env_size=$(((${env_arr[4]:0:0-1} - ${env_arr[3]:0:0-1} + 1) * 512))
	else
		local env_size=$(trans_unit $blk_sz ${env_arr[3]})
	fi
	local envleb=$(cal_leb $env_size)

	# Actual start of nand image build
	echo "LEB used for env.ubifs: $envleb"
	mkdir -p ${IMAGE_DEPLOY_DIR}/nand_ubi

	# prepare each volume in ubi, including creating ubifs images
	runcmd "dd if=/dev/zero of=${IMAGE_DEPLOY_DIR}/veeprom.img bs=$min_io count=1 conv=notrunc,sync status=none"
	cp ${HR_VEEPROM_AND_ENV_CONFIG_FILE} ${IMAGE_DEPLOY_DIR}/nand_ubi/nand_ubi_sys.cfg

	cd ${IMAGE_DEPLOY_DIR}/nand_ubi/
	runcmd "ubinize -o ${IMAGE_DEPLOY_DIR}/ubootenv.ubi -m $min_io -p $peb_size -v ${IMAGE_DEPLOY_DIR}/nand_ubi/nand_ubi_sys.cfg"
	dd if=/dev/zero ibs=1024 count=$((env_size / 1024)) | tr "\000" "\377" >${IMAGE_DEPLOY_DIR}/ubootenv.img
	dd if=${IMAGE_DEPLOY_DIR}/ubootenv.ubi of=${IMAGE_DEPLOY_DIR}/ubootenv.img conv=notrunc,sync status=none
	if [ ! -f "${IMAGE_DEPLOY_DIR}/ubootenv.ubi" ]; then
		echo "ubootenv.ubi Build Failed"
		exit 1
	fi
}

if [ $# -lt 1 ]; then
	usage
	exit 1
fi

while getopts "hc:" opt; do
	case $opt in
	c)
		config=$OPTARG
		;;
	h)
		usage
		exit 0
		;;
	\?)
		exit 1
		;;
	esac
done
shift $(($OPTIND - 1))
blk_sz=1
echo "******************************"
echo "Creating ${bootmode^^} ubi image."

if [ "${BOOT_MODE}" = "nand" ]; then
	min_io=${HR_PAGE_SIZE}
	peb_size=$((${min_io} * 64))
	leb_size=$((${min_io} * 62))
	gen_nand
fi

echo "******************************"
