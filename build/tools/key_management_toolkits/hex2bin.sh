#!/bin/bash

#$1: number wants to convert
#$2: output image name
hex2bin()
{
    num=$1
    
    msb=$(printf %x $(($num>>24&0xff)))
    msb2=$(printf %x $(($num>>16&0xff)))
    lsb=$(printf %x $(($num>>8&0xff)))
    lsb2=$(printf %x $(($num>>0&0xff)))
    echo -ne "\x$lsb2\x$lsb\x$msb2\x$msb" > $2
}

hex2bin $1 $2
