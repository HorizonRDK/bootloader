#!/usr/bin/env python2
import json
import os
import struct
import sys
import traceback

from collections import OrderedDict

# [<item name>, <addr 512info location>,
#  <pattern in gpt.conf>, <size 512info location>]
# mbrParts covers emmc and nor images
mbrParts = [
    ["cold_spl", 4, "miniboot/${UBOOT_SPL_NAME}", 8],
    ["ddr_param", 11, "miniboot/${DDR_IMAGE_NAME}", 15],
    ["warm_spl", 42, "miniboot/${UBOOT_WARM_SPL_NAME}", 43],
    ["bl31", 64, "miniboot/${BL31_IMAGE_NAME}", 67],
    ["uboot", 33, "uboot/${UBOOT_IMAGE_NAME}", -34],
    ["ubootbak", 36, "uboot/${UBOOT_IMAGE_NAME}", -37],
    ["uboot", 33, "uboot1/uboot.img", -34],
    ["ubootbak", 36, "uboot2/uboot.img", -37],
    ["uboot", 33, "uboot/uboot.img", -34],
    ["ubootbak", 36, "uboot_b/uboot.img", -37],
    ["ubootbak", 36, "ubootbak/uboot.img", -37]
]

# mbrNandParts Covers nand images
mbrNandParts = [
    ["cold_spl", 4, "miniboot/${UBOOT_SPL_NAME}", 8],
    ["cold_splbak1", 5, "miniboot/${UBOOT_SPL_NAME_BAK1}", -8],
    ["cold_splbak2", 6, "miniboot/${UBOOT_SPL_NAME_BAK2}", -8],
    ["cold_splbak3", 7, "miniboot/${UBOOT_SPL_NAME_BAK3}", -8],
    ["ddr_param", 11, "miniboot/${DDR_IMAGE_NAME}", 15],
    ["ddr_parambak1", 12, "miniboot/${DDR_IMAGE_NAME_BAK1}", 16],
    ["ddr_parambak2", 13, "miniboot/${DDR_IMAGE_NAME_BAK2}", 17],
    ["ddr_parambak3", 14, "miniboot/${DDR_IMAGE_NAME_BAK3}", 18],
    ["uboot", 33, "miniboot/${UBOOT_IMAGE_NAME}", 34],
    ["ubootbak", 36, "miniboot/${UBOOT_IMAGE_NAME_BAK}", 37],
    ["warm_spl", 42, "miniboot/${UBOOT_WARM_SPL_NAME}", 43],
    # ["warm_splbak1", 42, "miniboot/${UBOOT_WARM_SPL_NAME_BAK1}", 43],
    # ["warm_splbak2", 42, "miniboot/${UBOOT_WARM_SPL_NAME_BAK2}", 43],
    # ["warm_splbak3", 42, "miniboot/${UBOOT_WARM_SPL_NAME_BAK3}", 43],
    ["bpu_devid", 49, "miniboot/bpu", -52],
    ["bpu_rsakey", 54, "miniboot/bpu", -57],
    ["bpu_img", 59, "miniboot/bpu", -62],
    ["bl31", 64, "miniboot/${BL31_IMAGE_NAME}", 67],
    ["bl31", 64, "miniboot/${BL31_IMAGE_NAME_BAK}", 67],
    ["uboot", 33, "uboot/${UBOOT_IMAGE_NAME}", -34],
    ["ubootbak", 36, "uboot/${UBOOT_IMAGE_NAME}", -37],
    ["uboot", 33, "uboot1/uboot.img", -34],
    ["ubootbak", 36, "uboot2/uboot.img", -37],
    ["uboot", 33, "uboot/uboot.img", -34],
    ["ubootbak", 36, "uboot_b/uboot.img", -37],
    ["ubootbak", 36, "ubootbak/uboot.img", -37]
]


def resolveJson(path):
    file = open(path, "rb")
    fileJson = json.load(file, object_pairs_hook=OrderedDict)
    tmp_list = list(fileJson.values())
    return tmp_list


def bootInfoOutput():
    result = resolveJson(dtb_header_path)
    i = 0
    for i in range(len(result)):
        result[i] = int(result[i], 16)

    return result


def bootloaderInfoOutput():
    result = resolveJson(dtb_file_out_path)
    return result


def getFileSize(filePath):
    fsize = os.path.getsize(filePath)
    return fsize


def addCheckSum(filename):
    file_object = open(filename, 'rb')
    file_content = file_object.read()
    file_object.close()

    sum = 0
    for c in file_content:
        if isinstance(c, int):
            sum += c
        else:
            sum += ord(c)
    return sum


def trans_unit(size):
    unit = size[-1]
    num = int(size[:-1])
    if unit.lower() == 's':
        return num * 512
    else:
        if unit.lower() == 'k':
            return num * 1024
        elif unit.lower() == 'm':
            return num * 1024 * 1024
        elif unit.lower() == 'g':
            return num * 1024 * 1024 * 1024
        else:
            return int(size)


def processConf(imageConf):
    # dictionary stores: { key   <= partition name :
    #                      value <= [partition_offset, partition_size] }
    conf = open(imageConf, 'r')
    lines = conf.readlines()
    partDict = dict()
    prevOffset = -1
    for line in lines:
        segs = line.split(':')
        curPart = segs[1]
        if len(segs) == 6:
            curOffset = int(segs[3][:-1]) * 512
            if prevOffset >= 0:
                prevSize = curOffset - prevOffset
                partDict.update({prevPart: [prevOffset, prevSize]})
        else:
            if prevOffset >= 0:
                curOffset = prevOffset + prevSize
                partDict.update({prevPart: [prevOffset, prevSize]})
            else:
                if bootmode == 'emmc':
                    curOffset = 34 * 512
                else:
                    curOffset = 0
            prevSize = trans_unit(segs[3])

        prevOffset = curOffset
        prevPart = curPart

    # handle last line
    if len(segs) == 6:
        lastEnd = int(segs[4][:-1]) * 512
    else:
        lastEnd = prevOffset
    partDict.update({curPart: [curOffset, lastEnd - curOffset]})
    return partDict


def create_mbr(boardid, imageConf):
    bootmode = os.getenv('BOOT_MODE')
    print("bootmode: " + bootmode)
    update_mode = os.getenv('HR_OTA_UPDATE_MODE')
    build_type = os.getenv('TARGET_PROJECT')
    prefixdir = os.getenv('MINIBOOT_TARGET_DEPLOY_DIR')
    if prefixdir is None or prefixdir == "":
        prefixdir = "."

    imageParts = processConf(imageConf)
    global bootInfoContent
    bootInfoContent[0] = 0x43495248  # manu_id HRIC
    bootInfoContent[1] = 0x31413258  # chip_id X2A
    bootInfoContent[2] = 0x20200113  # fw_ver 20200113
    bootInfoContent[3] = 0x00000000  # info_csum
    bootInfoContent[10] = 0x80000000  # boot_loadaddr

    parts = mbrNandParts if bootmode == "nand" else mbrParts

    for curPart in parts:
        key = curPart[2]
        offset_size = imageParts.get(key)
        if offset_size is not None:
            partOffset = offset_size[0]
            partSize = offset_size[1]
            if curPart[0] == 'cold_spl':
                spl_off = partOffset
            # adding address of component
            bootInfoContent[curPart[1]] = partOffset
            if curPart[3] > 0:
                # adding size of component
                curName = os.getenv(key[key.find("{") + 1:key.find("}")])
                # fn = prefixdir + "/" + key[:key.find("/") + 1] + curName
                fn = prefixdir + "/" + curName
                if os.path.exists(fn):
                    if ('warm' in curName) or ((os.getenv('HR_QUICKBOOT') == 'true') and ('bl31' in curName)):
                        bootInfoContent[curPart[3]] = getFileSize(fn)
                    else:
                        bootInfoContent[curPart[3]] = partSize
                    bootInfoContent[curPart[3] + 1] = addCheckSum(fn)
        else:
            print("{} not found in gpt.conf!".format(curPart[0]))

    bootInfoContent[45] = int("0x"+uboot_load_addr, 16)  # other_laddr
    # bootInfoContent[46] = 0x00000000  # qspi_cfg
    fast_spl = os.getenv("HR_ENABLE_FAST_SPL")
    # mbr offset 47*4
    # bit24: 0 means this filed is invalid, 1 meands valid
    # bit20: 1 means 4 bus width, 0 means 8 bus width
    # bit[0-3]: divider, mclk = 192M / (divider + 1) / 2
    # bit[4-7]: Fixed value 7
    if fast_spl == 'true':
        bootInfoContent[47] = 0x01100071  # emmc_cfg
    else:
        bootInfoContent[47] = 0x01100073  # emmc_cfg
    bootInfoContent[48] = int("0x"+boardid, 16)  # board_id

    # avb 2.0 flag
    ifAVB = os.getenv("AVB_DM")
    if ifAVB == 'avb_dm' or ifAVB == 'kernel':
        bootInfoContent[69] = int("bva".encode("hex"), 16)

    # spl decrypt or verify uboot, bl31 and bpu
    encrypt_flag = os.getenv("ENCRYPT_FLAG")
    verify_flag = os.getenv("VERITY_FLAG")
    bootInfoContent[70] = 0x0
    if encrypt_flag == 'true':
        bootInfoContent[70] = bootInfoContent[70] | 0x1

    if verify_flag == 'true':
        bootInfoContent[70] = bootInfoContent[70] | (0x1 << 4)

    # bootInfoContent = np.asarray(bootInfoContent, dtype=np.int32)

    # spl info
    name = os.getenv('UBOOT_SPL_NAME')
    fn = os.getenv('SRC_SPL_DIR') + "/" + name
    if os.path.exists(fn):
        bootInfoContent[8] = ((getFileSize(fn) + 511)/512) * 512
        bootInfoContent[9] = addCheckSum(fn)    # spl info
        # To cope with SPL size, nand with 128 KiB erase block
        # need to fix backup SPL locations
        if os.getenv('HR_PAGE_SIZE') == '2048':
            bootInfoContent[5] = spl_off + (1 * 0x20000)
            bootInfoContent[6] = spl_off + (2 * 0x20000)
            bootInfoContent[7] = spl_off + (3 * 0x20000)

    # ddr info
    if build_type == "x2":
        ddr_name_prefix = os.getenv('DDR_NAME_PREFIX')
        fn = prefixdir + "/ddr/" + "imem_1D.bin"
        bootInfoContent[15] = ((getFileSize(fn) + 511)/512) * 512
        bootInfoContent[17] = addCheckSum(fn)
        fn = prefixdir + "/ddr/" + ddr_name_prefix + "_dmem_1D.bin"
        bootInfoContent[16] = ((getFileSize(fn) + 511)/512) * 512
        bootInfoContent[18] = addCheckSum(fn)
        fn = prefixdir + "/ddr/" + "imem_2D.bin"
        bootInfoContent[23] = ((getFileSize(fn) + 511)/512) * 512
        bootInfoContent[25] = addCheckSum(fn)
        fn = prefixdir + "/ddr/" + ddr_name_prefix + "_dmem_2D.bin"
        bootInfoContent[24] = ((getFileSize(fn) + 511)/512) * 512
        bootInfoContent[26] = addCheckSum(fn)
    uboot_size = os.getenv('MINIBOOT_UBOOT_SIZE')
    bootInfoContent[34] = int(uboot_size)
    bootInfoContent[37] = int(uboot_size)
    # old mbr
    bootInfoContent[112] = 0xFEEE0001
    bootInfoContent[113] = 0x0001FFFF
    bootInfoContent[114] = 0xEC420000
    bootInfoContent[115] = 0x00000002
    bootInfoContent[127] = 0xAA550000

    sum = 0
    i = 0
    for i in range(69):
        bootInfoContent[125] = bootInfoContent[i] >> 24
        sum += (bootInfoContent[125] & 0xff)
        bootInfoContent[125] = bootInfoContent[i] << 8
        bootInfoContent[125] = bootInfoContent[125] >> 24
        sum += (bootInfoContent[125] & 0xff)
        bootInfoContent[125] = bootInfoContent[i] << 16
        bootInfoContent[125] = bootInfoContent[125] >> 24
        sum += (bootInfoContent[125] & 0xff)
        bootInfoContent[125] = bootInfoContent[i] << 24
        bootInfoContent[125] = bootInfoContent[125] >> 24
        sum += (bootInfoContent[125] & 0xff)
        bootInfoContent[125] = 0
    bootInfoContent[3] = sum

dtb_header_path = r"dtb_header.json"
dtb_file_out_path = r"dtb_file_out.json"

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("arg count: {}, requires 3".format(len(sys.argv)))
        print("Usage: {} gpt.conf destname".format(sys.argv[0]))
        sys.exit(1)
    imageConf = sys.argv[1]
    destname = sys.argv[2]

    try:
        bootInfoContent = [0]*128
        boardid = os.getenv('BOARD_ID')
        bootmode = os.getenv('BOOT_MODE')
        uboot_load_addr = os.getenv("UBOOT_IMAGE_LOAD_ADDR")
        if (boardid is None or boardid == ""):
            boardid = "0"
        create_mbr(boardid, imageConf)

        print("destname:" + destname)

        file_produced0 = open(destname, 'wb')
        for i in range(len(bootInfoContent)):
            file_produced0.write(struct.pack('I', bootInfoContent[i]))

        file_produced0.close()
    except:
        print(sys.exc_info())
        print(traceback.format_exc())
        sys.exit(2)
    else:
        sys.exit(0)
