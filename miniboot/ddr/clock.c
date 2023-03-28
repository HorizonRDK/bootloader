
#include <asm/io.h>
#include <common.h>
#include <asm/arch/x2_sysctrl.h>
#include <asm/arch/clock.h>
#include <linux/delay.h>


#ifdef CONFIG_SPL_BUILD
#if 0
void dram_pll_init(ulong pll_val)
{
	unsigned int value;
	unsigned int try_num = 5;

	printf("set ddr's pll to %lu\n", pll_val / 1000000);

	writel(PD_BIT | DSMPD_BIT | FOUTPOST_DIV_BIT | FOUTVCO_BIT, X2_DDRPLL_PD_CTRL);

	switch (pll_val) {
		case MHZ(3200):
			/* Set DDR PLL to 1600 */
			value = FBDIV_BITS(200) | REFDIV_BITS(3) |
				POSTDIV1_BITS(1) | POSTDIV2_BITS(1);
			writel(value, X2_DDRPLL_FREQ_CTRL);

			writel(0x1, X2_DDRSYS_CLK_DIV_SEL);
			break;

		case MHZ(2666):
			/* Set DDR PLL to 1333 */
			value = FBDIV_BITS(111) | REFDIV_BITS(1) |
				POSTDIV1_BITS(2) | POSTDIV2_BITS(1);
			writel(value, X2_DDRPLL_FREQ_CTRL);

			writel(0x1, X2_DDRSYS_CLK_DIV_SEL);
			break;

		case MHZ(2133):
			/* Set DDR PLL to 1066 */
			value = FBDIV_BITS(87) | REFDIV_BITS(1) |
				POSTDIV1_BITS(2) | POSTDIV2_BITS(1);
			writel(value, X2_DDRPLL_FREQ_CTRL);

			writel(0x1, X2_DDRSYS_CLK_DIV_SEL);

			break;

		default:
			break;
	}

	value = readl(X2_DDRPLL_PD_CTRL);
	value &= ~(PD_BIT | FOUTPOST_DIV_BIT);
	writel(value, X2_DDRPLL_PD_CTRL);

	while (!(value = readl(X2_DDRPLL_STATUS) & LOCK_BIT)) {
		if (try_num <= 0) {
			break;
		}

		udelay(100);
		try_num--;
	}

	value = readl(X2_PLLCLK_SEL);
	value |= DDRCLK_SEL_BIT;
	writel(value, X2_PLLCLK_SEL);

	writel(0x1, X2_DDRSYS_CLKEN_SET);

	return;
}
#endif

void cnn_pll_init(void)
{
	unsigned int value;
	unsigned int try_num = 5;

	writel(PD_BIT | DSMPD_BIT | FOUTPOST_DIV_BIT | FOUTVCO_BIT,
		X2_CNNPLL_PD_CTRL);

	value = readl(X2_CNNPLL_PD_CTRL);
	value &= ~(PD_BIT | FOUTPOST_DIV_BIT);
	writel(value, X2_CNNPLL_PD_CTRL);

	/* 24MHz*125/1/3/1 */
	writel(FBDIV_BITS(125) | REFDIV_BITS(1) | POSTDIV1_BITS(3) | POSTDIV2_BITS(1),
			X2_CNNPLL_FREQ_CTRL);

	while (!(value = readl(X2_CNNPLL_STATUS) & LOCK_BIT)) {
		if (try_num <= 0)
			break;

		udelay(100);
		try_num--;
	}

	value = readl(X2_PLLCLK_SEL);
	value &= ~CNNPLL_SEL_BIT;
	value |= CNNCLK_SEL_BIT;
	writel(value, X2_PLLCLK_SEL);

	writel(CNN_MCLK0_DIV_SEL(REFCLK_DIV(1)) |
		   CNN_MCLK1_DIV_SEL(REFCLK_DIV(1)) ,
		   X2_CNNSYS_CLK_DIV_SEL);
}


void vio_pll_init(void)
{
	unsigned int value;
	unsigned int try_num = 5;

	 /* VIOPLL2: Disable */
	writel(PD_BIT | DSMPD_BIT | FOUTPOST_DIV_BIT | FOUTVCO_BIT,
			X2_VIOPLL2_PD_CTRL);

	/* VIOPLL2 Freq: 24MHz*99/1/1/1 */
	writel(FBDIV_BITS(99) | REFDIV_BITS(1) | POSTDIV1_BITS(1) | POSTDIV2_BITS(1),
			X2_VIOPLL2_FREQ_CTRL);

	/* VIOPLL2: Enable */
	value = readl(X2_VIOPLL2_PD_CTRL);
	value &= ~(PD_BIT | FOUTPOST_DIV_BIT);
	writel(value, X2_VIOPLL2_PD_CTRL);

	/* To reconfig VIOPLL should switch MUX to 24MHz becuase the PLL is using */
	value = readl(X2_PLLCLK_SEL);
	value &= ~VIOCLK_SEL_BIT;
	writel(value, X2_PLLCLK_SEL);

	/* VIOPLL: Disable */
	writel(PD_BIT | DSMPD_BIT | FOUTPOST_DIV_BIT | FOUTVCO_BIT,
			X2_VIOPLL_PD_CTRL);

   /* VIOPLL Freq: 24MHz*68/1/1/1 */
	writel(FBDIV_BITS(68) | REFDIV_BITS(1) | POSTDIV1_BITS(1) | POSTDIV2_BITS(1),
			X2_VIOPLL_FREQ_CTRL);

	/* VIOPLL: Enable */
	value = readl(X2_VIOPLL_PD_CTRL);
	value &= ~(PD_BIT | FOUTPOST_DIV_BIT);
	writel(value, X2_VIOPLL_PD_CTRL);

	/* VIOPLL/VIOPLL2 Locked */
	while (!(readl(X2_VIOPLL_STATUS) & LOCK_BIT) ||
		   !(readl(X2_VIOPLL2_STATUS) & LOCK_BIT))
	{
		if (try_num <= 0)
			break;

		udelay(100);
		try_num--;
	}

	value = readl(X2_PLLCLK_SEL);
	value |= (VIOCLK_SEL_BIT | VIOCLK2_SEL_BIT);
	writel(value, X2_PLLCLK_SEL);

	writel(IAR_PIX_CLK_SRC_SEL(0)                  |
		   SENSOR3_MCLK_2ND_DIV_SEL(REFCLK_DIV(4)) |
		   SENSOR2_MCLK_2ND_DIV_SEL(REFCLK_DIV(4)) |
		   IAR_PIX_CLK_2ND_DIV_SEL(REFCLK_DIV(1))  |
		   IAR_PIX_CLK_1ST_DIV_SEL(REFCLK_DIV(10)) |
		   SIF_MCLK_DIV_SEL(REFCLK_DIV(3))         |
		   SENSOR_DIV_CLK_SRC_SEL(1)               |
		   SENSOR1_MCLK_2ND_DIV_SEL(REFCLK_DIV(4)) |
		   SENSOR0_MCLK_2ND_DIV_SEL(REFCLK_DIV(4)) |
		   SENSOR_MCLK_1ST_DIV_SEL(REFCLK_DIV(16)) ,
		   X2_VIOSYS_CLK_DIV_SEL1);

	writel(MIPI_TX_IPI_CLK_2ND_DIV_SEL(REFCLK_DIV(3)) |
		   MIPI_TX_IPI_CLK_1ST_DIV_SEL(REFCLK_DIV(1)) |
		   MIPI_CFG_CLK_2ND_DIV_SEL(REFCLK_DIV(4))    |
		   MIPI_CFG_CLK_1ST_DIV_SEL(REFCLK_DIV(4))    |
		   PYM_MCLK_SRC_SEL(1)                        |
		   PYM_MCLK_DIV_SEL(REFCLK_DIV(2))            |
		   MIPI_PHY_REFCLK_2ND_DIV_SEL(REFCLK_DIV(4)) |
		   MIPI_PHY_REFCLK_1ST_DIV_SEL(REFCLK_DIV(17)),
		   X2_VIOSYS_CLK_DIV_SEL2);

	writel(MIPI_RX3_IPI_CLK_2ND_DIV_SEL(REFCLK_DIV(3)) |
		   MIPI_RX3_IPI_CLK_1ST_DIV_SEL(REFCLK_DIV(1)) |
		   MIPI_RX2_IPI_CLK_2ND_DIV_SEL(REFCLK_DIV(3)) |
		   MIPI_RX2_IPI_CLK_1ST_DIV_SEL(REFCLK_DIV(1)) |
		   MIPI_RX1_IPI_CLK_2ND_DIV_SEL(REFCLK_DIV(3)) |
		   MIPI_RX1_IPI_CLK_1ST_DIV_SEL(REFCLK_DIV(1)) |
		   MIPI_RX0_IPI_CLK_2ND_DIV_SEL(REFCLK_DIV(3)) |
		   MIPI_RX0_IPI_CLK_1ST_DIV_SEL(REFCLK_DIV(1)) ,
		   X2_VIOSYS_CLK_DIV_SEL3);

	/* X2_VIOSYS_CLKEN_SET default on */

#define IPS_CLK_CTRL		 0xA400000C
#define IPS_CLK_CTRL_SIF     (1 << 0)
#define IPS_CLK_CTRL_ISP0    (1 << 1)
#define IPS_CLK_CTRL_DEW0    (1 << 3)
#define IPS_CLK_CTRL_DEW1    (1 << 4)
#define IPS_CLK_CTRL_GDC0    (1 << 5)
#define IPS_CLK_CTRL_GDC1    (1 << 6)
#define IPS_CLK_CTRL_LDC0    (1 << 9)
#define IPS_CLK_CTRL_LDC1    (1 << 10)
#define IPS_CLK_CTRL_IPU0    (1 << 11)
#define IPS_CLK_CTRL_PYM_UV  (1 << 13)
#define IPS_CLK_CTRL_PYM_US  (1 << 14)
#define IPS_CLK_CTRL_PYM_DDR (1 << 15)
#define IPS_CLK_CTRL_PYM_ISP (1 << 16)
#define IPS_CLK_CTRL_MD      (1 << 17)
#define IPS_CLK_CTRL_IRAM    (1 << 18)

	/* IPS Clock Enable */
	value = readl(IPS_CLK_CTRL);
	value = value                |
			IPS_CLK_CTRL_SIF     |
			IPS_CLK_CTRL_ISP0    |
			IPS_CLK_CTRL_DEW0    |
			IPS_CLK_CTRL_DEW1    |
			IPS_CLK_CTRL_GDC0    |
			IPS_CLK_CTRL_GDC1    |
			IPS_CLK_CTRL_LDC0    |
			IPS_CLK_CTRL_LDC1    |
			IPS_CLK_CTRL_IPU0    |
			IPS_CLK_CTRL_PYM_UV  |
			IPS_CLK_CTRL_PYM_US  |
			IPS_CLK_CTRL_PYM_DDR |
			IPS_CLK_CTRL_PYM_ISP |
			IPS_CLK_CTRL_MD      |
			IPS_CLK_CTRL_IRAM;

	writel(value, IPS_CLK_CTRL);
}

void vio_pll_init2(void)
{
#if 0
	unsigned int value;
	unsigned int try_num = 5;

	writel(PD_BIT | DSMPD_BIT | FOUTPOST_DIV_BIT | FOUTVCO_BIT,
		X2_VIOPLL2_PD_CTRL);

	value = readl(X2_VIOPLL2_PD_CTRL);
	value &= ~(PD_BIT | FOUTPOST_DIV_BIT);
	writel(value, X2_VIOPLL2_PD_CTRL);

	while (!(value = readl(X2_VIOPLL2_STATUS) & LOCK_BIT)) {
		if (try_num <= 0) {
			break;
		}

		udelay(100);
		try_num--;
	}
	value = readl(IPS_CLK_CTRL);
	value = value | IPS_CLK_CTRL_SIF | IPS_CLK_CTRL_IPU;
	writel(value, IPS_CLK_CTRL);
#endif
}

/* Update Peri PLL to 1536MHz*/
uint32_t g_peripll = X2_OSC_CLK;	// for clk of uart
static const uint32_t g_osc = X2_OSC_CLK;
void switch_peri_pll(void)
{
	unsigned int value;
	unsigned int try_num = 5;

	/* Switch clock to osc (24MHz) */
	value =readl(X2_PLLCLK_SEL) & (~PERICLK_SEL_BIT);
	writel(value, X2_PLLCLK_SEL);

	/* Disable power of peripheral's pll */
	writel(PD_BIT | DSMPD_BIT | FOUTPOST_DIV_BIT | FOUTVCO_BIT,X2_PERIPLL_PD_CTRL);

	/* Config freq of peripheral's pll (64*24MHz/1/1/1=1536MHz) */
	value = FBDIV_BITS(64) | REFDIV_BITS(1) |	POSTDIV1_BITS(1) | POSTDIV2_BITS(1);
	writel(value, X2_PERIPLL_FREQ_CTRL);

	/* Enable peripheral's pll */
	value = readl(X2_PERIPLL_PD_CTRL);
	value &= ~(PD_BIT | FOUTPOST_DIV_BIT);
	writel(value, X2_PERIPLL_PD_CTRL);

	/* Check if pll is locked */
	while (!(value = readl(X2_PERIPLL_STATUS) & LOCK_BIT)) {
		if (try_num <= 0) {
			break;
		}
		udelay(100);
		try_num--;
	}

	/* Switch clock to PERI pll */
	value = readl(X2_PLLCLK_SEL);
	value |= PERICLK_SEL_BIT;
	writel(value, X2_PLLCLK_SEL);

	value = readl(X2_PERIPLL_FREQ_CTRL);
	/* Hold the freq of peripheral pll */
	g_peripll = ((g_osc / GET_REFDIV(value)) * GET_FBDIV(value)) / GET_POSTDIV1(value) / GET_POSTDIV2(value);

	return;
}

void x2a_pll_sel(void)
{
	unsigned int value;
	value = readl(X2_PLLCLK_SEL);
	value |= (CPUCLK_SEL_BIT | SYSCLK_SEL_BIT);
	writel(value, X2_PLLCLK_SEL);

	return;
}
#endif /* CONFIG_SPL_BUILD */

