#!/bin/bash
###
 # COPYRIGHT NOTICE
 # Copyright 2023 Horizon Robotics, Inc.
 # All rights reserved.
 # @Date: 2023-01-30 11:27:41
 # @LastEditTime: 2023-03-28 20:17:52
### 

# set -x
set -e

######## setting utils_funcs ###################
source ./utils_funcs.sh

export HR_TOP_DIR=$(realpath $(cd $(dirname $0); pwd)/../)
export HR_LOCAL_DIR=$(realpath $(cd $(dirname $0); pwd))

# check board config
check_board_config ${@:1}

export IMAGE_DEPLOY_DIR=${HR_IMAGE_DEPLOY_DIR}
[ ! -z ${IMAGE_DEPLOY_DIR} ] && [ ! -d $IMAGE_DEPLOY_DIR ] && mkdir $IMAGE_DEPLOY_DIR

export MINIBOOT_SOURCE_DIR=${HR_TOP_DIR}/miniboot/
export MINIBOOT_TARGET_DEPLOY_DIR=${IMAGE_DEPLOY_DIR}/miniboot
export MINIBOOT_TARGET_IMAGE=${IMAGE_DEPLOY_DIR}/miniboot.img

export SRC_SCRIPTS_DIR=${HR_LOCAL_DIR}/miniboot_sub_scripts
# export MINIBOOT_TARGET=miniboot.img

# BL31
export SRC_BL31_DIR=${MINIBOOT_SOURCE_DIR}/boot/bl31
export BL31_IMAGE_NAME=bl31.img
export BL31_IMAGE_LOAD_ADDR="0"
# ddr
export DDR_IMAGE_NAME=ddr_storage.bin
export EFUSE_IMAGE_NAME=efuse.bin
export KEY_IMAGE_NAME=key_set.bin

# spl
export SRC_SPL_DIR=${MINIBOOT_SOURCE_DIR}/boot/spl
# secure
export SECURE_CHIP="true"
export UBOOT_SPL_NAME="spl_storage_secure.bin"
export UBOOT_WARM_SPL_NAME="spl_warm_storage_secure.bin"
export AVB_DM="avb_dm"
export VERITY_FLAG="true"

# CR5
export CR5_IMAGE_NAME=cr5.bin
export SRC_CR5_DIR=${MINIBOOT_SOURCE_DIR}/boot/cr5
export CR5_IMAGE_LOAD_ADDR="80006800"  #sram + 26K

export BOOT_MODE=$HR_BOOT_MODE
export PART_NUMBER=$HR_PACK_PART_NUMBER_IN_MINIBOOT
export CHIP_TYPE=$HR_CHIP_TYPE
export DDR_FREQ=$HR_DDR_FREQ
export MINIBOOT_UBOOT_SIZE=$HR_UBOOT_SIZE
export UBOOT_IMAGE_LOAD_ADDR=$HR_UBOOT_IMAGE_LOAD_ADDR

if [ "$BOOT_MODE" = "nand" ]; then
    export UBOOT_SPL_NAME_BAK1=$UBOOT_SPL_NAME
    export UBOOT_SPL_NAME_BAK2=$UBOOT_SPL_NAME
    export UBOOT_SPL_NAME_BAK3=$UBOOT_SPL_NAME
    export UBOOT_WARM_SPL_NAME_BAK1=$UBOOT_WARM_SPL_NAME
    export UBOOT_WARM_SPL_NAME_BAK2=$UBOOT_WARM_SPL_NAME
    export UBOOT_WARM_SPL_NAME_BAK3=$UBOOT_WARM_SPL_NAME
    export DDR_IMAGE_NAME_BAK1=$DDR_IMAGE_NAME
    export DDR_IMAGE_NAME_BAK2=$DDR_IMAGE_NAME
    export DDR_IMAGE_NAME_BAK3=$DDR_IMAGE_NAME
    export BL31_IMAGE_NAME_BAK=$BL31_IMAGE_NAME
fi

# board id 
board_id=0

#########BOARD ID CONFIG#####
som_type=${HR_SOM_TYPE}
base_board_type=${HR_BASE_BOARD_TYPE}
ddr_freq=${HR_DDR_FREQ}
ddr_manufacture=${HR_DDR_MANUFACTURE}
ddr_type=${HR_DDR_TYPR}
ddr_capacity=${HR_DDR_CAPACITY}
ddr_alternative=${HR_DDR_ALTERNATIVE}
############################
MINIBOOT_COMPILE_VERSION=0.3
ddr_freq_arr=("667" "1600" "2133" "2666" "3200" "3600" "3733" "4266")
ddr_mfg_name_arr=("hynix" "micron" "samsung" "ddrphy_phyinit")
ddr_type_arr=("LPDDR4" "LPDDR4X" "DDR4" "DDR3L")
ddr_capacity_arr=("1" "2" "4")
#board_type_arr=("xj3" "cvb" "x3dvb" "j3dvb" "x3sdb" "customer" "fpga")
image_with_efuse="true"
######################################

# pack cr5 binary to warm spl,
# warm spl occupy 26K
# $1 warm spl
# $2 cr5 binary
# $3 warmspl + cr5 output path
MAX_WARMSPL_SIZE=26624  #26K
MX_CR5_SIZE=16384 #16K
function pack_cr5_warmspl()
{
    local warm_spl_file=$1
    local cr5_file=$2
    local warm_cr5_size=0
    local image_align=512

    if [ ! -f $warm_spl_file ] || [ ! -f $cr5_file ]; then
        echo "warm spl or cr5 binary is not exist"
        exit 1
    fi
    local warmspl_size=$(wc -c < $warm_spl_file)
    if [ $warmspl_size -gt $MAX_WARMSPL_SIZE ]; then
        echo "$warmspl_size is greater than warmspl max size($MAX_WARMSPL_SIZE)"
        exit 1
    fi
    local cr5_size=$(wc -c < $cr5_file)
    if [ $cr5_size -gt $MX_CR5_SIZE ]; then
        echo "$cr5_size is greater than cr5 max size($MX_CR5_SIZE)"
        exit 1
    fi
    dd if=/dev/zero of=$3 bs=1 count=$MAX_WARMSPL_SIZE  status=none
    dd if=$warm_spl_file of=$3 bs=1 count=$warmspl_size conv=notrunc status=none
    path="$SRC_SCRIPTS_DIR/image_pack"
    cd $path
    bash pack_cr5_tool.sh || {
        echo "$SRC_SCRIPTS_DIR/image_pack/pack_cr5_tool.sh failed"
        exit 1
    }
    cd -
    cat ${MINIBOOT_TARGET_DEPLOY_DIR}/cr5/$CR5_IMAGE_NAME >> $3
    warm_cr5_size=$(wc -c < $3)
    mod=$(($image_align-$((($warm_cr5_size%$image_align)))))
    if [ "$mod" -eq "$image_align" ]; then
        img_size_align=$warm_cr5_size
    else
        img_size_align=$(($warm_cr5_size + $mod))
    fi
    dd if=/dev/zero of=$3.pad bs=1 count=$img_size_align           status=none
    dd if=$3 of=$3.pad bs=1 count=$img_size_align conv=notrunc     status=none
    mv $3.pad $3

}

function gen_warmspl()
{
        warm_spl_tool="${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-warm-spl.sh"
        warm_spl_out=$MINIBOOT_TARGET_DEPLOY_DIR
        # bash $warm_spl_tool $SRC_SPL_DIR/spl_warm_storage.bin $warm_spl_out/spl_warm_storage_header.bin
        # pack_cr5_warmspl $warm_spl_out/spl_warm_storage_header.bin $SRC_CR5_DIR/cr5.bin $warm_spl_out/spl_warm_storage.bin
#rm $warm_spl_out/spl_warm_storage_header.bin
        bash $warm_spl_tool $SRC_SPL_DIR/spl_warm_storage_secure.bin $warm_spl_out/spl_warm_storage_secure_header.bin
        pack_cr5_warmspl $warm_spl_out/spl_warm_storage_secure_header.bin $SRC_CR5_DIR/cr5.bin $warm_spl_out/spl_warm_storage_secure.bin
#        rm $warm_spl_out/spl_warm_storage_secure_header.bin
}

function gen_miniboot_size_emmc()
{
    miniboot_size=0
    cur_part_nr=1
    for line in $(cat $gpt_config)
    do
        arr=(${line//:/ })
        local needparted=${arr[0]}

        if [ "$needparted" = "1" ];then
            if [ $cur_part_nr -lt $PART_NUMBER ]; then
                cur_part_nr=$((${cur_part_nr} + 1))
                continue
            fi

            local stops=${arr[4]}
            local stopsize=$(trans_unit $stops)
            miniboot_size=$((${stopsize} + 1))
            break
        fi
    done
    unset line

    if [ "$miniboot_size" = "0" ];then
        echo "get miniboot size failed"
        exit 1
    fi
}

function miniboot_check() {
    local lastsize=0
    local i=0
    for line in $(cat $gpt_config)
    do
        arr=(${line//:/ })
        let i=i+1

        local needparted=${arr[0]}
        local _name=${arr[1]}
        local dir=${_name%/*}
        local name=${_name##*/}
        local fs=${arr[2]}
        local starts=${arr[3]}
        local stops=${arr[4]}

        if [ "$needparted" = "0" ];then
            if [ "$fs" != "none" ];then
                echo "Error: \"$line\" filesystem is not supported"
                exit 1
            fi
            continue
        fi
        local startsize=$(trans_unit $starts)
        if [ $i -ne 1 ];then
            if [ $(($startsize)) -le $(($lastsize)) ];then
                echo "$config:line[$i], $(($startsize)) is less or equal than $(($lastsize))"
                exit 1
            fi
        fi
        local lastsize=$(trans_unit $stops)
    done
    unset line
    # add gpt_backup table
    let size=$lastsize+34
}

# Restore variable values in the partition table
function eval_gpt_conf()
{
    orig_conf="$1"
    eval_conf="$2"

    for line in $(cat $orig_conf)
    do
        eval echo "$line" >> $eval_conf
    done
    echo "GPT config:"
    cat $eval_conf
    echo "####################################"
    unset line
}

function miniboot_fill_partition()
{
    local basep
    local part_name
    local part_now=0
    local config="$1"
    for line in $(cat $config)
    do
        arr=(${line//:/ })

        local needparted=${arr[0]}
        local _name=${arr[1]}
        local dir=${_name%/*}
        local name=${_name##*/}
        local fs=${arr[2]}
        local starts=${arr[3]}
        local stops=${arr[4]}
        local stop=${stops%?}
        local start=${starts%?}

        part_now=`expr $part_now + $needparted`
        if [ $part_now -gt $PART_NUMBER ];then
            return 0
        fi

        if [ -f $prefixdir/$name ];then
            runcmd "dd if=$prefixdir/$name of=$MINIBOOT_TARGET_IMAGE seek=$start conv=notrunc,sync status=none"
        else
            echo "Error: no $prefixdir/$name found"
            exit -1
        fi
    done
    unset line
}

function build_miniboot_image()
{
    local size=0
    local fstype=""
    local prefixdir=${MINIBOOT_TARGET_DEPLOY_DIR}
    local orig_gpt_conf="$1"

    gpt_config=${MINIBOOT_TARGET_DEPLOY_DIR}/${HR_GPT_CONF_FILENAME}
    eval_gpt_conf ${orig_gpt_conf} ${gpt_config}
    miniboot_check
    echo "miniboot size is ${size} sector"

    echo "MINIBOOT_TARGET: ${MINIBOOT_TARGET_IMAGE}"
    rm -rf ${MINIBOOT_TARGET_IMAGE}
    mkdir -p $(dirname ${MINIBOOT_TARGET_IMAGE})

    # Get the end block position of the miniboot partition, and generate a miniboot.img with all '0',
    # and then fill the image of each partition into this miniboot.img
    gen_miniboot_size_emmc
    echo "miniboot_size is $miniboot_size sector"
    if [ "$BOOT_MODE" = "nand" ];then
        dd if=/dev/zero ibs=512  count=${miniboot_size} status=none | tr "\000" "\377" >${MINIBOOT_TARGET_IMAGE}
    else
        runcmd "dd if=/dev/zero of=${MINIBOOT_TARGET_IMAGE} bs=512 count=${miniboot_size}"
    fi

    # Fill the gpt partition first
    if [ "$BOOT_MODE" = "emmc" ];then
        main_img=${MINIBOOT_TARGET_DEPLOY_DIR}/gpt_main.img
        backup_img=${MINIBOOT_TARGET_DEPLOY_DIR}/gpt_backup.img
        runcmd "${SRC_SCRIPTS_DIR}/gen_gpt.py $gpt_config $main_img $backup_img"
        runcmd "dd if=$main_img of=${MINIBOOT_TARGET_IMAGE} bs=512 conv=notrunc,sync status=none"
    fi

    # Then use mbr to overwrite the first 512 bytes of miniboot.img
    # mbr
    destname=${MINIBOOT_TARGET_DEPLOY_DIR}/mbr.bin
    #runcmd "${SRC_SCRIPTS_DIR}/gen_miniboot_mbr.py $GPT_CONFIG $destname"
    runcmd "${SRC_SCRIPTS_DIR}/gen_miniboot_mbr.py $orig_gpt_conf $destname"
    if [ "$BOOT_MODE" = "emmc" ];then
        # Let gpt contain mbr
        runcmd "dd if=$destname of=$main_img bs=512 conv=notrunc,sync status=none"
        runcmd "dd if=$destname of=${MINIBOOT_TARGET_IMAGE} bs=512 conv=notrunc,sync status=none"
    elif [ "$BOOT_MODE" = "nor" ];then
        runcmd "dd if=$destname of=${MINIBOOT_TARGET_IMAGE} bs=512 seek=128 conv=notrunc,sync status=none"
    elif [ "$BOOT_MODE" = "nand" ];then
        runcmd "dd if=$destname of=${MINIBOOT_TARGET_IMAGE} bs=512 conv=notrunc,sync status=none"
    else
        :
    fi

    # Finally, fill in the spl, ddr, bl31, efuse, etc. contained in the miniboot
    if ! miniboot_fill_partition ${gpt_config} ;then
        exit 1
    fi
}

# calculate board_id
# ddr manufacture: hynix | micron
index=0
case $ddr_manufacture in
    hynix)
        index=1
        ;;
    micron)
        index=2
        ;;
    samsung)
        index=3
        ;;
    *)
        index=0
        ;;
esac
board_id=$(($board_id | ($index << 28)))

# ddr type: LPDDR4 | LPDDR4X | DDR4 | DDR3L
case $ddr_type in
    LPDDR4)
        index=1
        ;;
    LPDDR4X)
        index=2
        ;;
    DDR4)
        index=3
        ;;
    DDR3L)
        index=4
        ;;
    *)
        index=0
        ;;
esac
board_id=$(($board_id | ($index << 24)))

# ddr frequency: 667 | 1600 | 2133 | 2666 | 3200 | 3733 | 4266
case $ddr_freq in
    667)
        index=1
        ;;
    1600)
        index=2
        ;;
    2133)
        index=3
        ;;
    2666)
        index=4
        ;;
    3200)
        index=5
        ;;
    3733)
        index=6
        ;;
    4266)
        index=7
        ;;
    1866)
        index=8
        ;;
    2400)
        index=9
        ;;
    100)
        index=10
        ;;
    3600)
        index=11
        ;;
    *)
        index=0
        ;;
esac
board_id=$(($board_id | ($index << 20)))

# ddr capacity: 1G | 2G | 4G
case $ddr_capacity in
    1)
        index=1
        ;;
    2)
        index=2
        ;;
    4)
        index=4
        ;;
    *)
        index=0
        ;;
esac
board_id=$(($board_id | ($index << 16)))

# som type: x3som | j3som | customer som
case $som_type in
    x3som)
        index=1
        ;;
    j3som)
        index=2
        ;;
    x3sdb)
        index=3
        ;;
    *)
        if [[ $som_type =~ ^[0-9]+$ ]];then
            index=$som_type
        else
            index=0
        fi
        ;;
esac
board_id=$(($board_id | ($index << 8)))

# base board type: x3dvb | j3dvb | cvb | customer board
case $base_board_type in
    x3dvb)
        index=1
        ;;
    j3dvb)
        index=2
        ;;
    cvb)
        index=3
        ;;
    x3sdb)
        index=4
        ;;
    customer)
        index=5
        ;;
    *)
        index=0
        ;;
esac

board_id=$(($board_id | $index))
if [ ${HR_DDR_DFS} ];then
    board_id=$(($board_id | (${HR_DDR_DFS} << 7)))
fi
board_id=$(($board_id | ($ddr_alternative << 4)))
board_id=$(echo "obase=16;$board_id"|bc)
echo "VERSION:$MINIBOOT_COMPILE_VERSION"
echo $board_id

export BOARD_ID=$board_id

echo ${MINIBOOT_SOURCE_DIR}
if [ -d $MINIBOOT_TARGET_DEPLOY_DIR ]; then
    rm -rf $MINIBOOT_TARGET_DEPLOY_DIR
fi
#1. make ddr image
path=${MINIBOOT_SOURCE_DIR}/ddr
#1.1 make ddr storage.bin
cd $path
bash mk_ddr_bin.sh -o storage || {
        echo "./build/ddr/mk_ddr_bin.sh failed"
        exit 1
}
if [ -d $path/boot/ddr ]; then
    rm -rf $path/boot/ddr
fi
mkdir -p $MINIBOOT_TARGET_DEPLOY_DIR
#1.2 make efuse bin
if [ x$image_with_efuse = x"true" ];then
    python2 ./efuse/pack_efuse_outside.py || {
        echo "$path/efuse/pack_efuse.py failed"
        exit 1
    }
fi
cd -
#copy
if [ -d "$path" ];then
    cp -rf $path/spl_ddr_img.bin $path/$DDR_IMAGE_NAME
        if [ "$HR_BOOT_MODE" = "nand" ]; then
            cpfiles "$path/$DDR_IMAGE_NAME" "${MINIBOOT_TARGET_DEPLOY_DIR}/"
        else
                cpfiles "$path/$DDR_IMAGE_NAME" "${MINIBOOT_TARGET_DEPLOY_DIR}/"
        fi
fi
if [ x$image_with_efuse = x"true" ];then
    path="$SRC_SCRIPTS_DIR/image_pack"
    cd $path
    bash pack_efuse_tool.sh -b -i ${HR_KEY_MANAGEMENT_TOOLKITS_PATH}/fallback_key_sets || {
        echo "$SRC_SCRIPTS_DIR/image_pack/pack_efuse_tool.sh failed"
        exit 1
    }
    cd -
    cp ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/$EFUSE_IMAGE_NAME ${MINIBOOT_TARGET_DEPLOY_DIR}/$EFUSE_IMAGE_NAME
fi
path="$SRC_SCRIPTS_DIR/image_pack"
cd $path
bash pack_keyset_tool.sh || {
    echo "$SRC_SCRIPTS_DIR/image_pack/pack_keyset_tool.sh failed"
        exit 1
}
cd -

#2. pack bl31.img
cp $SRC_BL31_DIR/bl31.bin  ${MINIBOOT_TARGET_DEPLOY_DIR}/$BL31_IMAGE_NAME

cp ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/$KEY_IMAGE_NAME ${MINIBOOT_TARGET_DEPLOY_DIR}/$KEY_IMAGE_NAME
#2. generate mbr
#3. generage gpt
cpfiles "$SRC_SPL_DIR/*" "$MINIBOOT_TARGET_DEPLOY_DIR/"
#4. pack warm spl
gen_warmspl

#generate veeprom.bin
bash $SRC_SCRIPTS_DIR/gen_veeprom.sh $HR_GPT_CONF_DIR/$HR_GPT_CONF_FILENAME || {
    echo "$SRC_SCRIPTS_DIR/gen_veeprom.sh $HR_GPT_CONF_DIR/$HR_GPT_CONF_FILENAME failed"
    exit 1
}

# generate ubootenv
if [ "$HR_BOOT_MODE" = "nand" ]; then
    ${SRC_SCRIPTS_DIR}/gen_flash_img.sh -c $HR_GPT_CONF_DIR/$HR_GPT_CONF_FILENAME || {
        echo "generate $HR_BOOT_MODE image failed!"
        exit 1
    }
fi

#5. build uart boot pkg
miniboot_images_deploy_path=${IMAGE_DEPLOY_DIR}/factory_images
rm -rf ${miniboot_images_deploy_path}
mkdir -p ${miniboot_images_deploy_path}
cp ${MINIBOOT_TARGET_DEPLOY_DIR}/${UBOOT_SPL_NAME} ${miniboot_images_deploy_path}
cp ${MINIBOOT_TARGET_DEPLOY_DIR}/${BL31_IMAGE_NAME} ${miniboot_images_deploy_path}
cp ${MINIBOOT_TARGET_DEPLOY_DIR}/${UBOOT_WARM_SPL_NAME} ${miniboot_images_deploy_path}
cp ${MINIBOOT_TARGET_DEPLOY_DIR}/key_set.bin ${miniboot_images_deploy_path}
cp ${MINIBOOT_TARGET_DEPLOY_DIR}/ddr/efuse_hash_data ${miniboot_images_deploy_path}

#7. build uart mode ddr_xxx.bin
case $base_board_type in
    x3dvb)
        ddr_dqmap="dvb"
        ;;
    j3dvb)
        ddr_dqmap="dvb"
        ;;
    cvb)
        ddr_dqmap="cvb"
        ;;
    x3sdb)
        ddr_dqmap="sdb"
        ;;
esac

path=${MINIBOOT_SOURCE_DIR}/ddr
#1.1 make ddr storage.bin
cd $path
bash mk_ddr_bin.sh -b ${ddr_dqmap} || {
        echo "./build/ddr/mk_ddr_bin.sh failed"
        exit 1
}
if [ -d $path/uart_ddr_img ]; then
    mv $path/uart_ddr_img ${miniboot_images_deploy_path}
fi

echo "${HR_GPT_CONF_DIR}/${HR_GPT_CONF_FILENAME}"
build_miniboot_image ${HR_GPT_CONF_DIR}/${HR_GPT_CONF_FILENAME}

echo
echo "Create ${MINIBOOT_TARGET_IMAGE} Success"
echo

#6. deploy
cp $HR_GPT_CONF_DIR/$HR_GPT_CONF_FILENAME ${IMAGE_DEPLOY_DIR}

rm -rf $SRC_SCRIPTS_DIR/image_pack/out $SRC_SCRIPTS_DIR/image_pack/efuse-origin.bin
rm -rf $MINIBOOT_TARGET_DEPLOY_DIR
