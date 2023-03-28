/*
 * Horizon Robotics
 *
 *  Copyright (C) 2021 Horizon Robotics Inc.
 *  All rights reserved.
 *  Author: ming.yu<ming.yu@horizon.ai>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef __X2A_DDR_H__
#define __X2A_DDR_H__

#include "ddr_common.h"
#include "ddr.h"
#include "ddr_phy_registers.h"
#include "ddr_phy_regs_struct.h"
#include "ddr_umctl2_registers.h"
#include "ddr_umctl2_regs_struct.h"
#include "x3_info.h"
#include "hb_ddr_oem.h"

#define PRINT_DDR_LOG   1
//#define DDR_MODULE_NAME  "DDR"
enum {
	DDR_LOG_NOTHING = 0,
	DDR_LOG_EMERG,
	DDR_LOG_ALERT,
	DDR_LOG_CRIT,
	DDR_LOG_ERR,
	DDR_LOG_WARNING,
	DDR_LOG_NOTICE,
	DDR_LOG_INFO,
	DDR_LOG_DEBUG,
	DDR_LOG_IRQ,
	DDR_LOG_MAX
};

#define DDR_LOG_LEVEL   DDR_LOG_INFO//DDR_LOG_INFO//DDR_LOG_WARNING //DDR_LOG_NOTHING //DDR_LOG_INFO

extern const char *const log_level[DDR_LOG_MAX];

//if ((level) <= DDR_LOG_LEVEL) printf("%s: %s: %s(%d) %s: " fmt, DDR_MODULE_NAME, __FILE__, __func__, __LINE__, log_level[level], ##__VA_ARGS__)
#if (PRINT_DDR_LOG)
#define DDR_LOG(level, fmt, ...) \
    if ((level) <= DDR_LOG_LEVEL) printf("[DDR %s] " fmt, log_level[level], ##__VA_ARGS__)
#else
#define DDR_LOG(level, fmt, ...)
#endif

#ifdef CONFIG_SPL_LOAD_FIT

#define X2_SRAM_LOAD_MAX	(0x4000)
#else

#define X2_SRAM_LOAD_MAX	(0x8000)
#endif /* CONFIG_SPL_LOAD_FIT */

// only support one from the three macro. CONFIG_SUPPORT_PALLADIUM  CONFIG_SUPPORT_EDA CONFIG_SUPPORT_CHIP
//#define CONFIG_SUPPORT_PALLADIUM
//#define CONFIG_SUPPORT_EDA
#define CONFIG_SUPPORT_CHIP

//	#define MULTI_FILES

#ifdef CONFIG_SUPPORT_PALLADIUM
#define CONFIG_PHY_TRAIN_SKIP
#endif
#define DDR_PHY_TRAIN_1D
#define DDR_PHY_TRAIN_2D
//#define DDR_PHY_EYE_TEST
//#define DDRPHY_DBG

#define DDR_DFS_TEST 0
#define DDR_DFS_TEST_P0 3200

#define ECC_EN 0
#define RD_DBI_EN 0
#define WR_DBI_EN_LPDDR4 1
#define WR_DBI_EN_DDR4 0
#define DM_EN 1
#define DERATE_EN 1
#define DDC_EN 1


#define LPDDR4 	DDR_TYPE_LPDDR4
#define LPDDR4X DDR_TYPE_LPDDR4X
#define DDR4 	DDR_TYPE_DDR4
#define DDR3L 	DDR_TYPE_DDR3L

//For Diagnostic tool, need to close one of LPDDR4/DDR4 to ensure code size small
#define LPDDR4_ENABLED 1
#define DDR4_ENABLED 1

//Different board uses different controller setting
//Choose one of the following board_enable definition
#define XH_ENABLE 0
#define XS_ENABLE 1
#define JH_ENABLE 0
#define JM_ENABLE 0
#define CVB_M_ENABLE 0

// ddr type: LPDDR4 LPDDR4X DDR4
#define DDR_TYPE LPDDR4			// ddr default type
// datarate unit Mbps.
// lpddr4 4266 3733 3600 3200 2666 667 333 100
// ddr4 3200 2666 2400 2133 1866 1600
#define DDR_DATARATE 2666		// ddr default data rate
#define AXI_PORT_NUM 8

enum en_dis {
	DISABLE = 0,	/* Disable */
	ENABLE = 1,		/* Enable */
};

#define DDR_CS_NUM_DEFAULT 1
#define DDR_CS_NUM_LPDDR4_HYNIX 1
#if (JM_ENABLE == 1)
#define DDR_CS_NUM_LPDDR4_MICRON 1
#elif (CVB_M_ENABLE == 1)
#define DDR_CS_NUM_LPDDR4_MICRON 2
#endif
#define DDR_CS_NUM_DDR4_MICRON 1

#define DDR_VENDOR_DEFAULT     DDR_MANU_HYNIX
#if defined(DDR_VENDOR_DEFAULT_HYNIX)
#undef DDR_VENDOR_DEFAULT
#define DDR_VENDOR_DEFAULT     DDR_MANU_HYNIX
#elif defined(DDR_VENDOR_DEFAULT_MICRON)
#undef DDR_VENDOR_DEFAULT
#define DDR_VENDOR_DEFAULT     DDR_MANU_MICRON
#elif defined(DDR_VENDOR_DEFAULT_SAMSUNG)
#undef DDR_VENDOR_DEFAULT
#define DDR_VENDOR_DEFAULT     DDR_MANU_SAMSUNG
#endif

/* use build script to replace ddr type */
#if defined(SPL_LPDDR4)
#undef DDR_TYPE
#define DDR_TYPE LPDDR4
#elif defined(SPL_LPDDR4X)
#undef DDR_TYPE
#define DDR_TYPE LPDDR4X
#elif defined(SPL_DDR4)
#undef DDR_TYPE
#define DDR_TYPE DDR4
#elif defined(SPL_DDR3L)
#undef DDR_TYPE
#define DDR_TYPE DDR3L
#endif

/* use build script to replace ddr rate */
/* 4266 3733 3600 3200 2666 2400 2133 1688 1600 667 */
#if defined(SPL_DDR_4266)
#undef DDR_DATARATE
#define DDR_DATARATE 4266
#elif defined(SPL_DDR_3733)
#undef DDR_DATARATE
#define DDR_DATARATE 3733
#elif defined(SPL_DDR_3600)
#undef DDR_DATARATE
#define DDR_DATARATE 3600
#elif defined(SPL_DDR_3200)
#undef DDR_DATARATE
#define DDR_DATARATE 3200
#elif defined(SPL_DDR_2666)
#undef DDR_DATARATE
#define DDR_DATARATE 2666
#elif defined(SPL_DDR_2400)
#undef DDR_DATARATE
#define DDR_DATARATE 2400
#elif defined(SPL_DDR_2133)
#undef DDR_DATARATE
#define DDR_DATARATE 2133
#elif defined(SPL_DDR_1688)
#undef DDR_DATARATE
#define DDR_DATARATE 1688
#elif defined(SPL_DDR_1600)
#undef DDR_DATARATE
#define DDR_DATARATE 1600
#elif defined(SPL_DDR_1333)
#undef DDR_DATARATE
#define DDR_DATARATE 1333
#elif defined(SPL_DDR_667)
#undef DDR_DATARATE
#define DDR_DATARATE 667
#elif defined(SPL_DDR_333)
#undef DDR_DATARATE
#define DDR_DATARATE 333
#elif defined(SPL_DDR_100)
#undef DDR_DATARATE
#define DDR_DATARATE 100
#endif

/*
Support DFS
3200-2666-667
3200-2666-333
2666-1333-667  //P0 need modify ddr_freq = 2666; in x3_ddr_init.c for DDR_DFS_TEST mode
*/
/*
LPDDR4_FFS_6335_FSP
1 : Janice 6335 Flow+FSP (Need to disable DDC of P1/P2)
0 : SNPS   6335 Flow+NO FSP
*/
#define LPDDR4_FFS_6335_FSP  0

#if (LPDDR4_FFS_6335_FSP == 1)
#undef DDC_EN
#define DDC_EN 0
#endif

/* defined DFS P1 (and P2) */
#if (XS_ENABLE == 1)
//#define DDR_DATARATE_P1 667
//#define DDR_DATARATE_P1 333
#define DDR_DATARATE_P1 2666

#define DDR_DATARATE_P2 667
//#define DDR_DATARATE_P2 333

#else
#define DDR_DATARATE_P1 667
#define DDR_DATARATE_P2 333
#endif

#define ALIGN_512(x) ((x + 0x1ff) & (~0x1ff))

/* define saved data in SRAM */
#define DDR_REG_SAVE_ADDR				0x8000E000
#define X2A_DDR_REG_SAVE_MAX_SIZE		0xFE0

#define SAVED_SUSPEND_CTRL_REG_CNT		(DDR_REG_SAVE_ADDR+X2A_DDR_REG_SAVE_MAX_SIZE)
#define SAVED_SUSPEND_PHY_REG_CNT		(SAVED_SUSPEND_CTRL_REG_CNT+4)

#define DDR_PARAM_SAVE_ADDR				0x8000F000
#define SAVED_DDR_TYPE_ADDR				(DDR_PARAM_SAVE_ADDR+X2A_DDR_REG_SAVE_MAX_SIZE)
#define SAVED_DDR_VENDOR_ADDR			(SAVED_DDR_TYPE_ADDR+4)
#define SAVED_DDR_DATARATE_ADDR			(SAVED_DDR_TYPE_ADDR+8)
#define SAVED_DDR_PART_NUMBER			(SAVED_DDR_TYPE_ADDR+0xC)

#define SSCG_SWITCH         hdr_ddr.sscg_parm[0]
#define SSCG_DBG_SPREAD     hdr_ddr.sscg_parm[1]
#define SSCG_DBG_DIVVAL     hdr_ddr.sscg_parm[2]
#define SSCG_DISABLE        0
#define SSCG_LVL1           1
#define SSCG_LVL2           2
#define SSCG_DBG            3
#define LPDDR4_FREQS_CFG_ADD(p0, p1, p2, array, dfs_info, dfs_info_cnt) \
({  \
	uint32_t tmp_size = 0; \
	uint32_t tmp_padding_size = 0; \
	uint8_t tmp_zero = 0;  \
	for (i = 0; i < dfs_info_cnt; i++) { \
		if((dfs_info[i].dfs_p0 == p0) &&  \
				(dfs_info[i].dfs_p1 == p1) &&  \
				(dfs_info[i].dfs_p2 == p2))  { \
			tmp_size = sizeof(array); \
			printf("[%s:%d] write dfs multifile,0x%x bytes\n", __func__, __LINE__, tmp_size); \
			fwrite(array, 2, \
					sizeof(array) / 2, fp); \
			if (tmp_size % 512) \
				tmp_padding_size = 512 - ((tmp_size % 512)); \
			for (i = 0; i < tmp_padding_size; i++) { \
				fwrite(&tmp_zero, 1, 1, fp); \
			} \
		}  \
	}  \
	tmp_size;  \
})
#endif
