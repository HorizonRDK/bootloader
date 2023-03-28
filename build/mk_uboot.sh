#!/bin/bash
###
 # COPYRIGHT NOTICE
 # Copyright 2023 Horizon Robotics, Inc.
 # All rights reserved.
 # @Date: 2023-03-28 20:01:52
 # @LastEditTime: 2023-03-28 20:14:59
### 

set -e

######## setting utils_funcs ###################
source ./utils_funcs.sh

export HR_TOP_DIR=$(realpath $(cd $(dirname $0); pwd)/../)
export HR_LOCAL_DIR=$(realpath $(cd $(dirname $0); pwd))

# check board config
check_board_config ${@:1}

export IMAGE_DEPLOY_DIR=${HR_IMAGE_DEPLOY_DIR}
[ ! -z $IMAGE_DEPLOY_DIR ] && [ ! -d $IMAGE_DEPLOY_DIR ] && mkdir $IMAGE_DEPLOY_DIR

bootmode=$HR_BOOT_MODE

config_file=$HR_UBOOT_CONFIG_FILE

N=$(( ($(cat /proc/cpuinfo |grep 'processor'|wc -l)  + 1 ) / 2 ))

function build_all()
{
    make ${config_file} || {
        echo "make $config failed"
        exit 1
    }

    # Compile and generate uboot.bin
    if [ $# -eq 1 ]; then
        # Compile and generate the uboot.bin for the flash tool, 
        # set ddr_dqmap fixedly, and specify som_type for necessary 
        # voltage domain configuration and phy reset
        # som type: x3som | j3som | customer som
        case ${HR_SOM_TYPE} in
            x3som)
                som_type=1
                ;;
            j3som)
                som_type=2
                ;;
            x3sdb)
                som_type=3
                ;;
            *)
                if [[ ${HR_SOM_TYPE} =~ ^[0-9]+$ ]];then
                    som_type=${HR_SOM_TYPE}
                else
                    som_type=0
                fi
                ;;
        esac
        make KCFLAGS="-DROOTFS_TYPE=${HR_ROOTFS_FS_TYPE} -DHR_BASE_BOARD_TYPE=${1} -DHR_SOM_TYPE=${som_type}" -j${N} || {
            echo "make failed"
            exit 1
        }
    else
        # Compile and generate normal uboot.bin
        make KCFLAGS="-DROOTFS_TYPE=${HR_ROOTFS_FS_TYPE}" -j${N} || {
            echo "make failed"
            exit 1
        }
    fi


    cd ${HR_LOCAL_DIR}
    # Add uboot header
    bash pack_uboot_tool.sh || {
        echo "pack_uboot_tool.sh failed"
        exit 1
    }

    cd ${HR_LOCAL_DIR}
}

function build_clean()
{
    make clean
}

function build_distclean()
{
    make distclean
}

cd ${HR_TOP_DIR}/uboot

if [ $# -eq 0 ] || [ $# -eq 2 ] || [ "$1" = "all" ]; then
    if [ $# -eq 2 ]; then
        build_all $2
    else
        build_all
    fi
elif [ "$1" = "clean" ]; then
    build_clean
elif [ "$1" = "distclean" ]; then
    build_distclean
fi
