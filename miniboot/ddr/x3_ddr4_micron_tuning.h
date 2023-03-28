#ifndef __X2A_DDR4_MICRON_TUNING_H__
#define __X2A_DDR4_MICRON_TUNING_H__


#ifdef DDR4_A1 //SNPS Silicon Report Suggest
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //RNG1 : Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define ddr_test_name_DDR4_MICRON		"DDR4_A1"
#endif

#ifdef DDR4_A1_SLEW //SNPS Silicon Report Suggest
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //RNG1 : Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_A1_SLEW"
#endif

#ifdef DDR4_A2
#define MR1_DDR4_MICRON 0x0603 //Rtt_nom : 80 ohm / ODI : 48 ohm
#define MR6_DDR4_MICRON 0x0c11 //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7d //PU/PD : 60/40
#define TxImpedance_DDR4_MICRON 0xe1f //PU/PD : 60/40
#define ddr_test_name_DDR4_MICRON		"DDR4_A2"
#endif

#ifdef DDR4_A4
#define MR1_DDR4_MICRON 0x0203 //Rtt_nom : 120 ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr : 120 ohm
#define MR5_DDR4_MICRON 0x0480 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define ddr_test_name_DDR4_MICRON		"DDR4_A4"
#endif

#ifdef DDR4_A5
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_A5"
#endif

#ifdef DDR4_A6
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_A6"
#endif

#ifdef DDR4_A7
#define MR1_DDR4_MICRON 0x0005 //Rtt_nom : HZ ohm / ODI : 40 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_A7"
#endif

#ifdef DDR4_A8
#define MR1_DDR4_MICRON 0x0005 //Rtt_nom : HZ ohm / ODI : 40 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %71.7 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x63f //PU/PD : 40/60
#define TxSlewRate_DDR4_MICRON  0x2f3 //N/P : f/3
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_A8"
#endif

#ifdef DDR4_A11
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x63f //PU/PD : 40/60
#define TxImpedance_DDR4_MICRON_B2 0x63f //PU/PD : 40/120
#define TxSlewRate_DDR4_MICRON  0x2f3 //N/P : f/3
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_A11"
#endif

#ifdef DDR4_C14
#define ddr_test_name_DDR4_MICRON		"DDR4_C14"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F0
#define ddr_test_name_DDR4_MICRON		"DDR4_F0"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F1
#define ddr_test_name_DDR4_MICRON		"DDR4_F1"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F2
#define ddr_test_name_DDR4_MICRON		"DDR4_F2"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0203 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F3
#define ddr_test_name_DDR4_MICRON		"DDR4_F3"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0203 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F4
#define ddr_test_name_DDR4_MICRON		"DDR4_F4"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0205 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F5
#define ddr_test_name_DDR4_MICRON		"DDR4_F5"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0A //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F6
#define ddr_test_name_DDR4_MICRON		"DDR4_F6"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F7
#define ddr_test_name_DDR4_MICRON		"DDR4_F7"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0900 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F8
#define ddr_test_name_DDR4_MICRON		"DDR4_F8"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0800 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F9
#define ddr_test_name_DDR4_MICRON		"DDR4_F9"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0A //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F10
#define ddr_test_name_DDR4_MICRON		"DDR4_F10"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0A //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F11
#define ddr_test_name_DDR4_MICRON		"DDR4_F11"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2fE //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F12
#define ddr_test_name_DDR4_MICRON		"DDR4_F12"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x20F //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c20 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F13
#define ddr_test_name_DDR4_MICRON		"DDR4_F13"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x20F //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c17 //Vref : %66.5 VDDQ
#endif


#ifdef DDR4_F14
#define ddr_test_name_DDR4_MICRON		"DDR4_F14"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x63F //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif


#ifdef DDR4_F15
#define ddr_test_name_DDR4_MICRON		"DDR4_F15"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0980 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F16
#define ddr_test_name_DDR4_MICRON		"DDR4_F16"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0A //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F17
#define ddr_test_name_DDR4_MICRON		"DDR4_F17"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0900 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0A //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F18
#define ddr_test_name_DDR4_MICRON		"DDR4_F18"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0430 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c19 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F19
#define ddr_test_name_DDR4_MICRON		"DDR4_F19"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x20f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0430 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c0A //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F20
#define ddr_test_name_DDR4_MICRON		"DDR4_F20"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif


#ifdef DDR4_F21
#define ddr_test_name_DDR4_MICRON		"DDR4_F20"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x1C //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F22
#define ddr_test_name_DDR4_MICRON		"DDR4_F22"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F23
#define ddr_test_name_DDR4_MICRON		"DDR4_F23"
#define ATxSlewRate_DDR4_MICRON 0x3FF //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xFF //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2fF //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0201 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F24
#define ddr_test_name_DDR4_MICRON		"DDR4_F24"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define VrefInGlobal_DDR4_MICRON   0x250
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif
#ifdef DDR4_F25
#define ddr_test_name_DDR4_MICRON		"DDR4_F25"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define VrefInGlobal_DDR4_MICRON   0x250
#define MR1_DDR4_MICRON 0x0601 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif


#ifdef DDR4_F26
#define ddr_test_name_DDR4_MICRON		"DDR4_F26"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define VrefInGlobal_DDR4_MICRON   0x288
#define MR1_DDR4_MICRON 0x0603 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif


#ifdef DDR4_F27
#define ddr_test_name_DDR4_MICRON		"DDR4_F27"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0501 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#endif

#ifdef DDR4_F28
#define ddr_test_name_DDR4_MICRON		"DDR4_F28"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0503 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_F29
#define ddr_test_name_DDR4_MICRON		"DDR4_F29"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3d //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_F30
#define ddr_test_name_DDR4_MICRON		"DDR4_F30"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3F //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x63f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_F31
#define ddr_test_name_DDR4_MICRON		"DDR4_F31"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_F31A
#define ddr_test_name_DDR4_MICRON		"DDR4_F31A"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_F31B
#define ddr_test_name_DDR4_MICRON		"DDR4_F31B"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x1880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_F31C
#define ddr_test_name_DDR4_MICRON		"DDR4_F31C"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x1880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_F31D
#define ddr_test_name_DDR4_MICRON		"DDR4_F31D"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_F31E
#define ddr_test_name_DDR4_MICRON		"DDR4_F31E"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x208
#endif

#ifdef DDR4_F31F
#define ddr_test_name_DDR4_MICRON		"DDR4_F31F"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x250
#endif

#ifdef DDR4_F31G
#define ddr_test_name_DDR4_MICRON		"DDR4_F31G"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x180
#endif


#ifdef DDR4_F31H
#define ddr_test_name_DDR4_MICRON		"DDR4_F31H"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c18 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x180
#endif

#ifdef DDR4_F31I
#define ddr_test_name_DDR4_MICRON		"DDR4_F31I"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x180
#endif

#ifdef DDR4_F31J
#define ddr_test_name_DDR4_MICRON		"DDR4_F31J"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0005 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x180
#endif

#ifdef DDR4_F31K
#define ddr_test_name_DDR4_MICRON		"DDR4_F31K"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0503 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x1880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_F31L
#define ddr_test_name_DDR4_MICRON		"DDR4_F31L"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x180
#endif

#ifdef DDR4_F31M
#define ddr_test_name_DDR4_MICRON		"DDR4_F31M"
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxImpedance_DDR4_MICRON 0x3C //PU/PD : 60/60
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/2
#define TxOdtDrvStren_DDR4_MICRON 0x18 //40 ohm
#define TxImpedance_DDR4_MICRON 0x60f //PU/PD : 60/60
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : 120 ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0880 //Rtt_park: 120 ohm
#define MR6_DDR4_MICRON 0x0c12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_H0
#define ddr_test_name_DDR4_MICRON		"DDR4_H0"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0880 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_H1
#define ddr_test_name_DDR4_MICRON		"DDR4_H1"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0880 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_H2
#define ddr_test_name_DDR4_MICRON		"DDR4_H2"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0880 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_H3
#define ddr_test_name_DDR4_MICRON		"DDR4_H3"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x20f //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0880 //Rtt_park
#define MR6_DDR4_MICRON 0x0C20 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_H4
#define ddr_test_name_DDR4_MICRON		"DDR4_H4"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61f //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x1880 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_H5
#define ddr_test_name_DDR4_MICRON		"DDR4_H0"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr
#define MR5_DDR4_MICRON 0x0880 //Rtt_park
#define MR6_DDR4_MICRON 0x0C04 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_H6
#define ddr_test_name_DDR4_MICRON		"DDR4_H6"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3f //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0480 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K0
#define ddr_test_name_DDR4_MICRON		"DDR4_K0"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0480 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K1
#define ddr_test_name_DDR4_MICRON		"DDR4_K1"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0500 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K2
#define ddr_test_name_DDR4_MICRON		"DDR4_K2"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0503 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0500 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K3
#define ddr_test_name_DDR4_MICRON		"DDR4_K3"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K4
#define ddr_test_name_DDR4_MICRON		"DDR4_K4"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K5
#define ddr_test_name_DDR4_MICRON		"DDR4_K5"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K6
#define ddr_test_name_DDR4_MICRON		"DDR4_K6"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K7
#define ddr_test_name_DDR4_MICRON		"DDR4_K7"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K8
#define ddr_test_name_DDR4_MICRON		"DDR4_K8"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0503 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K9
#define ddr_test_name_DDR4_MICRON		"DDR4_K9"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K10
#define ddr_test_name_DDR4_MICRON		"DDR4_K10"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K11
#define ddr_test_name_DDR4_MICRON		"DDR4_K11"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0503 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K12
#define ddr_test_name_DDR4_MICRON		"DDR4_K12"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0503 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0630 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K13
#define ddr_test_name_DDR4_MICRON		"DDR4_K13"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x250
#endif

#ifdef DDR4_K14
#define ddr_test_name_DDR4_MICRON		"DDR4_K13"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0701 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x250
#endif

#ifdef DDR4_K15
#define ddr_test_name_DDR4_MICRON		"DDR4_K15"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x08 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x208
#endif

#ifdef DDR4_K16
#define ddr_test_name_DDR4_MICRON		"DDR4_K16"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x08 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x1D8
#endif

#ifdef DDR4_K17
#define ddr_test_name_DDR4_MICRON		"DDR4_K17"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0230 //Rtt_wr
#define MR5_DDR4_MICRON 0x0400 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K4A
#define ddr_test_name_DDR4_MICRON		"DDR4_K4A"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K4A1
#define ddr_test_name_DDR4_MICRON		"DDR4_K4A1"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K4A2
#define ddr_test_name_DDR4_MICRON		"DDR4_K4A2"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K4A3
#define ddr_test_name_DDR4_MICRON		"DDR4_K4A3"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x1800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_K4A4
#define ddr_test_name_DDR4_MICRON		"DDR4_K4A4"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x1800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x250
#endif

#ifdef DDR4_K4A5
#define ddr_test_name_DDR4_MICRON		"DDR4_K4A1"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0x61F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C12 //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x250
#endif

#ifdef DDR4_L0
#define ddr_test_name_DDR4_MICRON		"DDR4_L0"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0xE3F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_L1
#define ddr_test_name_DDR4_MICRON		"DDR4_L1"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0xE3F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0900 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_L2
#define ddr_test_name_DDR4_MICRON		"DDR4_L2"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x18 //
#define TxImpedance_DDR4_MICRON 0xE3F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0900 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x250
#endif

#ifdef DDR4_K5A
#define ddr_test_name_DDR4_MICRON		"DDR4_K5A"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3F //PU/PD
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x2E0
#endif

#ifdef DDR4_K5B
#define ddr_test_name_DDR4_MICRON		"DDR4_K5B"
#define ATxSlewRate_DDR4_MICRON 0x3FB //N/P
#define ATxSlewRate_DDR4_MICRON_45 0xFB //N/P
#define ATxImpedance_DDR4_MICRON 0x7F //PU/PD
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P
#define TxOdtDrvStren_DDR4_MICRON 0x38 //
#define TxImpedance_DDR4_MICRON 0xE3F //PU/PD
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom / ODI
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr
#define MR5_DDR4_MICRON 0x0800 //Rtt_park
#define MR6_DDR4_MICRON 0x0C0A //Vref : %66.5 VDDQ
#define VrefInGlobal_DDR4_MICRON   0x288
#endif

#ifdef DDR4_X6
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_X6"
#endif

#ifdef DDR4_X6A
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f4 //N/P : f/4
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_X6A"
#endif

#ifdef DDR4_X6B
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f0 //N/P : f/0
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_X6B"
#endif

#ifdef DDR4_X6D
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"DDR4_X6D"
#endif


#ifdef DDR4_X7
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x2A8
#define ddr_test_name_DDR4_MICRON		"DDR4_X7"
#endif


#ifdef DDR4_X7A
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f4 //N/P : f/4
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x2A8
#define ddr_test_name_DDR4_MICRON		"DDR4_X7A"
#endif

#ifdef DDR4_X7B
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f0 //N/P : f/4
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x2A8
#define ddr_test_name_DDR4_MICRON		"DDR4_X7B"
#endif

#ifdef DDR4_X7C
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f6 //N/P : f/4
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x2A8
#define ddr_test_name_DDR4_MICRON		"DDR4_X7C"
#endif


#ifdef DDR4_X8
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X8"
#endif

#ifdef DDR4_X8A
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f4 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X8A"
#endif

#ifdef DDR4_X8B
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f0 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X8B"
#endif

#ifdef DDR4_X8C
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f6 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X8C"
#endif

#ifdef DDR4_X8D
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x3D //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X8D"
#endif



#ifdef DDR4_X9
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x210
#define ddr_test_name_DDR4_MICRON		"DDR4_X9"
#endif

#ifdef DDR4_X9A
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f4 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x210
#define ddr_test_name_DDR4_MICRON		"DDR4_X9A"
#endif

#ifdef DDR4_X9B
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f0 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x210
#define ddr_test_name_DDR4_MICRON		"DDR4_X9B"
#endif

#ifdef DDR4_X11
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X11"
#endif

#ifdef DDR4_X11A
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f4 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X11A"
#endif

#ifdef DDR4_X11B
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f0 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X11B"
#endif

#ifdef DDR4_X11C
#define MR1_DDR4_MICRON 0x0003 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x18 //60 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f6 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_X11C"
#endif

//---------------------------------------------------
// DDR 2666 with M_D4_26_A0
// 2T-Wpre, 2T-Rpre, CL-19, CWL-16
#ifdef D4M4G_M26_B0
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ddr_test_name_DDR4_MICRON		"D4M4G_M26_B0"
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_26_A0 1
#endif



//---------------------------------------------------
// DDR 2666 with M_D4_26_A1
// 2T-Wpre, 2T-Rpre, CL-18, CWL-16
#ifdef DDR4_E1
#define ddr_test_name_DDR4_MICRON		"DDR4_E1"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_26_A1 1
#endif

#ifdef D4M4G_M26_C0
#define ddr_test_name_DDR4_MICRON		"D4M4G_M26_C0"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_26_A1 1
#endif

//---------------------------------------------------
// DDR 2666 with M_D4_26_A2
// 1T-Wpre, 2T-Rpre, CL-18, CWL-14
#ifdef DDR4_EW1
#define ddr_test_name_DDR4_MICRON		"DDR4_EW1"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0820 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 0
#define M_D4_26_A2 1
#endif

//---------------------------------------------------
// DDR 2666 with M_D4_26_A3
// 2T-Wpre, 1T-Rpre, CL-18, CWL-16
#ifdef DDR4_ER1
#define ddr_test_name_DDR4_MICRON		"DDR4_ER1"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 0
#define WR_PRE_2T 1
#define M_D4_26_A3 1
#endif

//---------------------------------------------------
#ifdef DDR4_3200_A0
//#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
//#define MR2_DDR4_MICRON 0x0838 //Rtt_wr : 80 ohm
//#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
//#define MR6_DDR4_MICRON 0x100a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_3200_A0"
#endif

#ifdef DDR4_3200_A1
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x100A //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"DDR4_3200_A1"
#endif

#ifdef DDR4_3200_A2
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x100A //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define RFSHTMG_DDR4_MICRON 0x003000D0
#define DRAMTMG0_DDR4_MICRON 0x18180D1A
#define ddr_test_name_DDR4_MICRON		"DDR4_3200_A2"
#endif


#ifdef D4M4G_M32_B0
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x100A //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"D4M4G_M32_B0"
#define M_D4_32_A2
#endif

#ifdef D4M4G_M32_B0R
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x100A //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define ddr_test_name_DDR4_MICRON		"D4M4G_M32_B0R"
#define M_D4_32_A2R
#endif

//----------------------------------------------------------------------------------------------------
// Micron DDR4 8Gb
//---------------------------------------------------
// DDR 2666 with M_D4_8Gb_26_A0
// 2T-Wpre, 2T-Rpre, CL-20, CWL-16
#ifdef D4M8G_M26_A0
#define ddr_test_name_DDR4_MICRON		"D4M8G_M26_A0"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_8Gb_26_A0 1
#endif

//---------------------------------------------------
// DDR 2666 with M_D4_8Gb_26_A1
// 2T-Wpre, 2T-Rpre, CL-19, CWL-16
#ifdef D4M8G_M26_B0
#define ddr_test_name_DDR4_MICRON		"D4M8G_M26_B0"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_8Gb_26_A1
#endif

//---------------------------------------------------
// DDR 3200 with M_D4_8Gb_32_A0
// 2T-Wpre, 2T-Rpre, CL-22, CWL-18
#ifdef D4M8G_M32_A0
#define ddr_test_name_DDR4_MICRON		"D4M8G_M32_A0"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_8Gb_32_A0 1
#endif

#ifdef D4M8G_M32_B0
#define ddr_test_name_DDR4_MICRON		"D4M8G_M32_B0"
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 48 ohm
#define MR2_DDR4_MICRON 0x0828 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x0c0a //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define RD_PRE_2T 1
#define WR_PRE_2T 1
#define M_D4_8Gb_32_A1
#endif

//----------------------------------------------------------------------------------------------------

#ifdef ENABLE_DDR_CUSTOMER_SETTINGS
//Add DDR4 impedance related setting customization here
#define MR1_DDR4_MICRON 0x0001
#define MR2_DDR4_MICRON 0x0830
#define MR5_DDR4_MICRON 0x0500
#define MR6_DDR4_MICRON 0x100A
#define ATxImpedance_DDR4_MICRON 0x7f
#define TxOdtDrvStren_DDR4_MICRON 0x38
#define TxImpedance_DDR4_MICRON 0xe3f
#define TxSlewRate_DDR4_MICRON  0x2f1
#define ATxSlewRate_DDR4_MICRON 0x3fb
#define ATxSlewRate_DDR4_MICRON_45 0xfb
#define VrefInGlobal_DDR4_MICRON   0x260
#define RFSHTMG_DDR4_MICRON 0x003000D0
#define DRAMTMG0_DDR4_MICRON 0x18180D1A
#define ddr_test_name_DDR4_MICRON		"CUSTOMER1"
#else
#ifdef DEFAULT_DDR_SETTING
#define MR1_DDR4_MICRON 0x0001 //Rtt_nom : HZ ohm / ODI : 34 ohm
#define MR2_DDR4_MICRON 0x0830 //Rtt_wr : 80 ohm
#define MR5_DDR4_MICRON 0x0500 //Rtt_park: 240 ohm
#define MR6_DDR4_MICRON 0x100A //Vref : %66.5 VDDQ
#define ATxImpedance_DDR4_MICRON 0x7f //PU/PD : 40/40
#define TxOdtDrvStren_DDR4_MICRON 0x38 //40 ohm
#define TxImpedance_DDR4_MICRON 0xe3f //PU/PD : 40/40
#define TxSlewRate_DDR4_MICRON  0x2f1 //N/P : f/1
#define ATxSlewRate_DDR4_MICRON 0x3fb //N/P : f/b
#define ATxSlewRate_DDR4_MICRON_45 0xfb //N/P : f/b
#define VrefInGlobal_DDR4_MICRON   0x260
#define RFSHTMG_DDR4_MICRON 0x003000D0
#define DRAMTMG0_DDR4_MICRON 0x18180D1A
#define ddr_test_name_DDR4_MICRON		"DDR4_3200_A2(default)"
#endif
#endif

//New test case add above...
#ifndef MR1_DDR4_MICRON
#define MR1_DDR4_MICRON 	0x0001
#endif

#ifndef MR2_DDR4_MICRON
#define MR2_DDR4_MICRON 	0x0830
#endif

#ifndef MR5_DDR4_MICRON
#define MR5_DDR4_MICRON 	0x0500
#endif

#ifndef MR6_DDR4_MICRON
#define MR6_DDR4_MICRON 	0x100A
#endif

#ifndef TxOdtDrvStren_DDR4_MICRON
#define TxOdtDrvStren_DDR4_MICRON 0x38
#endif

#ifndef TxImpedance_DDR4_MICRON
#define TxImpedance_DDR4_MICRON 	0xe3f
#endif
#ifndef TxImpedance_DDR4_MICRON_B2
#define TxImpedance_DDR4_MICRON_B2 	TxImpedance_DDR4_MICRON
#endif

#ifndef ATxImpedance_DDR4_MICRON
#define ATxImpedance_DDR4_MICRON   0x7f
#endif
#ifndef TxSlewRate_DDR4_MICRON
#define TxSlewRate_DDR4_MICRON   0x2f1
#endif
#ifndef ATxSlewRate_DDR4_MICRON
#define ATxSlewRate_DDR4_MICRON   0x3fb
#endif
#ifndef ATxSlewRate_DDR4_MICRON_45
#define ATxSlewRate_DDR4_MICRON_45   0xfb
#endif

#ifndef VrefInGlobal_DDR4_MICRON
#define VrefInGlobal_DDR4_MICRON   0x260
#endif

#ifndef RD_PRE_2T
#define RD_PRE_2T 1
#endif

#ifndef WR_PRE_2T
#define WR_PRE_2T 1
#endif

#endif
