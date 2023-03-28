/*
 * Very simple but very effective user-space memory tester.
 * Originally by Simon Kirby <sim@stormix.com> <sim@neato.org>
 * Version 2 by Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Version 3 not publicly released.
 * Version 4 rewrite:
 * Copyright (C) 2004-2012 Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Licensed under the terms of the GNU General Public License version 2 (only).
 * See the file COPYING for details.
 *
 * This file contains the functions for the actual tests, called from the
 * main routine in memtester.c.  See other comments in that file.
 *
 */

#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

#include "types.h"
#include "sizes.h"
//#include "memtester.h"
#include "ddr_common.h"
#include "ddr.h"

char progress[] = "-\\|/";
#define PROGRESSLEN 4
#define PROGRESSOFTEN 2500
#define ONE 0x00000001L

volatile unsigned long ddr_test_success[20] = {0};
volatile unsigned long ddr_test_fail[20] = {0};
volatile unsigned long ddr_test_fail_totle = 0;
volatile unsigned long loop = 0;

/* Function definitions. */
int use_phys = 1;
off_t physaddrbase = 0;
size_t read_retry_num = 20;

int compare_regions(ulv *bufa, ulv *bufb, size_t count) {
    int r = 0;
    size_t i;
    int j;
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    off_t physaddr;

	for (i = 0; i < count; i++, p1++, p2++) {
		if (*p1 != *p2) {
			for (j = 0; j < read_retry_num; j++) {
				if (use_phys) {
					physaddr = physaddrbase + (i * sizeof(ul));
					printf("read retry:%d\n", j);
					printf("FAILURE: 0x%08lx != 0x%08lx at physical address 0x%08lx.\n", (ul)*p1, (ul)*p2, physaddr);
				} else {
					printf("FAILURE: 0x%08lx != 0x%08lx at offset 0x%08lx.\n", (ul)*p1, (ul)*p2, (ul)(i * sizeof(ul)));
				}
			/* printf("Skipping to next test..."); */
			}
			r = -1;
			ddr_test_fail[loop]++;
			ddr_test_fail_totle++;
			physaddr = physaddr;//fixed compile warning
		}
	}
	ddr_test_success[loop]++;
    return r;
}

int test_stuck_address(ulv *bufa, size_t count) {
    ulv *p1 = bufa;
    unsigned int j;
    size_t i;
    off_t physaddr;

    printf("           ");
    for (j = 0; j < 16; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        printf("setting %3u", j);
        //fflush(stdout);
        for (i = 0; i < count; i++) {
            *p1 = ((j + i) % 2) == 0 ? (ul) p1 : ~((ul) p1);
            *p1++;
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        p1 = (ulv *) bufa;
        for (i = 0; i < count; i++, p1++) {
            if (*p1 != (((j + i) % 2) == 0 ? (ul) p1 : ~((ul) p1))) {
                if (use_phys) {
                    physaddr = physaddrbase + (i * sizeof(ul));
                   printf("FAILURE: possible bad address line at physical address 0x%08lx.\n", physaddr);
                } else {
                   printf("FAILURE: possible bad address line at offset 0x%08lx.\n", (ul)(i * sizeof(ul)));
                }
                printf("Skipping to next test...\n");
                //fflush(stdout);
                return -1;
            }
        }
    }
	physaddr = physaddr;//fixed compile warning
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    return 0;
}

int test_random_value(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    ul j = 0;
    size_t i;

    printf(" ");
    for (i = 0; i < count; i++) {
        *p1++ = *p2++ = rand_ul();
        if (!(i % PROGRESSOFTEN)) {
            printf("\b");
            printf("%c",progress[++j % PROGRESSLEN]);
            //fflush(stdout);
        }
    }
	j=j;//fixed compile warning
    printf("\b \b");
    return compare_regions(bufa, bufb, count);
}

int test_xor_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ ^= q;
        *p2++ ^= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_sub_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ -= q;
        *p2++ -= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_mul_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ *= q;
        *p2++ *= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_div_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        if (!q) {
            q++;
        }
        *p1++ /= q;
        *p2++ /= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_or_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ |= q;
        *p2++ |= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_and_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ &= q;
        *p2++ &= q;
    }
    return compare_regions(bufa, bufb, count);
}

int test_seqinc_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    size_t i;
    ul q = rand_ul();

    for (i = 0; i < count; i++) {
        *p1++ = *p2++ = (i + q);
    }
    return compare_regions(bufa, bufb, count);
}

int test_solidbits_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    ul q;
    size_t i;

    printf("\n");
    printf("           ");

    for (j = 0; j < 64; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        q = (j % 2) == 0 ? UL_ONEBITS : 0;
        printf("setting %3u", j);
        //fflush(stdout);
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = (i % 2) == 0 ? q : ~q;
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

int test_checkerboard_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    ul q;
    size_t i;

    printf("\n");
    printf("           ");
    //fflush(stdout);
    for (j = 0; j < 64; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        q = (j % 2) == 0 ? CHECKERBOARD1 : CHECKERBOARD2;
        printf("setting %3u", j);
        //fflush(stdout);
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = (i % 2) == 0 ? q : ~q;
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

int test_blockseq_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;

    printf("\n");
    printf("           ");
    //fflush(stdout);
    for (j = 0; j < 256; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        //fflush(stdout);
        for (i = 0; i < count; i++) {
            *p1++ = *p2++ = (ul) UL_BYTE(j);
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

int test_walkbits0_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;

    printf("\n");
    printf("           ");
    //fflush(stdout);
    for (j = 0; j < UL_LEN * 2; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        //fflush(stdout);
        for (i = 0; i < count; i++) {
            if (j < UL_LEN) { /* Walk it up. */
                *p1++ = *p2++ = ONE << j;
            } else { /* Walk it back down. */
                *p1++ = *p2++ = ONE << (UL_LEN * 2 - j - 1);
            }
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

int test_walkbits1_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;

    printf("\n");
    printf("           ");
    //fflush(stdout);
    for (j = 0; j < UL_LEN * 2; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        //fflush(stdout);
        for (i = 0; i < count; i++) {
            if (j < UL_LEN) { /* Walk it up. */
                *p1++ = *p2++ = UL_ONEBITS ^ (ONE << j);
            } else { /* Walk it back down. */
                *p1++ = *p2++ = UL_ONEBITS ^ (ONE << (UL_LEN * 2 - j - 1));
            }
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

int test_bitspread_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j;
    size_t i;

    printf("\n");
    printf("           ");
    //fflush(stdout);
    for (j = 0; j < UL_LEN * 2; j++) {
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        p1 = (ulv *) bufa;
        p2 = (ulv *) bufb;
        printf("setting %3u", j);
        //fflush(stdout);
        for (i = 0; i < count; i++) {
            if (j < UL_LEN) { /* Walk it up. */
                *p1++ = *p2++ = (i % 2 == 0)
                    ? (ONE << j) | (ONE << (j + 2))
                    : UL_ONEBITS ^ ((ONE << j)
                                    | (ONE << (j + 2)));
            } else { /* Walk it back down. */
                *p1++ = *p2++ = (i % 2 == 0)
                    ? (ONE << (UL_LEN * 2 - 1 - j)) | (ONE << (UL_LEN * 2 + 1 - j))
                    : UL_ONEBITS ^ (ONE << (UL_LEN * 2 - 1 - j)
                                    | (ONE << (UL_LEN * 2 + 1 - j)));
            }
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b");
        printf("testing %3u", j);
        //fflush(stdout);
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

int test_bitflip_comparison(ulv *bufa, ulv *bufb, size_t count) {
    ulv *p1 = bufa;
    ulv *p2 = bufb;
    unsigned int j, k;
    ul q;
    size_t i;

    printf("\n");
    printf("           ");
    //fflush(stdout);
    for (k = 0; k < UL_LEN; k++) {
        q = ONE << k;
        for (j = 0; j < 8; j++) {
            printf("\b\b\b\b\b\b\b\b\b\b\b");
            q = ~q;
            printf("setting %3u", k * 8 + j);
            //fflush(stdout);
            p1 = (ulv *) bufa;
            p2 = (ulv *) bufb;
            for (i = 0; i < count; i++) {
                *p1++ = *p2++ = (i % 2) == 0 ? q : ~q;
            }
            printf("\b\b\b\b\b\b\b\b\b\b\b");
            printf("testing %3u", k * 8 + j);
            //fflush(stdout);
            if (compare_regions(bufa, bufb, count)) {
                return -1;
            }
        }
    }
    printf("\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b");
    //fflush(stdout);
    return 0;
}

#ifdef TEST_NARROW_WRITES
int test_8bit_wide_random(ulv* bufa, ulv* bufb, size_t count) {
    u8v *p1, *t;
    ulv *p2;
    int attempt;
    unsigned int b, j = 0;
    size_t i;

    printf("\n");
    printf(" ");
    //fflush(stdout);
    for (attempt = 0; attempt < 2;  attempt++) {
        if (attempt & 1) {
            p1 = (u8v *) bufa;
            p2 = bufb;
        } else {
            p1 = (u8v *) bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword8.bytes;
            *p2++ = mword8.val = rand_ul();
            for (b=0; b < UL_LEN/8; b++) {
                *p1++ = *t++;
            }
            if (!(i % PROGRESSOFTEN)) {
				printf("\b");
				printf("%c",progress[++j % PROGRESSLEN]);
                //fflush(stdout);
            }
        }
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b \b");
    //fflush(stdout);
    return 0;
}

int test_16bit_wide_random(ulv* bufa, ulv* bufb, size_t count) {
    u16v *p1, *t;
    ulv *p2;
    int attempt;
    unsigned int b, j = 0;
    size_t i;

    printf("\n");
    printf(" ");
    //fflush( stdout );
    for (attempt = 0; attempt < 2; attempt++) {
        if (attempt & 1) {
            p1 = (u16v *) bufa;
            p2 = bufb;
        } else {
            p1 = (u16v *) bufb;
            p2 = bufa;
        }
        for (i = 0; i < count; i++) {
            t = mword16.u16s;
            *p2++ = mword16.val = rand_ul();
            for (b = 0; b < UL_LEN/16; b++) {
                *p1++ = *t++;
            }
            if (!(i % PROGRESSOFTEN)) {
				printf("\b");
				printf("%c",progress[++j % PROGRESSLEN]);
                //fflush(stdout);
            }
        }
        if (compare_regions(bufa, bufb, count)) {
            return -1;
        }
    }
    printf("\b \b");
    //fflush(stdout);
    return 0;
}
#endif

#define EXIT_FAIL_NONSTARTER    0x01
#define EXIT_FAIL_ADDRESSLINES  0x02
#define EXIT_FAIL_OTHERTEST     0x04

volatile unsigned int ddr_test_result[20];

struct test tests[] = {
    { "Random Value", test_random_value },
    { "Compare XOR", test_xor_comparison },
    { "Compare SUB", test_sub_comparison },
    { "Compare MUL", test_mul_comparison },
    { "Compare DIV",test_div_comparison },
    { "Compare OR", test_or_comparison },
    { "Compare AND", test_and_comparison },
    { "Sequential Increment", test_seqinc_comparison },
    { "Solid Bits", test_solidbits_comparison },
    { "Block Sequential", test_blockseq_comparison },
    { "Checkerboard", test_checkerboard_comparison },
    { "Bit Spread", test_bitspread_comparison },
    { "Bit Flip", test_bitflip_comparison },
    { "Walking Ones", test_walkbits1_comparison },
    { "Walking Zeroes", test_walkbits0_comparison },
#ifdef TEST_NARROW_WRITES
    { "8-bit Writes", test_8bit_wide_random },
    { "16-bit Writes", test_16bit_wide_random },
#endif
    { NULL, NULL }
};

#define TEST_MASK 0x2000//0xFFFF
#define DDR_TEST_START_ADDR 0x00000000
#define DDR_TEST_END_ADDR 0x10000000
void memtester(void)
{
    ul testmask;
    ulv *bufa, *bufb;
	ul bufsize, halflen, count;
    int exit_code = 0;

	physaddrbase = 0;
	bufsize = DDR_TEST_END_ADDR - DDR_TEST_START_ADDR;
    halflen = bufsize / 2;
    count = halflen / sizeof(ul);
    bufa = (ulv *) DDR_TEST_START_ADDR;
    bufb = (ulv *) (DDR_TEST_START_ADDR + ((DDR_TEST_END_ADDR - DDR_TEST_START_ADDR) / 2));
	testmask = TEST_MASK;
	printf("DDR_TEST_START_ADDR:\t0x%lx\n",(unsigned long)DDR_TEST_START_ADDR);
	printf("DDR_TEST_END_ADDR:\t0x%lx\n",(unsigned long)DDR_TEST_END_ADDR);
	printf("count:\t\t\t0x%lx\n",count);

    for (loop=0;;loop++) {
        if (!tests[loop].name) break;
        /* If using a custom testmask, only run this test if the
           bit corresponding to this test was set by the user.
         */
        if (testmask && (!((1 << loop) & testmask))) {
            continue;
        }
        printf("  %-20s: ", tests[loop].name);
        if (!tests[loop].fp(bufa, bufb, count)) {
            printf("ok\n");
        } else {
            exit_code |= EXIT_FAIL_OTHERTEST;
        }
        //fflush(stdout);
        ddr_test_result[loop] = 0xFEEDC0DE;
    }

    printf("\n");
	//while(1);
}

#define LIST_END_ADDR 0xFFFFFFFF
#define LIST_END_DATA 0xFFFFFFFF

struct REG_RANGE {
	uint32 start_addr;
	uint32 end_addr;
	};
struct REG_RANGE reg_rang_list[] = {
	//umctrl registers
	{0xA2D00000, 0xA2D01EF0},
	{0xA2D02020, 0xA2D021B8},
	{0xA2D02240, 0xA2002240},
	{0xA2D023D0, 0xA2D023DC},
	{0xA2D023f8, 0xA2D02424},
	{0xA2D03020, 0xA2D031B8},
	{0xA2D03240, 0xA2003240},
	{0xA2D033D0, 0xA2D033DC},
	{0xA2D04020, 0xA2D041B8},
	{0xA2D04240, 0xA2004240},
	{0xA2D043D0, 0xA2D043DC},
	//pub registers
//	{0xA2D00000, 0xA2D01EF0},
//	{0xA2D00000, 0xA2D01EF0},
//	{0xA2D00000, 0xA2D01EF0},
	//end
	{LIST_END_ADDR, LIST_END_DATA},

	};
void print_regs (struct REG_RANGE *p_reg)
{
	struct REG_RANGE *list_p = p_reg;
	uint32 i = 0;
	uint32 data_len = 0;
//	data_len = sizeof(uint64);
//	printf("sizeof(uint64) is %d.\n", data_len);
	data_len = sizeof(uint32);
	printf("sizeof(uint32) is %d.\n", data_len);
//	data_len = sizeof(uint16);
//	printf("sizeof(uint16) is %d.\n", data_len);
//	data_len = sizeof(unsigned int);
//	printf("sizeof(unsigned int) is %d.\n", data_len);
	while(LIST_END_ADDR != list_p->start_addr)
	{
		for(i = list_p->start_addr; i <= list_p->end_addr; i += data_len)
		{
			/* print address data */
			printf("Register address is 0x%08x; value is 0x%08x.\n", i, reg32_read((uint64)i));
		}
		list_p++;
	}
	reg32_write(0x0, 0x0);
}

#define START_ADDR 0
#define END_ADDR 0x70000000
void simple_test(void)
{
	uint32 i = 0;
	uint32 data_len = 0;
	data_len = sizeof(uint32);
	for (i = START_ADDR; i < END_ADDR; i += data_len)
	{
		reg32_write((uint64)i, 0);
	}
	for (i = START_ADDR; i < END_ADDR; i += data_len)
	{
		if (0 !=reg32_read((uint64)i))
			printf("read fail, offset %8x, read data %8x.\n", i, reg32_read((uint64)i));
		reg32_write((uint64)i, i);
	}
	printf("%s write done.\n", __func__);
	for (i = START_ADDR; i < END_ADDR; i += data_len)
	{
		if (i !=reg32_read((uint64)i))
			printf("read fail, offset %8x, read data %8x.\n", i, reg32_read((uint64)i));
	}
	printf("%s read done.\n", __func__);
}
#define TEST_NUM 4
void test_entry_t(void)
{
//	print_regs(&(reg_rang_list[0]));
	printf("%s: %d\n", __func__, __LINE__);
	simple_test();
	while(1)memtester(); // memtest to DDR

}

#define MANUAL_DDR_TEST_START_ADDR 0x00000000
#define MANUAL_DDR_TEST_END_ADDR 0x100
void Manual_Read(void)
{
    ulv *p1;
    ul bufsize, count;
    size_t i;

    bufsize = MANUAL_DDR_TEST_END_ADDR - MANUAL_DDR_TEST_START_ADDR;
    count = bufsize / sizeof(ul);
    p1 = (ulv *) MANUAL_DDR_TEST_START_ADDR;

    printf("\nManual read.\n");
    printf("Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);

    for (i = 0; i < count; i++) {
        printf("Manual Read: 0x%16lx, offset 0x%08lx.\n",(ul)*p1, (ul)p1);
        *p1++;
    }

}

void Manual_Write(unsigned long test_pattern)
{
    ulv *p1;
    ul bufsize, count;
    size_t i;

    bufsize = MANUAL_DDR_TEST_END_ADDR - MANUAL_DDR_TEST_START_ADDR;
    count = bufsize / sizeof(ul);
    p1 = (ulv *) MANUAL_DDR_TEST_START_ADDR;

        printf("\nManual write SINGLE_PATTERN:0x%lx.\n",test_pattern);
        printf("Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);

    for (i = 0; i < count; i++) {
        *p1++ = test_pattern;
    }
}

void Manual_Read_Write_Test(void)
{
    printf("Input 'r' to read data from Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);
    printf("Input 'a' to write 0x0000000000000000 data from Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);
    printf("Input 'b' to write 0xFFFFFFFFFFFFFFFF data from Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);
    printf("Input 'c' to write 0x5555555555555555 data from Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);
    printf("Input 'd' to write 0xAAAAAAAAAAAAAAAA data from Addres Start:0x%lx. End:0x%lx\n",(ul)MANUAL_DDR_TEST_START_ADDR,(ul)MANUAL_DDR_TEST_END_ADDR);
    while(1)
    {
        int test_flag = 0;
        test_flag = serial_getc();
        if(test_flag == 'r')
        {
            printf("\r\n Your input command is %c\n", test_flag);
	    Manual_Read();
        }
        if(test_flag == 'a')
        {
            printf("\r\n Your input command is %c\n", test_flag);
            Manual_Write(0x0);
        }
        if(test_flag == 'b')
        {
            printf("\r\n Your input command is %c\n", test_flag);
            Manual_Write(UL_ONEBITS);
        }
        if(test_flag == 'c')
        {
            printf("\r\n Your input command is %c\n", test_flag);
            Manual_Write(CHECKERBOARD1);
        }
        if(test_flag == 'd')
        {
            printf("\r\n Your input command is %c\n", test_flag);
            Manual_Write(CHECKERBOARD2);
        }
    }
}
