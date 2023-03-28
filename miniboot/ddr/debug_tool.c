/*
 * Input ODT(Optional), PHY DS(Optional), delay and vref register.
 * Output relative eye diagram based on memtester random test result.
 */

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

#include <asm/arch/ddr.h>
//#include <asm/arch/ddr_phy.h>
#include "ddr_phy_registers.h"

/* internal enumeration */
typedef enum delay_type {
	X_TXDQDLYTG,
	X_TXDQSDLYTG,
	X_RXENDLYTG,
	X_RXCLKDLYTG,
	X_RXCLKCDLYTG,
	X_UNKNOWN
} DELAY_TYPE;


/* internal structure */


/* internal global variable */
DELAY_TYPE x_delay_type=X_UNKNOWN;

unsigned long input_odt_ori=0;
unsigned long input_phy_ds_ori=0;
unsigned long input_x_delay_ori=0;
unsigned long input_y_vref_ori=0;

unsigned long input_odt_reg=0;
unsigned long input_phy_ds_reg=0;
unsigned long input_x_delay_reg=0;
unsigned long input_y_vref_reg=0;

unsigned char input_odt_flag=false;
unsigned char input_phy_ds_flag=false;
unsigned char input_x_delay_flag=false;
unsigned char input_y_vref_flag=false;

unsigned int start_pass_x_delay=0xFFFF;
unsigned int center_pass_x_delay=0xFFFF;
unsigned int end_pass_x_delay=0xFFFF;



/* Function definitions. */

int debug_tool_compare_regions(unsigned long volatile *bufa, unsigned long volatile *bufb, size_t count) {
    int r = 0;
    size_t i;
    unsigned long volatile *p1 = bufa;
    unsigned long volatile *p2 = bufb;

    for (i = 0; i < count; i++, p1++, p2++) {
        if (*p1 != *p2)
            r = -1;
    }
    return r;
}

int debug_tool_test_random_value(unsigned long volatile *bufa, unsigned long volatile *bufb, size_t count) {
    unsigned long volatile *p1 = bufa;
    unsigned long volatile *p2 = bufb;
    size_t i;

    for (i = 0; i < count; i++) {
        *p1++ = *p2++ = rand_ul();
    }
    return debug_tool_compare_regions(bufa, bufb, count);
}
/* from memtest end */

void debug_tool_init(void)
{
	x_delay_type=X_UNKNOWN;

	input_odt_ori=0;
	input_phy_ds_ori=0;
	input_x_delay_ori=0;
	input_y_vref_ori=0;

	input_odt_reg=0;
	input_phy_ds_reg=0;
	input_x_delay_reg=0;
	input_y_vref_reg=0;

	input_odt_flag=false;
	input_phy_ds_flag=false;
	input_x_delay_flag=false;
	input_y_vref_flag=false;

	start_pass_x_delay=0xFFFF;
	center_pass_x_delay=0xFFFF;
	end_pass_x_delay=0xFFFF;
}

void debug_tool_input_odt(unsigned long addr)
{
	input_odt_flag = true;
	input_odt_reg = addr;
	input_odt_ori = reg32_read(addr);
}

void debug_tool_input_phy_ds(unsigned long addr)
{
	input_phy_ds_flag = true;
	input_phy_ds_reg = addr;
	input_phy_ds_ori = reg32_read(addr);
}

void debug_tool_input_x_delay(unsigned long addr)
{
	input_x_delay_flag = true;
	input_x_delay_reg = addr;
	input_x_delay_ori = reg32_read(addr);

	switch(input_x_delay_reg){

	/* TXDQDLYTG*:
	TxDqDlyTg*[8:6] is the coarse delay, ie one unit of delay is 1 UI.
	TxDqDlyTg*[4:0] is the fine (fractional UI) delay, ie one unit of delay is one-thirtysecond of a UI =
	UI/32.
	TxDqDlyTg*[5] is reserved.
	*/
	//DBYTE0
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r1_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r2_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r2_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r2_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r2_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r3_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r3_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r3_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r3_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r4_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r4_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r4_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r4_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r5_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r5_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r5_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r5_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r6_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r6_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r6_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r6_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r7_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r7_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r7_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r7_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r8_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r8_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r8_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r8_p3:

	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r1_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r2_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r2_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r2_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r2_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r3_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r3_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r3_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r3_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r4_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r4_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r4_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r4_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r5_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r5_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r5_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r5_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r6_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r6_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r6_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r6_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r7_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r7_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r7_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r7_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r8_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r8_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r8_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r8_p3:

	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r1_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r2_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r2_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r2_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r2_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r3_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r3_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r3_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r3_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r4_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r4_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r4_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r4_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r5_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r5_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r5_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r5_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r6_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r6_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r6_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r6_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r7_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r7_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r7_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r7_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r8_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r8_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r8_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg2_r8_p3:

	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r1_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r2_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r2_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r2_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r2_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r3_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r3_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r3_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r3_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r4_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r4_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r4_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r4_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r5_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r5_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r5_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r5_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r6_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r6_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r6_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r6_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r7_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r7_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r7_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r7_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r8_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r8_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r8_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqDlyTg3_r8_p3:

	//DBYTE1
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r1_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r2_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r2_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r2_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r2_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r3_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r3_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r3_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r3_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r4_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r4_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r4_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r4_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r5_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r5_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r5_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r5_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r6_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r6_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r6_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r6_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r7_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r7_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r7_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r7_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r8_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r8_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r8_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r8_p3:

	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r1_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r2_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r2_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r2_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r2_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r3_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r3_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r3_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r3_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r4_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r4_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r4_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r4_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r5_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r5_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r5_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r5_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r6_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r6_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r6_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r6_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r7_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r7_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r7_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r7_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r8_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r8_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r8_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg1_r8_p3:

	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r1_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r2_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r2_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r2_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r2_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r3_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r3_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r3_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r3_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r4_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r4_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r4_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r4_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r5_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r5_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r5_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r5_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r6_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r6_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r6_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r6_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r7_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r7_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r7_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r7_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r8_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r8_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r8_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg2_r8_p3:

	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r1_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r2_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r2_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r2_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r2_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r3_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r3_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r3_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r3_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r4_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r4_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r4_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r4_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r5_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r5_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r5_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r5_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r6_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r6_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r6_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r6_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r7_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r7_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r7_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r7_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r8_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r8_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r8_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqDlyTg3_r8_p3:

	//DBYTE2
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r1_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r2_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r2_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r2_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r2_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r3_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r3_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r3_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r3_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r4_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r4_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r4_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r4_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r5_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r5_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r5_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r5_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r6_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r6_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r6_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r6_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r7_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r7_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r7_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r7_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r8_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r8_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r8_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg0_r8_p3:

	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r1_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r2_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r2_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r2_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r2_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r3_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r3_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r3_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r3_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r4_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r4_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r4_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r4_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r5_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r5_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r5_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r5_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r6_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r6_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r6_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r6_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r7_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r7_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r7_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r7_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r8_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r8_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r8_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg1_r8_p3:

	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r1_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r2_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r2_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r2_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r2_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r3_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r3_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r3_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r3_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r4_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r4_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r4_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r4_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r5_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r5_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r5_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r5_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r6_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r6_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r6_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r6_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r7_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r7_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r7_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r7_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r8_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r8_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r8_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg2_r8_p3:

	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r1_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r2_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r2_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r2_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r2_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r3_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r3_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r3_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r3_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r4_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r4_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r4_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r4_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r5_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r5_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r5_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r5_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r6_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r6_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r6_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r6_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r7_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r7_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r7_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r7_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r8_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r8_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r8_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqDlyTg3_r8_p3:

	//DBYTE3
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r1_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r2_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r2_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r2_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r2_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r3_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r3_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r3_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r3_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r4_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r4_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r4_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r4_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r5_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r5_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r5_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r5_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r6_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r6_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r6_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r6_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r7_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r7_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r7_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r7_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r8_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r8_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r8_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg0_r8_p3:

	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r1_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r2_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r2_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r2_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r2_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r3_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r3_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r3_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r3_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r4_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r4_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r4_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r4_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r5_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r5_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r5_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r5_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r6_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r6_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r6_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r6_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r7_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r7_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r7_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r7_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r8_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r8_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r8_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg1_r8_p3:

	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r1_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r2_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r2_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r2_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r2_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r3_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r3_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r3_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r3_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r4_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r4_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r4_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r4_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r5_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r5_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r5_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r5_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r6_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r6_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r6_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r6_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r7_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r7_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r7_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r7_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r8_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r8_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r8_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg2_r8_p3:

	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r1_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r2_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r2_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r2_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r2_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r3_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r3_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r3_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r3_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r4_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r4_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r4_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r4_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r5_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r5_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r5_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r5_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r6_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r6_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r6_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r6_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r7_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r7_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r7_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r7_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r8_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r8_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r8_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqDlyTg3_r8_p3:

		x_delay_type=X_TXDQDLYTG;
		break;

	/* TXDQSDLYTG*:
	TxDqsDlyTg*[9:6] is the coarse delay, ie one unit of delay is 1 UI.
	TxDqsDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
	TxDqsDlyTg*[5] is reserved.
	*/
	//DBYTE0
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE0__TxDqsDlyTg3_u1_p3:

	//DBYTE1
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE1__TxDqsDlyTg3_u1_p3:

	//DBYTE2
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE2__TxDqsDlyTg3_u1_p3:

	//DBYTE3
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE3__TxDqsDlyTg3_u1_p3:

		x_delay_type=X_TXDQSDLYTG;
		break;

	/* RXENDLYTG*:
	RxEnDlyTg*[10:6] is the coarse delay, ie one unit of delay is 1 UI.
	RxEnDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
	RxEnDlyTg*[5] is reserved.
	*/
	//DBYTE0
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxEnDlyTg3_u1_p3:

	//DBYTE1
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxEnDlyTg3_u1_p3:

	//DBYTE2
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxEnDlyTg3_u1_p3:

	//DBYTE3
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxEnDlyTg3_u1_p3:

		x_delay_type=X_RXENDLYTG;
		break;

	/* RXCLKDLYTG*:
	RxClkDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
	RxClkDlyTg*[5] is reserved. There is no coarse delay field, ie the max configurable delay is
	31/32 UI.
	*/
	//DBYTE0
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkDlyTg3_u1_p3:

	//DBYTE1
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkDlyTg3_u1_p3:

	//DBYTE2
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkDlyTg3_u1_p3:

	//DBYTE3
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkDlyTg3_u1_p3:

		x_delay_type=X_RXCLKDLYTG;
		break;

	/* RXCLKCDLYTG*:
	RxClkcDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
	RxClkcDlyTg*[5] is reserved. There is no coarse delay field, ie the max configurable delay is
	31/32 UI.
	*/
	//DBYTE0
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE0__RxClkcDlyTg3_u1_p3:

	//DBYTE1
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE1__RxClkcDlyTg3_u1_p3:

	//DBYTE2
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE2__RxClkcDlyTg3_u1_p3:

	//DBYTE3
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg0_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg1_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg2_u1_p3:

	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u0_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u0_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u0_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u0_p3:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u1_p0:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u1_p1:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u1_p2:
	case DWC_DDRPHYA_DBYTE3__RxClkcDlyTg3_u1_p3:

		x_delay_type=X_RXCLKCDLYTG;
		break;

	default:

		x_delay_type=X_UNKNOWN;
		DDR_LOG(DDR_LOG_DEBUG, "x_delay_type reg error\n");
		break;
	}
}

void debug_tool_input_y_vref(unsigned long addr)
{
	input_y_vref_flag = true;
	input_y_vref_reg = addr;
	input_y_vref_ori = reg32_read(addr);
}

void restore_input_register(void)
{
	//restore original register value
	if(input_odt_flag)
		reg32_write(input_odt_reg, input_odt_ori);

	if(input_phy_ds_flag)
		reg32_write(input_phy_ds_reg, input_phy_ds_ori);

	if(input_x_delay_flag)
		reg32_write(input_x_delay_reg, input_x_delay_ori);

	if(input_y_vref_flag)
		reg32_write(input_y_vref_reg, input_y_vref_ori);
}

#define DDR_DEBUG_TOOL_TEST_START_ADDR 0x00000000
#define DDR_DEBUG_TOOL_TEST_END_ADDR 0x00010000

bool test_and_output(void)
{
    unsigned long volatile *bufa, *bufb;
	unsigned long bufsize, halflen, count;

	bufsize = DDR_DEBUG_TOOL_TEST_END_ADDR - DDR_DEBUG_TOOL_TEST_START_ADDR;
    halflen = bufsize / 2;
    count = halflen / sizeof(unsigned long);
    bufa = (unsigned long volatile *) DDR_DEBUG_TOOL_TEST_START_ADDR;
    bufb = (unsigned long volatile *) (DDR_DEBUG_TOOL_TEST_START_ADDR + ((DDR_DEBUG_TOOL_TEST_END_ADDR - DDR_DEBUG_TOOL_TEST_START_ADDR) / 2));

	if(!debug_tool_test_random_value(bufa, bufb, count)){
		DDR_LOG(DDR_LOG_DEBUG, "*");
		return true;
	}
	else{
		DDR_LOG(DDR_LOG_DEBUG, " ");
		return false;
	}
}

void set_x_to_test( int x1_start_bit, unsigned int x1_max, unsigned int x2_max)
{
	bool test_result = false;
	int x_value=0;
	int y_value=0;
	unsigned int y_max;

	y_max = 64;

	DDR_LOG(DDR_LOG_DEBUG, "  delay:");
	if(x1_max!=0){
		for(unsigned int x1=0;x1<x1_max;x1++){
			DDR_LOG(DDR_LOG_DEBUG, "%02x",x1);
			for(int x2=2;x2<x2_max;x2++){
				DDR_LOG(DDR_LOG_DEBUG, "-");
			}
		}
	}

	DDR_LOG(DDR_LOG_DEBUG, "\n");
	for(unsigned int y=0;y<y_max;y++){
		y_value = y;
		DDR_LOG(DDR_LOG_DEBUG, "verf:%02x:",y);
		reg32_write(input_x_delay_reg, y_value);
		if(x1_max!=0){
			for(int x1=0;x1<x1_max;x1++){
				for(int x2=0;x2<x2_max;x2++){
					x_value = (x1<x1_start_bit)&(x2);
					reg32_write(input_x_delay_reg, x_value);
					test_result = test_and_output();
					if(test_result==true && start_pass_x_delay==0xFFFF)
						start_pass_x_delay = x_value;
					if(test_result==false && start_pass_x_delay!=0xFFFF && end_pass_x_delay==0xFFFF)
						end_pass_x_delay = x_value;
				}
			}
		}
		else{
			for(int x2=0;x2<x2_max;x2++){
				x_value = x2;
				reg32_write(input_x_delay_reg, x_value);
				test_result = test_and_output();
				if(test_result==true && start_pass_x_delay==0xFFFF)
					start_pass_x_delay = x_value;
				if(test_result==false && start_pass_x_delay!=0xFFFF && end_pass_x_delay==0xFFFF)
					end_pass_x_delay = x_value;
			}
		}
		if(start_pass_x_delay!=0xFFFF && end_pass_x_delay!=0xFFFF)
			center_pass_x_delay = (start_pass_x_delay+end_pass_x_delay)/2;
		DDR_LOG(DDR_LOG_DEBUG, "S:%x M:%x E:%x D:%x\n", start_pass_x_delay, center_pass_x_delay, end_pass_x_delay, end_pass_x_delay-start_pass_x_delay);
	}
}


void debug_tool_output(void)
{
	DDR_LOG(DDR_LOG_DEBUG, "\n\n");
	DDR_LOG(DDR_LOG_DEBUG, "***********************************\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   Debug Tool README           **\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   * ==> memtest PASS          **\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   _ ==> memtest FAIL          **\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   S ==> Start PASS delay      **\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   C ==> Center PASS delay     **\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   E ==> End PASS delay        **\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   D ==> PASS delay Delta      **\n");
	DDR_LOG(DDR_LOG_DEBUG, "***********************************\n");
	DDR_LOG(DDR_LOG_DEBUG, "**   input_odt_flag    :%d \n",input_odt_flag);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_phy_ds_flag :%d \n",input_phy_ds_flag);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_x_delay_flag:%d \n",input_x_delay_flag);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_y_vref_flag :%d \n",input_y_vref_flag);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_odt_reg     :%lx\n",input_odt_reg);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_phy_ds_reg  :%lx\n",input_phy_ds_reg);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_x_delay_reg :%lx\n",input_x_delay_reg);
	DDR_LOG(DDR_LOG_DEBUG, "**   input_y_vref_reg  :%lx\n",input_y_vref_reg);
	DDR_LOG(DDR_LOG_DEBUG, "***********************************\n");

	if(!input_x_delay_flag || !input_y_vref_flag){
		DDR_LOG(DDR_LOG_DEBUG, "please set x_delay / y_vref registers to simualte\n");
		return;
	}

	switch(x_delay_type){
	case X_TXDQDLYTG:
		/* TXDQDLYTG*:
		TxDqDlyTg*[8:6] is the coarse delay, ie one unit of delay is 1 UI.
		TxDqDlyTg*[4:0] is the fine (fractional UI) delay, ie one unit of delay is one-thirtysecond of a UI =
		UI/32.
		TxDqDlyTg*[5] is reserved. */
		set_x_to_test(6,8,32);
		break;

	case X_TXDQSDLYTG:
		/* TXDQSDLYTG*:
		TxDqsDlyTg*[9:6] is the coarse delay, ie one unit of delay is 1 UI.
		TxDqsDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
		TxDqsDlyTg*[5] is reserved.
		*/
		set_x_to_test(6,16,32);
		break;


	case X_RXENDLYTG:
		/* RXCLKDLYTG*:
		RxClkDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
		RxClkDlyTg*[5] is reserved. There is no coarse delay field, ie the max configurable delay is
		31/32 UI.
		*/
		set_x_to_test(0,0,32);
		break;

	case X_RXCLKDLYTG:
		/* RXCLKDLYTG*:
		RxClkDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
		RxClkDlyTg*[5] is reserved. There is no coarse delay field, ie the max configurable delay is
		31/32 UI.
		*/
		set_x_to_test(0,0,32);
		break;

	case X_RXCLKCDLYTG:
		/* RXCLKCDLYTG*:
		RxClkcDlyTg*[4:0] is the fine delay, ie one unit of delay is one-thirtysecond of a UI = UI/32.
		RxClkcDlyTg*[5] is reserved. There is no coarse delay field, ie the max configurable delay is
		31/32 UI.
		*/
		set_x_to_test(0,0,32);
		break;


	case X_UNKNOWN:
		DDR_LOG(DDR_LOG_DEBUG, "x_delay_type reg error\n");
		break;

	default:
		DDR_LOG(DDR_LOG_DEBUG, "x_delay_type reg not mapping\n");
		break;
	}
	restore_input_register();
}

void set_y_vref_all_to_test(void)
{
	unsigned long addr_y;
	for(int i=0;i<4;i++){//DBYTE#
		for(int j=0;j<9;j++){//_R#
			//DWC_DDRPHYA_DBYTE0__VrefDAC0_r0             	0x40100 	base
			//DWC_DDRPHYA_DBYTE0__VrefDAC0_r1             	0x40500 	base+(0x400*_R#)
			//DWC_DDRPHYA_DBYTE1__VrefDAC0_r0             	0x44100		base+(0x40000*DBYTE#)
			addr_y = DWC_DDRPHYA_DBYTE0__VrefDAC0_r0+(0x400*j)+(0x40000*i);
			debug_tool_input_y_vref(addr_y);
			debug_tool_output();

			//DWC_DDRPHYA_DBYTE0__VrefDAC1_r0             	0x400c0 	base
			//DWC_DDRPHYA_DBYTE0__VrefDAC1_r1             	0x404c0		base+(0x400*_R#)(
			//DWC_DDRPHYA_DBYTE1__VrefDAC1_r0             	0x440c0		base+(0x40000*DBYTE#)
			addr_y = DWC_DDRPHYA_DBYTE0__VrefDAC1_r0+(0x400*j)+(0x40000*i);
			debug_tool_input_y_vref(addr_y);
			debug_tool_output();
		}
	}
}


void debug_tool_output_all(void)
{
	unsigned long addr_x;

	debug_tool_init();
	DDR_LOG(DDR_LOG_DEBUG, "X_TXDQDLYTG test\n");
	for(int i=0;i<4;i++){//DBYTE#
		for(int j=0;j<4;j++){//TG#
			for(int k=0;k<9;k++){//_R#
				for(int l=0;l<4;l++){//_P#
					//DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p0        	0x40300		base
					//DWC_DDRPHYA_DBYTE0__TxDqDlyTg1_r0_p0        	0x40304 	base+(0x4*TG#)
					//DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r1_p0        	0x40700		base+(0x400*_R#)
					//DWC_DDRPHYA_DBYTE1__TxDqDlyTg0_r0_p0        	0x44300		base+(0x4000*DBYTE#)
					//DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p1        	0x440300  	base+(0x400000*_P#)
					addr_x = DWC_DDRPHYA_DBYTE0__TxDqDlyTg0_r0_p0+(0x4*j)+(0x400*k)+(0x4000*i)+(0x400000*l);
					debug_tool_input_x_delay(addr_x);
					set_y_vref_all_to_test();
				}
			}
		}
	}

	DDR_LOG(DDR_LOG_DEBUG, "X_TXDQSDLYTG test\n");
	for(int i=0;i<4;i++){//DBYTE#
		for(int j=0;j<4;j++){//TG#
			for(int k=0;k<2;k++){//_U#
				for(int l=0;l<4;l++){//_P#
					//DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p0       	0x40340		base
					//DWC_DDRPHYA_DBYTE0__TxDqsDlyTg1_u0_p0       	0x40344		base+(0x4*TG#)
					//DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u1_p0       	0x40740		base+(0x400*_U#)
					//DWC_DDRPHYA_DBYTE1__TxDqsDlyTg0_u0_p0       	0x44340		base+(0x4000*DBYTE#)
					//DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p1       	0x440340	base+(0x400000*_P#)
					addr_x = DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p0+(0x4*j)+(0x400*k)+(0x4000*i)+(0x400000*l);
					debug_tool_input_x_delay(addr_x);
					set_y_vref_all_to_test();
				}
			}
		}
	}

	DDR_LOG(DDR_LOG_DEBUG, "X_RXENDLYTG test\n");
	for(int i=0;i<4;i++){//DBYTE#
		for(int j=0;j<4;j++){//TG#
			for(int k=0;k<2;k++){//_U#
				for(int l=0;l<4;l++){//_P#
					//DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p0        	0x40200 	base
					//DWC_DDRPHYA_DBYTE0__RxEnDlyTg1_u0_p0        	0x40204		base+(0x4*TG#)
					//DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u1_p0        	0x40600 	base+(0x400*_U#)
					//DWC_DDRPHYA_DBYTE1__RxEnDlyTg0_u0_p0        	0x44200		base+(0x4000*DBYTE#)
					//DWC_DDRPHYA_DBYTE0__RxEnDlyTg0_u0_p1        	0x440200	base+(0x400000*_P#)
					addr_x = DWC_DDRPHYA_DBYTE0__TxDqsDlyTg0_u0_p0+(0x4*j)+(0x400*k)+(0x4000*i)+(0x400000*l);
					debug_tool_input_x_delay(addr_x);
					set_y_vref_all_to_test();
				}
			}
		}
	}

	DDR_LOG(DDR_LOG_DEBUG, "X_RXCLKDLYTG test\n");
	for(int i=0;i<4;i++){//DBYTE#
		for(int j=0;j<4;j++){//TG#
			for(int k=0;k<2;k++){//_U#
				for(int l=0;l<4;l++){//_P#
					//DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p0       	0x40230 	base
					//DWC_DDRPHYA_DBYTE0__RxClkDlyTg1_u0_p0       	0x40234		base+(0x4*TG#)
					//DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u1_p0       	0x40630 	base+(0x400*_U#)
					//DWC_DDRPHYA_DBYTE1__RxClkDlyTg0_u0_p0       	0x44230		base+(0x4000*DBYTE#)
					//DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p1       	0x440230	base+(0x400000*_P#)
					addr_x = DWC_DDRPHYA_DBYTE0__RxClkDlyTg0_u0_p0+(0x4*j)+(0x400*k)+(0x4000*i)+(0x400000*l);
					debug_tool_input_x_delay(addr_x);
					set_y_vref_all_to_test();
				}
			}
		}
	}

	DDR_LOG(DDR_LOG_DEBUG, "X_RXCLKCDLYTG test\n");
	for(int i=0;i<4;i++){//DBYTE#
		for(int j=0;j<4;j++){//TG#
			for(int k=0;k<2;k++){//_U#
				for(int l=0;l<4;l++){//_P#
					//DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p0      	0x40240		base
					//DWC_DDRPHYA_DBYTE0__RxClkcDlyTg1_u0_p0      	0x40244		base+(0x4*TG#)
					//DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u1_p0      	0x40640		base+(0x400*_U#)
					//DWC_DDRPHYA_DBYTE1__RxClkcDlyTg0_u0_p0      	0x44240		base+(0x4000*DBYTE#)
					//DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p1      	0x440240	base+(0x400000*_P#)
					addr_x = DWC_DDRPHYA_DBYTE0__RxClkcDlyTg0_u0_p0+(0x4*j)+(0x400*k)+(0x4000*i)+(0x400000*l);
					debug_tool_input_x_delay(addr_x);
					set_y_vref_all_to_test();
				}
			}
		}
	}
}
