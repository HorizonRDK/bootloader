#include "x3_ddr.h"
#include <asm/arch/x2a_dev.h>
#include <asm/arch/x2_pinmux.h>
#include "hb_ddr_oem.h"

#ifndef MULTI_FILES
#include <asm/arch/x2a_dev.h>
#include "dwc_ddrphy_phyinit_imem_diag.h"
#include "dwc_ddrphy_phyinit_dmem_diag.h"
#endif

#include "dwc_ddrphy_phyinit_dmem_struct.h"
#include "dwc_ddrphy_phyinit_dmem_2d_struct.h"
#include <asm/arch/x2_pinmux.h>

#include "ddr_pmu_train.strings.h"
#include "ddr_2d_pmu_train.strings.h"

#ifdef MULTI_FILES
#include "dwc_ddrphy_phyinit_dmem_2d_struct_16b.h"

extern struct DMEM_DDR4_2D_STRUCT_16B *p_dmem_ddr4_2d_16b;
extern struct DMEM_LPDDR4_2D_STRUCT_16B *p_dmem_lpddr4_2d_16b;
#endif

extern struct x2a_info_hdr g_binfo;

extern struct BOARD_DDR_INFO board_ddr_info;
extern struct DDRC_INFO ddrc_info;
extern uint64 umctl_reg_addr_base;
extern uint64 pub_reg_addr_base;

extern struct DMEM_DDR4_STRUCT *p_dmem_ddr4;
extern struct DMEM_LPDDR4_STRUCT *p_dmem_lpddr4;
extern struct DMEM_DDR4_2D_STRUCT *p_dmem_ddr4_2d;
extern struct DMEM_LPDDR4_2D_STRUCT *p_dmem_lpddr4_2d;

#ifdef YMODEM_BOOT
uint16 ddr_parameter[BL2_UART_DDR_PARAMTER_MAX_SIZE];
struct hb_ddr_uart_hdr ddr_hdr_uart;
#else
uint16 ddr_parameter[BL2_DDR_PARAMTER_MAX_SIZE];
struct hb_ddr_hdr ddr_hdr;
#endif

void set_ddrc_mem(uint16 * saddr, uint32 * daddr, uint32 s_size,
	uint32 mem_size)
{
	uint32 i, rdata;

	for (i = 0; i < (s_size); i++) {
	rdata = *(saddr+i);
	SETREG32((uintptr_t)(daddr + (i)), rdata);
	}

	if (s_size < mem_size) {
		for (i = s_size; i < (mem_size); i++) {
			SETREG32((uintptr_t)(daddr + (i)), 0);
		}
	}
}

#if 0
static void lpddr4_load_fw(unsigned long dest,
	unsigned long src, unsigned int fw_size, unsigned int fw_max_size)
{
	unsigned long fw_dest = dest;
	unsigned long fw_src = src;
	unsigned int tmp32;
	unsigned int i;

	for (i = 0; i < fw_size; ) {
		tmp32 = readl(fw_src);
		writel(tmp32 & 0x0000ffff, fw_dest);
		fw_dest += 4;
		writel((tmp32 >> 16) & 0x0000ffff, fw_dest);
		fw_dest += 4;
		fw_src += 4;
		i += 4;
	}

	for (i = fw_size; i < fw_max_size; i += 2 ) {
		writel(0x0, fw_dest);
		fw_dest += 4;
	}

	return;
}
#endif

/* get base board type by gpio */
static uint32 hb_board_type_get_by_gpio(void)
{
	uint32 reg, addr, board_type;

	/* get gpio6 value */
	addr = X2_GPIO_BASE + X3_GPIO0_VALUE_REG;
	reg = reg32_read(addr);

	board_type = PIN_BASE_BOARD_SEL(reg) + 1;

	return board_type;
}

uint32_t base_board_type_get(void) {
	uint32_t reg = readl(STRAP_PIN_REG);
	uint32_t boot_src, board_type;

	/* use boot strap to decide spl source */
	boot_src = PIN_2NDBOOT_SEL(reg);

	if ((boot_src != PIN_2ND_AP) && (boot_src != PIN_2ND_UART)) {
		board_type = BASE_BOARD_SEL(g_binfo.board_id);

		switch (board_type) {
		case AUTO_DETECTION:
			board_type = hb_board_type_get_by_gpio();
			break;
		case BASE_BOARD_X3_DVB:
		case BASE_BOARD_J3_DVB:
		case BASE_BOARD_CVB:
		case BASE_BOARD_CUSTOMER_BOARD:
			break;
		default:
			break;
		}
	} else {
		board_type = hb_board_type_get_by_gpio();
	}

#if !defined(WARM_BOOT_SPL)
	char *board_type_name[] = {
		"N/A",
		"X3_DVB",
		"J3_DVB",
		"CVB",
		"CUSTOMER_BOARD",
	};
	if(board_type<ARRAY_SIZE(board_type_name)) {
		DEBUG_LOG("board_type = %d (%s)\n", board_type, board_type_name[board_type]);
	} else {
		DEBUG_LOG("board_type = %d\n", board_type);
	}
#endif
	return board_type;
}

#if 0
#define WR_DQ_DLY_COMP_DEFAULT 4
#define WR_DQ_DLY_COMP_DDR2666 4
#define WR_DQ_DLY_COMP_DDR3200 3
#define WR_DQ_DLY_COMP_DDR3733 4
void dwc_ddrphy_phyinit_wr_comp_config (struct PUB_REGS* p_pub_reg)
{
	uint32 wr_q_dly = WR_DQ_DLY_COMP_DEFAULT;
	if(board_ddr_info.datarate == 2666) {
		wr_q_dly = WR_DQ_DLY_COMP_DDR2666;
	} else if(board_ddr_info.datarate == 3200) {
		wr_q_dly = WR_DQ_DLY_COMP_DDR3200;
	} else if(board_ddr_info.datarate == 3733) {
		wr_q_dly = WR_DQ_DLY_COMP_DDR3733;
	}
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
	p_pub_reg->DBYTE0__TxDqDlyTg0_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg0_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE1__TxDqDlyTg0_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg0_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE2__TxDqDlyTg0_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg0_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE3__TxDqDlyTg0_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg0_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE0__TxDqDlyTg1_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE0__TxDqDlyTg1_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE1__TxDqDlyTg1_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE1__TxDqDlyTg1_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE2__TxDqDlyTg1_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE2__TxDqDlyTg1_r8_p0 -= wr_q_dly;

	p_pub_reg->DBYTE3__TxDqDlyTg1_r0_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r1_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r2_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r3_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r4_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r5_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r6_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r7_p0 -= wr_q_dly;
	p_pub_reg->DBYTE3__TxDqDlyTg1_r8_p0 -= wr_q_dly;
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}
#endif

extern struct DRAM_CFG_PARAM lpddr4_ddrphy_hynix_cfg[];
unsigned int get_sizeof_lpddr4_ddrphy_hynix_cfg(void);
extern struct DRAM_CFG_PARAM ddr4_ddrphy_samsung_cfg[];
unsigned int get_sizeof_ddr4_ddrphy_samsung_cfg(void);

#define DDR_DQ_MAP_SIZE	32
uint32 ddr_dq_map_reg[DDR_DQ_MAP_SIZE] = {
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq0LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq1LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq2LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq3LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq4LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq5LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq6LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__Dq7LnSel,

	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq0LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq1LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq2LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq3LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq4LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq5LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq6LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__Dq7LnSel,

	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq0LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq1LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq2LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq3LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq4LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq5LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq6LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__Dq7LnSel,

	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq0LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq1LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq2LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq3LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq4LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq5LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq6LnSel,
	DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__Dq7LnSel,
};

uint8 xj3_dvb_dq_map[DDR_DQ_MAP_SIZE] = {
	0x2,0x1,0x7,0x0,0x5,0x3,0x4,0x6,
	0x3,0x6,0x7,0x5,0x0,0x4,0x1,0x2,
	0x4,0x0,0x1,0x2,0x7,0x3,0x6,0x5,
	0x3,0x7,0x2,0x6,0x0,0x4,0x5,0x1,
};
uint8 xj3_cvb_dq_map[DDR_DQ_MAP_SIZE] = {
	0x3,0x4,0x0,0x1,0x7,0x6,0x5,0x2,
	0x7,0x0,0x5,0x6,0x4,0x3,0x2,0x1,
	0x1,0x3,0x4,0x0,0x5,0x6,0x7,0x2,
	0x3,0x6,0x7,0x2,0x1,0x4,0x5,0x0,
};
uint8 xj3_customer_board_dq_map[DDR_DQ_MAP_SIZE] = {
	0x1,0x0,0x7,0x2,0x6,0x5,0x4,0x3,
	0x4,0x6,0x7,0x3,0x2,0x5,0x1,0x0,
	0x7,0x3,0x0,0x4,0x5,0x1,0x2,0x6,
	0x3,0x2,0x5,0x0,0x1,0x6,0x4,0x7,
};

#ifdef MULTI_FILES

uint32 ATxSlewRate_save=0;
uint32 ATxImpedance_save=0;
uint32 TxSlewRate_save=0;
uint32 TxOdtDrvStren_save=0;
uint32 TxImpedanceCtrl_save=0;
uint32 CalDrvStr0_save=0;
uint32 VrefInGlobal_save=0;
void save_phy_key_reg(unsigned int reg,unsigned int val)
{
    switch(reg) {
	    case DWC_DDRPHYA_ANIB0__ATxSlewRate : ATxSlewRate_save=val; break;
	    case DWC_DDRPHYA_ANIB0__ATxImpedance : ATxImpedance_save=val; break;
	    case DWC_DDRPHYA_DBYTE0__TxSlewRate_b0_p0 : TxSlewRate_save=val; break;
	    case DWC_DDRPHYA_DBYTE0__TxOdtDrvStren_b0_p0 : TxOdtDrvStren_save=val; break;
	    case DWC_DDRPHYA_DBYTE0__TxImpedanceCtrl1_b0_p0 : TxImpedanceCtrl_save=val; break;
	    case DWC_DDRPHYA_MASTER0__CalDrvStr0 : CalDrvStr0_save=val; break;
	    case DWC_DDRPHYA_MASTER0__VrefInGlobal_p0 : VrefInGlobal_save=val; break;
    }
}

void show_phy_key_reg(void)
{
	DEBUG_LOG("ATxSlewRate\t: %x\n",ATxSlewRate_save);
	DEBUG_LOG("ATxImpedance\t: %x\n",ATxImpedance_save);
	DEBUG_LOG("TxSlewRate\t: %x\n",TxSlewRate_save);
	DEBUG_LOG("TxOdtDrvStren\t: %x\n",TxOdtDrvStren_save);
	DEBUG_LOG("TxImpedanceCtrl\t: %x\n",TxImpedanceCtrl_save);
	DEBUG_LOG("CalDrvStr0\t: %x\n",CalDrvStr0_save);
	DEBUG_LOG("VrefInGlobal\t: %x\n",VrefInGlobal_save);
}

#endif

void dwc_ddrphy_phyinit_C_initPhyConfig (struct DRAM_CFG_PARAM *ddrphy_cfg, int num)
{
	int i = 0;
	struct DRAM_CFG_PARAM *ddrphy_cfg_tmp = 0;
	uint32 num_tmp = 0;
	uint32 __maybe_unused board_type = 0;

#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.ddr_ddrp.addr;
	fw_src_len = ddr_hdr_uart.ddr_ddrp.size;
#else
	uint32 fw_src_laddr = 0;

	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].ddr_ddrp.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].ddr_ddrp.size;

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif
	ddrphy_cfg_tmp = (struct DRAM_CFG_PARAM *)fw_dst_laddr;
	num_tmp = fw_src_len / sizeof(struct DRAM_CFG_PARAM);
	for (i = 0; i < num_tmp; i++) {
		save_phy_key_reg(ddrphy_cfg_tmp->reg,ddrphy_cfg_tmp->val);
		reg32_write((ddrphy_cfg_tmp->reg + pub_reg_addr_base),
			ddrphy_cfg_tmp->val);
		ddrphy_cfg_tmp++;
	}
	show_phy_key_reg();
#else

	for (i = 0; i < num; i++) {
		reg32_write((ddrphy_cfg->reg + pub_reg_addr_base), ddrphy_cfg->val);
		ddrphy_cfg++;
	}

	/* update phy reg for hynix */
	if (hb_ddr_vendor == DDR_MANU_HYNIX) {
		if(board_ddr_info.ddr_type==DDR_TYPE_LPDDR4) {
			#if LPDDR4_ENABLED == 1

			#if defined(WARM_BOOT_SPL)
			if (hb_ddr_part_number == H9HCNNN8KUMLHR) {
				num_tmp = get_sizeof_lpddr4_ddrphy_hynix_cfg_xh();
				ddrphy_cfg = lpddr4_ddrphy_hynix_cfg_xh;
			} else if (hb_ddr_part_number == H9HCNNNBKUMLHE) {
				num_tmp = get_sizeof_lpddr4_ddrphy_hynix_cfg_jh();
				ddrphy_cfg = lpddr4_ddrphy_hynix_cfg_jh;
			} else {
				num_tmp = get_sizeof_lpddr4_ddrphy_hynix_cfg();
				ddrphy_cfg = lpddr4_ddrphy_hynix_cfg;
			}
			#else
			num_tmp = get_sizeof_lpddr4_ddrphy_hynix_cfg();
			ddrphy_cfg = lpddr4_ddrphy_hynix_cfg;
			#endif

			for (i = 0; i < num_tmp; i++) {
				reg32_write((ddrphy_cfg->reg + pub_reg_addr_base), ddrphy_cfg->val);
				ddrphy_cfg++;
			}
			#endif
		}
	}

	/* update phy reg for samsung */
	if (hb_ddr_vendor == DDR_MANU_SAMSUNG) {
		if(board_ddr_info.ddr_type==DDR_TYPE_DDR4) {
		#if DDR4_ENABLED == 1
			num_tmp = get_sizeof_ddr4_ddrphy_samsung_cfg();
			ddrphy_cfg = ddr4_ddrphy_samsung_cfg;
			for (i = 0; i < num_tmp; i++) {
				reg32_write((ddrphy_cfg->reg + pub_reg_addr_base), ddrphy_cfg->val);
				ddrphy_cfg++;
			}
		#endif
		}
	}

	//base lpddr4 4266Mbps, other frequency need modify some parameters.
	if (board_ddr_info.p_dram_mdf_timing->p_ddrphy_mdf_param) {
		ddrphy_cfg_tmp = board_ddr_info.p_dram_mdf_timing->p_ddrphy_mdf_param;
		num_tmp = board_ddr_info.p_dram_mdf_timing->ddrphy_mdf_param_num;
		if(0 != num_tmp) {
			for (i = 0; i < num_tmp; i++) {
				reg32_write((ddrphy_cfg_tmp->reg + pub_reg_addr_base), ddrphy_cfg_tmp->val);
				ddrphy_cfg_tmp++;
			}
		}
	}
	if (board_ddr_info.p_dram_mdf_timing->p_ddrphy_mdf_io_param) {
		ddrphy_cfg_tmp = board_ddr_info.p_dram_mdf_timing->p_ddrphy_mdf_io_param;
		num_tmp = board_ddr_info.p_dram_mdf_timing->ddrphy_mdf_io_param_num;
		if(0 != num_tmp) {
			for (i = 0; i < num_tmp; i++) {
				reg32_write((ddrphy_cfg_tmp->reg + pub_reg_addr_base), ddrphy_cfg_tmp->val);
				ddrphy_cfg_tmp++;
			}
		}
	}
#endif
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
	#if LPDDR4_ENABLED == 1
		p_dmem_lpddr4 = (struct DMEM_LPDDR4_STRUCT *)(ddrc_info.pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET << 2));
		p_dmem_lpddr4_2d = (struct DMEM_LPDDR4_2D_STRUCT *)(ddrc_info.pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET << 2));
	#endif
	} else {
	#if DDR4_ENABLED == 1
		p_dmem_ddr4 = (struct DMEM_DDR4_STRUCT *)(ddrc_info.pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET << 2));
		p_dmem_ddr4_2d = (struct DMEM_DDR4_2D_STRUCT *)(ddrc_info.pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET << 2));
	#endif
	}

	if (board_ddr_info.read_dbi_en) {
			reg32_bits_write((DDRPHY_CFG_BASE + DWC_DDRPHYA_MASTER0__DMIPinPresent_p0), 0, 1, 1);
			reg32_bits_write((DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE0__DqDqsRcvCntrl1), 8, 1, 0);
			reg32_bits_write((DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE1__DqDqsRcvCntrl1), 8, 1, 0);
			reg32_bits_write((DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE2__DqDqsRcvCntrl1), 8, 1, 0);
			reg32_bits_write((DDRPHY_CFG_BASE + DWC_DDRPHYA_DBYTE3__DqDqsRcvCntrl1), 8, 1, 0);
	}

	if (hb_ddr_type != DDR_TYPE_DDR4) {
		board_type = base_board_type_get();
		uint8 *p_map_val=NULL;
		int i;
		if ((board_type == BASE_BOARD_X3_DVB) || (board_type == BASE_BOARD_J3_DVB)) {
			p_map_val = xj3_dvb_dq_map;
		} else if (board_type == BASE_BOARD_CVB) {
			p_map_val = xj3_cvb_dq_map;
		}else if (board_type == BASE_BOARD_CUSTOMER_BOARD) {
			p_map_val = xj3_customer_board_dq_map;
		}
		if (p_map_val) {
			for (i=0;i<DDR_DQ_MAP_SIZE;i++) {
				reg32_write(ddr_dq_map_reg[i],(uint32)p_map_val[i]);
			}
		}
	}
}

#if !defined(WARM_BOOT_SPL)
#ifdef MULTI_FILES
void output_ddr_parameter(void)
{
	DEBUG_LOG("\n*******************************************************\n");

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->MR11_A0:%x\n", p_dmem_lpddr4_2d_16b->MR11_A0);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->MR14_A0:%x\n", p_dmem_lpddr4_2d_16b->MR14_A0);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->MR12_A0:%x\n", p_dmem_lpddr4_2d_16b->MR12_A0);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->MR22_A0:%x\n\n", p_dmem_lpddr4_2d_16b->MR22_A0);

		DEBUG_LOG("p_dmem_lpddr4_2d_16b->MR3_A0:%x\n", p_dmem_lpddr4_2d_16b->MR3_A0);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->Reserved00:%x\n", p_dmem_lpddr4_2d_16b->Reserved00);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->Reserved0E:%x\n", p_dmem_lpddr4_2d_16b->Reserved0E);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->Delay_Weight2D:%x\n", p_dmem_lpddr4_2d_16b->Delay_Weight2D);
		DEBUG_LOG("p_dmem_lpddr4_2d_16b->Voltage_Weight2D:%x\n", p_dmem_lpddr4_2d_16b->Voltage_Weight2D);
	} else {

		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_0: %x\n", p_dmem_ddr4_2d_16b->MR_0);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_1: %x\n", p_dmem_ddr4_2d_16b->MR_1);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_2: %x\n", p_dmem_ddr4_2d_16b->MR_2);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_3: %x\n", p_dmem_ddr4_2d_16b->MR_3);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_4: %x\n", p_dmem_ddr4_2d_16b->MR_4);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_5: %x\n", p_dmem_ddr4_2d_16b->MR_5);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->MR_6: %x\n", p_dmem_ddr4_2d_16b->MR_6);

		DEBUG_LOG("p_dmem_ddr4_2d_16b->HdtCtrl:%x\n", p_dmem_ddr4_2d_16b->HdtCtrl);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->Reserved00:%x\n", p_dmem_ddr4_2d_16b->Reserved00);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->RX2D_TrainOpt:%x\n", p_dmem_ddr4_2d_16b->TX2D_TrainOpt);
		DEBUG_LOG("p_dmem_ddr4_2d_16b->RX2D_TrainOpt:%x\n", p_dmem_ddr4_2d_16b->RX2D_TrainOpt);
	}
	DEBUG_LOG("*******************************************************\n\n");

}
#endif

void dwc_ddrphy_phyinit_D_loadIMEM (void)
{
#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint32 fw_src_laddr = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;
#endif

	//Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
	//This allows the memory controller unrestricted access to the configuration CSRs
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
#ifdef MULTI_FILES
#ifdef YMODEM_BOOT
	/* Load ddr parameter firmware */
	//g_dev_ops.read(fw_src_laddr, fw_dst_laddr, fw_src_len);
	//memcpy(&ddr_hdr, ddr_parameter, sizeof(struct hb_ddr_uart_hdr));

	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.imem1.addr;
	fw_src_len = ddr_hdr_uart.imem1.size;

	DEBUG_LOG("uart load imem1 src_addr: %02x, load_addr: %02x, src_len: %02x\n",
		fw_src_laddr, (uint32_t)fw_dst_laddr, fw_src_len);
#else
	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].imem1.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].imem1.size;

	DEBUG_LOG("load imem1 src_addr: %02x, load_addr: %02x, src_len: %02x\n",
		fw_src_laddr, (uint32_t)fw_dst_laddr, fw_src_len);

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif
	set_ddrc_mem((uint16 *)fw_dst_laddr, (void *)(pub_reg_addr_base +
		(DWC_DDRPHYA_IMEM_OFFSET << 2)), fw_src_len / 2,
		(IMEM_LEN / 2));

	if (g_dev_ops.post_read)
		g_dev_ops.post_read(0x0);
#else
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		set_ddrc_mem(phyinit_imem_lpddr4, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_IMEM_OFFSET<<2)), get_sizeof_phyinit_imem_lpddr4(),
			(IMEM_LEN / sizeof(phyinit_imem_lpddr4[0])));
		#endif
	} else {
		#if DDR4_ENABLED == 1
		set_ddrc_mem(phyinit_imem_ddr4, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_IMEM_OFFSET<<2)), get_sizeof_phyinit_imem_ddr4(),
			(IMEM_LEN / sizeof(phyinit_imem_ddr4[0])));
		#endif
	}
#endif
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}



void dwc_ddrphy_phyinit_D_loadIMEM_2D (void)
{
#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

	if (g_dev_ops.proc_start) {
		g_dev_ops.proc_start();
	}
#endif
	//Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
	//This allows the memory controller unrestricted access to the configuration CSRs
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
#ifdef MULTI_FILES
#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.imem2.addr;
	fw_src_len = ddr_hdr_uart.imem2.size;
#else
	uint32 fw_src_laddr = 0;

	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].imem2.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].imem2.size;

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif

	set_ddrc_mem((uint16 *)fw_dst_laddr, (void *)(pub_reg_addr_base +
		(DWC_DDRPHYA_IMEM_OFFSET<<2)), fw_src_len / 2,
		(IMEM_LEN / 2));

	if (g_dev_ops.post_read)
		g_dev_ops.post_read(0x0);
#else
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		set_ddrc_mem(phyinit_imem_lpddr4_2D, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_IMEM_OFFSET<<2)), get_sizeof_phyinit_imem_lpddr4_2D(),
			(IMEM_LEN / sizeof(phyinit_imem_lpddr4_2D[0])));
		#endif
	} else {
		#if DDR4_ENABLED == 1
		set_ddrc_mem(phyinit_imem_ddr4_2D, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_IMEM_OFFSET<<2)), get_sizeof_phyinit_imem_ddr4_2D(),
			(IMEM_LEN / sizeof(phyinit_imem_ddr4_2D[0])));
		#endif
	}
#endif
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}


void dwc_ddrphy_phyinit_F_loadDMEM_pstate0 (void)
{
#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

	if (g_dev_ops.proc_start) {
		g_dev_ops.proc_start();
	}
#endif
	//Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
	//This allows the memory controller unrestricted access to the configuration CSRs
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
#ifdef MULTI_FILES
#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.dmem1.addr;
	fw_src_len = ddr_hdr_uart.dmem1.size;
#else
	uint32 fw_src_laddr = 0;

	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].dmem1.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].dmem1.size;

	/* Load dmem firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif
	set_ddrc_mem((uint16 *)fw_dst_laddr, (void *)(pub_reg_addr_base +
		(DWC_DDRPHYA_DMEM_OFFSET << 2)), fw_src_len / 2,
		(DMEM_LEN / 2));

	if (g_dev_ops.post_read)
		g_dev_ops.post_read(0x0);
#else

	//base lpddr4 4266Mbps, other frequency need modify some parameters.
	if (board_ddr_info.p_dram_mdf_timing->dmem_reconfig)
	{
		board_ddr_info.p_dram_mdf_timing->dmem_reconfig();
	}

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		set_ddrc_mem(phyinit_dmem_lpddr4, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET<<2)), get_sizeof_phyinit_dmem_lpddr4(),
			(DMEM_LEN / sizeof(phyinit_dmem_lpddr4[0])));
		#endif
	} else {
		#if DDR4_ENABLED == 1
		set_ddrc_mem(phyinit_dmem_ddr4, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET<<2)), get_sizeof_phyinit_dmem_ddr4(),
			(DMEM_LEN / sizeof(phyinit_dmem_ddr4[0])));
		#endif
	}

#endif
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}

void dwc_ddrphy_phyinit_F_loadDMEM_pstate0_2D (void)
{
#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

	if (g_dev_ops.proc_start) {
		g_dev_ops.proc_start();
	}
#endif
	//Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
	//This allows the memory controller unrestricted access to the configuration CSRs
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
#ifdef MULTI_FILES
#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.dmem2.addr;
	fw_src_len = ddr_hdr_uart.dmem2.size;
#else
	uint32 fw_src_laddr = 0;

	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].dmem2.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].dmem2.size;

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		p_dmem_lpddr4_2d_16b = (struct DMEM_LPDDR4_2D_STRUCT_16B*) fw_dst_laddr;
	} else {
		p_dmem_ddr4_2d_16b = (struct DMEM_DDR4_2D_STRUCT_16B *)fw_dst_laddr;
	}

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));

	output_ddr_parameter();
#endif
	set_ddrc_mem((uint16 *)fw_dst_laddr, (void *)(pub_reg_addr_base +
		(DWC_DDRPHYA_DMEM_OFFSET << 2)), fw_src_len / 2,
		(DMEM_LEN / 2));

	if (g_dev_ops.post_read)
		g_dev_ops.post_read(0x0);
#else
	//base lpddr4 4266Mbps, other frequency need modify some parameters.
	if (board_ddr_info.p_dram_mdf_timing->dmem_2d_reconfig)
		board_ddr_info.p_dram_mdf_timing->dmem_2d_reconfig();

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		set_ddrc_mem(phyinit_dmem_lpddr4_2D, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET<<2)), get_sizeof_phyinit_dmem_lpddr4_2D(),
			(DMEM_LEN / sizeof(phyinit_dmem_lpddr4_2D[0])));
		#endif
	} else {
		#if DDR4_ENABLED == 1
		set_ddrc_mem(phyinit_dmem_ddr4_2D, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_DMEM_OFFSET<<2)), get_sizeof_phyinit_dmem_ddr4_2D(),
			(DMEM_LEN / sizeof(phyinit_dmem_ddr4_2D[0])));
		#endif
	}
#endif
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}

#endif /* !defined(WARM_BOOT_SPL) */

static inline uint32 get_mail(uint32 dbg_en)
{
	uint32 value;
	uint32 temp;

	do{
		udelay(10);
	}while ((reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctShadowRegs) & 0x1));
	udelay(10);

	value = reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctWriteOnlyShadow);
	DDR_LOG(DDR_LOG_DEBUG, "wonlysha = 0x%x\n", value);

	if (dbg_en > 0) {
		temp = reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctDatWriteOnlyShadow);
		value |= temp << 16;
		DDR_LOG(DDR_LOG_DEBUG, "dwonlysha = 0x%x, ret = 0x%x\n", temp, value);
	}

	reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__DctWriteProt, 0x0);

	do{
		udelay(10);
	}while (!(reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctShadowRegs) & 0x1));
	udelay(10);

	reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__DctWriteProt, 0x1);

	return value;
}

#define MAX_DDR_FW_LOG_PARAM	32
void dwc_ddrphy_phyinit_G_waitFwDone_dbg(uint32 is_2d_fw)
{
	uint32 major_msg;
	uint32 str_index;
	uint32 loop_max;
	uint32 __maybe_unused log_param[MAX_DDR_FW_LOG_PARAM];

	while ((major_msg = get_mail(0)) != 0x7) {
		if (major_msg == 0x8) {
			str_index = get_mail(1);
			loop_max = str_index & 0xffff;

			for (int i = 0; i < loop_max; i++) {
				if(i<MAX_DDR_FW_LOG_PARAM) {
					log_param[i] = get_mail(1);
				} else {
					get_mail(1);
				}
			}
#ifdef DDRPHY_DBG
			int cnt;
			if(is_2d_fw) {
				for(cnt=0; cnt<FW_2D_LOG_CNT; cnt++) {
					if(fw_2d_log[cnt].id == str_index) {
						printf("0x%08x ",str_index);
						printf(fw_2d_log[cnt].str,
							log_param[0],log_param[1],log_param[2],log_param[3],
							log_param[4],log_param[5],log_param[6],log_param[7],
							log_param[8],log_param[9],log_param[10],log_param[11],
							log_param[12],log_param[13],log_param[14],log_param[15],
							log_param[16],log_param[17],log_param[18],log_param[19],
							log_param[20],log_param[21],log_param[22],log_param[23],
							log_param[24],log_param[25],log_param[26],log_param[27],
							log_param[28],log_param[29],log_param[30],log_param[31]);
						break;
					}
				}
			} else {
				for(cnt=0; cnt<FW_1D_LOG_CNT; cnt++) {
					if(fw_1d_log[cnt].id == str_index) {
						printf("0x%08x ",str_index);
						printf(fw_1d_log[cnt].str,
							log_param[0],log_param[1],log_param[2],log_param[3],
							log_param[4],log_param[5],log_param[6],log_param[7],
							log_param[8],log_param[9],log_param[10],log_param[11],
							log_param[12],log_param[13],log_param[14],log_param[15],
							log_param[16],log_param[17],log_param[18],log_param[19],
							log_param[20],log_param[21],log_param[22],log_param[23],
							log_param[24],log_param[25],log_param[26],log_param[27],
							log_param[28],log_param[29],log_param[30],log_param[31]);
						break;
					}
				}

			}
#endif
		}
	}

	return;
}

void dwc_ddrphy_phyinit_G_waitFwDone (void)
{
	volatile uint32 tmp;

	DDR_LOG(DDR_LOG_DEBUG, "dwc_ddrphy_phyinit_G_waitFwDone\n");
	printf("dwc_ddrphy_phyinit_G_waitFwDone\n");//to be delete
    //wait for firmware complete and training run successfully
	do {
		do{
			udelay(10);
		}while ((reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctShadowRegs) & 0x1));
		udelay(10);
		tmp = reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctWriteOnlyShadow);
		reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__DctWriteProt, 0x0);

		do{
			udelay(10);
		}while (!(reg32_read(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__UctShadowRegs) & 0x1));
		udelay(10);

		reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__DctWriteProt, 0x1);
	} while(0x07 != tmp);
	DDR_LOG(DDR_LOG_DEBUG, "dwc_ddrphy_phyinit_G_waitFwDone OK\n");
	printf("dwc_ddrphy_phyinit_G_waitFwDone OK!\n");//to be delete
}

#if !defined(WARM_BOOT_SPL)
void dwc_ddrphy_phyinit_G_execFW (uint32 is_2d_fw)
{
    // // 1.  Reset the firmware microcontroller by writing the MicroReset CSR to set the StallToMicro and
    // //     ResetToMicro fields to 1 (all other fields should be zero).
    // //     Then rewrite the CSR so that only the StallToMicro remains set (all other fields should be zero).
    SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x00000001); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
    SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x00000009); // DWC_DDRPHYA_APBONLY0_MicroReset
    SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x00000001); // DWC_DDRPHYA_APBONLY0_MicroReset
    //
    // // 2. Begin execution of the training firmware by setting the MicroReset CSR to 4'b0000.
    SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x00000000); // DWC_DDRPHYA_APBONLY0_MicroReset
    //
    // // 3.   Wait for the training firmware to complete by following the procedure in "uCtrl Initialization and Mailbox Messaging"
	dwc_ddrphy_phyinit_G_waitFwDone_dbg(is_2d_fw);

    // // 4.   Halt the microcontroller."
    SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x00000001); // DWC_DDRPHYA_APBONLY0_MicroReset
}

void dwc_ddrphy_phyinit_H_readMsgBlock (uint8 *cdd_rw_max_abs, uint8 *cdd_ww_max_abs)
{
	int8 cdd_rw_max = 0;
	int8 cdd_ww_max = 0;
	int8 cdd_cha_rw_0_0= 0;
	int8 cdd_cha_rw_0_1= 0;
	int8 cdd_cha_rw_1_0= 0;
	int8 cdd_cha_rw_1_1= 0;
	int8 cdd_cha_ww_0_1= 0;
	int8 cdd_cha_ww_1_0= 0;
	int8 cdd_chb_rw_0_0= 0;
	int8 cdd_chb_rw_0_1= 0;
	int8 cdd_chb_rw_1_0= 0;
	int8 cdd_chb_rw_1_1= 0;
	int8 cdd_chb_ww_0_1= 0;
	int8 cdd_chb_ww_1_0= 0;

	uint32 cs_test_fail = 0;
	reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x0);

//	cs_test_fail = reg32_read(pub_reg_addr_base + (0x54007<<2));
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		cs_test_fail = p_dmem_lpddr4->CsTestFail;
		#endif
	} else {
		#if DDR4_ENABLED == 1
		cs_test_fail = p_dmem_ddr4->CsTestFail;
		#endif
	}

	if ( cs_test_fail != 0x0){
		DDR_LOG(DDR_LOG_DEBUG, " Training is Failed");
		DDR_LOG(DDR_LOG_DEBUG, " CsTestFail value is %0x", cs_test_fail);
	}
	DDR_LOG(DDR_LOG_DEBUG, "Training Pass!\n");

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		cdd_cha_rw_0_0 = p_dmem_lpddr4->CDD_ChA_RW_0_0;//ligh
		cdd_cha_rw_0_1 = p_dmem_lpddr4->CDD_ChA_RW_0_1;//low
		cdd_cha_rw_1_0 = p_dmem_lpddr4->CDD_ChA_RW_1_0;//high
		cdd_cha_rw_1_1 = p_dmem_lpddr4->CDD_ChA_RW_1_1;//low
		cdd_cha_ww_0_1 = p_dmem_lpddr4->CDD_ChA_WW_0_1;//high
		cdd_cha_ww_1_0 = p_dmem_lpddr4->CDD_ChA_WW_1_0;//low
		cdd_chb_rw_0_0 = p_dmem_lpddr4->CDD_ChB_RW_0_0;//low
		cdd_chb_rw_0_1 = p_dmem_lpddr4->CDD_ChB_RW_0_1;//high
		cdd_chb_rw_1_0 = p_dmem_lpddr4->CDD_ChB_RW_1_0;//low
		cdd_chb_rw_1_1 = p_dmem_lpddr4->CDD_ChB_RW_1_1;//high
		cdd_chb_ww_0_1 = p_dmem_lpddr4->CDD_ChB_WW_0_1;//low
		cdd_chb_ww_1_0 = p_dmem_lpddr4->CDD_ChB_WW_1_0;//high
		#endif
		cdd_rw_max = max3(max3(cdd_cha_rw_0_0, cdd_cha_rw_0_1, cdd_cha_rw_1_0),
			max3(cdd_chb_rw_0_0, cdd_chb_rw_0_1, cdd_chb_rw_1_0) ,
			max(cdd_cha_rw_1_1, cdd_chb_rw_1_1));

		cdd_ww_max = max(max(cdd_cha_ww_0_1, cdd_cha_ww_1_0), max(cdd_chb_ww_0_1, cdd_chb_ww_1_0));
	} else {
		#if DDR4_ENABLED == 1
		cdd_cha_rw_0_0 = p_dmem_ddr4->CDD_RW_0_0;//ligh
		cdd_cha_rw_0_1 = p_dmem_ddr4->CDD_RW_0_1;//low
		cdd_cha_rw_1_0 = p_dmem_ddr4->CDD_RW_1_0;//high
		cdd_cha_rw_1_1 = p_dmem_ddr4->CDD_RW_1_1;//low
		cdd_cha_ww_0_1 = p_dmem_ddr4->CDD_WW_0_1;//high
		cdd_cha_ww_1_0 = p_dmem_ddr4->CDD_WW_1_0;//low
		#endif
		cdd_rw_max = max(max(cdd_cha_rw_0_0, cdd_cha_rw_0_1),max(cdd_cha_rw_1_0, cdd_cha_rw_1_1));
		cdd_ww_max = max(cdd_cha_ww_0_1, cdd_cha_ww_1_0);
	}

	*cdd_rw_max_abs = ABS(cdd_rw_max);
	*cdd_ww_max_abs = ABS(cdd_ww_max);
//	Resevered13 = reg32_read(pub_reg_addr_base + DDRPHY_CFG_BASE + (0x54009<<2));
//	print(" Resevered13 value is %0x",Resevered13);


	reg32_write(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x1);

}
#endif

void dwc_ddrphy_phyinit_I_loadPIEImage(struct DRAM_CFG_PARAM *pie_cfg, int num)
{
	int i = 0;
	struct DRAM_CFG_PARAM *pie_cfg_tmp = 0;
	uint32 num_tmp = 0;

#ifdef MULTI_FILES
	uint32 fw_src_len = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;

#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.ddr_pie.addr;
	fw_src_len = ddr_hdr_uart.ddr_pie.size;
#else
	uint32 fw_src_laddr = 0;

	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].ddr_pie.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].ddr_pie.size;

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif
	pie_cfg_tmp = (struct DRAM_CFG_PARAM *)fw_dst_laddr;
	num_tmp = fw_src_len / sizeof(struct DRAM_CFG_PARAM);

	for (i = 0; i < num_tmp; i++) {
		reg32_write((pie_cfg_tmp->reg + pub_reg_addr_base),
			pie_cfg_tmp->val);
		pie_cfg_tmp++;
	}
#else
	DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);
	for (i = 0; i < num; i++) {
		reg32_write((pie_cfg->reg + pub_reg_addr_base), pie_cfg->val);
		pie_cfg++;
	}
	//base 4266Mbps, other frequency need modify some parameters.
	if (board_ddr_info.p_dram_mdf_timing->p_pie_mdf_param)
	{
		pie_cfg_tmp = board_ddr_info.p_dram_mdf_timing->p_pie_mdf_param;
		num_tmp = board_ddr_info.p_dram_mdf_timing->pie_mdf_param_num;
		if (0 != num_tmp)
		{
			for (i = 0; i < num_tmp; i++)
			{
			reg32_write((pie_cfg_tmp->reg + pub_reg_addr_base), pie_cfg_tmp->val);
			pie_cfg_tmp++;
			}
		}
	}
#endif
}


void dwc_ddrphy_phyinit_J_enterMissionMode (void)
{
	uint32 value;
	DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);
	reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x0);
	//set DFIMISC.dfi_init_start to 1
	value = reg32_read(umctl_reg_addr_base + uMCTL2_DFIMISC) | 0x20;
	reg32_write(umctl_reg_addr_base + uMCTL2_DFIMISC, value);

	reg32_write(umctl_reg_addr_base + uMCTL2_SWCTL, 0x1);
	//wait sw_done
	do{
		udelay(10);
	}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_SWSTAT) & 0x1));
	udelay(10);
	DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);
	//wait DFISTAT.dfi_init_complete
	do{
		udelay(10);
	}while (!(reg32_read(umctl_reg_addr_base + uMCTL2_DFISTAT) & 0x1));
	udelay(10);
	DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);
}

#ifdef DDR_PHY_EYE_TEST
void dwc_ddrphy_phyinit_Z_loadDialogIMEM (void)
{
#ifdef MULTI_FILES
	uint32 fw_src_len;
	uint32 fw_src_laddr;
	uint32 rd_byte;

	uint32 mcu_sram;
	uint32 min_len;
#endif
	printf("\n diag imem...\n");

	//Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
	//This allows the memory controller unrestricted access to the configuration CSRs
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
#ifdef MULTI_FILES
	if (g_dev_ops.pre_read) {
		g_dev_ops.pre_read(&g_binfo, 0, 0x0, &fw_src_laddr, &fw_src_len);
	} else {
		fw_src_len = DIAG_IMEM_LEN;
	}
	/* Load 32KB firmware */
	mcu_sram = (pub_reg_addr_base + (DWC_DDRPHYA_IMEM_OFFSET<<2));
	while (fw_src_len > 0)
	{
		min_len = fw_src_len > X2_SRAM_LOAD_MAX ?
			X2_SRAM_LOAD_MAX : fw_src_len;
		rd_byte = g_dev_ops.read(fw_src_laddr, X2_SRAM_LOAD_ADDR, min_len);

		lpddr4_load_fw(mcu_sram, X2_SRAM_LOAD_ADDR, rd_byte, rd_byte);

		fw_src_len -= min_len;
		fw_src_laddr += min_len;
		mcu_sram += min_len * 2;
	}

	if (g_dev_ops.post_read)
		g_dev_ops.post_read(0x0);
#else
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		set_ddrc_mem(phyinit_imem_lpddr4_diag, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_IMEM_OFFSET<<2)), ARRAY_SIZE(phyinit_imem_lpddr4_diag),
			(DIAG_IMEM_LEN / sizeof(phyinit_imem_lpddr4_diag[0])));
	} else {
		set_ddrc_mem(phyinit_imem_ddr4_diag, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_IMEM_OFFSET<<2)), ARRAY_SIZE(phyinit_imem_ddr4_diag),
			(DIAG_IMEM_LEN / sizeof(phyinit_imem_ddr4_diag[0])));
	}
#endif
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}

void dwc_ddrphy_phyinit_Z_loadDialogDMEM (void)
{
#ifdef MULTI_FILES
	uint32 fw_src_len;
	uint32 fw_src_laddr;
	uint32 rd_byte;

	uint32 mcu_sram;
	uint32 min_len;
#endif
	printf("\n diag dmem...\n");
	//Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0.
	//This allows the memory controller unrestricted access to the configuration CSRs
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
#ifdef MULTI_FILES
	if (g_dev_ops.pre_read) {
		g_dev_ops.pre_read(&g_binfo, 0, 0x8000, &fw_src_laddr, &fw_src_len);
	} else {
		fw_src_len = DIAG_DMEM_LEN;
	}
	/* Load 16KB firmware */
	mcu_sram = pub_reg_addr_base + (DWC_DDRPHYA_DIAG_DMEM_OFFSET<<2);
	while (fw_src_len > 0) {
		min_len = fw_src_len > X2_SRAM_LOAD_MAX ?
			X2_SRAM_LOAD_MAX : fw_src_len;
		rd_byte = g_dev_ops.read(fw_src_laddr, X2_SRAM_LOAD_ADDR, min_len);

		lpddr4_load_fw(mcu_sram, X2_SRAM_LOAD_ADDR, rd_byte, rd_byte);

		fw_src_len -= min_len;
		fw_src_laddr += min_len;
		mcu_sram += min_len * 2;
	}

	if (g_dev_ops.post_read)
		g_dev_ops.post_read(0x0);
#else
	//base lpddr4 4266Mbps, other frequency need modify some parameters.
	if (board_ddr_info.p_dram_mdf_timing->dmem_reconfig)
	{
		board_ddr_info.p_dram_mdf_timing->dmem_reconfig();
	}

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		set_ddrc_mem(phyinit_dmem_lpddr4_diag, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_DIAG_DMEM_OFFSET<<2)), ARRAY_SIZE(phyinit_dmem_lpddr4_diag),
			(DIAG_DMEM_LEN / sizeof(phyinit_dmem_lpddr4_diag[0])));
	} else {
		set_ddrc_mem(phyinit_dmem_ddr4_diag, (void *)(pub_reg_addr_base +
			(DWC_DDRPHYA_DIAG_DMEM_OFFSET<<2)), ARRAY_SIZE(phyinit_dmem_ddr4_diag),
			(DIAG_DMEM_LEN / sizeof(phyinit_dmem_ddr4_diag[0])));
	}
#endif
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1); // DWC_DDRPHYA_APBONLY0_MicroContMuxSel
}



static void diag_fw_start_seq(void)
{
	DDR_LOG(DDR_LOG_INFO, "diag_fw_start_seq\n\n");
	unsigned int major_msg;
	unsigned int str_index;
	unsigned int loop_max;

	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DRTUB0__UctWriteProt,0x1);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__DctWriteProt,0x1);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DRTUB0__UctWriteOnly,0x0);

	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x1);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x9);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x1);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x0);

	while ((major_msg = get_mail(0)) != 0x7) {
		if (major_msg == 0x8) {
			str_index = get_mail(1);
			loop_max = str_index & 0xffff;

			for (int i = 0; i < loop_max; i++) {
				printf("arg: %d\n", i + 1);
				get_mail(1);
			}
		}
	}
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x1);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0);

	return;
}

#define DIAG_PRT_VREF_LOW_TO_HIGH  0
void lpddr4_exec_testtxeye_tc5_fw(uint8 byte_num, uint8 lane_num)
{
	printf("lpddr4_exec_testtxeye_tc5_fw\n\n");

	int vref_idx,dly_idx,nVREF,nDly,csr_txdqdly;
	int vref_mr_db=0;
	int row_no,col_no;
	unsigned int tmp;
	unsigned int errcnt[9];
	unsigned int err_cnt_l = 0;
	unsigned int err_cnt_h = 0;

	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0);

	SETREG32(pub_reg_addr_base + (0x54200<<2), 0x0605); //DiagSubTest, DiagTestNum
	SETREG32(pub_reg_addr_base + (0x54201<<2), 0x0001); //DiagRank, DiagPrbs
	SETREG32(pub_reg_addr_base + (0x54202<<2), 0x1f00); //DiagRepeatCount, DiagChannel
	SETREG32(pub_reg_addr_base + (0x54203<<2), (0x001f |(byte_num << 8))); //DiagByte, DiagLoopCount
	SETREG32(pub_reg_addr_base + (0x54204<<2), (0x0100 | (lane_num))); //DiagVrefInc, DiagLane
	SETREG32(pub_reg_addr_base + (0x54205<<2), 0x1f00); //DiagXCount, DiagDoZQ
	SETREG32(pub_reg_addr_base + (0x54206<<2), 0x0000); //DiagAddrLow
	SETREG32(pub_reg_addr_base + (0x54207<<2), 0x0000); //DiagAddrHigh
	SETREG32(pub_reg_addr_base + (0x54208<<2), 0x5555); //DiagSeedLow
	SETREG32(pub_reg_addr_base + (0x54209<<2), 0xaaaa); //DiagSeedHigh
	SETREG32(pub_reg_addr_base + (0x5420A<<2), 0x0001); //DiagInfLoop, DiagMisc0

	diag_fw_start_seq();

	for(int i=0;i<6;i=i+2) {
		tmp = GETREG32(pub_reg_addr_base + ((0x5420b+(i>>1))<<2)); //DiagReturnData
	    //printf("B[%0d - %0d] diag_addr=%x phy_diag_addr=%x diag_data=%x\n", i, (i+1), (0x5420b+(i>>1)), (unsigned int)(pub_reg_addr_base + ((0x5420b+(i>>1))<<2)), tmp);
	    if(i==0) {
	        nVREF = ((0x0000ff00 & tmp)>>8);
	    	nDly    = (0x000000ff & tmp);
	    	vref_idx=nVREF;
	    	dly_idx=nDly;
	    	printf("B[%0d - %0d] vref_idx=%x dly_idx=%x\n", i, (i+1), vref_idx, dly_idx);
	    }
	    if(i==2) {
	    	vref_mr_db = tmp;
		if(vref_mr_db>=40)
			printf("B[%0d - %0d] vref_mr_db=%x [Range1]\n", i, (i+1), vref_mr_db);
		else
			printf("B[%0d - %0d] vref_mr_db=%x [Range0]\n", i, (i+1), vref_mr_db);
	    }
	    if(i==4) {
	    	csr_txdqdly = tmp;
	    	printf("B[%0d - %0d] csr_txdqdly=%x\n", i, (i+1), csr_txdqdly);
	    }
	}//for
	#if DIAG_PRT_VREF_LOW_TO_HIGH
	row_no=0;
	#else
	row_no=vref_idx;
	#endif
	col_no=0;

	printf("\nTX EYE Error Count Printing\n\n");
	printf("Dly:      01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24\n");
	#if DIAG_PRT_VREF_LOW_TO_HIGH
	for(int i=6;i<(6+(vref_idx*nDly)+dly_idx);i=i+2)
	#else
	for(int i=(6+(vref_idx*nDly)+dly_idx);i>=6;i=i-2)
	#endif
	{
	    tmp = GETREG32(pub_reg_addr_base + ((0x5420b+(i>>1))<<2));
	    if((col_no%4)==0) {
	    	err_cnt_l=tmp;
	    } else {
	    	err_cnt_h= ( (0xffff0000 & (tmp<<16)) | err_cnt_l );
	    }
	    switch(col_no) {
		    case 2 : errcnt[0] = err_cnt_h;
		    case 6 : errcnt[1] = err_cnt_h;
		    case 10 : errcnt[2] = err_cnt_h;
		    case 14 : errcnt[3] = err_cnt_h;
		    case 18 : errcnt[4] = err_cnt_h;
		    case 22 : errcnt[5] = err_cnt_h;
		    case 26 : errcnt[6] = err_cnt_h;
		    case 30 : errcnt[7] = err_cnt_h;
		    case 34 : errcnt[8] = err_cnt_h;
	    }
	    if(col_no<nDly) col_no = col_no + 2;
	    if(col_no==36) {
			printf("nVREF %3x:",row_no);
			for(int i=0;i<9;i++){
				if(i==4&&row_no==vref_mr_db)
					#if DIAG_PRT_VREF_LOW_TO_HIGH
					printf("%2x  + %2x %2x ",
					(errcnt[i]&0x000000ff), ((errcnt[i]&0x00ff0000)>>16), ((errcnt[i]&0xff000000)>>24));
					#else
					printf("%2x  + %2x %2x ",
					((errcnt[i]&0x0000ff00)>>8), ((errcnt[i]&0xff000000)>>24), ((errcnt[i]&0x00ff0000)>>16));
					#endif
				else
					#if DIAG_PRT_VREF_LOW_TO_HIGH
					printf("%2x %2x %2x %2x ",
					(errcnt[i]&0x000000ff), ((errcnt[i]&0x0000ff00)>>8), ((errcnt[i]&0x00ff0000)>>16), ((errcnt[i]&0xff000000)>>24));
					#else
					printf("%2x %2x %2x %2x ",
					((errcnt[i]&0x0000ff00)>>8), (errcnt[i]&0x000000ff), ((errcnt[i]&0xff000000)>>24), ((errcnt[i]&0x00ff0000)>>16));
					#endif
			}
			printf("\n");
			col_no=0;
			#if DIAG_PRT_VREF_LOW_TO_HIGH
			row_no++;
			#else
			row_no--;
			#endif
	  	}
	}
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x1);
}

void lpddr4_exec_testrxeye_tc6_fw(uint32 byte_num, uint8 lane_num)
{
	printf("rx lpddr4_exec_testrxeye_tc6_fw\n\n");

	int vref_idx,dly_idx,nVREF,nDly;
	int vref_dac0=0;
	int vref_dac1, csr_rxclkdly;
	int row_no,col_no;
	unsigned int tmp;
	unsigned int errcnt[10];
	unsigned int err_cnt_l = 0;
	unsigned int err_cnt_h = 0;

	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0);

	SETREG32(pub_reg_addr_base + (0x54200<<2), 0x0006);//DiagSubTest, DiagTestNum
	SETREG32(pub_reg_addr_base + (0x54201<<2), 0x0002);//DiagRank, DiagPrbs
	SETREG32(pub_reg_addr_base + (0x54202<<2), 0x1f00);//DiagRepeatCount, DiagChannel
	SETREG32(pub_reg_addr_base + (0x54203<<2), (0x001f | (byte_num << 8))); //DiagByte, DiagLoopCount
	SETREG32(pub_reg_addr_base + (0x54204<<2), (0x0100 | (lane_num))); //DiagVrefInc, DiagLane
	SETREG32(pub_reg_addr_base + (0x54205<<2), 0x1f00);//DiagXCount, DiagDoZQ
	SETREG32(pub_reg_addr_base + (0x54206<<2), 0x0000);//DiagAddrLow
	SETREG32(pub_reg_addr_base + (0x54207<<2), 0x0000);//DiagAddrHigh
	SETREG32(pub_reg_addr_base + (0x54208<<2), 0x5555);//DiagSeedLow
	SETREG32(pub_reg_addr_base + (0x54209<<2), 0xaaaa);//DiagSeedHigh
	SETREG32(pub_reg_addr_base + (0x5420A<<2), 0x0001);//DiagInfLoop, DiagMisc0

	diag_fw_start_seq();


	for(int i=0;i<6;i=i+2) {
		tmp = GETREG32(pub_reg_addr_base + ((0x5420b+(i>>1))<<2));
	    //printf("B[%0d - %0d] diag_addr=%x phy_diag_addr=%x diag_data=%x\n", i, (i+1), (0x5420b+(i>>1)), (unsigned int)(pub_reg_addr_base + ((0x5420b+(i>>1))<<2)), tmp);
	    if(i==0) {
	        nVREF = ((0x0000ff00 & tmp)>>8);
	    	nDly    = (0x000000ff & tmp);
	    	vref_idx=nVREF;
	    	dly_idx=nDly;
	    	printf("B[%0d - %0d] vref_idx=%x dly_idx=%x\n", i, (i+1), vref_idx, dly_idx);
	    }
		if(i==2) {
			vref_dac0 = (0x000000ff & tmp);
			vref_dac1 = ((0x0000ff00 & tmp)>>8);
			printf("B[%0d - %0d] vref_dac0=%x vref_dac1=%x\n", i, (i+1), vref_dac0, vref_dac1);
  	    }
		if(i==4) {
			csr_rxclkdly = tmp;
			printf("B[%0d - %0d] csr_rxclkdly=%x\n", i, (i+1), csr_rxclkdly);
		}
	}//for
	#if DIAG_PRT_VREF_LOW_TO_HIGH
	row_no=0; // print from low to high about nVREF
	#else
	row_no=vref_idx; // print from high to low about nVREF
	#endif
	col_no=0;

	printf("\nRX EYE Error Count Printing\n\n");
	printf("Dly:      01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25 26\n");
	#if DIAG_PRT_VREF_LOW_TO_HIGH
	for(int i=6;i<(6+(vref_idx*nDly)+dly_idx);i=i+2) // print from low to high about nVREF
	#else
	for(int i=(6+(vref_idx*nDly)+dly_idx);i>=6;i=i-2) // print from high to low about nVREF
	#endif
	{
		tmp = GETREG32(pub_reg_addr_base + ((0x5420b+(i>>1))<<2));
	    if((col_no%4)==0) {
	    	err_cnt_l=tmp;
	    } else {
	    	err_cnt_h= ( (0xffff0000 & (tmp<<16)) | err_cnt_l );
	    }

	    switch(col_no) {
		    case 2 : errcnt[0] = err_cnt_h;
		    case 6 : errcnt[1] = err_cnt_h;
		    case 10 : errcnt[2] = err_cnt_h;
		    case 14 : errcnt[3] = err_cnt_h;
		    case 18 : errcnt[4] = err_cnt_h;
		    case 22 : errcnt[5] = err_cnt_h;
		    case 26 : errcnt[6] = err_cnt_h;
		    case 30 : errcnt[7] = err_cnt_h;
		    case 34 : errcnt[8] = err_cnt_h;
			case 36 : errcnt[9] = err_cnt_l;
	    }
	    if(col_no<nDly) col_no = col_no + 2;
	    if(col_no==38) {
			printf("nVREF %3x:",row_no);
			for(int i=0;i<10;i++){
				if(i==9)
					#if DIAG_PRT_VREF_LOW_TO_HIGH
					printf("%2x %2x ",
					(errcnt[i]&0x000000ff), ((errcnt[i]&0x0000ff00)>>8));
					#else
					printf("%2x %2x ",
					(errcnt[i]&0x000000ff), ((errcnt[i]&0x0000ff00)>>8));
					#endif
				else{
					if(i==4&&row_no==vref_dac0)
						#if DIAG_PRT_VREF_LOW_TO_HIGH
						printf("%2x %2x  + %2x ",
						(errcnt[i]&0x000000ff), ((errcnt[i]&0x0000ff00)>>8), ((errcnt[i]&0xff000000)>>24));
						#else
						printf("%2x %2x  + %2x ",
						((errcnt[i]&0x0000ff00)>>8), (errcnt[i]&0x000000ff), ((errcnt[i]&0xff000000)>>24));
						#endif
					else
						#if DIAG_PRT_VREF_LOW_TO_HIGH
						printf("%2x %2x %2x %2x ",
						(errcnt[i]&0x000000ff), ((errcnt[i]&0x0000ff00)>>8), ((errcnt[i]&0x00ff0000)>>16), ((errcnt[i]&0xff000000)>>24));
						#else
						printf("%2x %2x %2x %2x ",
						((errcnt[i]&0x0000ff00)>>8), (errcnt[i]&0x000000ff), ((errcnt[i]&0xff000000)>>24), ((errcnt[i]&0x00ff0000)>>16));
						#endif
				}
			}
			printf("\n");
			col_no=0;
			#if DIAG_PRT_VREF_LOW_TO_HIGH
			row_no++;
			#else
			row_no--;
			#endif
	  	}
	}
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroReset,0x1);
}
#endif

#ifdef CONFIG_PHY_TRAIN_SKIP
void dwc_ddrphy_manual_set(void)
{
	return;

	//Start of dwc_ddrphy_phyinit_progCsrSkipTrain(void)
	//NumRank_total = 4
	//PHY_Rx_Fifo_Dly = 1133
	//PHY_Tx_Insertion_Dly = 200
	//PHY_Rx_Insertion_Dly = 200
	//Pstate=0, Memclk=2142MHz, Programming DFIMRL to 0x7
	//Pstate=0, Memclk=2142MHz, Programming HwtMRL to 0x7
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__DFIMRL_p0, 0x7);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__DFIMRL_p0, 0x7);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__DFIMRL_p0, 0x7);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__DFIMRL_p0, 0x7);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__HwtMRL_p0, 0x7);
	//Pstate=0, Memclk=2142MHz, Programming TxDqsDlyTg0 to 0x100
	//Pstate=0, Memclk=2142MHz, Programming TxDqsDlyTg1 to 0x100
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u0_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u1_p0, 0x100);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u1_p0, 0x100);
	//Pstate=0, Memclk=2142MHz, Programming TxDqDlyTg0 to 0x8e
	//Pstate=0, Memclk=2142MHz, Programming TxDqDlyTg1 to 0x8e
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r0_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r1_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r2_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r3_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r4_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r5_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r6_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r7_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r8_p0, 0x8e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r8_p0, 0x8e);
	//Pstate=0, Memclk=2142MHz, Programming RxEnDly_10to6=17, Rxendly_5to0=19
	//Pstate=0, Memclk=2142MHz, Programming RxEnDlyTg0 to 0x453
	//Pstate=0, Memclk=2142MHz, Programming RxEnDlyTg1 to 0x453
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u0_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u1_p0, 0x453);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u1_p0, 0x453);
	//Pstate=0, Programming PIE RL=36 WL=18
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_INITENG0__Seq0BGPR1_p0, 0x2200);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_INITENG0__Seq0BGPR2_p0, 0x10);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_INITENG0__Seq0BGPR3_p0, 0x2e00);
	//Programming HwtLpCsEnA to 0x3
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__HwtLpCsEnA, 0x3);
	//Programming HwtLpCsEnB to 0x3
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__HwtLpCsEnB, 0x3);
	//Pstate=0, Memclk=2142MHz, Programming PptDqsCntInvTrnTg0 to 0x3e
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__PptDqsCntInvTrnTg0_p0, 0x3e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__PptDqsCntInvTrnTg0_p0, 0x3e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__PptDqsCntInvTrnTg0_p0, 0x3e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__PptDqsCntInvTrnTg0_p0, 0x3e);
	//Pstate=0, Memclk=2142MHz, Programming PptDqsCntInvTrnTg1 to 0x3e
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__PptDqsCntInvTrnTg1_p0, 0x3e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__PptDqsCntInvTrnTg1_p0, 0x3e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__PptDqsCntInvTrnTg1_p0, 0x3e);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__PptDqsCntInvTrnTg1_p0, 0x3e);
	//Programming PptCtlStatic CSR
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__PptCtlStatic, 0x703);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__PptCtlStatic, 0x70f);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__PptCtlStatic, 0x703);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__PptCtlStatic, 0x70f);
	//Programming HwtCAMode to 0x34
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__HwtCAMode, 0x34);
	//Pstate=0, Memclk=2142MHz, Programming DllGainCtl::DllGainIV=0x4, DllGainTV=0x5
	//Pstate=0, Memclk=2142MHz, Programming DllGainCtl to 0x54
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__DllGainCtl_p0, 0x54);
	//Pstate=0, Memclk=2142MHz, Programming DllLockParam::LcdlSeed0 to 47
	//Pstate=0, Memclk=2142MHz, Programming DllLockParam to 0x2f2
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__DllLockParam_p0, 0x2f2);
	//Programming AcsmCtrl23 to 0x10f
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_ACSM0__AcsmCtrl23, 0x10f);
	//Programming PllCtrl3::PllDacValIn to 0x10
	//Programming PllCtrl3::PllForceCal to 0x1
	//Programming PllCtrl3::PllMaxRange to 0x1f
	//Programming PllCtrl3 to 0x61f0
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__PllCtrl3, 0x61f0);
	//Special skipTraining configuration to Prevernt DRAM Commands on the first dfi status interface handshake.
	//In order to see this behavior, the frist dfi_freq should be in the range of 0x0f < dfi_freq_sel[4:0] < 0x14.
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_INITENG0__PhyInLP3, 0x0);
}
#endif

#if !defined(WARM_BOOT_SPL)
void dwc_ddrphy_train(void)
{
#ifndef YMODEM_BOOT
	DEBUG_LOG("magic = %02x\n", ddr_hdr.magic);
#endif

	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__MemResetL,0x2); // DWC_DDRPHYA_MASTER0_MemResetL
	DDR_LOG(DDR_LOG_INFO, "Loading 1D imem\n");
	dwc_ddrphy_phyinit_D_loadIMEM ();// this function needs to be finished by SW
	DDR_LOG(DDR_LOG_INFO, "Loading 1D dmem\n");
	dwc_ddrphy_phyinit_F_loadDMEM_pstate0 ();// this function needs to be finished by SW
	DDR_LOG(DDR_LOG_DEBUG, "executing 1D fw\n");
	DEBUG_LOG("executing 1D fw\n");//to be delete
	dwc_ddrphy_phyinit_G_execFW (false);

	unsigned int dfimrl_max=0;
	unsigned int tmp=0;
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_APBONLY0__MicroContMuxSel,0x0);

	tmp = GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__DFIMRL_p0);
	if (dfimrl_max<tmp) dfimrl_max=tmp;
	tmp = GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__DFIMRL_p0);
	if (dfimrl_max<tmp) dfimrl_max=tmp;
	tmp = GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__DFIMRL_p0);
	if (dfimrl_max<tmp) dfimrl_max=tmp;
	tmp = GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__DFIMRL_p0);
	if (dfimrl_max<tmp) dfimrl_max=tmp;

	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__DFIMRL_p0, dfimrl_max);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__DFIMRL_p0, dfimrl_max);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__DFIMRL_p0, dfimrl_max);
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__DFIMRL_p0, dfimrl_max);
	DEBUG_LOG("DWC_DDRPHYA_DBYTE0__DFIMRL_p0=%d\n", GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE0__DFIMRL_p0));
	DEBUG_LOG("DWC_DDRPHYA_DBYTE1__DFIMRL_p0=%x\n", GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE1__DFIMRL_p0));
	DEBUG_LOG("DWC_DDRPHYA_DBYTE2__DFIMRL_p0=%x\n", GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE2__DFIMRL_p0));
	DEBUG_LOG("DWC_DDRPHYA_DBYTE3__DFIMRL_p0=%x\n", GETREG32(pub_reg_addr_base + DWC_DDRPHYA_DBYTE3__DFIMRL_p0));

#ifdef DDR_PHY_TRAIN_2D
	SETREG32(pub_reg_addr_base + DWC_DDRPHYA_MASTER0__MemResetL,0x2); // DWC_DDRPHYA_MASTER0_MemResetL
	DDR_LOG(DDR_LOG_INFO, "Loading 2D imem\n");
	dwc_ddrphy_phyinit_D_loadIMEM_2D ();// this function needs to be finished by SW
	DDR_LOG(DDR_LOG_INFO, "Loading 2D dmem\n");
	dwc_ddrphy_phyinit_F_loadDMEM_pstate0_2D ();// this function needs to be finished by SW
	DDR_LOG(DDR_LOG_DEBUG, "executing 2D fw\n");
	DEBUG_LOG("executing 2D fw\n");//to be delete
	dwc_ddrphy_phyinit_G_execFW (true);
#endif

#ifdef DDR_PHY_EYE_TEST
	unsigned int reg = readl(STRAP_PIN_REG);
	if(PIN_SKIP_CSUM_SEL(reg)) {
		uint32 i, j;
		dwc_ddrphy_phyinit_Z_loadDialogIMEM();
		dwc_ddrphy_phyinit_Z_loadDialogDMEM();
		for (i = 0; i < 4; i++)
		{
			for(j = 0; j < 8; j++)
			{
				printf("byte: %d	lane: %d\n", i, j);
				lpddr4_exec_testtxeye_tc5_fw(i, j);
				lpddr4_exec_testrxeye_tc6_fw(i, j);
			}
		}
		printf("ddr eye diagram end\n");
		while(1);
	}
#endif
}
#endif
