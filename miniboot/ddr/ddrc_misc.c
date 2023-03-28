#include <stdio.h>
#include <linux/delay.h>
#include "x3_ddr.h"
#include "dwc_ddrphy_phyinit_dmem_struct_16b.h"
#include "dwc_ddrphy_phyinit_dmem_2d_struct_16b.h"

extern uint64 umctl_reg_addr_base;
extern struct BOARD_DDR_INFO board_ddr_info;
extern struct DMEM_DDR4_STRUCT_16B *p_dmem_ddr4_16b;
extern struct DMEM_LPDDR4_STRUCT_16B *p_dmem_lpddr4_16b;
extern struct DMEM_DDR4_2D_STRUCT_16B *p_dmem_ddr4_2d_16b;
extern struct DMEM_LPDDR4_2D_STRUCT_16B *p_dmem_lpddr4_2d_16b;
extern struct DDRC_INFO ddrc_info;
void axi_port_cfg (uint32 port_num, uint32 enable);

void ddrc_qos_cfg(void)
{
    reg32_write((umctl_reg_addr_base + uMCTL2_SCHED), 0x20003901 );     // 0x250    //// CAM 64 entry: HPR  6-entry), (VPR & LPR) 58-entry

    /* port0 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_0), 0x0000707f );   // 0x404
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_0), 0x0000707f );   // 0x408
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_0), 0x021000b );    // 0x494
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_0), 0x007fff00 );    // 0x498
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_0), 0x01100a03 );   // 0x49c
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_0), 0x007fff00 );   // 0x4a0

    /* port1 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_1), 0x0000707f );       // 0x4b4
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_1), 0x0000707f );       // 0x4b8
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_1), 0x0210000b );    // 0x544
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_1), 0x007fff00 );    // 0x548
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_1), 0x01100a03 );   // 0x54c
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_1), 0x007fff00 );   // 0x550

    /* port2 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_2), 0x0000707f );       // 0x564
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_2), 0x0000707f );       // 0x568
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_2), 0x0210000b );    // 0x5f4
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_2), 0x007fff00 );    // 0x5f8
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_2), 0x01100a03 );   // 0x5fc
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_2), 0x007fff00 );   // 0x600

    /* port3 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_3), 0x0000707f );       // 0x614
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_3), 0x0000707f );       // 0x618
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_3), 0x0210000b );    // 0x6a4
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_3), 0x007fff00 );    // 0x6a8
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_3), 0x01100a03 );   // 0x6ac
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_3), 0x007fff00 );   // 0x6b0

    /* port4 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_4), 0x0000707f );       // 0x6c4
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_4), 0x0000707f );       // 0x6c8
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_4), 0x0210000b );    // 0x754
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_4), 0x007fff00 );    // 0x758
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_4), 0x01100a03 );   // 0x75c
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_4), 0x007fff00 );   // 0x760

    /* port5 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_5), 0x0000707f );       // 0x774
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_5), 0x0000707f );       // 0x778
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_5), 0x0210000b );    // 0x804
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_5), 0x007fff00 );    // 0x808
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_5), 0x01100a03 );   // 0x80c
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_5), 0x007fff00 );   // 0x810

    /* port6 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_6), 0x0000707f );       // 0x824), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_6), 0x0000707f );       // 0x828), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_6), 0x0210000b );    // 0x8b4), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_6), 0x007fff00 );    // 0x8b8), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_6), 0x01100a03 );   // 0x8bc), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_6), 0x007fff00 );   // 0x8c0), A

    /* port7 */
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGR_7), 0x0000707f );       // 0x8d4), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGW_7), 0x0000707f );       // 0x8d8), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS0_7), 0x0210000b );    // 0x964), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGQOS1_7), 0x007fff00 );    // 0x968), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS0_7), 0x01100a03 );   // 0x96c), A
    reg32_write((umctl_reg_addr_base + uMCTL2_PCFGWQOS1_7), 0x007fff00 );   // 0x970), A

}

/* call this function after umctrl configed, before train start. If you want enable read dbi*/
void read_dbi_cfg (uint32 data)
{
	DEBUG_LOG("read_dbi:%x\n",data);
       reg32_bits_write((umctl_reg_addr_base + uMCTL2_DBICTL), 2, 1, data);     // 0x1C0    ////[2]:0,disable rd dbi; 1, enable rd dbi.
       if (1 == data)
       {
#ifndef MULTI_FILES
#if !defined(WARM_BOOT_SPL)

	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		p_dmem_lpddr4_16b->MR3_A0 |= (1 << 6);
		p_dmem_lpddr4_16b->MR3_A1 |= (1 << 6);
		p_dmem_lpddr4_16b->MR3_B0 |= (1 << 6);
		p_dmem_lpddr4_16b->MR3_B1 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_A0 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_A1 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_B0 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_B1 |= (1 << 6);
		#endif
	}
#endif
#endif
			   if (4266 == board_ddr_info.datarate)
			   {
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG0), 16, 7, 0x23);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG2), 8, 7, 0x23);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 16, 6, 0x14);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 8, 6, 0x18);
			   }
			   else if (3733 == board_ddr_info.datarate)
			   {
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG0), 16, 7, 0x1f);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG2), 8, 7, 0x1f);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 16, 6, 0x12);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 8, 6, 0x17);
			   }
			   else if (3200 == board_ddr_info.datarate)
			   {
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG0), 16, 7, 0x1B);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG2), 8, 7, 0x1B);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 16, 6, 0x10);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 8, 6, 0x14);
			   }
			   else if (2666 == board_ddr_info.datarate)
			   {
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG0), 16, 7, 0x17);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG2), 8, 7, 0x17);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 16, 6, 0x0D);
			      reg32_bits_write((umctl_reg_addr_base + uMCTL2_DRAMTMG2), 8, 6, 0x13);
			   }
			   else
			   {
			      /* invalid ddr frequency */
			   }
       }
#ifndef MULTI_FILES
#if !defined(WARM_BOOT_SPL)
       else
       {
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		p_dmem_lpddr4_16b->MR3_A0 &= (~(1 << 6));
		p_dmem_lpddr4_16b->MR3_A1 &= (~(1 << 6));
		p_dmem_lpddr4_16b->MR3_B0 &= (~(1 << 6));
		p_dmem_lpddr4_16b->MR3_B1 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_A0 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_A1 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_B0 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_B1 &= (~(1 << 6));
		#endif
	}
       }
#endif
#endif
}


/* call this function after umctrl configed, before train start. If you want enable write dbi*/
void write_dbi_cfg (uint32 data)
{
	DEBUG_LOG("write_dbi:%x\n",data);
       reg32_bits_write((umctl_reg_addr_base + uMCTL2_DBICTL), 1, 1, data);     // 0x1C0    ////[1]:0,disable wd dbi; 1, enable wd dbi.

#ifndef MULTI_FILES
#if !defined(WARM_BOOT_SPL)
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		#if LPDDR4_ENABLED == 1
		if (1 == data) {
			p_dmem_lpddr4_16b->MR3_A0 |= (1 << 7);
			p_dmem_lpddr4_16b->MR3_A1 |= (1 << 7);
			p_dmem_lpddr4_16b->MR3_B0 |= (1 << 7);
			p_dmem_lpddr4_16b->MR3_B1 |= (1 << 7);
			p_dmem_lpddr4_2d_16b->MR3_A0 |= (1 << 7);
			p_dmem_lpddr4_2d_16b->MR3_A1 |= (1 << 7);
			p_dmem_lpddr4_2d_16b->MR3_B0 |= (1 << 7);
			p_dmem_lpddr4_2d_16b->MR3_B1 |= (1 << 7);
		} else {
			p_dmem_lpddr4_16b->MR3_A0 &= (~(1 << 7));
			p_dmem_lpddr4_16b->MR3_A1 &= (~(1 << 7));
			p_dmem_lpddr4_16b->MR3_B0 &= (~(1 << 7));
			p_dmem_lpddr4_16b->MR3_B1 &= (~(1 << 7));
			p_dmem_lpddr4_2d_16b->MR3_A0 &= (~(1 << 7));
			p_dmem_lpddr4_2d_16b->MR3_A1 &= (~(1 << 7));
			p_dmem_lpddr4_2d_16b->MR3_B0 &= (~(1 << 7));
			p_dmem_lpddr4_2d_16b->MR3_B1 &= (~(1 << 7));
		}
		#endif
	}else {
		#if DDR4_ENABLED == 1
		if (1 == data) {
			p_dmem_ddr4_16b->MR_5 |= (1 << 11);
			p_dmem_ddr4_2d_16b->MR_5 |= (1 << 11);
		} else {
			p_dmem_ddr4_16b->MR_5 &= (~(1 << 11));
			p_dmem_ddr4_2d_16b->MR_5 &= (~(1 << 11));
		}
		#endif
	}
#endif
#endif
}

/* call this function after umctrl configed, before train start. If you want enable write dbi*/
void mask_write_cfg (uint32 data)
{
       reg32_bits_write((umctl_reg_addr_base + uMCTL2_DBICTL), 0, 1, data);     // 0x1C0    ////[0]:0,disable mask write; 1, enable mask write.

#ifndef MULTI_FILES
#if !defined(WARM_BOOT_SPL)
	if ((hb_ddr_type == DDR_TYPE_LPDDR4)||((hb_ddr_type == DDR_TYPE_LPDDR4X))) {
		if (0 == data) {
			p_dmem_lpddr4_16b->MR13_A0 |= (1 << 5);
			p_dmem_lpddr4_16b->MR13_A1 |= (1 << 5);
			p_dmem_lpddr4_16b->MR13_B0 |= (1 << 5);
			p_dmem_lpddr4_16b->MR13_B1 |= (1 << 5);
			p_dmem_lpddr4_2d_16b->MR13_A0 |= (1 << 5);
			p_dmem_lpddr4_2d_16b->MR13_A1 |= (1 << 5);
			p_dmem_lpddr4_2d_16b->MR13_B0 |= (1 << 5);
			p_dmem_lpddr4_2d_16b->MR13_B1 |= (1 << 5);
		} else {
			p_dmem_lpddr4_16b->MR13_A0 &= (~(1 << 5));
			p_dmem_lpddr4_16b->MR13_A1 &= (~(1 << 5));
			p_dmem_lpddr4_16b->MR13_B0 &= (~(1 << 5));
			p_dmem_lpddr4_16b->MR13_B1 &= (~(1 << 5));
			p_dmem_lpddr4_2d_16b->MR13_A0 &= (~(1 << 5));
			p_dmem_lpddr4_2d_16b->MR13_A1 &= (~(1 << 5));
			p_dmem_lpddr4_2d_16b->MR13_B0 &= (~(1 << 5));
			p_dmem_lpddr4_2d_16b->MR13_B1 &= (~(1 << 5));
		}
	}
#endif
#endif
}

unsigned int ddr_map_addr[12] = {
	uMCTL2_ADDRMAP0, uMCTL2_ADDRMAP1, uMCTL2_ADDRMAP2, uMCTL2_ADDRMAP3,
	uMCTL2_ADDRMAP4, uMCTL2_ADDRMAP5, uMCTL2_ADDRMAP6, uMCTL2_ADDRMAP7,
	uMCTL2_ADDRMAP8, uMCTL2_ADDRMAP9, uMCTL2_ADDRMAP10, uMCTL2_ADDRMAP11,
};

unsigned int lpddr4_ecc_map_micorn[12] = {
	0x001F1F14, 0x00050505, 0x00000000, 0x14141400,
	0x00001F1F, 0x040F0404, 0x04040404, 0x00000F0F,
	0x00003F3F, 0x04040404, 0x04040404, 0x001F1F04,
};

unsigned int lpddr4_ecc_map_x3_hynix[12] = {
	0x001F1F1F, 0x00050505, 0x00000000, 0x12121200,
	0x00001F1F, 0x040F0404, 0x0F040404, 0x00000F0F,
	0x00003F3F, 0x04040404, 0x04040404, 0x001F1F04,
};

unsigned int lpddr4_ecc_map_j3_hynix[12] = {
	0x001F1F1F, 0x00050505, 0x00000000, 0x13131300,
	0x00001F1F, 0x040F0404, 0x04040404, 0x00000F0F,
	0x00003F3F, 0x04040404, 0x04040404, 0x001F1F04,
};

unsigned int ddr4_ecc_map_micron[12] = {
	0x001F1F1F, 0x003F0505, 0x00000000, 0x12121200,
	0x00001F1F, 0x040F0404, 0x0F040404, 0x00000F0F,
	0x00003F07, 0x04040404, 0x04040404, 0x001F1F04,
};

unsigned int ddr4_ecc_map_samsung[12] = {
	0x001F1F1F, 0x003F0505, 0x00000000, 0x13131300,
	0x00001F1F, 0x040F0404, 0x04040404, 0x00000F0F,
	0x00003F07, 0x04040404, 0x04040404, 0x001F1F04,
};

/* inline ECC config */
void ddr_inline_ecc_cfg (uint32 data, uint8 gran)
{
	unsigned int *value = NULL;
	unsigned int i = 0;
	unsigned int *addr = ddr_map_addr;

	DEBUG_LOG("inline_ecc:%x\n", data);

	if (0 == data) {
		reg32_bits_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 0, 3, 0);
		return;
	}
	reg32_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 0x013f7f04);
	reg32_bits_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 30, 2, gran);
	reg32_write((umctl_reg_addr_base + uMCTL2_ECCCFG1), 0x00000790);
	reg32_write((umctl_reg_addr_base + uMCTL2_ECCCTL), 0x00000000);

	if (hb_ddr_part_number == MT53D1024M32D4DT) {
		/* JM */
		value = lpddr4_ecc_map_micorn;

	} else if (hb_ddr_part_number == H9HCNNN8KUMLHR){
		/* XH */
		value = lpddr4_ecc_map_x3_hynix;

	} else if (hb_ddr_part_number == H9HCNNNBKUMLHE) {
		/* JH */
		value = lpddr4_ecc_map_j3_hynix;

	} else if (hb_ddr_part_number == MT40A256M16LY) {
		/* ddr4 micron */
		value = ddr4_ecc_map_micron;

	} else if (hb_ddr_part_number == K4A8G165WC) {
		/* ddr4 samsung */
		value = ddr4_ecc_map_samsung;
	} else {
		/* default */
		value = lpddr4_ecc_map_j3_hynix;
	}

	for (i = 0; i < 12; i++) {
		reg32_write((umctl_reg_addr_base + *(addr + i)),  *(value + i));
	}
}

#define INLINE_ECC_TEST_ADDR_START		0x100000
#define INLINE_ECC_TEST_ADDR_END		0x200000

#define ECC_1_BIT_START					INLINE_ECC_TEST_ADDR_START
#define ECC_1_BIT_TEST_SIZE				(32*8)
#define ECC_2_BIT_START					(ECC_1_BIT_START+ECC_1_BIT_TEST_SIZE)
#define ECC_2_BIT_TEST_SIZE				(32*32*8)
#define ECC_MULTI_BIT_START				(ECC_2_BIT_START+ECC_2_BIT_TEST_SIZE)
#define ECC_MULTI_BIT_TEST_SIZE			(30*2)
void inline_ecc_test (uint64 addr_start, uint64 addr_end, uint8 check_result, uint8 map)
{
	uint32 i = 0, j = 0;
	uint32 data_len = 0;
	uint32 data_cnt = 0;
	uint64 addr_start_save = addr_start;

	data_len = sizeof(uint64);

	printf("%s: start to set pattern\n", __func__);
	/* ragion map all protected */
	ddrc_info.p_umctl_reg->SWCTL = (0x0);
	reg32_bits_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 8, 7, (uint32)map);
	ddrc_info.p_umctl_reg->SWCTL = (0x1);
	do{
		udelay(10);
	}while(1 != (ddrc_info.p_umctl_reg->SWSTAT & (0x1 << BIT0)));
	udelay(10);

	/* fill zero to memory */
	for (i = addr_start; i < addr_end; i += data_len) {
		writeq(0, (unsigned long)i);
	}

	/* ragion map all unprotected */
	ddrc_info.p_umctl_reg->SWCTL = (0x0);
	reg32_bits_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 8, 7, 0x0);
	ddrc_info.p_umctl_reg->SWCTL = (0x1);
	do{
		udelay(10);
	}while(1 != (ddrc_info.p_umctl_reg->SWSTAT & (0x1 << BIT0)));
	udelay(10);

	/* fill addr value to memory */
	for (i = addr_start; i < addr_end; i += data_len) {
		reg32_write(i, i);
	}

	for (i = addr_start; i < addr_end; i += data_len) {
		if (i != reg32_read(i)) {
			printf("read fail, offset %8x, read data %8x.\n", i, reg32_read((uint64)i));
		}
	}

	/* 1 bit pattern : 32*8bytes */
	data_cnt=32;
	for (i=0; i<data_cnt; i++) {
		reg32_write((uint64)(i*data_len)+addr_start, (1<<i));
	}
	addr_start+=(uint64)(data_cnt*data_len);

	/* 2 bit pattern : 32*32*8bytes */
	data_cnt=32;
	uint32 or_data=0;
	for (i=0; i<data_cnt; i++) {
		for (j=0; j<data_cnt; j++) {
			if(i==j)
				or_data = (i<31)? (1<<(i+1)) : 1;
			else
				or_data = 0;
			reg32_write((uint64)(((i*data_cnt)+j)*data_len)+addr_start, (1<<i)|(1<<j)|or_data);
		}
	}
	addr_start+=(uint64)(data_cnt*data_cnt*data_len);

	/* multi bits pattern : 32*32*8bytes */
	data_cnt=30;
	for (i=0;i<data_cnt;i++) {
		reg32_write((uint64)(i*data_len)+addr_start, (uint32)(0xffffffff<<i));
	}
	addr_start+=(uint64)(data_cnt*data_len);
	for (i=0;i<data_cnt;i++) {
		reg32_write((uint64)(i*data_len)+addr_start, (uint32)(0xffffffff>>i));
	}
	addr_start+=(uint64)(data_cnt*data_len);


	/* ragion map all protected */
	ddrc_info.p_umctl_reg->SWCTL = (0x0);
	reg32_bits_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 8, 7, (uint32)map);
	ddrc_info.p_umctl_reg->SWCTL = (0x1);
	do{
		udelay(10);
	}while(1 != (ddrc_info.p_umctl_reg->SWSTAT & (0x1 << BIT0)));
	udelay(10);

	if(check_result) {
		// read 1 bit pattern for ecc test
		for (i = addr_start_save; i < (ECC_1_BIT_TEST_SIZE/data_len); i += data_len) {
			if (0 != reg32_read(i)) {
				printf("inline ecc check result: read fail, offset %8x, read data %8x.\n", i, reg32_read((uint64)i));
			}
		}
		printf("%s: check result end\n", __func__);
		while(1);
	}
	printf("%s: %d\n", __func__, __LINE__);
}


void phy_period_update (uint32 en, uint32 cycle)
{
	reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFIUPD2), 31, 1, en);
	reg32_bits_write((umctl_reg_addr_base + uMCTL2_DFITMG0), 24, 5, cycle);
}

#define SBRWDATA_PATTERN0 (0x0)//(0x5a5a5a5a)
#define SBRWDATA_PATTERN1 (0x3c3c3c3c)
#define T_SCRUBI (0x3f)
#define SBRSTART0_ADDR (0x0)
#define SBRSTART1_ADDR (0x0)
#define SBRRANGE0_ADDR (0x37FFFFFF) // (DDR vaild highest address * 7/8 >> 2)
#define SBRRANGE1_ADDR (0x0)

void hobot_snps_scrub_test(uint32 sbr_write_en, uint8 map,  uint32 sbr_cyc_en)
{
	uint32 i = 0;
	uint32 range_addr = 0;

	DEBUG_LOG("%s: %d\n", __func__, __LINE__);
	if (sbr_write_en) {
		if ((hb_ddr_part_number == H9HCNNNBKUMLHE) ||
			(hb_ddr_part_number == K4A8G165WC))
			/* 2G */
			range_addr = 0x1BFFFFFF;
		else if (hb_ddr_part_number == MT53D1024M32D4DT)
			/* 4G */
			range_addr = 0x37FFFFFF;
		else
			/* 1G */
			range_addr = 0xDFFFFFF;

		DEBUG_LOG("range_addr: 0x%x\n", range_addr);

		/*
		 * 1. If MEMC_INLINE_ECC is defined and ECC is enabled,
		 * set ECCCFG1.ecc_region_parity_lock to 1.
		 */
		ddrc_info.p_umctl_reg->SWCTL = (0x0);
		ddrc_info.p_umctl_reg->ECCCFG1 |= (0x1 << BIT4);
		ddrc_info.p_umctl_reg->SWCTL = (0x1);
		do{
			udelay(10);
		}while(1 != (ddrc_info.p_umctl_reg->SWSTAT & (0x1 << BIT0)));
		udelay(10);
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		/*
		 * 2. Ensure that PCTRL_n.port_en are set to 0,
		 * block the AXI ports from taking the transaction.
		 * axi port en, all ports disable
		 */
		for (i = 0; i < AXI_PORT_NUM; i++) {
			axi_port_cfg(i, DISABLE);
		}
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		/*
		 * 3. If UMCTL2_OCECC_EN is defined and On-chip ECC is
		 * enabled(OCECCCFG0.ocecc_en = 1), set OCECCCFG0.ocecc_en to 0.
		 * This is required to avoid On-chip ECC error interrupt.
		 */

		/* 4. Set SBRCTL.scrub_mode = 1. */
		ddrc_info.p_umctl_reg->SBRCTL |= (0x1 << BIT2);

		/* 5. Set SBRCTL.scrub_interval = 0. */
		ddrc_info.p_umctl_reg->SBRCTL &= 0x0f;
		ddrc_info.p_umctl_reg->SBRCTL |= 0x30;
		ddrc_info.p_umctl_reg->SBRSTART0 = SBRSTART0_ADDR;
		ddrc_info.p_umctl_reg->SBRSTART1 = SBRSTART1_ADDR;
		ddrc_info.p_umctl_reg->SBRRANGE0 = range_addr;
		ddrc_info.p_umctl_reg->SBRRANGE1 = SBRRANGE1_ADDR;
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		/* 6. Set the desired pattern through SBRWDATA0 and SBRWDATA1 registers. */
		ddrc_info.p_umctl_reg->SBRWDATA0 = SBRWDATA_PATTERN0;

		/* 7. Enable the SBR by programming SBRCTL.scrub_en = 1. */
		ddrc_info.p_umctl_reg->SBRCTL |= (0x1 << BIT0);

		/* 8. Poll SBRSTAT.scrub_done = 1 (all scrub writes commands have been sent). */
		do{
			udelay(10);
		}while((1 << BIT1) != (ddrc_info.p_umctl_reg->SBRSTAT & (0x1 << BIT1)));
		udelay(10);
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		/* 9. Poll SBRSTAT.scrub_busy = 0 (all scrub writes data have been sent). */
		do{
			udelay(10);
		}while(1 == (ddrc_info.p_umctl_reg->SBRSTAT & (0x1 << BIT0)));
		udelay(10);
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		/* 10. Disable SBR by programming SBRCTL.scrub_en = 0. */
		ddrc_info.p_umctl_reg->SBRCTL &= (~(0x1 << BIT0));

		/*
		 * 11. If UMCTL2_OCECC_EN is defined,
		 * enable On-chip ECC by programming OCECCCFG0.ocecc_en to 1.
		 */
		if (sbr_cyc_en) {
			/*
			 * 12. Prepare for normal scrub operation (Reads) by programming SBRCTL.
			 * scrub_mode = 0 and SBRCTL.scrub_interval to tSCRUBI.
			 */
			ddrc_info.p_umctl_reg->SBRCTL &= (~(0x1 << BIT0));
			ddrc_info.p_umctl_reg->SBRCTL &= ~(0xffffff << BIT8);
			ddrc_info.p_umctl_reg->SBRCTL |= (T_SCRUBI << BIT8);
			ddrc_info.p_umctl_reg->SBRCTL &= (~(0x1 < BIT2));

			/* 13. Enable the SBR by programming SBRCTL.scrub_en = 1. */
			ddrc_info.p_umctl_reg->SBRCTL |= (0x1 << BIT0);
		}

		/* 14. Enable AXI ports by programming PCTRL_n.port_en = 1. */
		ddrc_info.p_umctl_reg->SWCTL = (0x0);
		// ddrc_info.p_umctl_reg->ECCCFG1 &= (~(0x1 << BIT4));
		ddrc_info.p_umctl_reg->ECCCFG0 |= (0x1 << BIT4);
		reg32_bits_write((umctl_reg_addr_base + uMCTL2_ECCCFG0), 8, 7, map);
		ddrc_info.p_umctl_reg->SWCTL = (0x1);
		do{
			udelay(10);
		}while(1 != (ddrc_info.p_umctl_reg->SWSTAT & (0x1 << BIT0)));
		udelay(10);
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		/* axi port en, all ports enable */
		for (i = 0; i < AXI_PORT_NUM; i++) {
			axi_port_cfg(i, ENABLE);
		}
		DEBUG_LOG("%s: %d\n", __func__, __LINE__);

		DDR_LOG(DDR_LOG_DEBUG, "%s done\n", __func__);
	}
}
