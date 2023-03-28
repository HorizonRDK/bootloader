#include <stdio.h>
#include "ddr.h"
#include "x3_ddr.h"
#if DDR4_ENABLED == 1
#include "dwc_ddrphy_phyinit_dmem_struct_16b.h"
#include "dwc_ddrphy_phyinit_dmem_2d_struct_16b.h"

#include "x3_ddr4_micron_tuning.h"

#ifndef MULTI_FILES
/* ddr4 timing config base params */
struct DRAM_TIMING_INFO ddr4_dram_timing = {
	.ddrc_cfg = ddr4_ddrc_cfg,
	.ddrc_cfg_num = 0,
	.ddrphy_cfg = ddr4_ddrphy_cfg,
	.ddrphy_cfg_num = 0,
	.ddrphy_pie = ddr4_phy_pie,
	.ddrphy_pie_num = 0,

};
struct DRAM_TIMING_MDF_INFO ddr4_dram_mdf_timing = {
	.p_ddrc_mdf_param = NULL,
	.ddrc_mdf_param_num = 0,
	/* ddrphy config */
	.p_ddrphy_mdf_param = NULL,
	.ddrphy_mdf_param_num = 0,
	/* ddr phy PIE */
	.p_pie_mdf_param = NULL,
	.pie_mdf_param_num = 0,
	/* ddr4x diff config */
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
