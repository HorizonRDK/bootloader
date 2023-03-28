#include <stdio.h>
#include "ddr.h"
#include "x3_ddr.h"
#include "hb_ddr_oem.h"

#if LPDDR4_ENABLED == 1
#include "dwc_ddrphy_phyinit_dmem_struct_16b.h"
#include "dwc_ddrphy_phyinit_dmem_2d_struct_16b.h"
#include "x3_lpddr4_hynix_tuning.h"
#include "x3_lpddr4_micron_tuning.h"

#ifndef MULTI_FILES
#include <asm/arch/x2a_dev.h>
#include <asm/arch/x2_pinmux.h>

extern struct x2a_info_hdr g_binfo;
extern struct BOARD_DDR_INFO board_ddr_info;

/* lpddr4 timing config base params */
struct DRAM_TIMING_INFO lpddr4_dram_timing = {
	.ddrc_cfg = lpddr4_ddrc_cfg,
	.ddrc_cfg_num = 0,
	.ddrphy_cfg = lpddr4_ddrphy_cfg,
	.ddrphy_cfg_num = 0,
	.ddrphy_pie = lpddr4_phy_pie,
	.ddrphy_pie_num = 0,
};

struct DRAM_TIMING_MDF_INFO lpddr4_dram_mdf_timing = {
	.p_ddrc_mdf_param = NULL,
	.ddrc_mdf_param_num = 0,
	/* ddrphy config */
	.p_ddrphy_mdf_param = NULL,
	.ddrphy_mdf_param_num = 0,
	/* ddr phy PIE */
	.p_pie_mdf_param = NULL,
	.pie_mdf_param_num = 0,
	/* lpddr4x diff config */
	.p_ddrphy_mdf_io_param = NULL,
	.ddrphy_mdf_io_param_num = 0,
	#ifndef MULTI_FILES
	/* ddr DMEM image diff */
	.dmem_reconfig = NULL,
	.dmem_2d_reconfig = NULL,
	#endif
};
#endif
#endif
