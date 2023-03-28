/*
 *    COPYRIGHT NOTICE
 *    Copyright 2020 Horizon Robotics, Inc.
 *    All rights reserved.
 */
#ifndef __X2A_INFO_H__
#define __X2A_INFO_H__
#include <stdint.h>
#define PRINT_SPL_LOG  1

#if defined(SPL_RELEASE)
#undef PRINT_SPL_LOG
#define PRINT_SPL_LOG 0
#endif

#if (PRINT_SPL_LOG)
#define DEBUG_LOG(fmt, ...) \
    printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_LOG(fmt, ...)
#endif

#define X3_GPIO0_CTRL_REG	0x8
#define X3_GPIO0_VALUE_REG	0xC
#define X3_GPIO6_CTRL_REG	0x68
#define X3_GPIO6_VALUE_REG	0x6C

#define X2_SYSCNT_BASE          (0xA6001000)
#define X2_GPIO_BASE            (0xA6003000)

/* auto detection */
#define AUTO_DETECTION	0x0

#define BOOTINFO_ADDR	0x10000000
#define BOOTINFO_SIZE	0x200
#define UNIQUE_ID_ADDR	(0x10000000 + BOOTINFO_SIZE)

#define DDR_STR_NAME_MAX 50
#define AFTER_EFUSE_NORMAL 0
#define AFTER_EFUSE_STOP (-1)
typedef struct _ddr_str_t{
	char name[DDR_STR_NAME_MAX];
	unsigned int value;
}ddr_str_t;
#define DDR_STR(a) {#a,a}
/*
 * lpddr4 part number
 * H9HCNNN8KUMLHR: lpddr4 hynix 1G(xh)
 * H9HCNNNBKUMLHR: lpddr4 hynix 2G(jh)
 * K4F8E304HBMGCJ: lpddr4 samsung 1G(xg)
 * K4F6E3S4HMMGCJ: lpddr4 samsung 2G(xg)
 * MT53D1024M32D4DT: lpddr4/lpddr4x micron 4G
 */
#define H9HCNNN8KUMLHR		0x0608
#define H9HCNNNBKUMLHR		0x0610
#define MT53D1024M32D4DT	0xff10
#define K4F8E304HBMGCJ		0x0108
#define K4F6E3S4HMMGCJ		0x0110
#define PART_DEFAULT		0xffff
#define LP4_MANU_ID_HYNIX	0x06
#define LP4_MANU_ID_MICRON	0xff
#define LP4_MANU_ID_SAMSUNG	0x01
#define MT53E1G32D2FW_046AUTA 	0xff20
#define MT53D512M32D2DT_046AAT  0xff21
#define MT53E256M32D2DS_053AAT	0xff22
#define K4A4G165WF_BCTD	        0xff30
#define K4FBE3D4HM_THCL         0x1010

#define PART_NUMBER_STR \
	DDR_STR(H9HCNNN8KUMLHR),\
	DDR_STR(H9HCNNNBKUMLHR),\
	DDR_STR(MT53D1024M32D4DT),\
	DDR_STR(K4F8E304HBMGCJ),\
	DDR_STR(PART_DEFAULT),\
	DDR_STR(K4F6E3S4HMMGCJ),\
	DDR_STR(LP4_MANU_ID_HYNIX),\
	DDR_STR(LP4_MANU_ID_MICRON),\
	DDR_STR(LP4_MANU_ID_SAMSUNG),\
	DDR_STR(MT53E1G32D2FW_046AUTA),\
	DDR_STR(MT53D512M32D2DT_046AAT),\
	DDR_STR(K4A4G165WF_BCTD),\
	DDR_STR(MT53E256M32D2DS_053AAT),

#define LP4_MANU_ID_HYNIX	0x06
#define LP4_MANU_ID_MICRON	0xff
#define LP4_MANU_ID_SAMSUNG	0x01

/*
 * ddr4 part number
 * MT40A256M16LY: DDR4 SDRAM 4Gbit 3200Mbps 16bit 1.2V FBGA96
 * K4A8G165WC: 8Gb C-die DDR4 SDRAM x16 1.2V 96FBGA
 */
#define MT40A256M16LY		0xAAAA
#define K4A8G165WC			0xBBBB

/* ddr manufacture */
#define DDR_MANU_HYNIX		0x1
#define DDR_MANU_MICRON		0x2
#define DDR_MANU_SAMSUNG	0x3
#define PIN_DDR_TYPE_SEL(x)	((x) & 0x1)

/* ddr type */
#define DDR_TYPE_LPDDR4		0x1
#define DDR_TYPE_LPDDR4X	0x2
#define DDR_TYPE_DDR4		0x3
#define DDR_TYPE_DDR3L		0x4

/* ddr frequency */
#define DDR_FREQC_667	0x1
#define DDR_FREQC_1600	0x2
#define DDR_FREQC_2133	0x3
#define DDR_FREQC_2666	0x4
#define DDR_FREQC_3200	0x5
#define DDR_FREQC_3733	0x6
#define DDR_FREQC_4266	0x7
#define DDR_FREQC_1866	0x8
#define DDR_FREQC_2400	0x9
#define DDR_FREQC_100   0xa
#define DDR_FREQC_3600  0xb
#define DDR_FREQC_333   0xc
#define DDR_FREQC_1333  0xd
#define DDR_FREQC_2640  0xe
/* ddr capacity */
#define DDR_CAPACITY_1G		0x1
#define DDR_CAPACITY_2G		0x2
#define DDR_CAPACITY_4G		0x3

/* som type */
#define SOM_TYPE_X3		0x1
#define SOM_TYPE_J3		0x2
#define SOM_TYPE_X3SDB		0x4

#define EFUSE_SOM_TYPE_X3	0x6
#define EFUSE_SOM_TYPE_J3	0x8

/* ecc config */
#define ECC_DEFAULT		0x0
#define ECC_ALL			0x1
#define ECC_OPTION_1		0x2
#define ECC_OPTION_2		0x3

/* alternative ddr para */
#define ALTERNATIVE_DEFAULT	0x0
#define ALTERNATIVE_ENABLE	0x1

/* base board type */
#define BASE_BOARD_X3_DVB		0x1
#define BASE_BOARD_J3_DVB		0x2
#define BASE_BOARD_CVB			0x3
#define BASE_BOARD_CUSTOMER_BOARD	0x4

/* manufacture */
#define DDR_MANUF_SEL(x)  (((x) >> 28) & 0xf)
#define DDR_TYPE_SEL(x) (((x) >> 24) & 0xf)
#define DDR_FREQ_SEL(x)  (((x) >> 20) & 0xf)
#define DDR_CAPACITY_SEL(x)  (((x) >> 16) & 0xf)
#define ECC_CONFIG_SEL(x)  (((x) >> 12) & 0xf)
#define SOM_TYPE_SEL(x)  (((x) >> 8) & 0xf)
#define ALTER_CONFIG_SEL(x) (((x) >> 4) & 0xf)
#define BASE_BOARD_SEL(x)  ((x) & 0xf)
#define PIN_BASE_BOARD_SEL(x)	((((x >> 14) & 0x1) << 0x1) | \
	((x >> 12) & 0x1))

/* efuse value */
#define DDR_VENDER_EFUSE_HYNIX		0x0
#define DDR_VENDER_EFUSE_MICRON		0x1
#define DDR_VENDER_EFUSE_SAMSUNG	0x2

#define DDR_TYPE_EFUSE_LPDDR4	0x0
#define DDR_TYPE_EFUSE_DDR4	0x1
#define DDR_TYPE_EFUSE_LPDDR4X	0x2

#define CHIP_TYPE_HORIZON_ROBOT	0x1

#define DDR_VENDER_EFUSE_SEL(x) ((x >> 6) & 0x3)
#define DDR_TYPE_EFUSE_SEL(x) ((x >> 4) & 0x3)
#define CHIP_TYPE_EFUSE_SEL(x) (x & 0xf)
#define SOM_TYPE_EFUSE_SEL(x) ((x >> 12) & 0xf)

#define HB_WDT_EN              1
#define HB_WDT_DIS              0

extern unsigned int hb_ddr_type;
extern unsigned int hb_ddr_vendor;
extern unsigned int hb_ddr_freq;
extern unsigned int hb_ddr_index;
extern unsigned int hb_ddr_part_number;
extern unsigned int hb_ddr_inline_ecc_en;
extern struct SDRAM_INFO sdram_info;
extern struct hb_unique_id uid;

#ifdef YMODEM_BOOT
extern struct hb_ddr_uart_hdr ddr_hdr_uart;
#else
extern struct hb_ddr_hdr ddr_hdr;
#endif

typedef enum {
	DEV_TYPE_EMMC = 0,
	DEV_TYPE_NOR,
	DEV_TYPE_NAND_2K,
	DEV_TYPE_NAND_4K,
	DEV_TYPE_AP,
	DEV_TYPE_UART,
	DEV_TYPE_USB,
	DEV_TYPE_USB_SECTOR,
	DEV_TYPE_SRAM
} x3_boot_src_t;

/*
 * magic: 0xFEFEFEFE
 */
struct hb_unique_id {
	unsigned int magic;
	unsigned int bank[4];
};

struct ddr_freq {
	unsigned int value;
	unsigned int micron_value;
};

struct x3_image_hdr {
	unsigned int img_addr;
	unsigned int img_size;
	unsigned int img_csum;
};

struct hb_ddt_mem {
	unsigned int addr;
	unsigned int size;
};

struct hb_ddr_uart_hdr {
	struct hb_ddt_mem imem1;	/* ddr imem */
	struct hb_ddt_mem imem2;
	struct hb_ddt_mem dmem1;	/* ddr dmem */
	struct hb_ddt_mem dmem2;

	struct hb_ddt_mem ddr_ddrc;
	struct hb_ddt_mem ddr_ddrp;
	struct hb_ddt_mem ddr_pie;
	struct hb_ddt_mem ddr_ddrc_freqs;
	struct hb_ddt_mem ddr_ddrp_freqs;
	struct hb_ddt_mem ddr_pie_freqs;
	struct hb_ddt_mem addr_map;
	unsigned int dqmap_addr[16];
	unsigned int board_id;
        unsigned int spl_version;
        unsigned int ddr_type;
        unsigned int ddr_vendor;
        unsigned int ddr_freq;
        unsigned int part_number;
	unsigned int dqmap_addr_fccsp[16];

};

struct hb_ddr_data {
	unsigned int ddr_type;
	unsigned int ddr_vendor;
	unsigned int ddr_freq;
	unsigned int part_number;

	struct hb_ddt_mem imem1;	/* ddr imem */
	struct hb_ddt_mem imem2;
	struct hb_ddt_mem dmem1;	/* ddr dmem */
	struct hb_ddt_mem dmem2;

	struct hb_ddt_mem ddr_ddrc;
	struct hb_ddt_mem ddr_ddrp;
	struct hb_ddt_mem ddr_pie;

	struct hb_ddt_mem ddr_ddrc_freqs;
	struct hb_ddt_mem ddr_ddrp_freqs;
	struct hb_ddt_mem ddr_pie_freqs;
	struct hb_ddt_mem addr_map;
};


struct dfs_freq {
       unsigned char freq_p1;
       unsigned char freq_p2;
};
/*
 * 5 blocks,512 bytes per block
 * */
struct hb_ddr_hdr {
	unsigned int magic;  /* HBOT */
	unsigned int count;
	unsigned short ecc_gran[4];
	unsigned short ecc_map[4];
	unsigned int sbr_pattern0;
	unsigned int sbr_pattern1;
	unsigned int ddr_para_addr;
	unsigned int ddr_para_size;

	struct hb_ddr_data ddr[20];
	char ddr_pin[3];
	char ota_check_count;
        unsigned int efuse_offset;
        unsigned int sscg_parm[3];
        unsigned int keyset_offset;
        unsigned int keyset_size;
	unsigned int eye_tool_pin;
	struct dfs_freq ddr_dfs[20];
	unsigned int dqmap_addr[16];
	unsigned int wdt_en;
	unsigned int wdt_time;
	unsigned int se_debug_pin;
	unsigned int cfg_qos;
	unsigned int read_qos;
	unsigned int write_qos;
	unsigned int efuse_gpio;
	unsigned int efuse_delay;
	unsigned int efuse_sta_gpio;
	unsigned int dqmap_addr_fccsp[16];
	int32_t      after_efuse_delay;
	unsigned int efuse_bit_debug;
	unsigned int reserve[48];
        unsigned int spl_version;
};

/* hb_info_hdr: 512 Info defined */
/* total length of should be less than 512 Bytes */
typedef struct x2a_info_hdr {
	unsigned int manu_id;	/* Manualfacture identify */
	unsigned int chip_id;	/* Chip identify */
	unsigned int fw_ver;	/* Firmware version */
	unsigned int info_csum;	/* A check sum of the structure */

	unsigned int boot_addr[4];	/* Address in storage */
	unsigned int boot_size;
	unsigned int boot_csum;
	unsigned int boot_laddr;	/* Load address */

	unsigned int ddt1_addr[4];	/* DDR 1D Training Firmware */
	unsigned int ddt1_imem_size;
	unsigned int ddt1_dmem_size;
	unsigned int ddt1_imem_csum;
	unsigned int ddt1_dmem_csum;

	unsigned int ddt2_addr[4];	/* DDR 2D Training Firmware */
	unsigned int ddt2_imem_size;
	unsigned int ddt2_dmem_size;
	unsigned int ddt2_imem_csum;
	unsigned int ddt2_dmem_csum;

	unsigned int ddrp_addr[4];	/* DDR Parameter for wakeup */
	unsigned int ddrp_size;
	unsigned int ddrp_csum;

	/*
	 * other_img[0]: u-boot (load to SPL_LOAD_UBOOT_ADDR)
	 * other_img[1]: Linux image (load to SPL_LOAD_LINUX_ADDR)
	 * other_img[2]: Linux dtb (load to SPL_LOAD_DTB_ADDR)
	 * other_img[3]: warm boot SPL (load to SPL_LOAD_WARM_SPL_ADDR)
	 */
	struct x3_image_hdr other_img[4];
	/* DDR buffer address for BL31 to jump (bl1->spl->bl31->other_laddr) */
	unsigned int other_laddr;

	unsigned int qspi_cfg;
	unsigned int emmc_cfg;

	unsigned int board_id;

	unsigned int bpu_devid_addr[3];	/* BPU Device ID information */
	unsigned int bpu_devid_size;
	unsigned int bpu_devid_csum;

	unsigned int bpu_rsakey_addr[3];	/* BPU RSA publish key bank */
	unsigned int bpu_rsakey_size;
	unsigned int bpu_rsakey_csum;

	unsigned int bpuimg_addr[3];	/* BPU Image */
	unsigned int bpuimg_size;
	unsigned int bpuimg_csum;

	unsigned int bl31img_addr[3];	/* BL31 image */
	unsigned int bl31img_size;
	unsigned int bl31img_csum;

	char secure_cfg[4];	/* avb 2.0 */
	unsigned int crypt_cfg;	/* spl encrypt or verity uboot, bl31 and bpu */

	unsigned int reserved[57];
	/* 512 Info remaining spots pls update when adding new item */
} x2a_info_hdr_t;

struct ddr_dfs_freqs {
	unsigned int dfs_p0;
	unsigned int dfs_p1;
	unsigned int dfs_p2;
};

unsigned int base_board_type_get(void);

unsigned int ddr_freq_macro_value_get(unsigned int value);

#endif /* __X2A_INFO_H__ */
