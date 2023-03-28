#ifndef __HB_DDR_OEM_H__
#define __HB_DDR_OEM_H__

#include "ddr_common.h"
#include "ddr.h"
#include "x3_ddr.h"
#include "ddr_phy_registers.h"
#include "ddr_phy_regs_struct.h"
#include "ddr_umctl2_registers.h"
#include "ddr_umctl2_regs_struct.h"
#include "x3_info.h"
#include "dwc_ddrphy_phyinit_dmem_struct_16b.h"
#include "dwc_ddrphy_phyinit_dmem_2d_struct_16b.h"
#include "x3_ddr4_micron_tuning.h"
#include "x3_ddr4_samsung_tuning.h"
#include "x3_lpddr4_hynix_tuning.h"
#include "x3_lpddr4_micron_tuning.h"
#include <stdio.h>

#ifdef SPL_DDR_PKG
#include <stdint.h>
#include <string.h>

struct hb_ddr_uart_hdr hdr_uart;
struct hb_ddr_hdr hdr_ddr;
#endif

#define UART_DDR_DIR              "uart_ddr_img"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ALIGN_512(x) ((x + 0x1ff) & (~0x1ff))
#define HB_DDR_HEAD_SIZE  512
#define ALTERNATIVE_PARA_ENABLED  1
enum boot_mode {
	BOOT_STORAGE = 0,
	BOOT_UART,
	BOOT_MAX
};

/* imem */
extern unsigned short int phyinit_imem_lpddr4[];
extern unsigned short int phyinit_imem_ddr4[];
extern unsigned short int phyinit_imem_lpddr4_2D[];
extern unsigned short int phyinit_imem_ddr4_2D[];
uint32_t get_sizeof_phyinit_imem_lpddr4(void);
uint32_t get_sizeof_phyinit_imem_ddr4(void);
uint32_t get_sizeof_phyinit_imem_lpddr4_2D(void);
uint32_t get_sizeof_phyinit_imem_ddr4_2D(void);

/* dmem */
extern unsigned short int phyinit_dmem_lpddr4[];
extern unsigned short int phyinit_dmem_ddr4[];
extern unsigned short int phyinit_dmem_lpddr4_2D[];
extern unsigned short int phyinit_dmem_ddr4_2D[];
uint32_t get_sizeof_phyinit_dmem_lpddr4(void);
uint32_t get_sizeof_phyinit_dmem_ddr4(void);
uint32_t get_sizeof_phyinit_dmem_lpddr4_2D(void);
uint32_t get_sizeof_phyinit_dmem_ddr4_2D(void);
void ddr4_dmem_reconfig_1600(void);
void ddr4_dmem_2d_reconfig_1600(void);
void ddr4_dmem_reconfig_2666(void);
void ddr4_dmem_2d_reconfig_2666(void);
void ddr4_dmem_reconfig_2400(void);
void ddr4_dmem_2d_reconfig_2400(void);
void ddr4_dmem_reconfig_3200(void);
void ddr4_dmem_2d_reconfig_3200(void);
void ddr4_dmem_reconfig_silicon(void);
void ddr4_write_dbi_cfg (uint32 data);
void ddr4_dmem_reconfig_init(unsigned int freq, unsigned int part_number);
void lpddr4_dmem_reconfig_667(void);
void lpddr4_dmem_reconfig_2666(void);
void lpddr4_dmem_reconfig_2666_xh(void);
void lpddr4_dmem_reconfig_3200(void);
void lpddr4_dmem_reconfig_3733(void);
void lpddr4_dmem_2d_reconfig_667(void);
void lpddr4_dmem_2d_reconfig_2666(void);
void lpddr4_dmem_2d_reconfig_2666_xh(void);
void lpddr4_dmem_2d_reconfig_3200(void);
void lpddr4_dmem_2d_reconfig_3733(void);
void lpddr4_micron_dmem_reconfig_silicon (unsigned int part_number,
	unsigned int alter_para, unsigned int freq);
void lpddr4_hynix_dmem_reconfig_silicon (unsigned int part_number,
	unsigned int alter_para, unsigned int freq);
void ddr_p_dmem_init(void);

/* ddrc */
extern struct DRAM_CFG_PARAM ddr4_ddrc_cfg[];
extern struct DRAM_CFG_PARAM ddr4_3200_ddrc_cfg[];
extern struct DRAM_CFG_PARAM ddr4_2666_ddrc_cfg_micron[];
extern struct DRAM_CFG_PARAM ddr4_2666_ddrc_cfg_samsung[];
extern struct DRAM_CFG_PARAM ddr4_2400_ddrc_cfg[];
extern struct DRAM_CFG_PARAM ddr4_1600_ddrc_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_ddrc_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_ddrc_cfg_hynix[];
extern struct DRAM_CFG_PARAM lpddr4_3200_ddrc_cfg_hynix[];
extern struct DRAM_CFG_PARAM lpddr4_100_ddrc_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_667_ddrc_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_2666_ddrc_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_2666_ddrc_cfg_xh[];
extern struct DRAM_CFG_PARAM lpddr4_2666_ddrc_cfg_jh[];
extern struct DRAM_CFG_PARAM lpddr4_3200_ddrc_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_3733_ddrc_cfg[];
uint32_t get_sizeof_ddr4_ddrc_cfg(void);
uint32_t get_sizeof_ddr4_3200_ddrc_cfg(void);
uint32_t get_sizeof_ddr4_2666_ddrc_cfg_micron(void);
uint32_t get_sizeof_ddr4_2666_ddrc_cfg_samsung(void);
uint32_t get_sizeof_ddr4_2400_ddrc_cfg(void);
uint32_t get_sizeof_ddr4_1600_ddrc_cfg(void);
uint32_t get_sizeof_lpddr4_ddrc_cfg(void);
uint32_t get_sizeof_lpddr4_ddrc_cfg_hynix(void);
uint32_t get_sizeof_lpddr4_3200_ddrc_cfg_hynix(void);
uint32_t get_sizeof_lpddr4_100_ddrc_cfg(void);
uint32_t get_sizeof_lpddr4_667_ddrc_cfg(void);
uint32_t get_sizeof_lpddr4_2666_ddrc_cfg(void);
uint32_t get_sizeof_lpddr4_2666_ddrc_cfg_xh(void);
uint32_t get_sizeof_lpddr4_2666_ddrc_cfg_jh(void);
uint32_t get_sizeof_lpddr4_3200_ddrc_cfg(void);
uint32_t get_sizeof_lpddr4_3733_ddrc_cfg(void);

/* ddrp */
extern struct DRAM_CFG_PARAM ddr4_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM ddr4_3200_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM ddr4_2666_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM ddr4_2400_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM ddr4_1600_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_ddrphy_hynix_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_ddrphy_hynix_cfg_xh[];
extern struct DRAM_CFG_PARAM lpddr4_ddrphy_hynix_cfg_jh[];
extern struct DRAM_CFG_PARAM lpddr4_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_100_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_667_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_2666_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_2666_ddrphy_cfg_xh[];
extern struct DRAM_CFG_PARAM lpddr4_2666_ddrphy_cfg_jh[];
extern struct DRAM_CFG_PARAM lpddr4_3200_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4_3733_ddrphy_cfg[];
extern struct DRAM_CFG_PARAM lpddr4x_phy_diff[];

uint32_t get_sizeof_ddr4_ddrphy_cfg(void);
uint32_t get_sizeof_ddr4_3200_ddrphy_cfg(void);
uint32_t get_sizeof_ddr4_2666_ddrphy_cfg(void);
uint32_t get_sizeof_ddr4_2400_ddrphy_cfg(void);
uint32_t get_sizeof_ddr4_1600_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4_ddrphy_hynix_cfg(void);
uint32_t get_sizeof_lpddr4_ddrphy_hynix_cfg_xh(void);
uint32_t get_sizeof_lpddr4_ddrphy_hynix_cfg_jh(void);
uint32_t get_sizeof_lpddr4_100_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4_667_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4_2666_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4_3200_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4_3733_ddrphy_cfg(void);
uint32_t get_sizeof_lpddr4x_phy_diff(void);

/* pie */
extern struct DRAM_CFG_PARAM ddr4_phy_pie[];
extern struct DRAM_CFG_PARAM ddr4_1600_phy_pie[];
extern struct DRAM_CFG_PARAM ddr4_2666_phy_pie[];
extern struct DRAM_CFG_PARAM ddr4_2400_phy_pie[];
extern struct DRAM_CFG_PARAM lpddr4_phy_pie[];
extern struct DRAM_CFG_PARAM lpddr4_100_phy_pie[];
extern struct DRAM_CFG_PARAM lpddr4_667_phy_pie[];
extern struct DRAM_CFG_PARAM lpddr4_2666_phy_pie[];
extern struct DRAM_CFG_PARAM lpddr4_3200_phy_pie[];
extern struct DRAM_CFG_PARAM lpddr4_3733_phy_pie[];
uint32_t get_sizeof_ddr4_phy_pie(void);
uint32_t get_sizeof_ddr4_1600_phy_pie(void);
uint32_t get_sizeof_ddr4_2666_phy_pie(void);
uint32_t get_sizeof_ddr4_2400_phy_pie(void);
uint32_t get_sizeof_lpddr4_phy_pie(void);
uint32_t get_sizeof_lpddr4_100_phy_pie(void);
uint32_t get_sizeof_lpddr4_667_phy_pie(void);
uint32_t get_sizeof_lpddr4_2666_phy_pie(void);
uint32_t get_sizeof_lpddr4_3200_phy_pie(void);
uint32_t get_sizeof_lpddr4_3733_phy_pie(void);

void  lpddr4_read_dbi_cfg (uint32 data);
void lpddr4_write_dbi_cfg (uint32 data);
void lpddr4_mask_write_cfg (void);
void lpddr4_cfg_init(void);
void lpddr4_micron_dmem_reconfig_init(unsigned int freq,
	unsigned int part_number, unsigned int alter_para);
void lpddr4_hynix_dmem_reconfig_init(unsigned int freq,
	unsigned int part_number, unsigned int alter_para);
void lpddr4_samsung_dmem_reconfig_init(unsigned int freq,
	unsigned int part_number, unsigned int alter_para);

extern struct DRAM_CFG_PARAM lpddr4_mstr_x3_hynix[12];
extern struct DRAM_CFG_PARAM lpddr4_mstr_j3_hynix[12];
extern struct DRAM_CFG_PARAM lpddr4_mstr_micron[12];

#ifdef SPL_DDR_PKG
/* imem */
void write_data_to_bin(FILE *fp, short int *data, unsigned int len);

/* dmem */
void ddr4_dmem_micron_write_to_bin(char *file,  unsigned int index);
void lpddr4_dmem_write_to_bin(char *file, unsigned int index);
void ddr4_dmem_reconfig_init(unsigned int freq, unsigned int part_number);

/* ddrc */
void ddr4_ddrc_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number);
void lpddr4_ddrc_micron_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number, unsigned int alter_para);
void lpddr4_ddrc_hynix_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number, unsigned int alter_para);
void lpddr4_ddrc_samsung_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number, unsigned int alter_para);


/* ddrp */
void ddr4_ddrp_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number);
void lpddr4_ddrp_micron_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number, unsigned int alter_para);
void lpddr4_ddrp_hynix_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number, unsigned int alter_para);
void lpddr4_ddrp_samsung_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number, unsigned int alter_para);

/* pie */
void ddr4_pie_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number);
void lpddr4_pie_write_to_bin(char *file, unsigned int freq,
	unsigned int index, unsigned int part_number);

/* mstr */
void micron_mstr_write_to_bin(char *file, unsigned int index);
void x3_hynix_write_to_bin(char *file, unsigned int index);
void j3_hynix_write_to_bin(char *file, unsigned int index);
void ddr_address_map_to_bin(char *file, unsigned int index,
		uint32_t part_number);
int32_t hb_add_dqmap(char *file, enum boot_mode mode);
#endif

#endif
