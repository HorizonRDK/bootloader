#!/bin/sh

# usb: uboot
# sh x2a-img-pkg.sh -i $1 -o boot.pkg -l 0 -u

# uart: uboot
sh x2a-img-pkg.sh -i $1 -o boot.pkg -l 0 -a

# uart: kernel
# sh x2a-img-pkg.sh -i $1 -o boot.pkg -l 1 -a

# usb: kernel
# sh x2a-img-pkg.sh -i $1 -o boot.pkg -l 1 -u
