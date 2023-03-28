#include <stdio.h>
#include "hb_ddr_oem.h"

/* #define H9HCNNN8KUMLHR  0x0608 */
struct DRAM_CFG_PARAM lpddr4_mstr_x3_hynix[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x12121200},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x0F040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/* #define H9HCNNNBKUMLHR  0x0610 */
struct DRAM_CFG_PARAM lpddr4_mstr_j3_hynix[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x13131300},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x04040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/* #define MT53D1024M32D4DT 0xff10 */
struct DRAM_CFG_PARAM lpddr4_mstr_micron[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F14},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x14141400},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x04040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/* #define MT53E1G32D2FW_046AUTA 0xff20 */
struct DRAM_CFG_PARAM lpddr4_mstr_micron_ff20[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x14141400},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x04040404},
	{uMCTL2_ADDRMAP7, 0x00000F04},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/*
 * For lpddr4 1GB 1Rank DDR
 * K4F8E304HBMGCJ 0x0108
 * MT53E256M32D2DS_053AAT
 */
struct DRAM_CFG_PARAM lpddr4_ecc_map_1GB_1R[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x12121200},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x0F040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/* #define K4F6E3S4HMMGCJ 0x0110 MT53D512M32D2DT_046AAT 0xff21*/
/*wait for pc*/
struct DRAM_CFG_PARAM lpddr4_mstr_samsung_0110_micron_ff21[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x13131300},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x04040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/* ddr4 samsung*/
struct DRAM_CFG_PARAM ddr4_mstr_micron[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x003F0505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x12121200},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x0F040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F07},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

/* ddr4 samsung*/
struct DRAM_CFG_PARAM ddr4_mstr_samsung[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F1F},
	{uMCTL2_ADDRMAP1, 0x003F0505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x13131300},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x04040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F07},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

// For 4GB 2Rank DDR
struct DRAM_CFG_PARAM lpddr4_ecc_map_samsung_4GB_2R[12] = {
	{uMCTL2_ADDRMAP0, 0x001F1F14},
	{uMCTL2_ADDRMAP1, 0x00050505},
	{uMCTL2_ADDRMAP2, 0x00000000},
	{uMCTL2_ADDRMAP3, 0x14141400},
	{uMCTL2_ADDRMAP4, 0x00001F1F},
	{uMCTL2_ADDRMAP5, 0x040F0404},
	{uMCTL2_ADDRMAP6, 0x04040404},
	{uMCTL2_ADDRMAP7, 0x00000F0F},
	{uMCTL2_ADDRMAP8, 0x00003F3F},
	{uMCTL2_ADDRMAP9, 0x04040404},
	{uMCTL2_ADDRMAP10, 0x04040404},
	{uMCTL2_ADDRMAP11, 0x001F1F04}
};

#ifdef SPL_DDR_PKG
void micron_mstr_write_to_bin(char *file, unsigned int index)
{
	FILE *fp = NULL;
	int mstr_size = 0;
	int padding_size = 0, i;
	char padding_value = 0;

	fp = fopen(file, "ab+");
	if (NULL == fp) {
		printf("File open fail!\n");
		return ;
	}

	/* mstr */
	mstr_size = sizeof(lpddr4_mstr_micron);
	printf("ddr4 pie size: %d\n", mstr_size);
	fwrite(lpddr4_mstr_micron, 2, mstr_size / 2, fp);

	/* align 512 */
	if (mstr_size % 512)
		padding_size = 512 - (mstr_size % 512);

	for (i = 0; i < padding_size; i++) {
		fwrite(&padding_value, 1, 1, fp);
	}

#ifdef YMODEM_BOOT
	hdr_uart.addr_map.addr = hdr_uart.ddr_pie.addr +
		ALIGN_512(hdr_uart.ddr_pie.size);
	hdr_uart.addr_map.size = mstr_size;
#else
	hdr_ddr.ddr[index].addr_map.addr = hdr_ddr.ddr[index].ddr_pie_freqs.addr +
		ALIGN_512(hdr_ddr.ddr[index].ddr_pie_freqs.size);
	hdr_ddr.ddr[index].addr_map.size = mstr_size;
#endif

	pclose(fp);
	return;
}

void x3_hynix_write_to_bin(char *file, unsigned int index)
{
	FILE *fp = NULL;
	int mstr_size = 0;
	int padding_size = 0, i;
	char padding_value = 0;

	fp = fopen(file, "ab+");
	if (NULL == fp) {
		printf("File open fail!\n");
		return ;
	}

	/* mstr */
	mstr_size = sizeof(lpddr4_mstr_x3_hynix);
	printf("ddr4 pie size: %d\n", mstr_size);
	fwrite(lpddr4_mstr_x3_hynix, 2, mstr_size / 2, fp);

	/* align 512 */
	if (mstr_size % 512)
		padding_size = 512 - (mstr_size % 512);

	for (i = 0; i < padding_size; i++) {
		fwrite(&padding_value, 1, 1, fp);
	}

#ifdef YMODEM_BOOT
	hdr_uart.ddr_pie.addr = hdr_uart.ddr_ddrp.addr +
		ALIGN_512(hdr_uart.ddr_ddrp.size);
	hdr_uart.ddr_pie.size = mstr_size;
#else
	hdr_ddr.ddr[index].addr_map.addr = hdr_ddr.ddr[index].ddr_pie_freqs.addr +
		ALIGN_512(hdr_ddr.ddr[index].ddr_pie_freqs.size);
	hdr_ddr.ddr[index].addr_map.size = mstr_size;

#endif

	pclose(fp);
	return;
}

void j3_hynix_write_to_bin(char *file, unsigned int index)
{
	FILE *fp = NULL;
	int mstr_size = 0;
	int padding_size = 0, i;
	char padding_value = 0;

	fp = fopen(file, "ab+");
	if (NULL == fp) {
		printf("File open fail!\n");
		return ;
	}

	/* mstr */
	mstr_size = sizeof(lpddr4_mstr_j3_hynix);
	printf("ddr4 pie size: %d\n", mstr_size);
	fwrite(lpddr4_mstr_j3_hynix, 2, mstr_size / 2, fp);

	/* align 512 */
	if (mstr_size % 512)
		padding_size = 512 - (mstr_size % 512);

	for (i = 0; i < padding_size; i++) {
		fwrite(&padding_value, 1, 1, fp);
	}

#ifdef YMODEM_BOOT
	hdr_uart.ddr_pie.addr = hdr_uart.ddr_ddrp.addr +
		ALIGN_512(hdr_uart.ddr_ddrp.size);
	hdr_uart.ddr_pie.size = mstr_size;
#else
	hdr_ddr.ddr[index].addr_map.addr = hdr_ddr.ddr[index].ddr_pie_freqs.addr +
		ALIGN_512(hdr_ddr.ddr[index].ddr_pie_freqs.size);
	hdr_ddr.ddr[index].addr_map.size = mstr_size;

#endif

	pclose(fp);
	return;
}

void ddr_address_map_to_bin(char *file, unsigned int index, uint32_t part_number)
{
	FILE *fp = NULL;
	int mstr_size = 0;
	int padding_size = 0, i;
	char padding_value = 0;

	fp = fopen(file, "ab+");
	if (NULL == fp) {
		printf("File open fail!\n");
		return ;
	}

	/* mstr */
	if (part_number == H9HCNNN8KUMLHR || part_number == 0 || part_number == PART_DEFAULT) {
		/*xh*/
		mstr_size = sizeof(lpddr4_mstr_x3_hynix);
		fwrite(lpddr4_mstr_x3_hynix, 2, mstr_size / 2, fp);
	} else if (part_number == H9HCNNNBKUMLHR) {
		/*jh*/
		mstr_size = sizeof(lpddr4_mstr_j3_hynix);
		fwrite(lpddr4_mstr_j3_hynix, 2, mstr_size / 2, fp);
	} else if (part_number == MT53D1024M32D4DT) {
		/*cvb micron*/
		mstr_size = sizeof(lpddr4_mstr_micron);
		fwrite(lpddr4_mstr_micron, 2, mstr_size / 2, fp);
	} else if (part_number == K4F8E304HBMGCJ || part_number == MT53E256M32D2DS_053AAT) {
		/*xg 1g jm 1g*/
		mstr_size = sizeof(lpddr4_ecc_map_1GB_1R);
		fwrite(lpddr4_ecc_map_1GB_1R, 2, mstr_size / 2, fp);
	} else if (part_number == K4F6E3S4HMMGCJ || part_number == MT53D512M32D2DT_046AAT) {
		/*xg 2g and micron 2G*/
		mstr_size = sizeof(lpddr4_mstr_samsung_0110_micron_ff21);
		fwrite(lpddr4_mstr_samsung_0110_micron_ff21, 2, mstr_size / 2, fp);
	} else if (part_number == K4FBE3D4HM_THCL) {
		mstr_size = sizeof(lpddr4_ecc_map_samsung_4GB_2R);
		fwrite(lpddr4_ecc_map_samsung_4GB_2R, 2, mstr_size / 2, fp);
	} else if (part_number == MT53E1G32D2FW_046AUTA) {
		/*micron 4g*/
		mstr_size = sizeof(lpddr4_mstr_micron_ff20);
		fwrite(lpddr4_mstr_micron_ff20, 2, mstr_size / 2, fp);
	} else if (part_number == MT40A256M16LY) {
		/*xy*/
		mstr_size = sizeof(ddr4_mstr_micron);
		fwrite(ddr4_mstr_micron, 2, mstr_size / 2, fp);
	} else if (part_number == K4A8G165WC || part_number == K4A4G165WF_BCTD) {
		/*xs*/
		mstr_size = sizeof(ddr4_mstr_samsung);
		fwrite(ddr4_mstr_samsung, 2, mstr_size / 2, fp);
	} else {
		printf("%s:error part number\n", __func__);
		mstr_size = sizeof(lpddr4_mstr_j3_hynix);
		fwrite(lpddr4_mstr_j3_hynix, 2, mstr_size / 2, fp);
	}
	printf("address map size: %d\n", mstr_size);

	/* align 512 */
	if (mstr_size % 512)
		padding_size = 512 - (mstr_size % 512);

	for (i = 0; i < padding_size; i++) {
		fwrite(&padding_value, 1, 1, fp);
	}

	hdr_uart.addr_map.addr = hdr_uart.ddr_pie.addr +
		ALIGN_512(hdr_uart.ddr_pie.size);
	hdr_uart.addr_map.size = mstr_size;

	hdr_ddr.ddr[index].addr_map.addr = hdr_ddr.ddr[index].ddr_pie_freqs.addr +
		ALIGN_512(hdr_ddr.ddr[index].ddr_pie_freqs.size);
	hdr_ddr.ddr[index].addr_map.size = mstr_size;


	pclose(fp);
	return;
}
#endif
