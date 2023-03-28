#!/usr/bin/python3
import json
import logging
import sys
import struct
import os
import argparse

HBM_WITH_SIG_ALIGN=65536
INST_SZ_ALIGN=65536
PAR_SZ_ALIGN=65536
HBM_ALIGN=64
HBM_CNT=0
EACH_HBM_HEADER_SZ=140
MAX_HBM_COUNT=4
BPU_IMG_HEADER_SZ=576
HBM_NAME_MAX_SIZE=100
#BPU_LOAD_ADDR=0x0
BPU_LOAD_ADDR_START=0x0
PAR_LOAD_ADDR=0
ALL_JSON_INST_SZ=0
ALL_HBM_SIZE=0
IMAGE_LEN=0
BPU_RANGE_SZ=0
#SIG_FLAG="0000"

def pad_image(file_name, pad_size):
    print("[%s %s,line:%s]" % (__file__, sys._getframe().f_code.co_name,sys._getframe().f_lineno) )
    zero_char = struct.pack('b', 0)
    ori_size = os.path.getsize(file_name)
    mod_size = ori_size % pad_size
    ori_file = open(file_name, 'rb')
    pad_file = open(file_name+'.pad', 'wb+')
    ori_str = ori_file.read(-1);
    pad_file.write(ori_str)
    if (mod_size == 0):
        return 
    tmp = pad_size - mod_size

    for i in range(tmp):
        pad_file.write(zero_char)
    ori_file.close()
    pad_file.close()


#get json instruct size
def get_all_inst_size(json_file):
    global ALL_JSON_INST_SZ
    with open(json_file, 'r') as f:
        json_data = json.load(f)
    inst_size = json_data["inst"]["Bpu_inst_size"]
    print("instuct size: ", inst_size)
    if ((inst_size % INST_SZ_ALIGN) > 0):
        print("instruct size should 0x10000 algin")
    ALL_JSON_INST_SZ = ALL_JSON_INST_SZ + inst_size


#pack hbm by json
def pack_hbm(json_file):
    global HBM_CNT
    global ALL_HBM_SIZE
    global BPU_LOAD_ADDR
    global IMAGE_LEN
    global BPU_RANGE_SZ
    global PAR_LOAD_ADDR
    global hbm_cnt
    with open(json_file, 'r') as f:
        json_data = json.load(f)
    if json_data["summary"]["file_name"] != "":
        hbm_file = json_data["summary"]["file_name"]
        print("hbm file name: ", hbm_file)
        pad_image(hbm_file, HBM_WITH_SIG_ALIGN)

        #cat hbm to bpu_data.bin
        hbm_pad = open(hbm_file + ".pad", 'rb')
        bpu_data = open("./bpu_data.bin", 'ab+')
        ori_str = hbm_pad.read(-1);
        bpu_data.write(ori_str)
        bpu_data.close()
        hbm_pad.close()

        bpu_img = open("./bpu_image.bin", 'r+')
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ, 0)
        print(bpu_img.tell())
        bpu_img.write(hbm_file)
        print(json_data["summary"]["file_name"])
        
        hbm_size = json_data["summary"]["file_size"]
        tmp = hbm_size % HBM_ALIGN
        if ((tmp % HBM_ALIGN) > 0):
            print("hbm size should 64 bytes algin")
            return
        tmp_hex = struct.pack('I', hbm_size)
        print(hbm_size)
        #get hbm with signature size
        hbm_with_sig_sz = os.path.getsize(hbm_file+'.pad')
        print("real hbm size:", hbm_with_sig_sz)
        bpu_img.close()
        bpu_img = open("./bpu_image.bin", 'rb+')
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE, 0)
        bpu_img.write(tmp_hex)

        #instruct offset
        inst_offset_str = json_data["inst"]["Bpu_inst_offset"]
        inst_offset = int(inst_offset_str, 16)
        print("instuct offset: ", inst_offset)
        if ((inst_offset % INST_SZ_ALIGN) > 0):
            print("instruct offset should 0x10000 algin")
        inst_offset_hex = struct.pack('I', inst_offset)
        #bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 4, 0)
        #bpu_img.write(inst_offset_hex)
        
        #instruct load address
        inst_load_addr_hex = struct.pack('I', BPU_LOAD_ADDR)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 4, 0)
        bpu_img.write(inst_load_addr_hex)

        #instruct size
        inst_size = json_data["inst"]["Bpu_inst_size"]
        print("instuct size: ", inst_size)
        if ((inst_size % INST_SZ_ALIGN) > 0):
            print("instruct size should 0x10000 algin")
        inst_size_hex = struct.pack('I', inst_size)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 8, 0)
        bpu_img.write(inst_size_hex)
        
        #parameter load address
        par_load_addr_hex = struct.pack('I', PAR_LOAD_ADDR)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 12, 0)
        bpu_img.write(par_load_addr_hex)

        #parameter load size
        par_size = json_data["param"]["Bpu_param_size"]
        print("parameter size: ", par_size)
        if ((par_size % INST_SZ_ALIGN) > 0):
            print("paramter size should 0x10000 algin")
        par_size_hex = struct.pack('I', par_size)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 16, 0)
        bpu_img.write(par_size_hex)
        
        #parameter offset
        par_offset_str = json_data["param"]["Bpu_param_offset"]
        par_offset = int(par_offset_str, 16)
        print("paramter offset: ", par_offset)
        if ((inst_offset % INST_SZ_ALIGN) > 0):
            print("parameter offset should 0x10000 algin")
        
        #calculate this hbm instruct offset in whole bpu image data,
        #do not include bpu image header
        inst_offset_in_image = ALL_HBM_SIZE + inst_offset
        inst_offset_in_image_hex = struct.pack("I", inst_offset_in_image)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 20, 0)
        bpu_img.write(inst_offset_in_image_hex)

        #calculate this hbm parameter offset in whole bpu image data,
        #do not include bpu image header
        par_offset_in_image = ALL_HBM_SIZE + par_offset
        par_offset_in_image_hex = struct.pack("I", par_offset_in_image)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 24, 0)
        bpu_img.write(par_offset_in_image_hex)

        #calculate this hbm signature offset in whole bpu image data,
        #do not include bpu image header
        sig_offset_in_image = ALL_HBM_SIZE + hbm_size
        sig_offset_in_image_hex = struct.pack("I", sig_offset_in_image)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 28, 0)
        bpu_img.write(sig_offset_in_image_hex)

        #calculate this hbm offset in whole bpu image data,
        #do not include bpu image header
        hbm_offset_in_image_hex = struct.pack("I", ALL_HBM_SIZE)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 32, 0)
        bpu_img.write(hbm_offset_in_image_hex)
        ALL_HBM_SIZE = ALL_HBM_SIZE + hbm_with_sig_sz

        #signature flag
        sig_flag_hex = struct.pack("I", SIG_FLAG[HBM_CNT])
        #sig_flag_hex = struct.pack("I", 0)
        bpu_img.seek(HBM_CNT * EACH_HBM_HEADER_SZ + HBM_NAME_MAX_SIZE + 36, 0)
        bpu_img.write(sig_flag_hex)

        BPU_LOAD_ADDR = BPU_LOAD_ADDR + inst_size
        PAR_LOAD_ADDR = PAR_LOAD_ADDR + par_size
        BPU_RANGE_SZ = BPU_RANGE_SZ + inst_size + par_size
        IMAGE_LEN = IMAGE_LEN + hbm_with_sig_sz
        HBM_CNT = HBM_CNT + 1
        bpu_img.close()
        #os.remove(hbm_file + '.pad')
    else:
        print("name is null")
    print("[%s %s,line:%s]" % (__file__, sys._getframe().f_code.co_name,sys._getframe().f_lineno))


def pack_mul_hbm(all_json):
    global PAR_LOAD_ADDR
    global BPU_LOAD_ADDR
    global ALL_JSON_INST_SZ
    global IMAGE_LEN
    
    if (os.path.exists("bpu_image.bin") == "true") :
        os.remove("./bpu_image.bin")
    zero_char = struct.pack('b', 0)
    bpu_img = open("./bpu_image.bin", 'wb+')
    for i in range(BPU_IMG_HEADER_SZ):
        bpu_img.write(zero_char)
    bpu_img.close()
    for name in all_json:
        print("json name:", name)
        get_all_inst_size(name)
    PAR_LOAD_ADDR = BPU_LOAD_ADDR + ALL_JSON_INST_SZ
    BPU_LOAD_ADDR_START = BPU_LOAD_ADDR
    for name in all_json:
        pack_hbm(name)

    #write image len
    bpu_img = open("./bpu_image.bin", 'rb+')
    image_len_hex = struct.pack("I", IMAGE_LEN)
    bpu_img.seek(MAX_HBM_COUNT * EACH_HBM_HEADER_SZ, 0)
    bpu_img.write(image_len_hex)

    #write bpu range start
    bpu_load_start_hex = struct.pack("I", BPU_LOAD_ADDR_START)
    bpu_img.seek(MAX_HBM_COUNT * EACH_HBM_HEADER_SZ + 4, 0)
    bpu_img.write(bpu_load_start_hex)

    #write bpu range size
    bpu_range_hex = struct.pack("I", BPU_RANGE_SZ)
    bpu_img.seek(MAX_HBM_COUNT * EACH_HBM_HEADER_SZ + 8, 0)
    bpu_img.write(bpu_range_hex)

    #write bpu image instruct size
    all_inst_hex = struct.pack("I", ALL_JSON_INST_SZ)
    bpu_img.seek(MAX_HBM_COUNT * EACH_HBM_HEADER_SZ + 12, 0)
    bpu_img.write(all_inst_hex)
    bpu_data = open("./bpu_data.bin", 'rb')

    ori_str = bpu_data.read(-1);
    bpu_img.write(ori_str)
    bpu_data.close()
    bpu_img.close()
    os.remove("./bpu_data.bin")

if __name__ == '__main__':
    global SIG_FLAG
    global BPU_LOAD_ADDR
    parser = argparse.ArgumentParser()
    parser.add_argument('-j', required=True,default=False,type=str, help='input json file name,')
    parser.add_argument('-s', required=True,type=str, default=['0', '0', '0', '0'], help='signature flag,0--horizon signature, 1--customer')
    parser.add_argument('-a', required=True,type=str, help='bpu hbm load start address')
    args = parser.parse_args()
    all_json_str = args.j.split(',')
    sig_cnt=0
    SIG_FLAG=args.s.split(',')
    for s in SIG_FLAG:
        if (SIG_FLAG[sig_cnt]=='0') :
            SIG_FLAG[sig_cnt] = 0
        elif (SIG_FLAG[sig_cnt] == '1'):
            SIG_FLAG[sig_cnt] = 1
        else:
            print("signature flag is 0 or 1")
        sig_cnt=sig_cnt+1
    #print(SIG_FLAG)
    for s in range(4):
        SIG_FLAG.append(0)
    #print(SIG_FLAG)
    #print(args.a)
    BPU_LOAD_ADDR=int(args.a, 16);
    print("bpu hbm load addr: 0x%x" %(BPU_LOAD_ADDR))
    pack_mul_hbm(all_json_str)

