#!/bin/bash

####################################################
# This script is used to get each ddr parameters
# when add or change any paramters, use this scripts
# to compare each ddr parameter.
# ddr image spl_ddr_img.bin is genarated after compile
# usage: ./get-each-ddr.sh spl_ddr_img.bin
# then, each ddr parameter will be stored in the
# directory(storage_ddr_dir), which include ddr header
# (ddr_header.bin), dqmap and each ddr parameter
####################################################
STORAGE_DDR_DIR="storage_ddr_dir"
HEADER_SIZE=2560
MAGIC_OFFSET=0
COUNT_OFFSET=4
HEADER_DDR_OFFSET=40
EACH_DDR_HEADER_SIZE=104
DQ_MAP_OFFSET=2192

#get each ddr paramters
function get_ddr_par() {

    local ddr_para_count=$1
    for((i=0;i<ddr_para_count;i++));
    do
        ddr_type_offset=$(($HEADER_DDR_OFFSET + $EACH_DDR_HEADER_SIZE * $i))
        ddr_vendor_offset=$(($ddr_type_offset + 4))
        ddr_freq_offset=$(($ddr_type_offset + 8))
        ddr_partnumber_offset=$(($ddr_type_offset + 12))
        imem_addr_offset=$(($ddr_type_offset + 16))
        imem1_size_offset=$(($ddr_type_offset + 20))
        imem2_size_offset=$(($ddr_type_offset + 28))
        ddr_type=$(hexdump -n 4 -s $ddr_type_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        ddr_vendor=$(hexdump -n 4 -s $ddr_vendor_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        ddr_freq=$(hexdump -n 4 -s $ddr_freq_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        ddr_partnumber=$(hexdump -n 4 -s $ddr_partnumber_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        imem1_size="0x"$(hexdump -n 4 -s $imem1_size_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        imem2_size="0x"$(hexdump -n 4 -s $imem2_size_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        imem_addr="0x"$(hexdump -n 4 -s $imem_addr_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        echo "ddr index:$i ddr_vendor:$ddr_vendor ddr type:$ddr_type ddr freq:$ddr_freq ddr part number: $ddr_partnumber"
        each_ddr_name=vendor-$ddr_vendor-type-$ddr_type-freq-$ddr_freq-partnumber-$ddr_partnumber
        if [ -d $STORAGE_DDR_DIR/$each_ddr_name ]; then
            rm $STORAGE_DDR_DIR/$each_ddr_name -r
        fi
        mkdir $STORAGE_DDR_DIR/$each_ddr_name
        imem1_size=$(printf %d $imem1_size)
        imem2_size=$(printf %d $imem2_size)
        imem_addr=$(printf %d $imem_addr)
        imem_size=$(($imem1_size + $imem2_size))
        echo "dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/$each_ddr_name/imem.bin bs=1 count=$imem_size skip=$(($imem_addr + $HEADER_SIZE))"
        dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/$each_ddr_name/imem.bin bs=1 count=$imem_size skip=$(($imem_addr + $HEADER_SIZE))

        imem1_next_addr_offset=$(($ddr_type_offset + 16 + $EACH_DDR_HEADER_SIZE))
        imem1_next_addr="0x"$(hexdump -n 4 -s $imem1_next_addr_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        imem1_next_addr=$(printf %d $imem1_next_addr)

        dmem1_addr_offset=$(($ddr_type_offset + 32))
        dmem1_addr="0x"$(hexdump -n 4 -s $dmem1_addr_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        dmem1_addr=$(printf %d $dmem1_addr)
        if [ $i -eq $(($ddr_count - 1)) ]; then
            dmem1_next_addr_offset=$DQ_MAP_OFFSET
        elif [ $imem_addr -ne $imem1_next_addr ]; then
            dmem1_next_addr_offset=$imem1_next_addr_offset
        else
            dmem1_next_addr_offset=$(($ddr_type_offset + 32 + $EACH_DDR_HEADER_SIZE))
        fi
        dmem1_next_addr="0x"$(hexdump -n 4 -s $dmem1_next_addr_offset -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        dmem1_next_addr=$(printf %d $dmem1_next_addr)
        ddr_par_size=$(($dmem1_next_addr - $dmem1_addr))
        echo "dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/$each_ddr_name/parameter.bin bs=1 count=$ddr_par_size skip=$(($dmem1_addr + $HEADER_SIZE))"
        dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/$each_ddr_name/parameter.bin bs=1 count=$ddr_par_size skip=$(($dmem1_addr + $HEADER_SIZE))
done
}

#get dqmap parameters
function get_dqmap()
{
    for((i=0;i<16;i++));
    do
        dqmap_addr="0x"$(hexdump -n 4 -s $(($DQ_MAP_OFFSET +  $i * 4)) -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
        dqmap_addr=$(printf %d $dqmap_addr)
	if [ $dqmap_addr -ne 0 ]; then
            echo "dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/dqmap-$i.bin bs=1 count=512 skip=$(($dqmap_addr + $HEADER_SIZE))"
            dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/dqmap-$i.bin bs=1 count=512 skip=$(($dqmap_addr + $HEADER_SIZE))
	fi

    done

}
if [ $# -eq 0 ]; then
    echo "......usage......."
    echo "get-each-ddr.sh spl_ddr_img.bin"
    exit 1
fi
if [ -d $STORAGE_DDR_DIR ]; then
    rm $STORAGE_DDR_DIR -r
fi
    mkdir $STORAGE_DDR_DIR

STORAGE_DDR_IMAGE=$1
if [ ! -f $STORAGE_DDR_IMAGE ]; then
    echo "$STOREAGE_DDR_IMAGE is not exist"
fi

#header
dd if=$STORAGE_DDR_IMAGE of=$STORAGE_DDR_DIR/ddr_header.bin bs=512 count=5
magic_value=$(hexdump -n 4 -s $MAGIC_OFFSET -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
echo "magic value:$magic_value"
if [ $magic_value = "544f4248" ]; then
    echo "this is ddr image"
else
    echo "this is not ddr image"
fi

ddr_count="0x"$(hexdump -n 4 -s $COUNT_OFFSET -e '1/4 "%02x"' $STORAGE_DDR_IMAGE)
echo "ddr count is :$ddr_count"
ddr_count=$(printf %d $ddr_count)
echo "ddr count is :$ddr_count"

get_ddr_par $ddr_count
get_dqmap
