#ifndef __DDR_H__
#define __DDR_H__

#include "ddr_common.h"

#define DDR_CS_NUM_MAX 2

#define IMEM_LEN 32768 /* byte */
#define DMEM_LEN 16384 /* byte */

#define DIAG_IMEM_LEN 22756 /* byte */
#define DIAG_DMEM_LEN 6900 /* byte */

#define PMU_SYS_BASE		(0xA6000000)

#define SYSCTL_SW_REG_BASE (0xA1000000)

#define PMU_WDT_RST_TRIG_CTRL	(PMU_SYS_BASE + 0x0020)
#define WDT_RST_SW_REQ			BIT(12)
#define WDT_TRIG_PMU_EN			BIT(8)
#define WDT_TRIG_IO_EN			BIT(4)
#define WDT_TRIG_RST_EN			BIT(0)

#define DDRPLL_FREQ_CTRL (SYSCTL_SW_REG_BASE + 0x30)
#define DDRPLL_PD_CTRL (SYSCTL_SW_REG_BASE + 0x34)
#define DDRPLL_STATUS (SYSCTL_SW_REG_BASE + 0x38)
#define DDRPLL_FRAC (SYSCTL_SW_REG_BASE + 0x3C)
#define PLLCLK_SEL (SYSCTL_SW_REG_BASE + 0x300)
#define DDRSYS_CLKEN (SYSCTL_SW_REG_BASE + 0x130)
#define DDRSYS_CLKEN_SET (SYSCTL_SW_REG_BASE + 0x134)
#define DDRSYS_CLKEN_CLR (SYSCTL_SW_REG_BASE + 0x138)
#define DDRSYS_CLK_DIV_SEL (SYSCTL_SW_REG_BASE + 0x230)
#define DDRSYS_CLKOFF_STA (SYSCTL_SW_REG_BASE + 0x238)


#define DDRC_PERF_MON_ADDR	(0xA2D10000)
#define SYSCTRL_BASE		(0xA1000000)

#define DDRC_CFG_BASE (0xA2D00000)
#define DDRPHY_CFG_BASE (0xA2000000)

#define DWC_DDRPHYA_IMEM_OFFSET 0x50000
#define DWC_DDRPHYA_DMEM_OFFSET 0x54000
#define DWC_DDRPHYA_DIAG_DMEM_OFFSET 0x54200


#define X2A_PMU_DDRSYS_CTRL		(PMU_SYS_BASE + 0x0014)
#define X2A_PMU_W_SRC			(PMU_SYS_BASE + 0x0030)

#define X2A_SYSC_DDRSYS_SW_RSTEN		(SYSCTRL_BASE + 0x430)


#define DDR_SW_REG_DDR_MSG_MRR_DATA_RD_0 (DDRC_PERF_MON_ADDR + 0x10)
#define DDR_SW_REG_DDR_MSG_MRR_DATA_RD_1 (DDRC_PERF_MON_ADDR + 0x14)
#define DDR_SW_REG_DDR_MSG_MRR_DATA_RD_2 (DDRC_PERF_MON_ADDR + 0x18)
#define DDR_SW_REG_DDR_MSG_MRR_DATA_RD_3 (DDRC_PERF_MON_ADDR + 0x1C)

/* ddr phy dfi register */
#define DDRC_PHY_DFI1_ENABLE		(DDRC_PERF_MON_ADDR + 0x08)

/* user data type */
enum FW_TYPE {
	FW_1D_IMAGE,
	FW_2D_IMAGE,
};
enum DDR_TYPE {
	LPDDR4 = 1,
	LPDDR4X,
	DDR4,
	DDR3L
};

struct DDRPLL_CFG {
	uint32 frac;
	uint32 fbdiv;
	uint32 refdiv;
	uint32 postdiv1;
	uint32 postdiv2;
	uint32 bypass;
};
struct DDRC_INFO {
	uint64 umctl_reg_addr_base;
	struct UMCTL_REGS* p_umctl_reg;
	uint64 pub_reg_addr_base;
	struct	PUB_REGS* p_pub_reg;
};

struct DRAM_CFG_PARAM {
	unsigned int reg;
	unsigned int val;
};

struct DRAM_FSP_MSG {
	unsigned int drate;
	enum FW_TYPE fw_type;
	struct DRAM_CFG_PARAM *fsp_cfg;
	unsigned int fsp_cfg_num;
};

struct DRAM_TIMING_INFO {
	/* umctl2 config */
	struct DRAM_CFG_PARAM *ddrc_cfg;
	unsigned int ddrc_cfg_num;
	/* ddrphy config */
	struct DRAM_CFG_PARAM *ddrphy_cfg;
	unsigned int ddrphy_cfg_num;
	/* ddr phy PIE */
	struct DRAM_CFG_PARAM *ddrphy_pie;
	unsigned int ddrphy_pie_num;

	/* umctl2 freq 1/2/3 config */
	struct DRAM_CFG_PARAM *ddrc_freqs_cfg;
	unsigned int ddrc_freqs_cfg_num;
	/* ddrphy freq 1/2/3 config */
	struct DRAM_CFG_PARAM *ddrphy_freqs_cfg;
	unsigned int ddrphy_freqs_cfg_num;
	/* ddr phy freq 1/2/3 PIE */
	struct DRAM_CFG_PARAM *ddrphy_pie_freqs;
	unsigned int ddrphy_pie_freqs_num;
};

struct DRAM_TIMING_MDF_INFO {
	/* umctl2 config */
	struct DRAM_CFG_PARAM *p_ddrc_mdf_param;
	uint32 ddrc_mdf_param_num;
	/* ddrphy config */
	struct DRAM_CFG_PARAM *p_ddrphy_mdf_param;
	uint32 ddrphy_mdf_param_num;
	/* ddr phy PIE */
	struct DRAM_CFG_PARAM *p_pie_mdf_param;
	uint32 pie_mdf_param_num;
	/* lpddr4x diff config */
	struct DRAM_CFG_PARAM *p_ddrphy_mdf_io_param;
	uint32 ddrphy_mdf_io_param_num;
	#ifndef MULTI_FILES
	/* ddr DMEM image diff */
	void (*dmem_reconfig)(void);
	/* ddr DMEM_2D image diff */
	void (*dmem_2d_reconfig)(void);
	#endif
};

struct BOARD_DDR_INFO {
	uint32 datarate;
	enum DDR_TYPE ddr_type;
	/* ddrpll config */
	struct DDRPLL_CFG *p_ddrpll_cfg;
	struct DRAM_TIMING_INFO *p_dram_timing;
	struct DRAM_TIMING_MDF_INFO *p_dram_mdf_timing;
	uint32 write_dbi_en;
	uint32 read_dbi_en;
	uint32 inline_ecc_en;
	uint32 dm_en;
	uint32 derate_en;
	uint32 ddc_en;
};

enum LP4_MR8_TYPE
{
	S16_SDRAM = 0,
};

enum LP4_MR8_DENSITY
{
	PER_CHN_2Gb = 0,
	PER_CHN_3Gb,
	PER_CHN_4Gb,
	PER_CHN_6Gb,
	PER_CHN_8Gb,
	PER_CHN_12Gb,
	PER_CHN_16Gb,
	PER_CHN_1Gb = 0xC,
};

enum LP4_MR8_IO_WIDTH
{
	PER_CHN_16 = 0x0,
	PER_CHN_8 = 0x1,
};

struct LP4_TYPE
{
	uint32 mr8_type_cryp;
	uint32 type;
};

struct LP4_DENSITY
{
	uint32 mr8_density_cryp;
	uint32 density;
	uint32 row_num;
	uint32 bank_num;
	uint32 col_num;
};

struct LP4_IO_WIDTH
{
	uint32 mr8_io_width_cryp;
	uint32 io_width;
};
struct LP4_MR8_T
{
	uint32 type;
	uint32 density;
	uint32 io_width;
	uint32 row_num;
	uint32 bank_num;
	uint32 col_num;
};

struct SDRAM_INFO
{
	uint32 cs_num;
	uint8 mr5_value[DDR_CS_NUM_MAX];
	uint8 mr8_value[DDR_CS_NUM_MAX];
	struct LP4_MR8_T mr8_info[DDR_CS_NUM_MAX];
};

void ddr_init(void);

#endif /* __DDR_H__ */
