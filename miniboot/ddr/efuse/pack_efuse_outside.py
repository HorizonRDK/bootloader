#!/usr/bin/python

import json
import struct
import sys
import os

output_file = sys.path[0] + str("/efuse-origin.bin")
input_file = sys.path[0] + str("/efuse_cfg_outside.json")


def write_socid_to_efuse_bin(data):
    efuse_img = open(output_file, 'ab+')
    efuse_img.write(data)
    efuse_img.close()


def write_to_efuse_bin(data):
    efuse_img = open(output_file, 'ab+')
    data_hex = struct.pack('I', data)
    efuse_img.write(data_hex)
    efuse_img.close()


def outside_efuse(json_buf):
    bypass = json_buf["outside"]["bypass"]
    write_to_efuse_bin(bypass)

    if ("setlock" in json_data["outside"]):
        setlock = json_data["outside"]["setlock"]
        if setlock < 0 and setlock > 1:
            print("setlock is only 0 or 1")
            sys.exit(1)
        write_to_efuse_bin(setlock)
    else:
        write_to_efuse_bin(0)
    value = json_buf["outside"]["disjtag"]
    if value != 0 and value != 1:
        print("error: disjtag is only 0 or 1!!!!!")
        sys.exit(1)
    write_to_efuse_bin(value)

    value = json_buf["outside"]["disbifsd"]
    if value != 0 and value != 1:
        print("error: disbifsd is only 0 or 1!!!!!")
        sys.exit(1)
    write_to_efuse_bin(value)

    value = json_buf["outside"]["disbifspi"]
    if value != 0 and value != 1:
        print("error: disbifspi is only 0 or 1!!!!")
        sys.exit(1)
    write_to_efuse_bin(value)

    value = json_buf["outside"]["veri_uboot"]
    if value != 0 and value != 1:
        print("error: verify uboot bit is only 0 or 1!!!!")
        sys.exit(1)

    if ("sel_key" in json_data["outside"]):
        sel_key = json_buf["outside"]["sel_key"]
        if sel_key != 0 and sel_key != 1:
            print("error: select key is only 0 or 1!!!!")
            sys.exit(1)
    else:
        sel_key = 0

    value = value + (sel_key << 1)
    write_to_efuse_bin(value)

    value = json_buf["outside"]["veri_bpu"]
    if value != 0 and value != 1:
        print("error: verify bpu bit is only 0 or 1!!!!")
        sys.exit(1)
    write_to_efuse_bin(value)

    if ("debug_lock" in json_data["outside"]):
        debug_lock = json_data["outside"]["debug_lock"]
        if debug_lock < 0 and debug_lock > 1:
            print("debug lock is only 0 or 1")
            sys.exit(1)
        write_to_efuse_bin(debug_lock + 1)
    else:
        write_to_efuse_bin(0)

    customerid = json_data["outside"]["customerid"]
    int_customerid = int(customerid, 16)
    if int_customerid > 65535:
        print("customer id range 0~0xffff")
        sys.exit(1)

    write_to_efuse_bin(int_customerid)
    productid = json_data["outside"]["productid"]
    int_customerid = int(productid, 16)
    if int_customerid > 255:
        print("customer id range 0~0xff")
        sys.exit(1)
    write_to_efuse_bin(int_customerid)

    if ("id_lock" in json_data["outside"]):
        id_lock = json_data["outside"]["id_lock"]
        if id_lock < 0 and id_lock > 1:
            print("id lock is only 0 or 1")
            sys.exit(1)
        write_to_efuse_bin(id_lock + 1)
    else:
        write_to_efuse_bin(0)

    for i in range(5):
        bank = "bank"+str(i + 7)
        str_outside_bank = json_buf["outside"]["normalbank"][bank]
        if isinstance(str_outside_bank, unicode):
            int_outside_bank = int(str_outside_bank, 16)
            write_to_efuse_bin(int_outside_bank)
            write_to_efuse_bin(0)
            continue

        int_outside_bank = int(str_outside_bank[0], 16)
        write_to_efuse_bin(int_outside_bank)
        size = len(str_outside_bank)
        if size == 1:
            write_to_efuse_bin(0)
        elif size == 2:
            if str_outside_bank[1] == "lock":
                write_to_efuse_bin(2)
            elif str_outside_bank[1] == "unlock":
                write_to_efuse_bin(1)
            else:
                print("error key word in bank value, lock or unlock")
        else:
            print("error size in bank value")

    secure_bank0 = 0
    write_to_efuse_bin(secure_bank0)

    # compitable with previous outside json, no hash bank
    if ("securebank" not in json_data["outside"]):
        for i in range(16):
            write_to_efuse_bin(0)
        for i in json_buf["outside"]["socid"]:
            i_str = i[2:]
            i_str = i_str.rjust(32, '0')
            hex_i = i_str.decode('hex')[::-1]
            write_socid_to_efuse_bin(hex_i)
        return

    for i in range(8):
        bank = "hash"+str(i)
        str_outside_bank = json_buf["outside"]["securebank"][bank]
        if isinstance(str_outside_bank, unicode):
            int_outside_bank = int(str_outside_bank, 16)
            write_to_efuse_bin(int_outside_bank)
            write_to_efuse_bin(0)
            continue

        int_outside_bank = int(str_outside_bank[0], 16)
        write_to_efuse_bin(int_outside_bank)
        size = len(str_outside_bank)
        if size == 1:
            write_to_efuse_bin(0)
        elif size == 2:
            if str_outside_bank[1] == "lock":
                write_to_efuse_bin(2)
            elif str_outside_bank[1] == "unlock":
                write_to_efuse_bin(1)
            else:
                print("error key word in bank value, lock or unlock")
        else:
            print("error size in bank value")
    for i in json_buf["outside"]["socid"]:
        i_str = i[2:]
        i_str = i_str.rjust(32, '0')
        hex_i = i_str.decode('hex')[::-1]
        write_socid_to_efuse_bin(hex_i)


if os.path.exists(output_file) is True:
    os.remove(output_file)

with open(input_file, 'r') as f:
    json_data = json.load(f)
    efuse_img = open(output_file, 'w+')
    efuse_img.write("HBDH")
    efuse_img.close()
    outside_efuse(json_data)
