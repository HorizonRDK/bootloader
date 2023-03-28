#!/bin/bash

#set -x
set -e

function write_string()
{
    local offset=$1
    local size=$2
    local value=$3
    local i=${#value}
    while [ $i -lt $size ]; do
        value=${value}"\0"
        let i+=1
    done

    echo -n -e "$value" | dd of=${veeprom_bin} bs=1 seek=$offset bs=1 count=$size conv=notrunc,sync status=none
    [ $? ] || { echo "write initial value $value to veeprom Failed!!!"; exit 1; }
    echo "write initial value $3 to veeprom.bin done!"
}

function write_num()
{
    local offset=$1
    local size=$(( $2 * 2))
    local value=$(echo "obase=16; $3" | bc)
    local i=${#value}
    while [ $i -lt $size ]; do
        value="0"${value}
        let i+=1
    done

    for i in $(seq 0 2 $(($size - 1))); do
        echo -n -e "\\x${value:$i:2}" | dd of=${veeprom_bin} bs=1 seek=$offset count=1 conv=notrunc,sync status=none; offset=$offset
        let offset+=1
        [ $? ] || { echo "write initial value $value to veeprom Failed!!!"; exit 1; }
    done
    echo "write initial value 0x$value to veeprom.bin done!"
}

echo "******************************"
echo "**** Creating veeprom.bin ****"

gpt_conf=$1
veeprom_size=0
veeprom_bin=""

if [ "${BOOT_MODE}" = "nand" ];then
    veeprom_size=8
    veeprom_bin="${MINIBOOT_TARGET_DEPLOY_DIR}/veeprom.bin"
else
    for line in $(cat $gpt_conf); do
        arr=(${line//:/ })

        needparted=${arr[0]}
        _name=${arr[1]}
        dir=${_name%/*}
        name=${_name##*/}
        starts=${arr[3]}
        stops=${arr[4]}
        stop=${stops%?}
        start=${starts%?}
        if [ "$dir" = "veeprom" ]; then
            veeprom_size=$(( $stop - $start + 1))
            mkdir -p "${MINIBOOT_TARGET_DEPLOY_DIR}"
            veeprom_bin="${MINIBOOT_TARGET_DEPLOY_DIR}/${name}"
            break
        fi
    done
fi

[ -f "${veeprom_bin}" ] && { rm -rf ${veeprom_bin}; }

dd if=/dev/zero of=${veeprom_bin} bs=512 count=$veeprom_size conv=notrunc,sync status=none

# write default upmode
if [ "$HR_OTA_UPDATE_MODE" = "AB" ];then
    write_string 29 8 "AB"
elif [ "$HR_OTA_UPDATE_MODE" = "golden" ];then
    write_string 29 8 "golden"
else
    echo "HR_OTA_UPDATE_MODE setting error!"
    exit 1
fi

if [ "$HR_ROOTFS_TYPE" = "ubuntu" ];then
    write_string 137 4 "UBTU"
fi

# Initialize other default values
# reset_reason normal
write_string 9 8 "normal"

# countflag on
write_num 131 1 1

# reset_count 0
write_num 38 1 0

# upflage 13
write_num 8 1 13

# partstatus 0
write_num 37 1 0

# continue_up 0
write_num 136 1 0

if [ "${HR_COUNT_STORE_MODE}" = "pmu" ];then
# count 'E', store count value in pmu register
write_num 38 1 69
fi

echo "** Create veeprom.bin done! **"
echo "******************************"
