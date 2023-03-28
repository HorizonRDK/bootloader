#!/usr/bin/env python2
import sys

from gpt import *


def create_empty_gpt_entry():
    partition_type_guid = b"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    unique_partition_guid = b"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    starting_lba = 0
    ending_lba = 0
    attributes = 0
    partition_name = "\x00\x00".encode('utf-16')[2:]
    print(partition_name)
    # '<16s 16s Q Q Q 72s'
    entry = GPTPartitionEntry(partition_type_guid, unique_partition_guid,
                              starting_lba,
                              ending_lba,
                              attributes,
                              partition_name)
    return entry


def create_gpt_entry(start_lba, end_lba, name):
    partition_type_guid = uuid.uuid4().bytes
    unique_partition_guid = uuid.uuid4().bytes
    starting_lba = start_lba
    ending_lba = end_lba
    attributes = 0
    partition_name = name.decode("utf-8").encode('utf-16')[2:]
    # print("starting: %x, end: %x, name: %s" % (start_lba, end_lba, name))
    entry = GPTPartitionEntry(partition_type_guid,
                              unique_partition_guid,
                              starting_lba,
                              ending_lba,
                              attributes,
                              partition_name)
    return entry


def complete_gpt_entries(entrylist):
    an = create_empty_gpt_entry()
    for i in range(len(entrylist), 0x80, 1):
        entrylist.append(an)


def create_gpt_header():
    signature = b"EFI PART"
    revision = b"\x00\x00\x01\x00"
    header_size = 0x5c
    header_crc32 = 0  # TODO
    reserved = b"\x00\x00\x00\x00"
    my_lba = 1
    alternate_lba = 0  # TODO
    first_usable_lba = 34
    last_usable_lba = 0  # TODO
    disk_guid = uuid.uuid4().bytes
    partition_entry_lba = 2
    number_of_partition_entries = 0x80
    size_of_partition_entry = 0x80
    partition_entry_array_crc32 = 0  # TODO
    hdr = GPTHeader(signature, revision, header_size, header_crc32, reserved, my_lba,
                    alternate_lba, first_usable_lba, last_usable_lba, disk_guid,
                    partition_entry_lba, number_of_partition_entries, size_of_partition_entry,
                    partition_entry_array_crc32)

    return hdr


def create(alternate_lba, entrylist):
    complete_gpt_entries(entrylist)

    entriesdata = encode_gpt_partition_entry_array(entrylist, 0x80, 0x80)

    hdr = create_gpt_header()
    hdr.alternate_lba = alternate_lba
    hdr.last_usable_lba = alternate_lba - 33
    hdr.partition_entry_array_crc32 = calculate_partition_entry_array_crc32(
        entriesdata)
    # print"crc: 0x%x" % hdr.partition_entry_array_crc32
    hdr.header_crc32 = hdr.calculate_header_crc32()
    # print"header crc: 0x%x" % hdr.header_crc32

    gptdata = encode_gpt_header(hdr)

    # gpt_main
    maindata = bytearray()
    # mbr
    maindata.extend(bytearray(0x200))
    # gpt header
    maindata.extend(gptdata)
    maindata.extend(bytearray(0x200 - len(gptdata)))
    # gpt table
    maindata.extend(entriesdata)
    # maindata.extend(bytearray(128 * 128 - len(entriesdata)))

    # gpt_backup
    backdata = bytearray()
    # gpt table
    backdata.extend(entriesdata)
    # gpt header
    backdata.extend(gptdata)
    backdata.extend(bytearray(0x200 - len(gptdata)))

    return (bytes(maindata), bytes(backdata))


def parse_conf(path, entrylist):
    maxsize = 0
    with open(path, "rb") as f:
        items = f.readlines()

    for item in items:
        (ispart, name, fstype, starts, stops, crop) = item.split(b':')
        if int(ispart) == 1:
            if name.find(b'/') != -1:
                name = name[:name.find(b'/')]
            entry = create_gpt_entry(int(starts[:-1]), int(stops[:-1]), name)
            entrylist.append(entry)
            maxsize = stops[:-1]

    return int(maxsize)+33


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("Error: args number is not 4")
        print("Usage: sys.argv[0] gpt.conf main_img backup_img")
        sys.exit(1)

    path = sys.argv[1]
    main_img = sys.argv[2]
    backup_img = sys.argv[3]
    entrylist = []
    alternate_lba = parse_conf(path, entrylist)
    (main_data, backup_data) = create(alternate_lba, entrylist)

    with open(main_img, "wb") as f:
        f.write(main_data)

    with open(backup_img, "wb") as f:
        f.write(backup_data)
