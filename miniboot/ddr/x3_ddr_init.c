#include "x3_ddr.h"
#include <asm/arch/x2a_def.h>
#include "ddr.h"
#include "debug_tool.h"
#include <asm/arch/x2a_dev.h>
#include <asm/arch/x2_pinmux.h>
#include <scomp.h>
#include "hb_ddr_oem.h"
//uMCTRL feature

//'MC-initiated' requests

//'PHY-initiated' requests

//Training: �'PHY-Independent' training

//Guaranteed coherency for write-after-read (WAR) and read-after-write (RAW) hazards

//ZQ Reset feature through software

//Paging policy selectable  : Auto-precharge with each access

//automatic SDRAM power-down entry and exit caused by lack of transaction arrival for a programmable time

//automatic Clock Stop (mDDR/LPDDR2/LPDDR3/LPDDR4) entry and exit caused by lack of transaction arrival

//automatic uMCTL2 low power mode operation caused by lack of transaction arrival for a programmable time through the Hardware Low Power Interface

//automatic self-refresh entry and exit  caused by lack of transaction arrival for a programmable time

//self-refresh entry and exit under software control

//self-refresh entry and exit using dedicated DDRC hardware low power interface control

//explicit SDRAM mode register updates under software control

//Flexible address mapper logic to allow application specific mapping of row, column, bank, and rank bits

//Controller-generated auto-refreshes at programmable average intervals

//Ability to issue a refresh through direct software request


//IN multi-rank designs, an offset can be applied to each rank��s refresh timer to allow rank refreshes	to expire at different times

//Ability to group up to 8 controller-generated refreshes together to be issued consecutively (this reduces the frequency of page closings, increases overall efficiency)

//When LPDDR2/LPDDR3/LPDDR4 is used, selectable ability to perform per-bank refreshes rather than all-banks refreshes

//When DDR4 is used, fine granularity refresh can be selected


//defects
//The workaround is to toggle the RFSHCTL3.refresh_update_level register twice to avoid this issue. The value of refresh_burst is latched internally on the first toggle, and the uMCTL2 controller uses it on the second toggle

//DDR4 temperature controlled refresh is not supported when Retry is enabled (CRCPARCTRL1.crc_parity_retry_enable = 1



//DDR3/DDR4
//support for ZQ long calibration after self-refresh exit

//direct software request  ZQ short calibration

//programmable internal control for ZQ short calibration cycles



//LPDDR4

//direct software request control ZQ calibration

//programmable internal control for ZQ calibration cycles

//ZQ calibration after SR-Powerdown exit

#define DDR_REG_DUMP 0
#if DDR_REG_DUMP
extern uint32 umctl2_reg_dump_addr[];
extern uint32 phy_reg_dump_addr[];
extern uint64 umctl_reg_addr_base;
extern uint64 pub_reg_addr_base;
#endif

extern struct x2a_info_hdr g_binfo;
#ifdef YMODEM_BOOT
extern uint16 ddr_parameter[BL2_UART_DDR_PARAMTER_MAX_SIZE];
extern struct hb_ddr_uart_hdr ddr_hdr_uart;
#else
extern uint16 ddr_parameter[BL2_DDR_PARAMTER_MAX_SIZE];
extern struct hb_ddr_hdr ddr_hdr;
#endif

#if DDR4_ENABLED == 1
extern struct DRAM_TIMING_INFO ddr4_dram_timing;
extern struct DRAM_TIMING_MDF_INFO ddr4_dram_mdf_timing;

struct DMEM_DDR4_STRUCT *p_dmem_ddr4 = (struct DMEM_DDR4_STRUCT *)(DDRPHY_CFG_BASE +
	((DWC_DDRPHYA_DMEM_OFFSET) << 2));

struct DMEM_DDR4_2D_STRUCT *p_dmem_ddr4_2d = (struct DMEM_DDR4_2D_STRUCT *)(DDRPHY_CFG_BASE +
	((DWC_DDRPHYA_DMEM_OFFSET) << 2));

extern struct DMEM_DDR4_STRUCT_16B *p_dmem_ddr4_16b;
extern struct DMEM_DDR4_2D_STRUCT_16B *p_dmem_ddr4_2d_16b;
#endif

#if LPDDR4_ENABLED == 1
extern struct DRAM_TIMING_INFO lpddr4_dram_timing;
extern struct DRAM_TIMING_MDF_INFO lpddr4_dram_mdf_timing;

struct DMEM_LPDDR4_STRUCT *p_dmem_lpddr4 = (struct DMEM_LPDDR4_STRUCT *)(DDRPHY_CFG_BASE +
	((DWC_DDRPHYA_DMEM_OFFSET) << 2));
struct DMEM_LPDDR4_2D_STRUCT *p_dmem_lpddr4_2d = (struct DMEM_LPDDR4_2D_STRUCT *)(DDRPHY_CFG_BASE +
	((DWC_DDRPHYA_DMEM_OFFSET) << 2));
extern struct DMEM_LPDDR4_STRUCT_16B *p_dmem_lpddr4_16b;
extern struct DMEM_LPDDR4_2D_STRUCT_16B *p_dmem_lpddr4_2d_16b;

#endif

extern uint32 lpddr4_mrr (uint32 mr_rank, uint32 mr_addr);

void ddrc_qos_cfg(void);
void read_dbi_cfg (uint32 data);
void write_dbi_cfg (uint32 data);
void mask_write_cfg(uint32 data);
void ddr_inline_ecc_cfg (uint32 data, uint8 gran);
void address_map_config(uint32 ddr_type);
void address_map_config_warm(void);
void umctrl_reg_modify_adjust_ddr (void);
void dwc_ddrphy_phyinit_C_initPhyConfig (struct DRAM_CFG_PARAM *ddrphy_cfg, int num);
void dwc_ddrphy_train(void);
void dwc_ddrphy_phyinit_H_readMsgBlock (uint8 *cdd_rw_max_abs, uint8 *cdd_ww_max_abs);
void dwc_ddrphy_phyinit_I_loadPIEImage(struct DRAM_CFG_PARAM *pie_cfg, int num);
void dwc_ddrphy_phyinit_J_enterMissionMode (void);
void test_entry_t(void);
extern uint32 sdram_info_detect (void);

unsigned int hb_som_type = SOM_TYPE_J3;
unsigned int hb_ddr_type = DDR_TYPE;
unsigned int hb_ddr_vendor = DDR_MANU_HYNIX;
unsigned int hb_ddr_freq = DDR_FREQC_2666;
unsigned int hb_ddr_index = 0;
unsigned int hb_ddr_part_number = 0;
unsigned int hb_ddr_inline_ecc_en = 0;
uint8 hb_ddr_ecc_map = 0;
uint8 hb_ddr_ecc_gran = 0;

uint32_t* p_DDR_Type = (uint32_t *)SAVED_DDR_TYPE_ADDR;
uint32_t* p_DDR_Vendor = (uint32_t *)SAVED_DDR_VENDOR_ADDR;
uint32_t* p_DDR_Datarate = (uint32_t *)SAVED_DDR_DATARATE_ADDR;
uint32_t* p_DDR_Partnumber = (uint32_t *)SAVED_DDR_PART_NUMBER;

struct BOARD_DDR_INFO board_ddr_info = {
	.datarate = DDR_DATARATE,
	.ddr_type = DDR_TYPE,
	.p_dram_timing = NULL,
	.p_dram_mdf_timing = NULL,
	.write_dbi_en = 0,
	.read_dbi_en = RD_DBI_EN,
	.inline_ecc_en = ECC_EN,
};
uint64 umctl_reg_addr_base = DDRC_CFG_BASE;
//struct UMCTL_REGS* p_umctl_reg = (struct UMCTL_REGS*)DDRC_CFG_BASE;
uint64 pub_reg_addr_base = DDRPHY_CFG_BASE;
//struct	PUB_REGS* p_pub_reg = (struct	PUB_REGS*)DDRPHY_CFG_BASE;

struct DDRC_INFO ddrc_info = {
	.umctl_reg_addr_base = DDRC_CFG_BASE,
	.p_umctl_reg = (struct UMCTL_REGS*)(DDRC_CFG_BASE),
	.pub_reg_addr_base = DDRPHY_CFG_BASE,
	.p_pub_reg = (struct	PUB_REGS*)DDRPHY_CFG_BASE,
};

// ddrpll_freq_ctrl [11:0] ddrpll_fbdiv; [17:12] ddrpll_refdiv; [22:20] ddrpll_postdiv1; [26:24] ddrpll_postdiv2;
//ddrpll_pd_ctrl [0] ddrpll_pd; [4] ddrpll_dsmpd; [5] ddrpll_dacpd; [8] ddrpll_foutpostdivpd; [12] ddrpll_foutvcopd; [13] ddrpll_fout4phasepd; [16] ddrpll_bypass
//ddrpll_status [0] ddrpll_lock
//ddrpll_frac [23:0] ddrpll_frac
struct DDRPLL_CFG ddrpll_cfg_2133 = {
	.frac = 0xDE0000,
	.fbdiv = 88,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_1866 = {
	.frac = 0xCA0000,
	.fbdiv = 77,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_1600 = {
	.frac = 0xA80000,
	.fbdiv = 66,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_1466 = {
	.frac = 0x140000,
	.fbdiv = 61,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_1333 = {
	.frac = 0x780000,
	.fbdiv = 55,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_1200 = {
	.frac = 0x0,
	.fbdiv = 50,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_1066 = {
	.frac = 0x520000,
	.fbdiv = 44,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_932 = {
	.frac = 0xD40000,
	.fbdiv = 38,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_800 = {
	.frac = 0x350000,
	.fbdiv = 33,
	.refdiv = 1,
	.postdiv1 = 1,
	.postdiv2 = 1,
	.bypass = 0
};
struct DDRPLL_CFG ddrpll_cfg_667 = {
	.frac = 0x0,
	.fbdiv = 222,
	.refdiv = 2,
	.postdiv1 = 4,
	.postdiv2 = 1,
	.bypass = 1
};
struct DDRPLL_CFG ddrpll_cfg_100 = {
	.frac = 0x0,
	.fbdiv = 34,
	.refdiv = 2,
	.postdiv1 = 4,
	.postdiv2 = 1,
	.bypass = 1
};

void ddrpll_power_down(void) {
    SETREG32(DDRPLL_PD_CTRL, 0x3111);
//	while(!(reg32_read(DDRSYS_CLKOFF_STA) & 0x1));
}

void ddrpll_power_up(void) {
	// Use FRAC mode.
    //SETREG32(DDRPLL_PD_CTRL, 0x3000);
	reg32_bits_write(DDRPLL_PD_CTRL, 0, 16, 0x3000);
}

void ddr_pll_cfg (struct DDRPLL_CFG * p_ddrpll_cfg)
{
	SETREG32(DDRPLL_FRAC, p_ddrpll_cfg->frac);
	SETREG32(DDRPLL_FREQ_CTRL, (p_ddrpll_cfg->postdiv2 <<24) | (p_ddrpll_cfg->postdiv1 << 20) | (p_ddrpll_cfg->refdiv << 12) | p_ddrpll_cfg->fbdiv);
	SETREG32(DDRPLL_PD_CTRL, GETREG32(DDRPLL_PD_CTRL) | (p_ddrpll_cfg->bypass << 16));
}
void ddrpll_lock_polling(void) {
	do{
		udelay(10);
	}while ((0x1 & GETREG32(DDRPLL_STATUS)) == 0);
	udelay(10);
}

#if DDR_REG_DUMP
void ddr_umctl2_reg_dump(void)
{
	uint32 i = 0;
	uint32 reg_value = 0;
	uint32 reg_addr = 0;
	//uint32 reg_num = 0;
	//reg_num = ARRAY_SIZE(phy_reg_dump_addr);

	//for (i = 0; i < reg_num; i++)
	i = 0;
	while(LIST_END_ADDR != umctl2_reg_dump_addr[i])
	{
		reg_addr = umctl_reg_addr_base + umctl2_reg_dump_addr[i];
		reg_value = reg32_read((uint64)reg_addr);
		printf("address : 0x%08x; value : 0x%08x.\n", reg_addr, reg_value);
		i++;
	}
}

void ddr_phy_reg_dump(void)
{
	uint32 i = 0;
	uint32 reg_value = 0;
	uint32 reg_addr = 0;
	//uint32 reg_num = 0;
	//reg_num = ARRAY_SIZE(phy_reg_dump_addr);

	SETREG32(pub_reg_addr_base + 0x340000,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
	//for (i = 0; i < reg_num; i++)
	i = 0;
	while(LIST_END_ADDR != phy_reg_dump_addr[i])
	{
		reg_addr = pub_reg_addr_base + phy_reg_dump_addr[i];
		reg_value = reg32_read((uint64)reg_addr);
		printf("address : 0x%08x; value : 0x%08x.\n", reg_addr, reg_value);
		i++;
	}
	SETREG32(pub_reg_addr_base + 0x340000,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}
#endif

void dram_pll_init(void)
{

	/* struct DDRPLL_CFG *p_ddrpll_cfg = &ddrpll_cfg_2133; */
	struct DDRPLL_CFG *p_ddrpll_cfg = board_ddr_info.p_ddrpll_cfg;

	/* pll power down */
	ddrpll_power_down();
	/* change pll seeting */
	ddr_pll_cfg(p_ddrpll_cfg);

	if ((&ddrpll_cfg_667 == p_ddrpll_cfg) || (&ddrpll_cfg_100 == p_ddrpll_cfg))
		SETREG32(DDRSYS_CLK_DIV_SEL, 0x3);
	else
		SETREG32(DDRSYS_CLK_DIV_SEL, 0x1);

	/* pll power up */
	ddrpll_power_up();
	/* polling lock status */
	ddrpll_lock_polling();
	/* while ((0x1 & GETREG32(DDRPLL_STATUS)) == 0); */
}

void lpddr_freq_related_info_modify(void)
{
	#if LPDDR4_ENABLED == 1
#ifndef MULTI_FILES
	struct DRAM_TIMING_MDF_INFO *dram_timing_mdf = board_ddr_info.p_dram_mdf_timing;
#endif
	if (4266 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = NULL;
		dram_timing_mdf->dmem_2d_reconfig = NULL;
		dram_timing_mdf->p_ddrc_mdf_param = NULL;
		dram_timing_mdf->ddrc_mdf_param_num = 0;
		dram_timing_mdf->p_ddrphy_mdf_param = NULL;
		dram_timing_mdf->ddrphy_mdf_param_num = 0;
		dram_timing_mdf->p_pie_mdf_param = NULL;
		dram_timing_mdf->pie_mdf_param_num = 0;
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_2133;
	} else if (3733 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &lpddr4_dmem_reconfig_3733;
		dram_timing_mdf->dmem_2d_reconfig = &lpddr4_dmem_2d_reconfig_3733;
		dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_3733_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_3733_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &lpddr4_3733_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_lpddr4_3733_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &lpddr4_3733_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_lpddr4_3733_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1866;
	} else if (3200 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &lpddr4_dmem_reconfig_3200;
		dram_timing_mdf->dmem_2d_reconfig = &lpddr4_dmem_2d_reconfig_3200;
		dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_3200_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_3200_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &lpddr4_3200_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_lpddr4_3200_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &lpddr4_3200_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_lpddr4_3200_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1600;
	} else if (2666 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &lpddr4_dmem_reconfig_2666;
		dram_timing_mdf->dmem_2d_reconfig = &lpddr4_dmem_2d_reconfig_2666;

		#if defined(WARM_BOOT_SPL)
		if (hb_ddr_part_number == H9HCNNN8KUMLHR) {
			dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_2666_ddrc_cfg_xh[0];
			dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_2666_ddrc_cfg_xh();
		} else if (hb_ddr_part_number == H9HCNNNBKUMLHE) {
			dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_2666_ddrc_cfg_jh[0];
			dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_2666_ddrc_cfg_jh();
		} else {
			dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_2666_ddrc_cfg[0];
			dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_2666_ddrc_cfg();
		}
		#else
		dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_2666_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_2666_ddrc_cfg();
		#endif
		dram_timing_mdf->p_ddrphy_mdf_param = &lpddr4_2666_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_lpddr4_2666_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &lpddr4_2666_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_lpddr4_2666_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1333;
	} else if (667 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &lpddr4_dmem_reconfig_667;
		dram_timing_mdf->dmem_2d_reconfig = &lpddr4_dmem_2d_reconfig_667;
		dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_667_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_667_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &lpddr4_667_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_lpddr4_667_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &lpddr4_667_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_lpddr4_667_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_667;
	} else if (100 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &lpddr4_dmem_reconfig_667;
		dram_timing_mdf->dmem_2d_reconfig = &lpddr4_dmem_2d_reconfig_667;
		dram_timing_mdf->p_ddrc_mdf_param = &lpddr4_100_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_lpddr4_100_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &lpddr4_100_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_lpddr4_100_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &lpddr4_100_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_lpddr4_100_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_100;
	} else {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = NULL;
		dram_timing_mdf->dmem_2d_reconfig = NULL;
		dram_timing_mdf->p_ddrc_mdf_param = NULL;
		dram_timing_mdf->ddrc_mdf_param_num = 0;
		dram_timing_mdf->p_ddrphy_mdf_param = NULL;
		dram_timing_mdf->ddrphy_mdf_param_num = 0;
		dram_timing_mdf->p_pie_mdf_param = NULL;
		dram_timing_mdf->pie_mdf_param_num = 0;
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_2133;
	}
	#endif
}
void ddr_freq_related_info_modify(void)
{
	#if DDR4_ENABLED == 1
#ifndef MULTI_FILES
	struct DRAM_TIMING_MDF_INFO *dram_timing_mdf = board_ddr_info.p_dram_mdf_timing;
#endif

	if (3200 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &ddr4_dmem_reconfig_3200;
		dram_timing_mdf->dmem_2d_reconfig = &ddr4_dmem_2d_reconfig_3200;
		dram_timing_mdf->p_ddrc_mdf_param = &ddr4_3200_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_ddr4_3200_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &ddr4_3200_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_ddr4_3200_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = NULL;
		dram_timing_mdf->pie_mdf_param_num = 0;
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1600;
	} else if (2666 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &ddr4_dmem_reconfig_2666;
		dram_timing_mdf->dmem_2d_reconfig = &ddr4_dmem_2d_reconfig_2666;
		if (hb_ddr_vendor == DDR_MANU_MICRON) {
			dram_timing_mdf->p_ddrc_mdf_param = &ddr4_2666_ddrc_cfg_micron[0];
			dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_ddr4_2666_ddrc_cfg_micron();
		} else if (hb_ddr_vendor == DDR_MANU_SAMSUNG) {
			dram_timing_mdf->p_ddrc_mdf_param = &ddr4_2666_ddrc_cfg_samsung[0];
			dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_ddr4_2666_ddrc_cfg_samsung();
		}
		dram_timing_mdf->p_ddrphy_mdf_param = &ddr4_2666_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_ddr4_2666_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &ddr4_2666_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_ddr4_2666_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1333;
	} else if (2400 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &ddr4_dmem_reconfig_2400;
		dram_timing_mdf->dmem_2d_reconfig = &ddr4_dmem_2d_reconfig_2400;
		dram_timing_mdf->p_ddrc_mdf_param = &ddr4_2400_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_ddr4_2400_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &ddr4_2400_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_ddr4_2400_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &ddr4_2400_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_ddr4_2400_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1200;
	} else if (1600 <= board_ddr_info.datarate) {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = &ddr4_dmem_reconfig_1600;
		dram_timing_mdf->dmem_2d_reconfig = &ddr4_dmem_2d_reconfig_1600;
		dram_timing_mdf->p_ddrc_mdf_param = &ddr4_1600_ddrc_cfg[0];
		dram_timing_mdf->ddrc_mdf_param_num = get_sizeof_ddr4_1600_ddrc_cfg();
		dram_timing_mdf->p_ddrphy_mdf_param = &ddr4_1600_ddrphy_cfg[0];
		dram_timing_mdf->ddrphy_mdf_param_num = get_sizeof_ddr4_1600_ddrphy_cfg();
		dram_timing_mdf->p_pie_mdf_param = &ddr4_1600_phy_pie[0];
		dram_timing_mdf->pie_mdf_param_num = get_sizeof_ddr4_1600_phy_pie();
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_800;
	} else {
		#ifndef MULTI_FILES
		dram_timing_mdf->dmem_reconfig = NULL;
		dram_timing_mdf->dmem_2d_reconfig = NULL;
		dram_timing_mdf->p_ddrc_mdf_param = NULL;
		dram_timing_mdf->ddrc_mdf_param_num = 0;
		dram_timing_mdf->p_ddrphy_mdf_param = NULL;
		dram_timing_mdf->ddrphy_mdf_param_num = 0;
		dram_timing_mdf->p_pie_mdf_param = NULL;
		dram_timing_mdf->pie_mdf_param_num = 0;
		#endif
		board_ddr_info.p_ddrpll_cfg = &ddrpll_cfg_1600;
	}
	#endif
}
void ddr_type_related_info_modify(void)
{
	struct DRAM_TIMING_MDF_INFO *dram_timing_mdf = NULL;
#ifndef MULTI_FILES
	if (hb_ddr_type == DDR_TYPE_LPDDR4) {
		#if LPDDR4_ENABLED == 1
		p_dmem_lpddr4_16b = (struct DMEM_LPDDR4_STRUCT_16B *)phyinit_dmem_lpddr4;
		p_dmem_lpddr4_2d_16b = (struct DMEM_LPDDR4_2D_STRUCT_16B *)phyinit_dmem_lpddr4_2D;
		#endif
	} else {
		#if DDR4_ENABLED == 1
		p_dmem_ddr4_16b = (struct DMEM_DDR4_STRUCT_16B *)phyinit_dmem_ddr4;
		p_dmem_ddr4_2d_16b = (struct DMEM_DDR4_2D_STRUCT_16B *)phyinit_dmem_ddr4_2D;
		#endif
	}
#endif

	if (LPDDR4 == board_ddr_info.ddr_type) {
		#if LPDDR4_ENABLED == 1
#ifndef MULTI_FILES
		board_ddr_info.p_dram_timing = &lpddr4_dram_timing;
		board_ddr_info.p_dram_mdf_timing = &lpddr4_dram_mdf_timing;
		dram_timing_mdf = board_ddr_info.p_dram_mdf_timing;
		if(dram_timing_mdf!=NULL){
		dram_timing_mdf->p_ddrphy_mdf_io_param = NULL;
		dram_timing_mdf->ddrphy_mdf_io_param_num = 0;
		}
#endif
		lpddr_freq_related_info_modify();
		#endif
	} else if (LPDDR4X == board_ddr_info.ddr_type) {
		#if LPDDR4_ENABLED == 1
#ifndef MULTI_FILES
		board_ddr_info.p_dram_timing = &lpddr4_dram_timing;
		board_ddr_info.p_dram_mdf_timing = &lpddr4_dram_mdf_timing;
		dram_timing_mdf = board_ddr_info.p_dram_mdf_timing;
		if(dram_timing_mdf!=NULL){
		dram_timing_mdf->p_ddrphy_mdf_io_param = &lpddr4x_phy_diff[0];
		dram_timing_mdf->ddrphy_mdf_io_param_num = get_sizeof_lpddr4x_phy_diff();
		}
#endif
		lpddr_freq_related_info_modify();
		#endif
	} else if (DDR4 == board_ddr_info.ddr_type) {
		#if DDR4_ENABLED == 1
#ifndef MULTI_FILES
		board_ddr_info.p_dram_timing = &ddr4_dram_timing;
		board_ddr_info.p_dram_mdf_timing = &ddr4_dram_mdf_timing;
		dram_timing_mdf = board_ddr_info.p_dram_mdf_timing;
		if(dram_timing_mdf!=NULL){
		dram_timing_mdf->p_ddrphy_mdf_io_param = NULL;
		dram_timing_mdf->ddrphy_mdf_io_param_num = 0;
		}
#endif
		ddr_freq_related_info_modify();
		#endif
	} else {
		dram_timing_mdf->p_ddrphy_mdf_io_param = NULL;
		dram_timing_mdf->ddrphy_mdf_io_param_num = 0;
		printf("*WRONG DDR TYPE*\n");
	}
}


#if !defined(WARM_BOOT_SPL)
void dly_timing_update(uint8 cdd_rw_max_abs, uint8 cdd_ww_max_abs)
{
	uint32 bl = 16;
	uint32 temp, rd2wr_old, wr2rd_old, rd2wr_new, wr2rd_new, txdqsdly_coarse,
		txdqsdly_fine, trained_txdqsdly, tctrl_delay, t_wrdata_delay, value;
	DDR_LOG(DDR_LOG_INFO, "dly_timing_update\n");
	reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x1);

	//uMCTL2_DRAMTMG2 update
	temp = reg32_read(umctl_reg_addr_base + uMCTL2_DRAMTMG2);
	rd2wr_old = (temp & 0x3F00) >> 8;//bit[13:8]: rd2wr //
	wr2rd_old = (temp & 0x3F);//bit[5:0]: wr2rd //
	rd2wr_new = ((cdd_rw_max_abs + 0x1) >> 1) + rd2wr_old;
	wr2rd_new = ((cdd_ww_max_abs + 0x1) >> 1) + wr2rd_old;
	reg32_write(umctl_reg_addr_base + uMCTL2_DRAMTMG2, (rd2wr_new <<8) | (wr2rd_new) |
		(temp & 0xFFFFFC0C0));

	//uMCTL2_DFITMG0 uMCTL2_DFITMG1 update
	temp = reg32_read(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p0);
	txdqsdly_coarse = (temp & 0x3C0) >> 6;
	txdqsdly_fine = temp & 0x1F;

	trained_txdqsdly = ((txdqsdly_coarse << 5) +
		txdqsdly_fine + 0x3F) >> 6;

	temp = reg32_read(umctl_reg_addr_base + uMCTL2_DFITMG0);
	tctrl_delay = (temp & 0x1F000000) >> 24;

	t_wrdata_delay = (tctrl_delay << 1) + 6 + (bl>>1) + trained_txdqsdly;
	if (((temp & 0x8000) >> 15) == 1) {
		t_wrdata_delay += 0x1;
	}
	temp = reg32_read(umctl_reg_addr_base + uMCTL2_DFITMG1);
	value = ((t_wrdata_delay + 1) >>1 ) << 16;
	value |= (temp & 0xFFE0FFFF);
	reg32_write(umctl_reg_addr_base + uMCTL2_DFITMG1, value);

	reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x0);
}
#endif

void auto_refresh_cfg (uint32 enable)
{
	uint64 reg_addr = 0;
	reg_addr = umctl_reg_addr_base + uMCTL2_RFSHCTL3;
	reg32_bits_write(reg_addr, 0, 1, (~enable));
}

/*******************************************************************************/
//port_num: axi port number
//enable: 1, enable access; 0, disable access;
/*******************************************************************************/
void axi_port_cfg (uint32 port_num, uint32 enable)
{
	uint64 reg_addr = 0;
	reg_addr = umctl_reg_addr_base + uMCTL2_PCTRL_0 + 0xB0 * port_num;
	reg32_write(reg_addr, enable);
}


void dwc_ddrphy_phyinit_C_initPhyConfig (struct DRAM_CFG_PARAM *ddrphy_cfg, int num);
void dwc_ddrphy_manual_set(void);
void dwc_ddrphy_phyinit_H_readMsgBlock (uint8 *cdd_rw_max_abs, uint8 *cdd_ww_max_abs);
void dwc_ddrphy_phyinit_I_loadPIEImage(struct DRAM_CFG_PARAM *pie_cfg, int num);
void dwc_ddrphy_phyinit_J_enterMissionMode (void);
void test_entry_t(void);
void Manual_Read_Write_Test(void);
unsigned int is_ddr_init(void);
void lpddr4_restore_param(uint32 restore_ctrl_reg);
void ddr_acdc_test(void);
void dma_write_test(void);
void hobot_snps_scrub_test(uint32 sbr_write_en, uint8 map,  uint32 sbr_cyc_en);

#ifndef MULTI_FILES
static void hb_dram_timing_init(void)
{
#if DDR4_ENABLED == 1
	ddr4_dram_timing.ddrc_cfg_num = get_sizeof_ddr4_ddrc_cfg();
	ddr4_dram_timing.ddrphy_cfg_num = get_sizeof_ddr4_ddrphy_cfg();
	ddr4_dram_timing.ddrphy_pie_num = get_sizeof_ddr4_phy_pie();
#endif

#if LPDDR4_ENABLED == 1
	lpddr4_dram_timing.ddrc_cfg_num = get_sizeof_lpddr4_ddrc_cfg();
	lpddr4_dram_timing.ddrphy_cfg_num = get_sizeof_lpddr4_ddrphy_cfg();
	lpddr4_dram_timing.ddrphy_pie_num = get_sizeof_lpddr4_phy_pie();
#endif
}
#endif

// void ddr_frequent_init()
static uint32 hb_ddr_default_freq_get(void)
{
	if ((hb_ddr_type == DDR_TYPE_DDR4) && (hb_ddr_vendor == DDR_MANU_MICRON))
		return 3200;

	if ((hb_ddr_type == DDR_TYPE_LPDDR4) && (hb_ddr_vendor == DDR_MANU_SAMSUNG))
		return 3200;

	return DDR_DATARATE;
}

void dram_frequency_init(void)
{
	uint32 ddr_freq = DDR_FREQ_SEL(g_binfo.board_id);
	DEBUG_LOG("board id = %02x\n", g_binfo.board_id);

	switch (ddr_freq) {
	case AUTO_DETECTION:
		ddr_freq = hb_ddr_default_freq_get();
		break;
	case DDR_FREQC_667:
		ddr_freq = 667;
		break;
	case DDR_FREQC_1600:
		ddr_freq = 1600;
		break;
	case DDR_FREQC_2133:
		ddr_freq = 2133;
		break;
	case DDR_FREQC_2400:
		ddr_freq = 2400;
		break;
	case DDR_FREQC_2666:
		ddr_freq = 2666;
		break;
	case DDR_FREQC_3200:
		ddr_freq = 3200;
		break;
	case DDR_FREQC_3733:
		ddr_freq = 3733;
		break;
	case DDR_FREQC_4266:
		ddr_freq = 4266;
		break;

	default:
		ddr_freq = 2666;
		break;
	}
	board_ddr_info.datarate = ddr_freq;
	hb_ddr_freq = ddr_freq;
	DEBUG_LOG("ddr daterate: %d\n", ddr_freq);
}

/* auto detection */
static uint32 hb_efuse_ddr_type_get(void) {
	unsigned int value = 0;
	unsigned int ddr_type = 0;

	DEBUG_LOG("***** using efuse ddr type ******\n");

	/* get efuse ddr type: bank28 */
	value = scomp_read_sw_efuse_bnk(EFS_NS, 28);
	if (((value >> 0x4) & 0xf) == 0)
		return DDR_TYPE;

	/* using efuse ddr type */
	ddr_type = DDR_TYPE_EFUSE_SEL(value);
	switch (ddr_type) {
	case DDR_TYPE_EFUSE_LPDDR4:
		ddr_type = DDR_TYPE_LPDDR4;
		break;
	case DDR_TYPE_EFUSE_DDR4:
		ddr_type = DDR_TYPE_DDR4;
		break;
	case DDR_TYPE_EFUSE_LPDDR4X:
		ddr_type = DDR_TYPE_LPDDR4X;
		break;
	default:
		ddr_type = DDR_TYPE_LPDDR4;
		break;
	}

	return ddr_type;
}

// unsigned int hb_efuse_ddr_type(void)
//{
//	return DDR_TYPE_LPDDR4;
//}

void hb_ddr_type_init(uint32_t boot_src)
{
#if defined(SPL_LPDDR4)
	board_ddr_info.ddr_type = DDR_TYPE_LPDDR4;
#elif defined(SPL_LPDDR4X)
	board_ddr_info.ddr_type = DDR_TYPE_LPDDR4X;
#elif defined(SPL_DDR4)
	board_ddr_info.ddr_type = DDR_TYPE_DDR4;
#elif defined(SPL_DDR3L)
	board_ddr_info.ddr_type = DDR_TYPE_DDR3L;
#else
	uint32 ddr_type = 0;

	if ((boot_src != PIN_2ND_AP) && (boot_src != PIN_2ND_UART)) {
		ddr_type = DDR_TYPE_SEL(g_binfo.board_id);

		switch (ddr_type) {
		case AUTO_DETECTION:
			board_ddr_info.ddr_type = hb_efuse_ddr_type_get();
			break;
		case DDR_TYPE_LPDDR4:
		case DDR_TYPE_LPDDR4X:
		case DDR_TYPE_DDR4:
		case DDR_TYPE_DDR3L:
			board_ddr_info.ddr_type = ddr_type;
			break;

		default:
			board_ddr_info.ddr_type = DDR_TYPE_LPDDR4;
			break;
		}

#if !defined(WARM_BOOT_SPL)
		char *ddr_type_str[] = {
			"N/A",
			"LPDDR4",
			"LPDDR4X",
			"DDR4",
			"DDR3L",
		};

		if(board_ddr_info.ddr_type < ARRAY_SIZE(ddr_type_str)) {
			DEBUG_LOG("ddr_type = %d (%s)\n", board_ddr_info.ddr_type, ddr_type_str[board_ddr_info.ddr_type]);
		} else {
			DEBUG_LOG("ddr_type = %d\n", board_ddr_info.ddr_type);
		}
#endif
	} else {
		/* uart and ap mode using efuse ddr type */
		board_ddr_info.ddr_type = hb_efuse_ddr_type_get();
	}
#endif

	hb_ddr_type = board_ddr_info.ddr_type;
}

uint32_t hb_efuse_ddr_vendor_get(uint32_t reg)
{
	unsigned int value = 0;
	unsigned int ddr_vender = 0;

	DEBUG_LOG("***** using efuse vendor type *****\n");

	/* get efuse ddr type: bank28 */
	value = scomp_read_sw_efuse_bnk(EFS_NS, 28);
	if (((value >> 0x4) & 0xf) == 0)
		return DDR_VENDOR_DEFAULT;

	/* using efuse ddr type */
	ddr_vender = DDR_VENDER_EFUSE_SEL(value);
	switch (ddr_vender) {
	case DDR_VENDER_EFUSE_HYNIX:
		ddr_vender = DDR_MANU_HYNIX;
		break;
	case DDR_VENDER_EFUSE_MICRON:
		ddr_vender = DDR_MANU_MICRON;
		break;
	case DDR_VENDER_EFUSE_SAMSUNG:
		ddr_vender = DDR_MANU_SAMSUNG;
		break;
	default:
		ddr_vender = DDR_VENDOR_DEFAULT;
		break;
	}

	return ddr_vender;
}

uint32_t hb_ddr_vendor_init(void)
{
	uint32_t ddr_vendor;

#if defined(SPL_DDR_VENDOR_MICRON)
	ddr_vendor = DDR_MANU_MICRON;
#elif defined(SPL_DDR_VENDOR_HYNIX)
	ddr_vendor = DDR_MANU_HYNIX;
#elif defined(SPL_DDR_VENDOR_SAMSUNG)
	ddr_vendor = DDR_MANU_SAMSUNG;
#else
	uint32_t reg = readl(STRAP_PIN_REG);
	uint32_t boot_src, ddr_manufacture;

	/* use boot strap to decide spl source */
	boot_src = PIN_2NDBOOT_SEL(reg);

	if ((boot_src != PIN_2ND_AP) && (boot_src != PIN_2ND_UART)) {
		ddr_manufacture = DDR_MANUF_SEL(g_binfo.board_id);

		switch (ddr_manufacture) {
		case AUTO_DETECTION:
			ddr_vendor = hb_efuse_ddr_vendor_get(reg);
			break;
		case DDR_MANU_HYNIX:
			ddr_vendor = DDR_MANU_HYNIX;
			break;
		case DDR_MANU_MICRON:
			ddr_vendor = DDR_MANU_MICRON;
			break;
		case DDR_MANU_SAMSUNG:
			ddr_vendor = DDR_MANU_SAMSUNG;
			break;
		default:
			ddr_vendor = DDR_MANU_HYNIX;
			break;
		}
	} else {
		ddr_vendor = hb_efuse_ddr_vendor_get(reg);
	}
#endif

	hb_ddr_vendor = ddr_vendor;

	return ddr_vendor;
}

static void hb_efuse_som_type_init(void)
{
	unsigned int value = 0;
	unsigned int som_type = 0;

	/* get efuse value: bank28 */
	value = scomp_read_sw_efuse_bnk(EFS_NS, 28);

	/* using efuse som type */
	som_type = SOM_TYPE_EFUSE_SEL(value);
	switch (som_type) {
	case EFUSE_SOM_TYPE_X3:
		hb_som_type = SOM_TYPE_X3;
		break;
	case EFUSE_SOM_TYPE_J3:
		hb_som_type = SOM_TYPE_J3;
		break;
	default:
		hb_som_type = SOM_TYPE_J3;
		break;
	}
}

#if defined(MULTI_FILES) && !defined(WARM_BOOT_SPL)
static void hb_ddr_parameter_preload(void)
{
#ifdef YMODEM_BOOT
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

	/* Load ddr parameter firmware */
	g_dev_ops.read(0, fw_dst_laddr, 0);
	memcpy(&ddr_hdr_uart, ddr_parameter, sizeof(struct hb_ddr_uart_hdr));
#else
	uint32 ecc_option = 0;

	if (g_dev_ops.pre_read) {
		g_dev_ops.pre_read(&g_binfo, 0, 0, NULL, NULL);
	}

	ecc_option = ECC_CONFIG_SEL(g_binfo.board_id);
	if ((ecc_option > 0) && (ecc_option < 5)) {
		hb_ddr_ecc_gran = ddr_hdr.ecc_gran[ecc_option - 1] & 0xff;
		hb_ddr_ecc_map = ddr_hdr.ecc_map[ecc_option - 1] & 0xff;
	} else {
		hb_ddr_ecc_gran = 0;
		hb_ddr_ecc_map = 0;
	}
	DEBUG_LOG("ddr_hdr.ecc_gran: 0x%x\n", hb_ddr_ecc_gran);
	DEBUG_LOG("ddr_hdr.ecc_map: 0x%x\n", hb_ddr_ecc_map);
#endif
}
#endif

struct ddr_freq ddr_freq_valid_list[] = {
	{ 100, DDR_FREQC_100 },
	{ 667, DDR_FREQC_667 },
	{ 1600, DDR_FREQC_1600 },
	{ 2133, DDR_FREQC_2133 },
	{ 2400, DDR_FREQC_2400 },
	{ 2666, DDR_FREQC_2666 },
	{ 3200, DDR_FREQC_3200 },
	{ 3733, DDR_FREQC_3733 },
	{ 4266, DDR_FREQC_4266 },
};

unsigned int ddr_freq_macro_value_get(unsigned int value)
{
	unsigned int i = 0, ddr_freq = 0;
	unsigned int leng = ARRAY_SIZE(ddr_freq_valid_list);

	for (i = 0; i< leng; i++) {
		if (ddr_freq_valid_list[i].value == value) {
			ddr_freq = ddr_freq_valid_list[i].micron_value;
			break;
		}
	}

	if (i >= leng)
		ddr_freq = DDR_FREQC_2666;

	return ddr_freq;
}


static unsigned int hb_ddr_part_number_get(void)
{
	unsigned int part_number = 0;

	if (hb_ddr_type == DDR_TYPE_DDR4) {
		if (hb_ddr_vendor == DDR_MANU_MICRON)
			part_number = MT40A256M16LY;
		else if (hb_ddr_vendor == DDR_MANU_SAMSUNG)
			part_number = K4A8G165WC;
		else
			part_number = MT40A256M16LY;
	} else if (hb_ddr_type == DDR_TYPE_LPDDR4) {
		if (hb_ddr_vendor == DDR_MANU_HYNIX) {
			if (hb_som_type == SOM_TYPE_X3)
				part_number = H9HCNNN8KUMLHR;
			else if (hb_som_type == SOM_TYPE_J3)
				part_number = H9HCNNNBKUMLHE;
		} else if (hb_ddr_vendor == DDR_MANU_MICRON) {
			part_number = MT53D1024M32D4DT;
		} else if (hb_ddr_vendor == DDR_MANU_SAMSUNG) {
			part_number = K4F8E304HBMGCJ;
		} else {
			part_number = H9HCNNNBKUMLHE;
		}
	}

	return part_number;
}

#ifdef MULTI_FILES
static void hb_ddr_para_query(void)
{
#ifndef YMODEM_BOOT
	unsigned int index = 0;
	unsigned int count = ddr_hdr.count;
	unsigned int ddr_freq = 0;
	bool para_valid = false;
	unsigned int alter_para = ALTER_CONFIG_SEL(g_binfo.board_id);
	unsigned int part_number = hb_ddr_part_number;

	ddr_freq = ddr_freq_macro_value_get(hb_ddr_freq);

	/* checking DDR parameters */
	for (index = 0; index < count; index++) {
		if (ddr_hdr.ddr[index].ddr_freq == ddr_freq &&
			ddr_hdr.ddr[index].part_number == part_number) {
			para_valid = true;
			hb_ddr_index = index;
			break;
		}
	}

	/* checking alternative DDR parameter */
	if ((ALTERNATIVE_ENABLE == alter_para) && (para_valid == true)) {
		para_valid = false;
		for (index = hb_ddr_index + 1; index < count; index++) {
			if (ddr_hdr.ddr[index].ddr_freq == ddr_freq &&
				ddr_hdr.ddr[index].part_number == part_number) {
				para_valid = true;
				hb_ddr_index = index;
				break;
			}
		}

		if (para_valid) {
			printf("using alternative ddr parameter!\n");
		} else {
			para_valid = true;
			printf("Can't find alternative ddr parameter, using default ddr paramter!\n");
		}
	}

	if (!para_valid) {
		printf("Error: can't find invalid ddr parameter!\n");
		while(1);
	}

	DEBUG_LOG("hb_ddr_index: %d\n", hb_ddr_index);
#else
	return;
#endif
}
#endif


#if LPDDR4_ENABLED == 1
extern struct DRAM_CFG_PARAM lpddr4_ddrc_cfg_hynix[];
extern struct DRAM_CFG_PARAM lpddr4_3200_ddrc_cfg_hynix[];
uint32 get_sizeof_lpddr4_ddrc_cfg_hynix(void);
uint32 get_sizeof_lpddr4_3200_ddrc_cfg_hynix(void);
#endif

void ddr_controller_cfg(struct DRAM_CFG_PARAM *ddrc_cfg, int num)
{
	int i = 0;
	struct DRAM_CFG_PARAM *ddrc_cfg_tmp = NULL;
	uint32 num_tmp = 0;
#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint32 fw_src_laddr = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.ddr_ddrc.addr;
	fw_src_len = ddr_hdr_uart.ddr_ddrc.size;

	DEBUG_LOG("uart load ddrc src_addr: %02x, load_addr: %02x, src_len: %02x\n",
		fw_src_laddr, (uint32_t)fw_dst_laddr, fw_src_len);
#else
	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].ddr_ddrc.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].ddr_ddrc.size;

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif

	ddrc_cfg_tmp = (struct DRAM_CFG_PARAM *)fw_dst_laddr;
	num_tmp = fw_src_len / sizeof(struct DRAM_CFG_PARAM);
	for (i = 0; i < num_tmp; i++) {
		reg32_write((ddrc_cfg_tmp->reg + umctl_reg_addr_base),ddrc_cfg_tmp->val);
		ddrc_cfg_tmp++;
	}
#else
	for (i = 0; i < num; i++) {
		reg32_write((ddrc_cfg->reg + umctl_reg_addr_base), ddrc_cfg->val);
		ddrc_cfg++;
	}

	if (hb_ddr_vendor == DDR_MANU_HYNIX) {
		#if LPDDR4_ENABLED == 1
		int hynix_num = 0;
		if(board_ddr_info.ddr_type == DDR_TYPE_LPDDR4) {
			hynix_num = get_sizeof_lpddr4_ddrc_cfg_hynix();
			ddrc_cfg = (struct DRAM_CFG_PARAM *)lpddr4_ddrc_cfg_hynix;
			for (i = 0; i < hynix_num; i++) {
				reg32_write((ddrc_cfg->reg + umctl_reg_addr_base),
					ddrc_cfg->val);
				ddrc_cfg++;
			}
			if(board_ddr_info.datarate==3200) {
				num = get_sizeof_lpddr4_3200_ddrc_cfg_hynix();
				ddrc_cfg = (struct DRAM_CFG_PARAM *)lpddr4_3200_ddrc_cfg_hynix;
				for (i = 0; i < num; i++) {
					reg32_write((ddrc_cfg->reg + umctl_reg_addr_base),
						ddrc_cfg->val);
					ddrc_cfg++;
				}
			}
		}
		#endif
	}

	DDR_LOG(DDR_LOG_INFO, "dly_timing_update\n");
	/* base 4266Mbps, other frequency need modify some parameters. */
	if (board_ddr_info.p_dram_mdf_timing->p_ddrc_mdf_param) {
		ddrc_cfg_tmp = board_ddr_info.p_dram_mdf_timing->p_ddrc_mdf_param;
		num_tmp = board_ddr_info.p_dram_mdf_timing->ddrc_mdf_param_num;
		if (0 != num_tmp) {
			for (i = 0; i < num_tmp; i++) {
				reg32_write((ddrc_cfg_tmp->reg + umctl_reg_addr_base),
					ddrc_cfg_tmp->val);
				ddrc_cfg_tmp++;
			}
		}
	}

#endif
}

void show_ddr_vendor_name(void)
{
	if(hb_ddr_vendor == DDR_MANU_MICRON)
		DEBUG_LOG("### MICRON DDR ###\n");
	else if(hb_ddr_vendor == DDR_MANU_HYNIX)
		DEBUG_LOG("### HYNIX DDR ###\n");
	else if(hb_ddr_vendor == DDR_MANU_SAMSUNG)
		DEBUG_LOG("### SAMSUNG DDR ###\n");
	else
		DEBUG_LOG("### DDR vendor unknown (%d) ###\n", hb_ddr_vendor);
}

#if 0
uint32_t hb_boot_cnt_init(uint32_t boot_src)
{
	uint32_t boot_cnt = 0;

#if defined(SPL_DDR_VENDOR_MICRON) || defined(SPL_DDR_VENDOR_HYNIX) || \
	 defined(SPL_DDR_VENDER_SAMSUNG)
	boot_cnt = 1;
#endif

#ifndef MULTI_FILES
	boot_cnt = 1;
#endif

#if defined(WARM_BOOT_SPL)
	boot_cnt = 1;
#endif
	if ((boot_src == PIN_2ND_AP) || (boot_src == PIN_2ND_UART))
		boot_cnt = 1;

	if (hb_ddr_type == DDR_TYPE_DDR4)
		boot_cnt = 1;

	return boot_cnt;
}
#endif

///////////////////////////////
uint32_t get_buf_cksum(uint32_t *pbuf, uint32_t bsize)
{
	uint32_t csum = 0;
	uint32_t i = 0;

	for (i = 0; i < bsize; i++) {
		csum += pbuf[i];
	}
	return csum;
}

#define CHECK_SUM_SAVE_START_ADDR		0x100000
#define CHECK_SUM_SAVE_END_ADDR			0x200000

#define CHECK_SUM_BLOCK_SIZE			0x100000

#define CHECK_SUM_START_ADDR			0x200000
#define CHECK_SUM_END_ADDR				0x7e000000

#define CHECK_SUM_START_BLOCK			(CHECK_SUM_START_ADDR/CHECK_SUM_BLOCK_SIZE)
#define CHECK_SUM_END_BLOCK				(CHECK_SUM_END_ADDR/CHECK_SUM_BLOCK_SIZE)

void check_check_sum(void)
{
	uint32_t status_err = 0;
	uintptr_t block = 0;
	uint32_t check_sum = 0;
	uint32_t *p_check_sum_save=(uint32_t *)CHECK_SUM_SAVE_START_ADDR;
	for(block=CHECK_SUM_START_BLOCK;block<CHECK_SUM_END_BLOCK;block++) {
		if(block%32 == 0) {
			printf("#");
		}
		check_sum = get_buf_cksum((uint32_t *)(block*CHECK_SUM_BLOCK_SIZE),CHECK_SUM_BLOCK_SIZE);
		if(p_check_sum_save[block] != check_sum) {
			printf("ERROR: address[0x%lx] (%ld MB) check sum error\n",
				(block*CHECK_SUM_BLOCK_SIZE),(block*CHECK_SUM_BLOCK_SIZE));
			status_err=1;
		}
	}
	while(status_err);
}
/////////////////////////////
void ddr_resume(void)
{
	unsigned int i;

	// 1. init ddr table/ID/Vendor/Type
#ifndef MULTI_FILES
	struct DRAM_TIMING_INFO *dram_timing = board_ddr_info.p_dram_timing;
#endif

#ifndef MULTI_FILES
	hb_dram_timing_init();
	ddr_p_dmem_init();
#endif

	hb_ddr_type = board_ddr_info.ddr_type = *p_DDR_Type;
	hb_ddr_vendor = *p_DDR_Vendor;
	hb_ddr_freq = board_ddr_info.datarate = *p_DDR_Datarate;
	hb_ddr_part_number = *p_DDR_Partnumber;
	printf("ddr_resume: ddr_type = %d, ddr_vendor=%d, ddr_freq=%d, ddr_part_number=0x%x\n",
		hb_ddr_type,hb_ddr_vendor,hb_ddr_freq,hb_ddr_part_number);

	ddr_type_related_info_modify();

#ifndef MULTI_FILES
	dram_timing = board_ddr_info.p_dram_timing;
#endif

	// 2. init ddr pll & clock
	printf("dram_pll_init\n");
	dram_pll_init();
	reg32_write(PLLCLK_SEL, (0x1<<12) | reg32_read(PLLCLK_SEL));
	reg32_write(DDRSYS_CLKEN_SET, 0x1);
	mdelay(1);

	// 3. power on & reset ddr_sys
	reg32_write(X2A_PMU_DDRSYS_CTRL, 0x1);
	reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0xfffffffe);

	// 4. enable 2th DFI interface. only for lpddr4
	if (DDR4 != board_ddr_info.ddr_type) {
		reg32_write(DDRC_PHY_DFI1_ENABLE, 0x1);
	}

	// 5. config ddr controller default setting
	reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x1);
	reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x1);
	do{
		udelay(10);
	}while ((reg32_read(umctl_reg_addr_base + uMCTL2_STAT) & 0x7));
	udelay(10);

	printf("config ddr controller restore setting\n");
	lpddr4_restore_param(1);
	ddrc_qos_cfg();

	// 6. enable auto refresh
	auto_refresh_cfg(ENABLE);

	// 7. De-assert the resets (core_uMCTL2_rstn and aresetn_n)
	reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0x0);

	reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x0);

	reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x120);

	reg32_write(umctl_reg_addr_base + uMCTL2_DERATEEN, 0x1404);

	reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x0);

	// set DFIMISC.dfi_init_compelete_en to 0
	reg32_bits_clear(umctl_reg_addr_base + uMCTL2_DFIMISC, 1);
	reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x1);
	do{
		udelay(10);
	}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_SWSTAT) & 0x1));
	udelay(10);

	printf("restore ddr setting from sram\n");
	// 8. restore controller & phy register from sram
#ifdef MULTI_FILES
	dwc_ddrphy_phyinit_C_initPhyConfig(NULL, 0);
#else
	dwc_ddrphy_phyinit_C_initPhyConfig(dram_timing->ddrphy_cfg,
		dram_timing->ddrphy_cfg_num);
#endif
	printf("config ddr phy restore setting\n");
	lpddr4_restore_param(0);
	mdelay(1);

	dwc_ddrphy_phyinit_J_enterMissionMode();

	reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x0);

	// set DFIMISC.dfi_init_start to 0
	reg32_bits_clear(umctl_reg_addr_base + uMCTL2_DFIMISC,0x20);

	reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x1);

	reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x0);

	//set DFIMISC.dfi_init_complete_en to 1
	reg32_bits_set(umctl_reg_addr_base + uMCTL2_DFIMISC,0x1);

	reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x1);

	//wait sw_done
	do{
		udelay(10);
	}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_SWSTAT) & 0x1));
	udelay(10);

	reg32_bits_clear(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x20);
	//wait operating mode = normal
	do{
		udelay(10);
	}while ((0x1 != (reg32_read(umctl_reg_addr_base + uMCTL2_STAT) & 0x7)));
	udelay(10);

	reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x0);

	//axi port en, all ports enable
	for (i = 0; i < AXI_PORT_NUM; i++) {
		axi_port_cfg(i, ENABLE);
	}
	printf("ddr_resume exit\n");
}

void auto_detect_test(void)
{
//			if((hb_ddr_part_number!=H9HCNNN8KUMLHR)||(sdram_info.cs_num!=1))
//			if((hb_ddr_part_number!=H9HCNNNBKUMLHE)||(sdram_info.cs_num!=1))
//			if((hb_ddr_part_number!=MT53D1024M32D4DT)||(sdram_info.cs_num!=2))
		if((hb_ddr_part_number!=K4F8E304HBMGCJ)||(sdram_info.cs_num!=1))
		{
			printf("error: auto detect failed (cnt=%d, part number = 0x%x, cs_num=%d)\n",
					reg32_read(X2A_DDR_AUTO_DETECT_REC), hb_ddr_part_number,sdram_info.cs_num);
			while(1);
		} else {
			uint32 cnt;
			cnt = reg32_read(X2A_DDR_AUTO_DETECT_REC);
			cnt++;
			reg32_write(X2A_DDR_AUTO_DETECT_REC, cnt);
			printf("PASS: auto detect success (cnt=%d, part number = 0x%x, cs_num=%d)\n",
				cnt, hb_ddr_part_number,sdram_info.cs_num);
			mdelay(1000);
			reg32_write(PMU_WDT_RST_TRIG_CTRL, (WDT_RST_SW_REQ|WDT_TRIG_PMU_EN));
		}

}

void inline_ecc_test (uint64 addr_start, uint64 addr_end, uint8 check_result, uint8 map);

void ddr_init(void)
{
	unsigned int do_ddr_init=0;
	do_ddr_init = is_ddr_init();
	if(!do_ddr_init) {
		ddr_resume();
		return;
	}

#ifndef WARM_BOOT_SPL
	uint32_t value, i;
	uint8 cdd_rw_max_abs, cdd_ww_max_abs;

	/* use boot strap to decide spl source */
	uint32_t reg = readl(STRAP_PIN_REG);
	uint32_t boot_src = PIN_2NDBOOT_SEL(reg);
	uint32_t boot_cnt = 1;
	uint32_t retry_flag = 0;

#ifndef MULTI_FILES
	struct DRAM_TIMING_INFO *dram_timing = NULL;
	hb_dram_timing_init();
	ddr_p_dmem_init();
#endif

	/* get ddr type */
	hb_ddr_type_init(boot_src);

	/* get efuse som type */
	hb_efuse_som_type_init();

	#ifdef MULTI_FILES
		/* ddr parameter preload */
		hb_ddr_parameter_preload();
	#endif

	hb_ddr_vendor = hb_ddr_vendor_init();
	hb_ddr_part_number = hb_ddr_part_number_get();

	do {
		boot_cnt = 1;
		sdram_info.mr5_value[0] = 0xFF;
		sdram_info.mr8_value[0] = 0xFF;

		for (; boot_cnt < 2; boot_cnt++) {
			if (boot_cnt == 0) {
				DEBUG_LOG("***************** ddr auto detect **************\n");

				#ifdef MULTI_FILES
				hb_ddr_part_number = PART_DEFAULT;
				board_ddr_info.datarate = 100;
				hb_ddr_vendor = DDR_MANU_MICRON;
				hb_ddr_freq = 100;

				hb_ddr_para_query();
				lpddr_freq_related_info_modify();
				#endif
			} else {
				if ((boot_src != PIN_2ND_AP) && (boot_src != PIN_2ND_UART)) {
					dram_frequency_init();
					show_ddr_vendor_name();
					board_ddr_info.inline_ecc_en = (ECC_CONFIG_SEL(g_binfo.board_id) > 0 ? 1 :0);

					#ifdef MULTI_FILES
					hb_ddr_para_query();
					#endif

					*p_DDR_Type = board_ddr_info.ddr_type;
					*p_DDR_Vendor = hb_ddr_vendor;
					*p_DDR_Datarate = board_ddr_info.datarate;
					*p_DDR_Partnumber = hb_ddr_part_number;
					hb_ddr_inline_ecc_en = board_ddr_info.inline_ecc_en;
				}
				ddr_type_related_info_modify();

				DEBUG_LOG("ddr_type = %d, ddr_vendor=%d, ddr_freq=%d\n",
					hb_ddr_type,hb_ddr_vendor, hb_ddr_freq);
			}

			#ifndef MULTI_FILES
			dram_timing = board_ddr_info.p_dram_timing;
			#endif

			if (boot_cnt == 1) {
				reg32_write(X2A_PMU_DDRSYS_CTRL, 0x0);
				reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0x1);
			}

			DEBUG_LOG("dram_pll_init\n");
			dram_pll_init();
			DDR_LOG(DDR_LOG_INFO, "dram_pll_init done\n");
			reg32_write(PLLCLK_SEL, (0x1<<12) | reg32_read(PLLCLK_SEL));
			reg32_write(DDRSYS_CLKEN_SET, 0x1);
			mdelay(1);

			/* After power-up: */
			reg32_write(X2A_PMU_DDRSYS_CTRL, 0x1);

			/*
			 * 1. Assert the core_ddrc_rstn and aresetn_n resets
			 * 2. Assert presetn
			 * 3. Start the clocks (pclk, core_ddrc_core_clk, aclk_n)
			 * 4. De-assert presetn once the clocks are active and stable
			 */
			reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0xfffffffe);

			/* enable 2th DFI interface. only for lpddr4 */
			if (DDR4 != board_ddr_info.ddr_type) {
				reg32_write(DDRC_PHY_DFI1_ENABLE, 0x1);
			}

			DDR_LOG(DDR_LOG_INFO, "DFI1_ENABLE: 0x%x\n", reg32_read(DDRC_PHY_DFI1_ENABLE));
			reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x1);
			reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x1);

			/*
			 * 5. Allow 128 cycles for synchronization of presetn to
			 * core_ddrc_core_clk and aclk domains and to permit
			 * initialization of end logic
			 */
			DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);
			do{
				udelay(10);
			}while ((reg32_read(umctl_reg_addr_base + uMCTL2_STAT) & 0x7));
			udelay(10);
			DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);

			/*
			 * 6. Initialize the registers
			 *	DFIMISC.dfi_init_complete_en must be set to 0
			 *	INIT0.skip_dram_init=2'b00
			 *	RFSHCTL3.dis_auto_refresh=1
			 *	PWRCTL.powerdown_en=0
			 *	PWRCTL.selfref_en=0
			 *	DERATEEN.derate_enable=0
			 *	ZQCTL0.dis_auto_zq=1
			 *	DFILPCFG0.dfi_lp_en_sr=0
			 *	(Note 1)a	MRCTRL0.sw_init_int=1
			 *	(Note 2)b
			 */
			#ifdef MULTI_FILES
			ddr_controller_cfg(NULL, 0);
			#else
			ddr_controller_cfg(dram_timing->ddrc_cfg, dram_timing->ddrc_cfg_num);
			#endif
			ddrc_qos_cfg();

			if ((hb_ddr_type == DDR_TYPE_LPDDR4)||(hb_ddr_type == DDR_TYPE_LPDDR4X)) {
				board_ddr_info.write_dbi_en = WR_DBI_EN_LPDDR4;
			} else {
				board_ddr_info.write_dbi_en = WR_DBI_EN_DDR4;
			}

			read_dbi_cfg(board_ddr_info.read_dbi_en);
			ddr_inline_ecc_cfg(board_ddr_info.inline_ecc_en, hb_ddr_ecc_gran);
			write_dbi_cfg(board_ddr_info.write_dbi_en);
			mask_write_cfg(1);

			DDR_LOG(DDR_LOG_INFO, "ddr_controller_cfg done\n");

			/* 7. De-assert the resets (core_uMCTL2_rstn and aresetn_n) */
			reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0x0);

			reg32_write(umctl_reg_addr_base + uMCTL2_DBG1, 0x0);
#ifdef CONFIG_SUPPORT_PALLADIUM
			reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x0);
#else
			if (LPDDR4 == board_ddr_info.ddr_type)
				reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x120);
			else if (DDR4 == board_ddr_info.ddr_type)
				reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x1A0);
			else
				reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x120);
#endif /* CONFIG_SUPPORT_PALLADIUM */
			reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x0);

			/* DFIMISC.dfi_init_compelete_en to 0 */
			reg32_bits_clear(umctl_reg_addr_base + uMCTL2_DFIMISC, (1 << 0));

			/* DFIMISC.dfi_frequency */
			/* reg32_bits_set(umctl_reg_addr_base + uMCTL2_DFIMISC, (1 << 12)); */
			/* diff with DV */
			reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x1);
			do{
				udelay(10);
			}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_SWSTAT) & 0x1));
			udelay(10);

			#ifdef MULTI_FILES
			dwc_ddrphy_phyinit_C_initPhyConfig(NULL, 0);
			#else
			dwc_ddrphy_phyinit_C_initPhyConfig(dram_timing->ddrphy_cfg,
				dram_timing->ddrphy_cfg_num);
			#endif

#ifndef CONFIG_PHY_TRAIN_SKIP
			if (boot_cnt != 0) {
#ifdef MULTI_FILES
				if (g_dev_ops.proc_start) {
					g_dev_ops.proc_start();
				}
#else
				if ((hb_ddr_type == DDR_TYPE_LPDDR4)||(hb_ddr_type == DDR_TYPE_LPDDR4X)) {
					#if LPDDR4_ENABLED == 1
					if (hb_ddr_vendor == DDR_MANU_HYNIX)
						lpddr4_hynix_dmem_reconfig_silicon(0, 0, 0);
					else if (hb_ddr_vendor == DDR_MANU_MICRON)
						lpddr4_micron_dmem_reconfig_silicon();
					#endif
				} else {
					#if DDR4_ENABLED == 1
					ddr4_dmem_reconfig_silicon();
					#endif
				}
#endif	/* MULTI_FILES */
				DDR_LOG(DDR_LOG_INFO, "dwc_ddrphy_train start\n");
				dwc_ddrphy_train();
			}
#else
			dwc_ddrphy_manual_set();
#endif

#ifndef CONFIG_PHY_TRAIN_SKIP
			if (boot_cnt != 0)
				dwc_ddrphy_phyinit_H_readMsgBlock(&cdd_rw_max_abs, &cdd_ww_max_abs);
#endif /* CONFIG_PHY_TRAIN_SKIP */

			#ifdef MULTI_FILES
			dwc_ddrphy_phyinit_I_loadPIEImage(NULL, 0);
			#else
			dwc_ddrphy_phyinit_I_loadPIEImage(dram_timing->ddrphy_pie, dram_timing->ddrphy_pie_num);
			#endif
			dwc_ddrphy_phyinit_J_enterMissionMode();

			reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x0);

			/* set DFIMISC.dfi_init_start to 0 */
			value = reg32_read(umctl_reg_addr_base + uMCTL2_DFIMISC) & (~0x20);
			reg32_write(umctl_reg_addr_base + uMCTL2_DFIMISC, value);

			if (boot_cnt != 0) {
				// CDD read back, config uMCTL
				#ifndef CONFIG_PHY_TRAIN_SKIP
				dly_timing_update(cdd_rw_max_abs, cdd_ww_max_abs);
				#endif /* CONFIG_PHY_TRAIN_SKIP */
			}

			/* set DFIMISC.dfi_init_complete_en to 1 */
			reg32_bits_set(umctl_reg_addr_base + uMCTL2_DFIMISC,0x1);
			reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x1);

			/* wait sw_done */
			do{
				udelay(10);
			}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_SWSTAT) & 0x1));
			udelay(10);
			do{
				udelay(10);
			}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_DFIMISC) & 0x1));
			udelay(10);

			/* diff with EDA C */
			value = reg32_read(umctl_reg_addr_base + uMCTL2_PWRCTL) & (~0x20);
			reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, value);

			/* wait operating mode = normal */
			do{
				udelay(10);
			}while ((0x1 != (reg32_read(umctl_reg_addr_base + uMCTL2_STAT) & 0x7)));
			udelay(10);
			DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);

			#ifdef MULTI_FILES
			if (hb_ddr_type == DDR_TYPE_LPDDR4 && boot_cnt == 0) {
				if (0 == sdram_info_detect()) {
					/* config retry flag */
					retry_flag = 0;

					hb_ddr_part_number = (sdram_info.mr5_value[0] << 8)
						+ sdram_info.mr8_value[0];

					/* init micron ddr vendor */
					if (hb_ddr_part_number == MT53D1024M32D4DT)
						hb_ddr_vendor = DDR_MANU_MICRON;
					else if(hb_ddr_part_number == K4F8E304HBMGCJ)
						hb_ddr_vendor = DDR_MANU_SAMSUNG;
					else
						hb_ddr_vendor = DDR_MANU_HYNIX;
				} else {
					retry_flag += 1;

					if (retry_flag > 5) {
						/* using default ddr config */
						printf("Can't auto detect LPDDR4 type, using default config JH\n");
						retry_flag = 0;
						hb_ddr_part_number = H9HCNNNBKUMLHE;
						hb_ddr_vendor = DDR_MANU_HYNIX;

						sdram_info.cs_num = 1;
						sdram_info.mr5_value[0] = 0x6;
						sdram_info.mr8_value[0] = 0x10;
					} else {
						/* retry auto detect */
						hb_ddr_part_number = PART_DEFAULT;
						break;
					}
				}
			}
			#endif
		}
	}while(retry_flag);

	/* enable auto refresh */
	auto_refresh_cfg(ENABLE);

	reg32_write(umctl_reg_addr_base + uMCTL2_PWRCTL, 0x0);

	/* axi port en, all ports enable */
	for (i = 0; i < AXI_PORT_NUM; i++) {
		axi_port_cfg(i, ENABLE);
	}
	hobot_snps_scrub_test(board_ddr_info.inline_ecc_en, hb_ddr_ecc_map, 0);
	reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x1);

	/*Before memtest, you should check manual r/w is OK*/
	/*memtest may report success incorrectly when both 2 regions read fail but compare all the same*/
	//Manual_Read_Write_Test();

	/*for ecc test*/
	//	#define INLINE_ECC_TEST_ADDR_START		0x100000
	//	#define INLINE_ECC_TEST_ADDR_END		0x200000
	//	inline_ecc_test(INLINE_ECC_TEST_ADDR_START,INLINE_ECC_TEST_ADDR_END,0,hb_ddr_ecc_map);

	/*for memtest*/
	// test_entry_t(); // memtest to DDR

	/*for single pattern w/r*/
	// ddr_acdc_test();

	/*for electronical characterization measurement*/
	//dma_write_test();

	/* auto detect test */
//		auto_detect_test();

    #if DDR_REG_DUMP
	ddr_umctl2_reg_dump();
	ddr_phy_reg_dump();
    #endif
#endif

}

