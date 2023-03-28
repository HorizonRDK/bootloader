#!/bin/bash
set -e
spl_img=$1
output=$2
rm -rf $output
echo "Creating Warm SPL to: $output"

bash ${HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH}/x3-img-pkg.sh -i $spl_img -o $output -t warm_spl
