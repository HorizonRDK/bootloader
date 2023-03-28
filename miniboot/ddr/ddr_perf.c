#include <stdio.h>
#include <stdlib.h>

#include "types.h"

//#include <asm/arch/ddr.h>
#include "ddr.h"
//#include <asm/arch/ddr_phy.h>
//#include "ddr_phy_registers.h"

/******************performance monitor registers*****************/
#define DDR_PORT_READ_QOS_CTRL    (DDRC_PERF_MON_ADDR + 0x00)
#define DDR_PORT_WRITE_QOS_CTRL   (DDRC_PERF_MON_ADDR + 0x04)
#define DDR_PHY_DFI1_ENABLE_CTRL  (DDRC_PERF_MON_ADDR + 0x08)
#define PERF_MONITOR_ENABLE       (DDRC_PERF_MON_ADDR + 0x20)
#define PERF_MONITOR_PERIOD       (DDRC_PERF_MON_ADDR + 0x24)
#define PERF_MONITOR_SRCPND       (DDRC_PERF_MON_ADDR + 0x28)
#define PERF_MONITOR_INTMASK      (DDRC_PERF_MON_ADDR + 0x2C)
#define PERF_MONITOR_SETMASK      (DDRC_PERF_MON_ADDR + 0x30)
#define PERF_MONITOR_UNMASK       (DDRC_PERF_MON_ADDR + 0x34)

#define MP0X_RID_CFG(index)       (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x00)
#define MP0X_RADDR_TX_NUM(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x10)
#define MP0X_RDATA_TX_NUM(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x14)
#define MP0X_RADDR_ST_CYC(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x18)
#define MP0X_RA2LSTRD_LAT(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x1C)
#define MP0X_WID_CFG(index)       (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x30)
#define MP0X_WADDR_TX_NUM(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x40)
#define MP0X_WDATA_TX_NUM(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x44)
#define MP0X_WADDR_ST_CYC(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x48)
#define MP0X_WA2BRESP_LAT(index)  (DDRC_PERF_MON_ADDR + 0x100*((index)+1) + 0x4C)

#define RD_CMD_TX_NUM_INDDRC      (DDRC_PERF_MON_ADDR + 0x700)
#define WR_CMD_TX_NUM_INDDRC      (DDRC_PERF_MON_ADDR + 0x704)
#define MWR_CMD_TX_NUM_INDDRC     (DDRC_PERF_MON_ADDR + 0x708)
#define RDWR_SWITCH_NUM_INDDRC    (DDRC_PERF_MON_ADDR + 0x70C)
#define ACT_CMD_TX_NUM_INDDRC     (DDRC_PERF_MON_ADDR + 0x710)
#define ACT_CMD_FOR_RD_TX_NUM_INDDRC  (DDRC_PERF_MON_ADDR + 0x714)
#define WAR_HAZARD_NUM_INDDRC     (DDRC_PERF_MON_ADDR + 0x718)
#define RAW_HAZARD_NUM_INDDRC     (DDRC_PERF_MON_ADDR + 0x71C)
#define WAW_HAZARD_NUM_INDDRC     (DDRC_PERF_MON_ADDR + 0x720)
#define PRECHARGE_CMD_TX_NUM      (DDRC_PERF_MON_ADDR + 0x724)
#define PRECHARGE_CMD_FOR_RDWR_TX_NUM (DDRC_PERF_MON_ADDR + 0x728)


/**********************IO_TEST*******************************/
#define BYPASS_MODE_EN            (DDRC_IO_TEST + 0x00)

/************************************************************/
#define DDRC_PORT_NUM               6
#define DDRC_CPU_PORT_INDEX         0
#define DDRC_APB_PORT_INDEX         1
#define DDRC_CNN0_PORT_INDEX        2
#define DDRC_CNN1_PORT_INDEX        3
#define DDRC_IPU_PORT_INDEX         4
#define DDRC_PERI_PORT_INDEX        5



#define PERF_ENABLE                        1
#define PERF_DISABLE                       0

#define PERF_MONITOR_GLOBAL_ENABLE         (1<<(0))
#define PERF_MONITOR_PORT_ENABLE(index)    (1<<((index)+1))
#define PERF_MONITOR_DDRC_ENABLE           (1<<7)

/*pclk=333M, T=3ns, Set follow registers as*/
#define PERF_PERIOD                        100000         /*The period is 100ms*/
#define PERF_MONITOR_PERIOD_PCLK_TICKS(us_period)      ((us_period)*1000/3)  /*us_period means the period unit is us.*/

#define PERF_MONITOR_INT_ENABLE            1
#define PERF_MONITOR_INT_DISABLE           0

struct perf_statistics
{
    unsigned int port_read_bandwidth;
    unsigned int port_read_stall;
    unsigned int port_read_delay;
    unsigned int port_write_bandwidth;
    unsigned int port_write_stall;
    unsigned int port_write_delay;
    unsigned int read_cmd_bandwidth;
    unsigned int write_cmd_bandwidth;
    unsigned int mask_write_cmd_bandwidth;
};

static inline void reg32_write_perf(unsigned long addr, u32 val)
{
	writel(val, addr);
}

static inline u32 reg32_read_perf(unsigned long addr)
{
	return readl(addr);
}

/*
functions:
1. perf monitor enable
    para1: port num
    para2: diable/enable
2.perf monitor period set
   para1: time period unit:pclk
3.perf interrupt disable/enable
4.dump port perf(port num)
5.dump_total_perf


*/

#if 0
static void ddr_perf_monitor_enable(unsigned int portnum, int enable)
{
    if(portnum >= DDRC_PORT_NUM)
    {
        printf( "<ddr perf>Input portnum is out of range!");
        return;
    }

    if(PERF_ENABLE == enable)
    {
        reg32_write_perf(
                     PERF_MONITOR_ENABLE,
                     PERF_MONITOR_GLOBAL_ENABLE|
                     PERF_MONITOR_PORT_ENABLE(portnum)|
                     PERF_MONITOR_DDRC_ENABLE
                    );
    }
    else
    {
        reg32_write_perf(PERF_MONITOR_ENABLE, 0);
    }

}

static void ddr_perf_monitor_int(int enable)
{
    if(PERF_MONITOR_INT_ENABLE == enable)
    {
        reg32_write_perf(PERF_MONITOR_UNMASK, 1);
    }
    else
    {
        reg32_write_perf(PERF_MONITOR_SETMASK, 1);
    }
}
#endif
void ddr_perf_dump_port(unsigned int portnum)
{
#if 0
    unsigned int tmp = 0;
    /*RID_CFG register is used to filter transaction ID. The definition of ID please reference AXI bus theory. It could filter ID from different master.*/
	/* All make "arid & ~id_mask == id_tgt" transaction ID could be monitored.*/
    printf( "\r\n----------------------------port %d performance monitor registers--------------------------",portnum);
    tmp = reg32_read_perf(MP0X_RID_CFG(portnum));
    printf( "\r\nMP0X_RID_CFG(%d):0x%x. ID target:0x%x, ID mask:0x%x",portnum, tmp, tmp&0xFF, (tmp>>16) & 0xFF);

    tmp = reg32_read_perf(MP0X_RADDR_TX_NUM(portnum));
    printf( "\r\nMP0X_RADDR_TX_NUM(%d):0x%x. Master port read transaction num:%d",portnum, tmp, tmp);

    tmp = reg32_read_perf(MP0X_RDATA_TX_NUM(portnum));
    printf( "\r\nMP0X_RDATA_TX_NUM(%d):0x%x. Master port read data num:%d",portnum, tmp, tmp);

    tmp = reg32_read_perf(MP0X_RADDR_ST_CYC(portnum));
    printf( "\r\nMP0X_RADDR_ST_CYC(%d):0x%x. Accumulated time when read requests are stalled:%d unit:aclk cycle",portnum, tmp, tmp);

    tmp = reg32_read_perf(MP0X_RA2LSTRD_LAT(portnum));
    printf( "\r\nMP0X_RA2LSTRD_LAT(%d):0x%x. Sum of ra2lstrd of all read transactions:%d",portnum, tmp, tmp);

    printf( "\r\n====================================================");
    tmp = reg32_read_perf(MP0X_WID_CFG(portnum));
    printf( "\r\nMP0X_WID_CFG(%d):0x%x. WID target:0x%x, WID mask:0x%x",portnum, tmp, tmp&0xFF, (tmp>>16) & 0xFF);

    tmp = reg32_read_perf(MP0X_WADDR_TX_NUM(portnum));
    printf( "\r\nMP0X_WADDR_TX_NUM(%d):0x%x. Master port write transaction num:%d",portnum, tmp, tmp);

    tmp = reg32_read_perf(MP0X_WDATA_TX_NUM(portnum));
    printf( "\r\nMP0X_WDATA_TX_NUM(%d):0x%x. Master port write data num:%d",portnum, tmp, tmp);

    tmp = reg32_read_perf(MP0X_WADDR_ST_CYC(portnum));
    printf( "\r\nMP0X_RADDR_ST_CYC(%d):0x%x. Accumulated time when write requests are stalled:%d unit:aclk cycle",portnum, tmp, tmp);

    tmp = reg32_read_perf(MP0X_WA2BRESP_LAT(portnum));
    printf( "\r\nMP0X_WA2BRESP_LAT(%d):0x%x. Sum of wa2bresp of all writes transactions:%d",portnum, tmp, tmp);
#endif
}

void ddr_perf_dump_total(struct perf_statistics *perf_statist)
{
#if 0
    unsigned int tmp = 0;
    printf( "\r\n----------------------------total port performance monitor registers-----------------------");
    tmp = reg32_read_perf(RD_CMD_TX_NUM_INDDRC);
    printf( "\r\nRD_CMD_TX_NUM_INDDRC:0x%x. Num of read command that is issued by DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(WR_CMD_TX_NUM_INDDRC);
    printf( "\r\nWR_CMD_TX_NUM_INDDRC:0x%x. Num of write command that is issued by DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(MWR_CMD_TX_NUM_INDDRC);
    printf( "\r\nMWR_CMD_TX_NUM_INDDRC:0x%x. Num of mask write command that is issued by DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(RDWR_SWITCH_NUM_INDDRC);
    printf( "\r\nRDWR_SWITCH_NUM_INDDRC:0x%x. Num of Read to Write and Write to Read bus-tun-around happens in DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(ACT_CMD_TX_NUM_INDDRC);
    printf( "\r\nACT_CMD_TX_NUM_INDDRC:0x%x. Num of active command that is issued by DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(ACT_CMD_FOR_RD_TX_NUM_INDDRC);
    printf( "\r\nACT_CMD_FOR_RD_TX_NUM_INDDRC:0x%x. Num ofread active command that is issued DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(WAR_HAZARD_NUM_INDDRC);
    printf( "\r\nWAR_HAZARD_NUM_INDDRC:0x%x. Num of Write-after-Read collision that happens in DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(RAW_HAZARD_NUM_INDDRC);
    printf( "\r\nRAW_HAZARD_NUM_INDDRC:0x%x. Num of Read-after-Write collision that happens in DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(WAW_HAZARD_NUM_INDDRC);
    printf( "\r\nWAW_HAZARD_NUM_INDDRC:0x%x. Num of Write-after-Write collision that happens in DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(PRECHARGE_CMD_TX_NUM);
    printf( "\r\nPRECHARGE_CMD_TX_NUM:0x%x. Num of Precharge that is issued by DDRC:%d", tmp, tmp);

    tmp = reg32_read_perf(PRECHARGE_CMD_FOR_RDWR_TX_NUM);
    printf( "\r\nPRECHARGE_CMD_FOR_RDWR_TX_NUM:0x%x. Num of Precharge that is issued for Read or Write commands by DDRC:%d", tmp, tmp);
#endif
/*
sprintf( buf + length, "p[%d](bw:%u stall:%u delay:%u) ", i, \
						(ddr_info[cur].portdata[i].rdata_num * 16 * (1000000/g_monitor_poriod)) >> 20, \
						ddr_info[cur].portdata[i].raddr_cyc / ddr_info[cur].portdata[i].rdata_num, \
						ddr_info[cur].portdata[i].raddr_latency / ddr_info[cur].portdata[i].rdata_num);
*/
    unsigned long addr_num,data_num,addr_cyc,addr_latency;

    addr_num = reg32_read_perf(MP0X_RADDR_TX_NUM(0));
    data_num = reg32_read_perf(MP0X_RDATA_TX_NUM(0));
    addr_cyc = reg32_read_perf(MP0X_RADDR_ST_CYC(0));
    addr_latency = reg32_read_perf(MP0X_RA2LSTRD_LAT(0));
    perf_statist->port_read_bandwidth = (data_num * 16 * (1000000/PERF_PERIOD)) >> 20;
    perf_statist->port_read_stall     = addr_cyc / addr_num;
    perf_statist->port_read_delay     = addr_latency / addr_num;

    addr_num = reg32_read_perf(MP0X_WADDR_TX_NUM(0));
    data_num = reg32_read_perf(MP0X_WDATA_TX_NUM(0));
    addr_cyc = reg32_read_perf(MP0X_WADDR_ST_CYC(0));
    addr_latency = reg32_read_perf(MP0X_WA2BRESP_LAT(0));
    perf_statist->port_write_bandwidth = (data_num * 16 * (1000000/PERF_PERIOD)) >> 20;
    perf_statist->port_write_stall     = addr_cyc / addr_num;
    perf_statist->port_write_delay     = addr_latency / addr_num;

    addr_num = reg32_read_perf(RD_CMD_TX_NUM_INDDRC);
    data_num = reg32_read_perf(WR_CMD_TX_NUM_INDDRC);
    addr_cyc = reg32_read_perf(MWR_CMD_TX_NUM_INDDRC);
    perf_statist->read_cmd_bandwidth = (addr_num * 64 * (1000000/PERF_PERIOD)) >> 20;
    perf_statist->write_cmd_bandwidth = (data_num * 64 * (1000000/PERF_PERIOD)) >> 20;
    perf_statist->mask_write_cmd_bandwidth = (addr_cyc * 64 * (1000000/PERF_PERIOD)) >> 20;

    /*printf( "\r port 0(bandwidth:%u MB/s stall:%u delay:%u)     ",\
                  (data_num * 16 * (1000000/PERF_PERIOD)) >> 20, \
                  (addr_cyc / addr_num), addr_latency / addr_num);
       */

/*
   read_data_0 = GETREG32(0xa2d10110);
   read_data_1 = GETREG32(0xa2d10114);
   read_data_2 = GETREG32(0xa2d10118);
   read_data_3 = GETREG32(0xa2d1011c);

    print(" port0 raddr_transfer_num is %0x",read_data_0);
    print(" port0 rdata_transfer_num is %0x",read_data_1);
    print(" port0 raddr_stalling_cyc is %0x",read_data_2);
    print(" port0 raddr_to_lastrdata is %0x",read_data_3);



    print(" port0 read transaction bandwidth is  %0d MB/s",(read_data_1*16)>>20);
    print(" port0 average read transaction stalling time is %0d cycle",read_data_2 /read_data_0);
    print(" port0 average read data delay time is %0d cycle",read_data_3 /read_data_0);

   read_data_0 = GETREG32(0xa2d10140);
   read_data_1 = GETREG32(0xa2d10144);
   read_data_2 = GETREG32(0xa2d10148);
   read_data_3 = GETREG32(0xa2d1014c);

    print(" port0 waddr_transfer_num is %0x",read_data_0);
    print(" port0 wdata_transfer_num is %0x",read_data_1);
    print(" port0 waddr_stalling_cyc is %0x",read_data_2);
    print(" port0 waddr_to_lastrdata is %0x",read_data_3);


    print(" port0 write transaction bandwidth is  %0d MB/s",(read_data_1*16)>>20);
    print(" port0 average write transaction stalling time is %0d cycle",read_data_2 /read_data_0);
    print(" port0 average write data delay time is %0d cycle",read_data_3 /read_data_0);

       read_data_0 = GETREG32(0xa2d10700);
   read_data_1 = GETREG32(0xa2d10704);
   read_data_2 = GETREG32(0xa2d10708);
   read_data_3 = GETREG32(0xa2d1070c);
   read_data_4 = GETREG32(0xa2d10710);
   read_data_5 = GETREG32(0xa2d10714);
   read_data_6 = GETREG32(0xa2d10718);
   read_data_7 = GETREG32(0xa2d1071c);
   read_data_8 = GETREG32(0xa2d10720);
   read_data_9 = GETREG32(0xa2d10724);
   read_data_10 = GETREG32(0xa2d10728);



    print(" ddrc  rd_cmd_transfer_num                   is %0x",read_data_0);
    print(" ddrc  wr_cmd_transfer_num                   is %0x",read_data_1);
    print(" ddrc  mwr_cmd_transfer_num                  is %0x",read_data_2);


    print(" ddrc  rdwr_switch_transfer_num              is %0x",read_data_3);
    print(" ddrc  war_hazard_transfer_num               is %0x",read_data_4);
    print(" ddrc  raw_hazard_transfer_num               is %0x",read_data_5);
    print(" ddrc  waw_hazard_transfer_num               is %0x",read_data_6);
    print(" ddrc  activate_cmd_transfer_num             is %0x",read_data_7);
    print(" ddrc  activate_cmd_for_rd_transfer_num      is %0x",read_data_8);
    print(" ddrc  precharge_cmd_transfer_num            is %0x",read_data_9);
    print(" ddrc  precharge_cmd_for_rdwr_transfer_num   is %0x",read_data_10);



    print(" ddrc  read command bandwidth                    is %0d MB/s",(read_data_0*64)>>20);
    print(" ddrc  write command bandwidth                   is %0d MB/s",(read_data_1*64)>>20);
    print(" ddrc  Mask write command bandwidth              is %0d MB/s",(read_data_2*64)>>20);

*/
}

#define TIMER0_BASE_ADDR      0xA1002000
static inline void init_timer0(void)
{
    reg32_write_perf(TIMER0_BASE_ADDR,0x1);//enable timer0
    reg32_write_perf(TIMER0_BASE_ADDR+0xC,0); //one-time mode
}



void ddr_perf_monitor_init(void)
{
    int temp = 0;
    int us_period = PERF_PERIOD;

    reg32_write_perf(PERF_MONITOR_PERIOD, PERF_MONITOR_PERIOD_PCLK_TICKS(us_period));
    //SETREG32(0xa2d10024, 0x13de4355);//1s
    reg32_write_perf(PERF_MONITOR_SETMASK, 0x1);
    //SETREG32(0xa2d10030, 0x1);
    reg32_write_perf(PERF_MONITOR_ENABLE, 0xFF);
    //SETREG32(0xa2d10020, 0xff);

    temp = reg32_read_perf(PERF_MONITOR_INTMASK);
    //temp = GETREG32(0xa2d1002c);

    temp = 0;
    while(temp==0)
    {
        temp = reg32_read_perf(PERF_MONITOR_SRCPND);
        //temp = GETREG32(0xa2d10028);
    }
    reg32_write_perf(PERF_MONITOR_SRCPND, 0x1);
    //SETREG32(0xa2d10028, 0x1);
    init_timer0();
}

void start_timer0(void)
{
    /*Set Timer0 as 0xFFFFFFFF. In 24MHz clock the timer is about 176 seconds.*/
    reg32_write_perf(TIMER0_BASE_ADDR+0x10,0xFFFFFFFF);
    reg32_write_perf(TIMER0_BASE_ADDR+0x14,0xFFFFFFFF);
    reg32_write_perf(TIMER0_BASE_ADDR+0x4,1);
}

void stop_timer0(void)
{
    reg32_write_perf(TIMER0_BASE_ADDR+0x8,1);
}

unsigned long get_timer0_val(void)
{
    unsigned long val = 0L;
    val = reg32_read_perf(TIMER0_BASE_ADDR+0x1C);
    val = val << 32;
    val += reg32_read_perf(TIMER0_BASE_ADDR+0x18);
    return val;
}


//typedef unsigned int DATA_TYPE;
typedef unsigned long DATA_TYPE;
//#define INIT_VALUE_DWORD         0x5A5A5A5A5A5A5A5A
#define INIT_VALUE_WORD          0x00000000//0x5A5A5A5A//0x5A5A5A5A//0x0000000F//0x00000000//0x5A5A5A5A
#define INIT_VALUE               INIT_VALUE_WORD
#define DDR_SIZE                 CONFIG_SYS_SDRAM_SIZE /*0x80000000 */ /*SVB:2GB DDR*/
#define SLASH_STEP               (DDR_SIZE>>4) //0x10000000 /*SVB:�C??256MB?�u�A���L�@����?*/
#define LINES     "\r\n--------------------------------------------------"
/*****************************************************************************
 Prototype    : get_band_by_MBpSec
 Description  : get DDR band width via transfer data and check the transfer period
 Input        : unsigned long ul_size_Byte  (Data unit: word)
                unsigned long ticks         (Time unit: ticks)
 Output       : None
 Return Value : static
 Calls        :
 Called By    :

  History        :
  1.Date         : 2019/4/22
    Author       : wuyakun
    Modification : Created function

*****************************************************************************/
static inline unsigned long get_band_by_MBpSec(unsigned long ul_size_Byte, unsigned long ticks)
{
    #if 0
    unsigned long rate_BytePerSec = ul_size_Byte * get_tbclk() / ticks;//get_tbclk get tick clock frequency
    return rate_BytePerSec/MHZ(1);
    #else
    return ul_size_Byte*1/ticks;  //timer0 use 1MHz clock
    #endif
}

/*****************************************************************************
 Prototype    : ddr_acdc_test
 Description  : In SPL, to measure electrical characteristics. It needs simple read/write in data bus, function do not return.
 Input        : void
 Output       : None
 Return Value :
 Calls        :
 Called By    :

  History        :
  1.Date         : 2019/4/19
    Author       : wuyakun
    Modification : Created function

*****************************************************************************/
void ddr_acdc_test(void)
{
    DATA_TYPE pattern = INIT_VALUE;
    DATA_TYPE *ddr_start_addr = 0;
    //unsigned long ul_step = 0x1000000; /*SVB: Check status each 16MB data.*/
    unsigned long ul_count = 0;
    //unsigned long ul_slash_step = 0x10000000; /*SVB: print slash each 256MB data*/
    int slash_flag = 1;
    //unsigned long start_counter = 0;
    unsigned long now = 0;
    //unsigned long now_counter = 0;
    unsigned long rate_by_MBpSec = 0;
    int test_flag = 0;
    struct perf_statistics st_perf_statist;
    int write_before_read_flag = 1;

    /*
        Read Performance register, check data
        Branch to WRITE or READ based on the command from serial port
        Based on timer0 to count time and measure bandwidth
        Close DCACHE
      */
    ddr_perf_monitor_init();
    dcache_disable();
    printf( "\r\n------------------Begin DDR Pressure Test-------------\n");
    /*printf( "Pinmux value:read_write %d (0 means write), test_process %d (1 means end)\n",
                   (PIN_SKIP_CSUM_SEL(readl(STRAP_PIN_REG))),   (PIN_EN_MMU_SEL(readl(STRAP_PIN_REG))));*/
    //pcnt_start = get_ticks();//use pcnt counter
    printf( "\r\nInput 'w' to begin write through ddr test. / Input 'r' to begin read test. / Input 'c' to check DDR size. / Input 's' to skip test.");
    while(1)
    {
        test_flag = serial_getc();
        if((test_flag == 'w') || (test_flag == 'r') || (test_flag == 'c'))
        {
            printf( "\r\n Your input command is %c\n", test_flag);
            break;
        }
    }

    //start_counter = 0;
    ul_count = 0;

    while(1)
    {
        start_timer0();//use timer0 counter
        switch(test_flag)
        {
            case 'w':
            {
                do
                {
                    ddr_start_addr[0] = pattern;
                    ddr_start_addr++;
                    ul_count += sizeof(DATA_TYPE); /*ul_count unit: word*/
                    pattern = ~pattern;
                    //pattern = pattern^0x1;
                    //pattern = pattern^0xFFFFFFF0;;
                    //pattern = pattern^0xFFFFFFFE;
					//printf("=pattern:0x%x\n",pattern);
                }
                while(ul_count < SLASH_STEP);
				//printf("=pattern:0x%lx\n",pattern);
                break;
            }
            case 'r':
            {
                if(1 == write_before_read_flag)
                {
                    /*Write before read, each bit on DQ bus need to be reverted. Polling read all DDR means each word is complement of its adjacent word.*/
                    do
                    {
                        ddr_start_addr[0] = pattern;
                        ddr_start_addr++;
                        ul_count += sizeof(DATA_TYPE); /*ul_count unit: word*/
                        pattern = ~pattern;
                    }
                    while(ul_count < DDR_SIZE);

                    write_before_read_flag = 0;
                    ddr_start_addr = 0;
                    ul_count = 0;
                }
                asm volatile("str x3, %0" : "+m" (pattern));/*If not using volatile and inline compilation, the read logic would be optimized by compiler. Only the last is reserved*/
                do
                {
                    #if 0
                    read_val = ddr_start_addr[0];
                    #else
                	asm volatile("ldr x3, %0" : "+m" (ddr_start_addr[0]));
                	#endif
                    ddr_start_addr++;
                    ul_count += sizeof(DATA_TYPE);
                }
                while(ul_count < SLASH_STEP);
                asm volatile("ldr x3, %0" : "+m" (pattern));
                break;
            }
            case 'c':
            #if 1
            {
                /*Write before read, each bit on DQ bus need to be reverted. Polling read all DDR means each word is complement of its adjacent word.*/
                //pattern = INIT_VALUE;
                char flag = 0;
                do
                {
                    //ddr_start_addr[0] = pattern;
                    *ddr_start_addr = (unsigned long)ddr_start_addr;
                    ddr_start_addr++;
                    ul_count += sizeof(DATA_TYPE);
                    //pattern = ~pattern;
                }
                while(ul_count < DDR_SIZE);

                ddr_start_addr = 0;
                ul_count = 0;
                //pattern = INIT_VALUE;

                do
                {
                    DATA_TYPE read_once = 0L;
                    DATA_TYPE read_again = 0L;
                    read_once = *ddr_start_addr;

                    if(read_once != (unsigned long)ddr_start_addr)
                    {
                        flag  = 1;
                        read_again = *ddr_start_addr;
                        printf( "Hardware Error: miscompare on at DDR 0x%lx: read:0x%lx, reread:0x%lx ",\
                                  (unsigned long)ddr_start_addr, (unsigned long)read_once, (unsigned long)read_again);
						read_again = read_again; //fix compile warning
                    }
                    ddr_start_addr++;
                    //pattern = ~pattern;
                    ul_count += sizeof(DATA_TYPE);
                }
                while(ul_count < DDR_SIZE);
                if (0 == flag)
                {
                    printf( "DDR size is %d GB. Status: PASS - please verify no corrected errors!\n", DDR_SIZE>>30);
                }
                else
                {
                    printf( "Status: FAIL - Hardware Error!\n");
                }
                return;
            }
            #else
            {
                *ddr_start_addr = pattern;
				/*write pattern into address 0 as the judgement of overflow.*/
                ul_count += sizeof(DATA_TYPE);
                printf( "\r\nWirte 0x%x to address 0", pattern);
                ddr_start_addr++;
                do
                {
                    /*Write data "Address" into the corresponding address */
                    *ddr_start_addr = (DATA_TYPE)ddr_start_addr;
                    if(pattern != *(DATA_TYPE *)(0L))/*read the value of 0*/
                    {
                        printf( "\r\n DDR's size is 0x%lx(%ld GB)", ul_count,ul_count>>30);
                        return;
                    }
                    ul_count += sizeof(DATA_TYPE);
                    ddr_start_addr++;
                    if(0 == ul_count%(128<<20))
                    {
                        printf( ".");
                    }
                    if(ul_count == DDR_SIZE)
                    {
                        printf( "\r\ncount increased to DDR_SIZE.Addr[0]=0x%x",*(DATA_TYPE *)(0L));
                    }
                }
                while(1);
            }
            #endif
            default : break;
        }

        /*Transfer each ul_slash_step word would print one slash*/
        {
            ddr_perf_dump_total(&st_perf_statist);
            now = get_timer0_val();
            stop_timer0();
            #if 0
            now_counter = ul_count;
            if(now_counter < start_counter)
            {
                ul_total_size = 0xFFFFFFFFFFFFFFFF - start_counter + now_counter;
            }
            else
            {
                ul_total_size = now_counter - start_counter;
            }

            rate_by_MBpSec = get_band_by_MBpSec(ul_total_size, now);
            #else
            rate_by_MBpSec = get_band_by_MBpSec(SLASH_STEP, now);
            #endif

            if(slash_flag % 2)
            {
                printf( "\r\\:%s rate_by_timer0:  %ld MB/s read(bw:%u MB/s stall:%u delay:%u) write(bw:%u MB/s stall:%u delay:%u) ddrc(read_bw %u MB/s write_bw %u MB/s mask write %u MB/s)",\
                              (test_flag == 'w') ? "write":"read", rate_by_MBpSec, \
                              st_perf_statist.port_read_bandwidth,\
                              st_perf_statist.port_read_stall,\
                              st_perf_statist.port_read_delay,\
                              st_perf_statist.port_write_bandwidth,\
                              st_perf_statist.port_write_stall,\
                              st_perf_statist.port_write_delay,\
                              st_perf_statist.read_cmd_bandwidth,\
                              st_perf_statist.write_cmd_bandwidth,\
                              st_perf_statist.mask_write_cmd_bandwidth);
            }
            else
            {
                //printf( "\r/: %s rate_by_timer0:  %ld MB/s   ", (test_flag == 'w') ? "write":"read", rate_by_MBpSec);
                    printf( "\r/:%s rate_by_timer0:  %ld MB/s read(bw:%u MB/s stall:%u delay:%u) write(bw:%u MB/s stall:%u delay:%u) ddrc(read_bw %u MB/s write_bw %u MB/s mask write %u MB/s)",\
                              (test_flag == 'w') ? "write":"read", rate_by_MBpSec, \
                              st_perf_statist.port_read_bandwidth,\
                              st_perf_statist.port_read_stall,\
                              st_perf_statist.port_read_delay,\
                              st_perf_statist.port_write_bandwidth,\
                              st_perf_statist.port_write_stall,\
                              st_perf_statist.port_write_delay,\
                              st_perf_statist.read_cmd_bandwidth,\
                              st_perf_statist.write_cmd_bandwidth,\
                              st_perf_statist.mask_write_cmd_bandwidth);
            }
			rate_by_MBpSec = rate_by_MBpSec; //fix compile warning

            slash_flag++;
            ul_count = 0;
        }

        if((unsigned long)ddr_start_addr >= DDR_SIZE)
        {
            ddr_start_addr = 0;
        }

        if(test_flag == 's')
        {
            printf( "\nSkip DDR TEST and continue to load uboot!\n");
            break;
        }
    }
}

#define DMA_WRITE_DBG 0
void dma_write_test(void)
{
	//Write all 1 for high speed scope test and measure power issue.
	//# program source content as 0xFFFFFFFF
	//int i=0;
	//int j=4;
	unsigned int k=0;
	void *waddr;
	#if DMA_WRITE_DBG
	void *raddr;
	#endif
	unsigned int *checkaddr;
	//unsigned int *raddr;
	//uint32 pollingDone=0;
	//uint64 z=0x20000000;
	//uint64 sadd=0;
	#if 0
	while (i<1024)
	{
		sadd=z+i*j;
		printf("%d sadd %x\n", i, sadd);
		SETREG32(sadd, 0xFFFFFFFF);
		i++;
	}
	#endif
	#if 0//only 0xFFFFFFFF case
	waddr = (void *)0x20000000;
	memset(waddr,0x0000000F,1024);
	#else//0xFFFFFFFF/0x0000000F case
	waddr = (void *)0x20000000;
	for(int i=0;i<1024;i=i+4){
		if(i%8==0){
			checkaddr = waddr+i;
			//*checkaddr = 0x0000000F;
			//*checkaddr = 0x000000FF;
			*checkaddr = 0x5a5a5a5a;
			#if DMA_WRITE_DBG
			printf("a. %d  %x: %x\n",i,checkaddr,*checkaddr);
			#endif
		}
		else{
			checkaddr = waddr+i;
			*checkaddr = 0xa5a5a5a5;
			//*checkaddr = 0x0000000F;
			#if DMA_WRITE_DBG
			printf("b. %d  %x: %x\n",i,checkaddr,*checkaddr);
			#endif
		}
	}
	#endif

	//while (k<1000000000)
	while (k<0x1000)
	{
		//# program source address
		SETREG32(0xA1005100, 0x20000000);

		//# program dest address
		SETREG32(0xA1005104, 0x21000000+0x1000*k);

		//# set ctrl register, size=1KByte
		SETREG32(0xA1005108, 0xf10003FF);

		//# set clear bit mux
		SETREG32(0xA1005014, 0x3);

		//# write DMAC_SOFT_REQ
		SETREG32(0xA1005004, 0x1);
		//devmem 0xA1005004 32 0x1
		printf("%x dma from 0x20000000 to %x\n",k,0x21000000+0x1000*k);

		while(GETREG32(0xA100500c)==0)
			printf("Wait DMA done...\n");

		while(GETREG32(0xA100500c)==1)
		{
			//pollingDone=GETREG32(0xA100500c);
			SETREG32(0xA100500c, 0x1);
			//printf("Clear DMA\n");
		}
		#if DMA_WRITE_DBG
		raddr = (void *)0x21000000;
		checkaddr = raddr;
		printf("  %x:%x  ", checkaddr, *checkaddr);
		checkaddr = raddr+4;
		printf("  %x:%x\n", checkaddr, *checkaddr);
		#endif
		k++;
	}

}
