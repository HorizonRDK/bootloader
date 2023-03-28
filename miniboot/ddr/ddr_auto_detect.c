
#include "x3_ddr.h"
#include "ddr.h"
#include <asm/arch/x2a_dev.h>
extern struct DDRC_INFO ddrc_info;
struct UMCTL_REGS* p_umctl_reg;
extern uint64 umctl_reg_addr_base;
extern struct BOARD_DDR_INFO board_ddr_info;
#define DCH_BIT0_OFFSET 16
#define CS_BIT1_OFFSET 8
#define CS_BIT0_OFFSET 0
#define BANK_B2_OFFSET 16
#define BANK_B1_OFFSET 8
#define BANK_B0_OFFSET 0
#define COL_B5_OFFSET 24
#define COL_B4_OFFSET 16
#define COL_B3_OFFSET 8
#define COL_B2_OFFSET 0
#define COL_B9_OFFSET 24
#define COL_B8_OFFSET 16
#define COL_B7_OFFSET 8
#define COL_B6_OFFSET 0
#define COL_ADDR_SHIFT_OFFSET 31
#define COL_B11_OFFSET 8
#define COL_B10_OFFSET 0
#define ROW_B11_OFFSET 24
#define ROW_B2_10_OFFSET 16
#define ROW_B1_OFFSET 8
#define ROW_B0_OFFSET 0
#define LPDDR3_6GB_12GB_OFFSET 31
#define LPDDR4_3GB_6GB_12GB_OFFSET 29
#define ROW_B15_OFFSET 24
#define ROW_B14_OFFSET 16
#define ROW_B13_OFFSET 8
#define ROW_B12_OFFSET 0
#define ROW_B17_OFFSET 8
#define ROW_B16_OFFSET 0
#define BG_B1_OFFSET 8
#define BG_B0_OFFSET 0
#define ROW_B5_OFFSET 24
#define ROW_B4_OFFSET 16
#define ROW_B3_OFFSET 8
#define ROW_B2_OFFSET 0
#define ROW_B9_OFFSET 24
#define ROW_B8_OFFSET 16
#define ROW_B7_OFFSET 8
#define ROW_B6_OFFSET 0
#define CID_B1_OFFSET 16
#define CID_B0_OFFSET 8
#define ROW_B10_OFFSET 0

#ifdef YMODEM_BOOT
extern uint16 ddr_parameter[BL2_UART_DDR_PARAMTER_MAX_SIZE];
extern struct hb_ddr_uart_hdr ddr_hdr_uart;
#else
extern uint16 ddr_parameter[BL2_DDR_PARAMTER_MAX_SIZE];
extern struct hb_ddr_hdr ddr_hdr;
#endif
extern struct x2a_info_hdr g_binfo;

char samsung_string[]="Samsung";
char nanya_string[]="Nanya";
char hynix_string[]="SK hynix";
char winbond_string[]="Winbond";
char esmt_string[]="ESMT";
char uniic_string[]="Xi'an UniIC Semiconductors Co.,Ltd";
char jsc_string[]="JSC";
char fidelix_string[]="Fidelix";
char ultra_string[]="Ulra Memeory";
char ap_string[]="AP Memeory";
char micron_string[]="Micron";

struct LP4_MANU_ID
{
	uint8 manu_id_value;
	char *p_manu_name;
};

struct LP4_MANU_ID manu_id_valid_list[] = {
	{0x01, samsung_string},
	{0x05, nanya_string},
	{0x06, hynix_string},
	{0x08, winbond_string},
	{0x09, esmt_string},
	{0x1A, uniic_string},
	{0x1C, jsc_string},
	{0xF8, fidelix_string},
	{0xF9, ultra_string},
	{0xFD, ap_string},
	{0xFF, micron_string},
};

struct LP4_TYPE type_valid_list[] = {
	{PER_CHN_16,	0x10}
	};
struct LP4_DENSITY density_valid_list[] = {
	{PER_CHN_2Gb,		0x10000000,	14,	3,	10},
	{PER_CHN_3Gb,		0x18000000,	15,	3,	10},
	{PER_CHN_4Gb,		0x20000000,	15,	3,	10},
	{PER_CHN_6Gb,		0x30000000,	16,	3,	10},
	{PER_CHN_8Gb,		0x40000000,	16,	3,	10},
	{PER_CHN_12Gb,		0x60000000,	17,	3,	10},
	{PER_CHN_16Gb,		0x80000000,	17,	3,	10},
	{PER_CHN_1Gb,		0x08000000,	13,	3,	10}
	};
struct LP4_IO_WIDTH io_width_valid_list[] = {
	{PER_CHN_16,	0x10},
	{PER_CHN_8,	0x8}
	};
struct SDRAM_INFO sdram_info = {
	.cs_num = 1,
	{0xFF, 0xFF},
	{0xFF, 0xFF},
	{
		{
		.type = LPDDR4,
		.density = 0x40000000,
		.io_width = 16,
		.row_num = 16,
		.bank_num = 3,
		.col_num = 10,
		},
		{
		.type = LPDDR4,
		.density = 0x40000000,
		.io_width = 16,
		.row_num = 16,
		.bank_num = 3,
		.col_num = 10,
		}
	},
};
uint32 ddr_cs_num = 2;

/* mrr opperation */
uint32 lpddr4_mrr (uint32 mr_rank, uint32 mr_addr)
{
	p_umctl_reg = ddrc_info.p_umctl_reg;
	while((p_umctl_reg->MRSTAT) & 0x1) {
		printf("%s  mr_rd_busy assert!\n", __func__);
		udelay(1);
	}
	p_umctl_reg->MRCTRL1 = ((mr_addr & 0xff) << 8);		//lpddr4 mr address.
	p_umctl_reg->MRCTRL0 = (((1 << mr_rank) & 0x3) << 4) | 0x1 ;		//rank & read type
	p_umctl_reg->MRCTRL0 |= (1<<31);  // bit31 mr_wr , trigger mr operation

	uint32 reg1, reg2, RD0, RD1, RD2, RD3;
	do{
		udelay(1);
		reg1=p_umctl_reg->MRCTRL0;
	}while(reg1 & (1<<31));

	do{
		udelay(1);
		reg2=p_umctl_reg->MRSTAT;
	}while(reg2 & 0x1);
	udelay(10);

	RD0=reg32_read(DDR_SW_REG_DDR_MSG_MRR_DATA_RD_0);
	RD1=reg32_read(DDR_SW_REG_DDR_MSG_MRR_DATA_RD_1);
	RD2=reg32_read(DDR_SW_REG_DDR_MSG_MRR_DATA_RD_2);
	RD3=reg32_read(DDR_SW_REG_DDR_MSG_MRR_DATA_RD_3);
	if((RD0!=RD1) || (RD0!=RD2) || (RD0!=RD3) ||
		(RD1!=RD2) || (RD1!=RD3) || (RD2!=RD3) ) {
		printf("error: lpddr4 mr%d (rank=0x%x, MRCTRL0=0x%x, MRSTAT=0x%x, MSTR=0x%x) : 0x%x 0x%x 0x%x 0x%x\n",
			mr_addr, mr_rank, reg1, reg2, p_umctl_reg->MSTR,
			RD0,RD1,RD2,RD3);
	} else {
		printf("lpddr4 mr%d (rank=0x%x, MRCTRL0=0x%x, MRSTAT=0x%x, MSTR=0x%x) : 0x%x 0x%x 0x%x 0x%x\n",
			mr_addr, mr_rank, reg1, reg2, p_umctl_reg->MSTR,
			RD0,RD1,RD2,RD3);
	}

	return ((reg32_read(DDR_SW_REG_DDR_MSG_MRR_DATA_RD_0)>>16)&0xff);	//need shift if there is bytes swap
}

/* mrw opperation */
void lpddr4_mrw (uint32 mr_rank, uint32 mr_addr, uint32 mr_data)
{
	p_umctl_reg = ddrc_info.p_umctl_reg;
	while(p_umctl_reg->MRSTAT & 0x1) //polling mr_wr_busy == 0
	{
		printf("__func__ mr_wr_busy assert!\n");
	}
	p_umctl_reg->MRCTRL1 = ((mr_addr & 0xff) << 8) | (mr_data);		//lpddr4 mr address & mr_data
	p_umctl_reg->MRCTRL0 = (((1 << mr_rank) & 0x3) << 4) & (~0x1) ;		//rank & read type
	p_umctl_reg->MRCTRL0 |= (0x1 << 31);  // bit31 mr_wr
	while(p_umctl_reg->MRSTAT & 0x1); //polling mr_wr_busy == 0
}

/* mr8 value anlysis */
void lp4_mr8_anlysis (struct LP4_MR8_T *mr8_info, uint32 mr8_value)
{
	uint32 i, loop_n;
	uint32 mr8_io_width, mr8_type, mr8_density;
	mr8_type = (mr8_value >> 2) & (0x3);
	mr8_density = (mr8_value >> 2) & (0xf);
	mr8_io_width = (mr8_value >> 6) & (0x3);
	/* type */
	loop_n = ARRAY_SIZE(type_valid_list);
	for (i = 0; i < loop_n; i++)
	{
		if (type_valid_list[i].mr8_type_cryp == mr8_type)
		{
			mr8_info->type = type_valid_list[i].type;
			break;
		}
	}
	if (i >= loop_n)
	{
		printf("type invaild. mr8 value is %x\n", mr8_value);
		while_loop();
	}
	/* density */
	loop_n = ARRAY_SIZE(density_valid_list);
	for (i = 0; i < loop_n; i++)
	{
		if (density_valid_list[i].mr8_density_cryp ==  mr8_density)
		{
			mr8_info->density = density_valid_list[i].density;
			mr8_info->row_num = density_valid_list[i].row_num;
			mr8_info->bank_num = density_valid_list[i].bank_num;
			mr8_info->col_num = density_valid_list[i].col_num;
			break;
		}
	}
	if (i >= loop_n)
	{
		printf("density invaild. mr8 value is %x\n", mr8_value);
		while_loop();
	}
	/* io_width */
	loop_n = ARRAY_SIZE(io_width_valid_list);
	for (i = 0; i < loop_n; i++)
	{
		if (io_width_valid_list[i].mr8_io_width_cryp ==  mr8_io_width)
		{
			mr8_info->io_width = io_width_valid_list[i].io_width;
			break;
		}
	}
	if (i >= loop_n)
	{
		printf("io_width invaild. mr8 value is %x\n", mr8_value);
		while_loop();
	}

}

uint32 get_ddr_mr_info(uint32 *cs_num,uint8 *mr5_value,uint8 *mr8_value)
{
	mr5_value[0] = lpddr4_mrr(0,5);
	mr8_value[0] = lpddr4_mrr(0,8);

	if(mr5_value[0]==LP4_MANU_ID_MICRON) {
		*cs_num = 2;
	} else {
		*cs_num = 1;
	}
	printf("get_ddr_mr_info:cs_num=%d, mr5=0x%x, mr8=0x%x\n",*cs_num,mr5_value[0],mr8_value[0]);
	return 0;
}

uint32 sdram_info_detect (void)
{
	uint32 mr_rank = 0;
	uint32 ret = 0;
	DDR_LOG(DDR_LOG_INFO, "%s: %d\n", __func__, __LINE__);

	ret |= get_ddr_mr_info(&sdram_info.cs_num,sdram_info.mr5_value,sdram_info.mr8_value);

	DDR_LOG(DDR_LOG_INFO, "sdram cs number: %d\n", ddr_cs_num);
	DDR_LOG(DDR_LOG_INFO, "sdram cs number: %d\n", sdram_info.cs_num);
	for (mr_rank = 0; mr_rank < ddr_cs_num ; mr_rank++) {
		DDR_LOG(DDR_LOG_INFO, "sdram cs%d mr5 value: 0x%x\n", mr_rank,
			sdram_info.mr5_value[mr_rank]);
	}
	for (mr_rank = 0; mr_rank < ddr_cs_num ; mr_rank++) {
		DDR_LOG(DDR_LOG_INFO, "sdram cs%d mr8 value: 0x%x\n", mr_rank,
			sdram_info.mr8_value[mr_rank]);
	}

	if (ddr_cs_num == 1)
		hb_ddr_vendor = DDR_MANU_HYNIX;
	else if (ddr_cs_num == 2)
		hb_ddr_vendor = DDR_MANU_MICRON;
	else
		ret = 0xFFFFFFFF;

	return ret;
}

void address_map_config_warm(void)
{
	struct DRAM_CFG_PARAM *cfg_tmp = NULL;
	int i, num_tmp = ARRAY_SIZE(lpddr4_mstr_micron);

	if (hb_ddr_part_number == MT53D1024M32D4DT)
		cfg_tmp = lpddr4_mstr_micron;
	else if (hb_ddr_part_number == H9HCNNN8KUMLHR)
		cfg_tmp = lpddr4_mstr_x3_hynix;
	else
		cfg_tmp = lpddr4_mstr_j3_hynix;

	printf("num : %d\n", num_tmp);
	for (i = 0; i < num_tmp; ++i) {
		reg32_write((cfg_tmp->reg + umctl_reg_addr_base),
			cfg_tmp->val);
		cfg_tmp++;
	}
}

/* set address config according memory info */
void address_map_config(uint32 ddr_type)
{
#ifdef MULTI_FILES
	uint32 fw_src_len = 0, i;
	uint32 fw_src_laddr = 0;
	uint64 fw_dst_laddr = (uint64)ddr_parameter;
	struct DRAM_CFG_PARAM *cfg_tmp = 0;
	uint32 num_tmp = 0;

#ifdef YMODEM_BOOT
	fw_dst_laddr = fw_dst_laddr + ALIGN_512(sizeof(struct hb_ddr_uart_hdr)) +
		ddr_hdr_uart.addr_map.addr;
	fw_src_len = ddr_hdr_uart.addr_map.size;
#else
	fw_src_laddr = g_binfo.ddt1_addr[0] + ALIGN_512(sizeof(struct hb_ddr_hdr)) +
		ddr_hdr.ddr[hb_ddr_index].addr_map.addr;
	fw_src_len = ddr_hdr.ddr[hb_ddr_index].addr_map.size;

	/* Load 32KB firmware */
	g_dev_ops.read(fw_src_laddr, fw_dst_laddr, ALIGN_512(fw_src_len));
#endif
	cfg_tmp = (struct DRAM_CFG_PARAM *)fw_dst_laddr;
	num_tmp = fw_src_len / sizeof(struct DRAM_CFG_PARAM);

	for (i = 0; i < num_tmp; i++) {
		reg32_write((cfg_tmp->reg + umctl_reg_addr_base),
			cfg_tmp->val);
		cfg_tmp++;
	}
#else
	/* HIF address bit number = [internal base] + [register value] */
	uint32 dch_bit0 = 31;
	uint32 cs_bit1 = 31;    //internal base 7
	uint32 cs_bit0 = 31;    //internal base 6
	uint32 bank_b2 = 8;	//internal base 4
	uint32 bank_b1 = 8;	//internal base 3
	uint32 bank_b0 = 8;	//internal base 2
	uint32 col_b9 = 0;	//internal base 9
	uint32 col_b8 = 0;	//internal base 8
	uint32 col_b7 = 0;	//internal base 7
	uint32 col_b6 = 0;	//internal base 6
	uint32 col_b5 = 0;	//internal base 5
	uint32 col_b4 = 0;	//internal base 4
	uint32 col_b3 = 0;	//internal base 3
	uint32 col_b2 = 0;	//internal base 2
	uint32 col_addr_shift = 0;
	uint32 col_b11 = 31;	//internal base 11
	uint32 col_b10 = 31;	//internal base 10
	uint32 row_b2_10 = 7;	//row position according each row bit, internal base 8
	uint32 row_b1 = 7;	//internal base 7
	uint32 row_b0 = 7;	//internal base 6
	uint32 row_b17 = 31;	//internal base 23
	uint32 row_b16 = 7;	//internal base 22
	uint32 row_b15 = 7;	//internal base 21
	uint32 row_b14 = 7;	//internal base 20
	uint32 row_b13 = 7;	//internal base 19
	uint32 row_b12 = 7;	//internal base 18
	uint32 row_b11 = 7;	//internal base 17
	uint32 row_b10 = 7;	//internal base 16
	uint32 row_b9 = 7;	//internal base 15
	uint32 row_b8 = 7;	//internal base 14
	uint32 row_b7 = 7;	//internal base 13
	uint32 row_b6 = 7;	//internal base 12
	uint32 row_b5 = 7;	//internal base 11
	uint32 row_b4 = 7;	//internal base 10
	uint32 row_b3 = 7;	//internal base 9
	uint32 row_b2 = 7;	//internal base 8
	uint32 cid_b1 =31;
	uint32 cid_b0 = 31;
	uint32 bg_b1 = 63;
	uint32 bg_b0 = 63;
	uint32 lpddr3_6gb_12gb = 0;
	uint32 lpddr4_3gb_6gb_12gb = 0;

	/* data channel used for interlevel, X2A do not use, set 31 */
	/* only one rank, addrmap_cs_bit0/1 set 31 */
	if (1 == sdram_info.cs_num) {
		cs_bit0 = 31;
		cs_bit1 = 31;
	} else if (2 == sdram_info.cs_num) {
		/* rank0 density less than rank1 density, do not support; snps support 1/2/4 rank, X2A just support 1/2 rank */
		if (sdram_info.mr8_info[0].density < sdram_info.mr8_info[1].density) {
			printf("Invalid 2 rank density structure! cs0 0x%08x, cs1 0x%08x.\n", sdram_info.mr8_info[0].density, sdram_info.mr8_info[1].density);
			while_loop();
		}
		/* addrmap_cs_bit1 = 31 */
		cs_bit1 = 31;
		/* addrmap_cs_bit0 = row_n + bank_n + coloum_n - 6 (6:internel offset)*/
		cs_bit0 = sdram_info.mr8_info[0].row_num + sdram_info.mr8_info[0].bank_num + sdram_info.mr8_info[0].col_num - 6;
	}
	if ((10 != sdram_info.mr8_info[0].col_num) || (10 != sdram_info.mr8_info[1].col_num)) {
		printf("Invalid coloum structure! cs0 0x%08x, cs1 0x%08x.\n", sdram_info.mr8_info[0].col_num, sdram_info.mr8_info[1].col_num);
		while_loop();
	}
	if ((3 != sdram_info.mr8_info[0].bank_num) || (3 != sdram_info.mr8_info[1].bank_num)) {
		printf("Invalid bank structure! cs0 0x%08x, cs1 0x%08x.\n", sdram_info.mr8_info[0].bank_num, sdram_info.mr8_info[1].bank_num);
		while_loop();
	}
	switch (sdram_info.mr8_info[0].row_num) {
	case 13:
		row_b13 = 31;
		row_b14 = 31;
		row_b15 = 31;
		row_b16 = 31;
		break;
	case 14:
		row_b14 = 31;
		row_b15 = 31;
		row_b16 = 31;
		break;
	case 15:
		row_b15 = 31;
		row_b16 = 31;
		break;
	case 16:
		row_b16 = 31;
		break;
	case 17:
		break;
	default:
		printf("Invalid row structure! cs0 0x%08x.\n", sdram_info.mr8_info[0].row_num);
		while_loop();
		break;
	}

	if ((0x18000000 == sdram_info.mr8_info[0].density) &&
		(16 == sdram_info.mr8_info[0].io_width)) {
		lpddr4_3gb_6gb_12gb = 1;
	} else if (((0x30000000 == sdram_info.mr8_info[0].density) && (16 == sdram_info.mr8_info[0].io_width)) ||
		((0x18000000 == sdram_info.mr8_info[0].density) && (8 == sdram_info.mr8_info[0].io_width))) {
		lpddr4_3gb_6gb_12gb = 2;
	} else if (((0x60000000 == sdram_info.mr8_info[0].density) && (16 == sdram_info.mr8_info[0].io_width))
		|| ((0x30000000 == sdram_info.mr8_info[0].density) && (8 == sdram_info.mr8_info[0].io_width))) {
		lpddr4_3gb_6gb_12gb = 3;
	} else {
		lpddr4_3gb_6gb_12gb = 0;
	}
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP0, ((dch_bit0 << DCH_BIT0_OFFSET) | (cs_bit1 <<
		CS_BIT1_OFFSET) | cs_bit0 << CS_BIT0_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP1, ((bank_b2 << BANK_B2_OFFSET) | (bank_b1 <<
		BANK_B1_OFFSET) | bank_b0 << BANK_B0_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP2, ((col_b5 << COL_B5_OFFSET) | (col_b4 <<
		COL_B4_OFFSET) | (col_b3 << COL_B3_OFFSET) | col_b2 << COL_B2_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP3, ((col_b9 << COL_B9_OFFSET) | (col_b8 <<
		COL_B8_OFFSET) | (col_b7 << COL_B7_OFFSET) | col_b6 << COL_B6_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP4, ((col_addr_shift << COL_ADDR_SHIFT_OFFSET) |
		(col_b11 << COL_B11_OFFSET) | col_b10 << COL_B10_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP5, ((row_b11 << ROW_B11_OFFSET) | (row_b2_10 <<
		ROW_B2_10_OFFSET) | (row_b1 << ROW_B1_OFFSET) | row_b0 << ROW_B0_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP6, ((lpddr3_6gb_12gb << LPDDR3_6GB_12GB_OFFSET) |
		(lpddr4_3gb_6gb_12gb << LPDDR4_3GB_6GB_12GB_OFFSET) | (row_b15 <<
		ROW_B15_OFFSET) | (row_b14 << ROW_B14_OFFSET) |(row_b13 << ROW_B13_OFFSET)
		| row_b12 << ROW_B12_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP7, ((row_b17 << ROW_B17_OFFSET) | row_b16 << ROW_B16_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP8, ((bg_b1 << BG_B1_OFFSET) | bg_b0 << BG_B0_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP9, ((row_b5 << ROW_B5_OFFSET) | (row_b4 << ROW_B4_OFFSET) |
		(row_b3 << ROW_B3_OFFSET) | row_b2 << ROW_B2_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP10, ((row_b9 << ROW_B9_OFFSET) | (row_b8 <<
		ROW_B8_OFFSET) | (row_b7 << ROW_B7_OFFSET) | row_b6 << ROW_B6_OFFSET));
	reg32_write(umctl_reg_addr_base + uMCTL2_ADDRMAP11, ((cid_b1 << CID_B1_OFFSET) | (cid_b0 <<
		CID_B0_OFFSET) | row_b10 << ROW_B10_OFFSET));
#endif
}


/* set other config according memory info */
void umctrl_reg_modify_adjust_ddr (void)
{
#if defined(WARM_BOOT_SPL)
	sdram_info.cs_num = hb_ddr_vendor;
#endif
	printf("sdram_info.cs_num = %d\n",sdram_info.cs_num);

	/* active_ranks 2b'1: one rank; 2b'11: two ranks. */
	reg32_bits_write(umctl_reg_addr_base + uMCTL2_MSTR, 24, 4,
		((1 << sdram_info.cs_num) - 1));
}

