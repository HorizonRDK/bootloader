#include <asm/arch/x2_dev.h>
#include <asm/arch/x2a_def.h>
#include "x3_ddr.h"
#include "dwc_save_ret_regs_lp4.h"

void lpddr4_restore_param(uint32 restore_ctrl_reg)
{
	uint32 i = 0;
	uint32 controller_reg_cnt=reg32_read(SAVED_SUSPEND_CTRL_REG_CNT);
	uint32 phy_reg_cnt=reg32_read(SAVED_SUSPEND_PHY_REG_CNT);
	if((controller_reg_cnt+phy_reg_cnt)>(X2A_DDR_REG_SAVE_MAX_SIZE>>2)) {
		printf("error: saved param is over range (ctrl_reg_cnt=%d,phy_reg_cnt=%d)\n",controller_reg_cnt,phy_reg_cnt);
		return;
	}

	uint32 *p_umctrl_reg_store = (uint32 *)DDR_REG_SAVE_ADDR;
	uint32 *p_dwc_ddrphy_reg_store = (uint32 *)(DDR_REG_SAVE_ADDR + (uintptr_t)controller_reg_cnt * sizeof(uint32));
	uint32 umctrl_reg_save_addr = DDR_PARAM_SAVE_ADDR;
	uint32 dwc_ddrphy_reg_save_addr = DDR_PARAM_SAVE_ADDR + controller_reg_cnt * sizeof(uint32);

	DDR_LOG(DDR_LOG_INFO, "lpddr4_restore_param: enter (restore_ctrl_reg=%d)\n",restore_ctrl_reg);
	if(restore_ctrl_reg) {
		// restore ddr controller registers
		reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0);
		uint32 data;
		uint32 reg;
		for (i = 0; i < controller_reg_cnt; i++)
		{
			/* &0xffff for secure protect */
			reg = p_umctrl_reg_store[i]&0xffff;
			data = reg32_read(umctrl_reg_save_addr);
			reg32_write(DDRC_CFG_BASE + reg, data);
			umctrl_reg_save_addr += sizeof(uint32);
		}
		reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 1);
		//wait sw_done
		do{
			udelay(10);
		}while (!(reg32_read(DDRC_CFG_BASE + uMCTL2_SWSTAT) & 0x1));
		udelay(10);
	}else {
		// restore ddr phy registers
		reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x0);
		reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_DRTUB0__UcclkHclkEnables, 0x3);

		for (i = 0; i < phy_reg_cnt; i++)
		{
			/* &0xffffff for secure protect */
			reg32_write(DDRPHY_CFG_BASE + (p_dwc_ddrphy_reg_store[i]&0xffffff), reg32_read(dwc_ddrphy_reg_save_addr));
			dwc_ddrphy_reg_save_addr += sizeof(uint32);
		}
		reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_DRTUB0__UcclkHclkEnables, 0x2);
		reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x1);
	}
}

void axi_port_cfg (uint32 port_num, uint32 enable);

void ddr_io_retention_enter(void)
{
	uint32 i;

	//axi port en, all ports enable
	for (i = 0; i < AXI_PORT_NUM; i++)
	{
		axi_port_cfg(i, DISABLE);
	}

	do{
		udelay(10);
	}while(0x0 != (reg32_read(DDRC_CFG_BASE + uMCTL2_PSTAT)));
	udelay(10);
	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DERATEEN, 0x1);
	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_SBRCTL, 0x1);
	do{
		udelay(10);
	}while(0x1 == (reg32_read(DDRC_CFG_BASE + uMCTL2_SBRSTAT) & 0x1));
	udelay(10);
    reg32_write(DDRC_CFG_BASE + uMCTL2_DBG1, 0x2);
	do{
		udelay(10);
	}while(0x6000000 != (reg32_read(DDRC_CFG_BASE + uMCTL2_DBGCAM) & 0x6000000));
	udelay(10);
	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DFILPCFG0, 0x1);
	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DFILPCFG1, 0x1);
	do{
		udelay(10);
	}while(0x2 == (reg32_read(DDRC_CFG_BASE + uMCTL2_DFISTAT) & 0x2));
	udelay(10);
	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DFIPHYMSTR, 0x1);
	reg32_bits_set(DDRC_CFG_BASE + uMCTL2_PWRCTL, 0x20);
	do{
		udelay(10);
	}while(0x23 != (reg32_read(DDRC_CFG_BASE + uMCTL2_STAT) & 0x3f));
	udelay(10);
    reg32_write(DDRC_CFG_BASE + uMCTL2_DBG1, 0x3);
	do{
		udelay(10);
	}while(0x30000000 != (reg32_read(DDRC_CFG_BASE + uMCTL2_DBGCAM) & 0x30000000));
	udelay(10);
	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x0);

	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DFIMISC, 0x1);

	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x1);
	do{
		udelay(10);
	}while(0x0 == (reg32_read(DDRC_CFG_BASE + uMCTL2_SWSTAT) & 0x1));
	udelay(10);
    reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x0);

	reg32_bits_set(DDRC_CFG_BASE + uMCTL2_DFIMISC, 0x1f20);

    reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x1);
	do{
		udelay(10);
	}while(0x0 == (reg32_read(DDRC_CFG_BASE + uMCTL2_SWSTAT) & 0x1));
	udelay(10);
    //poll DFISTAT
	do{
		udelay(10);
	}while(0x1 == (reg32_read(DDRC_CFG_BASE + uMCTL2_DFISTAT) & 0x1));
	udelay(10);
    reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x0);
	reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_DRTUB0__UcclkHclkEnables, 0x3);
	do{
		udelay(10);
	}while(0x0 == (reg32_read(DDRPHY_CFG_BASE + DWC_DDRPHYA_INITENG0__PhyInLP3) & 0x1));
	udelay(10);

#ifdef VIRL_LPDDR34
	reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_DRTUB0__UcclkHclkEnables, 0x2);
#else
	reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_DRTUB0__UcclkHclkEnables, 0x0);
#endif

	reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x1);
	reg32_bits_set(DDRC_CFG_BASE + uMCTL2_PWRCTL, (1<<3));
	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x0);

	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DFIMISC, (1<<5));
	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x1);
	do{
		udelay(10);
	}while(0x0 == (reg32_read(DDRC_CFG_BASE + uMCTL2_SWSTAT) & 0x1));
	udelay(10);
	do{
		udelay(10);
	}while(0x0 == (reg32_read(DDRC_CFG_BASE + uMCTL2_DFISTAT) & 0x1));
	udelay(10);

    for (i=0; i<10; i++) {
        asm("nop");
    }

    reg32_write(X2A_PMU_DDRSYS_CTRL, 0x0);
    reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0xffffffff);
    reg32_write(DDRSYS_CLKEN_CLR, 0x1);

 }

void ddr_controller_cfg(struct DRAM_CFG_PARAM *ddrc_cfg, int num);
void dwc_ddrphy_phyinit_J_enterMissionMode (void);

extern struct BOARD_DDR_INFO board_ddr_info;
 void ddr_io_retention_exit(void)
 {
	unsigned int value, i;
	struct DRAM_TIMING_INFO *dram_timing = board_ddr_info.p_dram_timing;

	reg32_write(DDRSYS_CLKEN_SET, 0x1);

	//After power-up:
	reg32_write(X2A_PMU_DDRSYS_CTRL, 0x1);
	//1. Assert the core_ddrc_rstn and aresetn_n resets
	//2. Assert presetn
	//3. Start the clocks (pclk, core_ddrc_core_clk, aclk_n)


	//4. De-assert presetn once the clocks are active and stable
	reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0xfffffffe);
	//enable 2th DFI interface. only for lpddr4
	reg32_write(DDRC_PHY_DFI1_ENABLE, 0x1);

	reg32_write(DDRC_CFG_BASE + uMCTL2_DBG1, 0x1);
	reg32_write(DDRC_CFG_BASE + uMCTL2_PWRCTL, 0x1);

	//5. Allow 128 cycles for synchronization of presetn to core_ddrc_core_clk and aclk domains and to permit initialization of end logic
	do{
		udelay(10);
	}while ((reg32_read(DDRC_CFG_BASE + uMCTL2_STAT) & 0x7));
	udelay(10);

	//6. Initialize the registers

	//  DFIMISC.dfi_init_complete_en must be set to 0
	//  INIT0.skip_dram_init=2'b00
	//  RFSHCTL3.dis_auto_refresh=1
	//  PWRCTL.powerdown_en=0
	//  PWRCTL.selfref_en=0
	//  DERATEEN.derate_enable=0
	//  ZQCTL0.dis_auto_zq=1
	//  DFILPCFG0.dfi_lp_en_sr=0
	//  (Note 1)a   MRCTRL0.sw_init_int=1
	//  (Note 2)b
	ddr_controller_cfg(dram_timing->ddrc_cfg, dram_timing->ddrc_cfg_num);

	reg32_bits_write(DDRC_CFG_BASE + uMCTL2_RFSHCTL3, 0, 1, 0);
	//7. De-assert the resets (core_uMCTL2_rstn and aresetn_n)

	reg32_write(X2A_SYSC_DDRSYS_SW_RSTEN, 0x0);

	reg32_write(DDRC_CFG_BASE + uMCTL2_DBG1, 0x0);
#ifdef CONFIG_SUPPORT_PALLADIUM
	reg32_write(DDRC_CFG_BASE + uMCTL2_PWRCTL, 0x0);
#else
	reg32_write(DDRC_CFG_BASE + uMCTL2_PWRCTL, 0x120);
#endif /* CONFIG_SUPPORT_PALLADIUM */
	SETREG32(DDRC_CFG_BASE + uMCTL2_DERATEEN, 0x1404);
	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x0);

	/* DFIMISC.dfi_init_compelete_en to 0 */
	reg32_bits_clear(DDRC_CFG_BASE + uMCTL2_DFIMISC, (1 << 0));

	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x1);

	do{
		udelay(10);
	}while (!(reg32_read(DDRC_CFG_BASE + uMCTL2_SWSTAT) & 0x1));
	udelay(10);

	lpddr4_restore_param(1);
	lpddr4_restore_param(0);

	dwc_ddrphy_phyinit_J_enterMissionMode();

	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x0);
	//set DFIMISC.dfi_init_start to 0
	value = reg32_read(DDRC_CFG_BASE + uMCTL2_DFIMISC) & ~0x20;
	reg32_write(DDRC_CFG_BASE + uMCTL2_DFIMISC, value);


	reg32_write(DDRC_CFG_BASE + uMCTL2_DBG1, 0x1);


	reg32_write(DDRC_CFG_BASE + uMCTL2_DBG1, 0x0);

	//set DFIMISC.dfi_init_complete_en to 1
	reg32_bits_set(DDRC_CFG_BASE + uMCTL2_DFIMISC,0x1);

	reg32_write(DDRC_CFG_BASE + uMCTL2_SWCTL, 0x1);
	//wait sw_done
	do{
		udelay(10);
	}while (!(reg32_read(DDRC_CFG_BASE + uMCTL2_SWSTAT) & 0x1));
	udelay(10);

	//diff with EDA C
	value = reg32_read(DDRC_CFG_BASE + uMCTL2_PWRCTL) & ~0x20;
	reg32_write(DDRC_CFG_BASE + uMCTL2_PWRCTL, value);
	//wait operating mode = normal
	do{
		udelay(10);
	}while ((0x1 != (reg32_read(DDRC_CFG_BASE + uMCTL2_STAT) & 0x7)));
	udelay(10);
	//enable auto refresh
	//  auto_refresh_cfg(ENABLE);

	reg32_write(DDRC_CFG_BASE + uMCTL2_PWRCTL, 0x0);
	//axi port en, all ports enable
	for (i = 0; i < AXI_PORT_NUM; i++)
	{
		axi_port_cfg(i, ENABLE);
	}
	reg32_write(DDRPHY_CFG_BASE + DWC_DDRPHYA_APBONLY0__MicroContMuxSel, 0x1);
}
