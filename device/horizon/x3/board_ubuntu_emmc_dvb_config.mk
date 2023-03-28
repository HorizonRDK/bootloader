#!/bin/bash

# 编译后镜像输出路径
export HR_IMAGE_DEPLOY_DIR=${HR_TOP_DIR}/deploy_ubuntu_dvb

# 可以设置整个系统的版本信息，在OTA升级中会有涉及
source ${HR_TOP_DIR}/"device/horizon/x3/hr_ubuntu_build_version.mk"
export HR_BSP_VERSION="x3_ubuntu_v${HR_BUILD_VERSION}"

# 配置交叉编译工具链
export ARCH=arm64
export TOOLCHAIN_PATH=/opt/gcc-ubuntu-9.3.0-2020.03-x86_64-aarch64-linux-gnu
export CROSS_COMPILE=${TOOLCHAIN_PATH}/bin/aarch64-linux-gnu-
export TOOLCHAIN_LD_LIBRARY_PATH=${TOOLCHAIN_PATH}/lib/x86_64-linux-gnu/

# avbtools工具脚本存放路径，在对kernel和分区文件系统添加校验信息时需要使用到（mk_system.sh）
export HR_AVB_TOOLS_PATH=${HR_TOP_DIR}/build/tools/avbtools
# key_management_toolkits工具脚本存放路径，在编译miniboot、uboot添加header信息时使用，里面也存放了校验需要使用的key文件
export HR_KEY_MANAGEMENT_TOOLKITS_PATH=${HR_TOP_DIR}/build/tools/key_management_toolkits
# 生成uart启动固件时需要使用到的脚本工具，配合（./xbuild.sh foctory）命令使用
export HR_MK_UART_BOOT_PACKAGE_TOOLS_PATH=${HR_TOP_DIR}/build/tools/uart_usb_boot

# 配置存储介质，支持 "emmc", "nand", "nor"
export HR_BOOT_MODE="emmc"

# 备份还原模式，支持AB备份和golden模式（需要设置 HR_KERNEL_WITH_RECOVERY = true），每种模式对应的分区表有区别，需要同步修改分区表
export HR_OTA_UPDATE_MODE="golden"

# 设置存储启动计数的位置，设置为 pmu，则使用寄存器来保存重启计数；否则会存储在veeprom分区内
export HR_COUNT_STORE_MODE="pmu"

# 分区表配置文件所在目录和文件名
export HR_GPT_CONF_DIR=${HR_TOP_DIR}/"device/horizon/x3"
export HR_GPT_CONF_FILENAME="emmc_ubuntu_gpt.conf"

# Miniboot相关配置
# miniboot 在引导uboot启动时，加载uboot的内存地址
export HR_UBOOT_IMAGE_LOAD_ADDR="4000000"
# miniboot读取的uboot镜像大小，如果用户编译的uboot.img镜像超过了2MB,此处和分区中uboot的分区大小都需要相应修改
export HR_UBOOT_SIZE=2097152  #2M SIZE
# 打包几个分区镜像进miniboot分区，1代表miniboot分区的spl镜像前只有mbr和gpt，2代表spl之前还有例如veeprom分区这种分区
export HR_PACK_PART_NUMBER_IN_MINIBOOT=2

# 芯片类型： x3
export HR_CHIP_TYPE="x3"
# 芯片核心板类型: auto(0) | x3som(1) | j3som(2) | x3sdb(3), 或者 0-15之间的数字，用于指示核心板类型
export HR_SOM_TYPE="x3som"
# 使用的基础硬件参考设计，主要影响ddr的pcb走线，一定要正确，否则ddr training不过。 可选参数 "x3dvb" "j3dvb" "cvb" "x3sdb"
export HR_BASE_BOARD_TYPE="x3dvb"

# DDR参数配置
# 频率可选参数 "667" "1600" "2133" "2640" "2666" "3200" "3600"
export HR_DDR_FREQ="2666"
# 厂家可选参数 "hynix" "micron" "samsung"
export HR_DDR_MANUFACTURE="samsung"
# ddr类型可选 "LPDDR4" "LPDDR4X" "DDR4"
export HR_DDR_TYPR='LPDDR4'
# ddr容量大小 "1" "2" "4", 可不配置，支持自动识别
export HR_DDR_CAPACITY="0"
# 当相同ddr厂家、类型、频率时有多组ddr参数时，需要通过这个配置项来做区分
export HR_DDR_ALTERNATIVE=0

# 建议：每次新增核心板时都对应添加一套 HR_SOM_TYPE、uboot_config_file、kernel_config_file、uboot和kernel下的dts

# uboot 编译配置文件，在这个配置文件中需要指定使用的dts文件
export HR_UBOOT_CONFIG_FILE=xj3_soc_defconfig

# kernel 配置
# kernel的设备树通过 HR_SOM_TYPE 和 HR_BASE_BOARD_TYPE 组合后的数字(例如：304)，在tools/dtbmapping/dtb_mapping_xj3.json匹配
# kernel 编译配置文件
export HR_KERNEL_CONFIG_FILE=xj3_perf_ubuntu_defconfig
# golden 模式需要编译 recovery 分区， HR_OTA_UPDATE_MODE="golden"时需要配置为"true"
export HR_KERNEL_WITH_RECOVERY="true"

# rootfs 配置
# X3M 支持 yocto 和 ubuntu 两种根文件系统，在此处指定根文件系统类型和预编译的文件系统路径
export HR_ROOTFS_TYPE=ubuntu
export HR_ROOTFS_DIR=${HR_TOP_DIR}/system/rootfs_ubuntu
export HR_ROOTFS_PKG=focal-xj3-arm64.tar.xz
# 根文件系统中是否集成内核的驱动模块ko文件
export HR_ROOTFS_WITH_KO="false"
# 根文件系统中是否集成地平线多媒体接口库文件
export HR_ROOTFS_WITH_MEDIA_LIBS="false"
# 根文件系统中是否集成地平线sdk中的deb软件包，并且在设备第一次启动时自动安装
export HR_ROOTFS_WITH_HR_DEBS="true"
# 根文件系统的分区名，需要和分区表配置对应
export HR_ROOTFS_PART_NAME="system"
# 是否对根文件系统添加avb校验，支持镜像安全
export HR_ROOTFS_AVB_VERITY="false"
# 根文件系统类型，请在分区表中全部设置为none，统一在这里进行设置，因为uboot也依赖这个配置来设置启动项，支持 "ext4", "squashfs"
export HR_ROOTFS_FS_TYPE="ext4"

# 环境变量配置标志，用来标识当前env环境已经完成了板级配置项的设置
export HR_IS_BOARD_CONFIG_EXPORT="true"
