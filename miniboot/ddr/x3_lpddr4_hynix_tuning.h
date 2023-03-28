#ifndef __X2A_LPDDR4_HYNIX_TUNING_H__
#define __X2A_LPDDR4_HYNIX_TUNING_H__

/* hynix ddr fine tune*/
#ifdef HAB2
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x8
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xb2
#define sReserved00_LPDDR4_HYNIX 		0x40
#define sReserved0E_LPDDR4_HYNIX 		0x04
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x20
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x80
#define ddr_test_name_LPDDR4_HYNIX		"HAB2"
#endif

#ifdef HY5
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xe00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe3f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x10
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xb2
#define sReserved00_LPDDR4_HYNIX 		0x40
#define sReserved0E_LPDDR4_HYNIX 		0x04
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x20
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x80
#define ddr_test_name_LPDDR4_HYNIX		"HY5"
#endif

#ifdef HAA
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe3f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x10
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xb2
#define sReserved00_LPDDR4_HYNIX 		0x40
#define sReserved0E_LPDDR4_HYNIX 		0x04
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x20
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x80
#define ddr_test_name_LPDDR4_HYNIX		"HAA"
#endif

#ifdef HA
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HA"
#endif

#ifdef HB
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define CalDrvStr0_LPDDR4_HYNIX 			0x33
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HB"
#endif

#ifdef HC
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HC"
#endif

#ifdef HD
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HD"
#endif

#ifdef HE
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define CalDrvStr0_LPDDR4_HYNIX 			0x33
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HE"
#endif

#ifdef HF
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HF"
#endif

#ifdef HG
#define TxSlewRate_LPDDR4_HYNIX 			0x1bb
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HG"
#endif

#ifdef HH
#define TxSlewRate_LPDDR4_HYNIX 			0x1bb
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define CalDrvStr0_LPDDR4_HYNIX 			0x33
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HH"
#endif

#ifdef HI
#define TxSlewRate_LPDDR4_HYNIX 			0x1bb
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HI"
#endif

#ifdef HJ
#define TxSlewRate_LPDDR4_HYNIX 			0x1bb
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HJ"
#endif

#ifdef HK
#define TxSlewRate_LPDDR4_HYNIX 			0x1bb
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define CalDrvStr0_LPDDR4_HYNIX 			0x33
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x1e
#define ddr_test_name_LPDDR4_HYNIX		"HK"
#endif

#ifdef HL
#define TxSlewRate_LPDDR4_HYNIX 			0x1bb
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HL"
#endif

#ifdef HM
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HM"
#endif

#ifdef HN
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HN"
#endif

#ifdef HO
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x20f
#define MR14_LPDDR4_HYNIX 				0x19
#define ddr_test_name_LPDDR4_HYNIX		"HO"
#endif

#ifdef HP
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60f
#define MR14_LPDDR4_HYNIX 				0x19
#define ddr_test_name_LPDDR4_HYNIX		"HP"
#endif

#ifdef HQ
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR3_LPDDR4_HYNIX					0xb2
#define ddr_test_name_LPDDR4_HYNIX		"HQ"
#endif

#ifdef HR
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR3_LPDDR4_HYNIX					0xb2
#define ddr_test_name_LPDDR4_HYNIX		"HR"
#endif

#ifdef HS
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x20f
#define MR14_LPDDR4_HYNIX 				0x19
#define MR3_LPDDR4_HYNIX					0xb2
#define ddr_test_name_LPDDR4_HYNIX		"HS"
#endif

#ifdef HT
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60f
#define MR14_LPDDR4_HYNIX 				0x19
#define MR3_LPDDR4_HYNIX					0xb2
#define ddr_test_name_LPDDR4_HYNIX		"HT"
#endif

#ifdef HN1
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x33
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HN1"
#endif

#ifdef HN2
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x44
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HN2"
#endif

#ifdef HN3
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x33
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HN3"
#endif

#ifdef HN4
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x44
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HN4"
#endif

#ifdef HN5
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR14_LPDDR4_HYNIX 				0x2e
#define ddr_test_name_LPDDR4_HYNIX		"HN5"
#endif

#ifdef HN6
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR22_LPDDR4_HYNIX 				0x2
#define ddr_test_name_LPDDR4_HYNIX		"HN6"
#endif

#ifdef HV1
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x4c
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HV1"
#endif

#ifdef HV2
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x4f
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HV2"
#endif

#ifdef HV3
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x4c
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HV3"
#endif

#ifdef HV4
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x4f
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HV4"
#endif

#ifdef HV5
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xe00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x4a
#define MR22_LPDDR4_HYNIX 				0x6
#define ddr_test_name_LPDDR4_HYNIX		"HV5"
#endif

#ifdef HV6
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xe00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x65
#define MR14_LPDDR4_HYNIX 				0x4f
#define MR22_LPDDR4_HYNIX 				0x6
#define ddr_test_name_LPDDR4_HYNIX		"HV6"
#endif

#ifdef HP0
#define ATxImpedance_LPDDR4_HYNIX	    0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP0"
#endif

#ifdef HP1
#define ATxImpedance_LPDDR4_HYNIX	    0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x4e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP1"
#endif

#ifdef HP2
#define ATxImpedance_LPDDR4_HYNIX	    0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP2"
#endif

#ifdef HP3
#define ATxImpedance_LPDDR4_HYNIX	    0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x1ff
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x4e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP3"
#endif

#ifdef HP4
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP4"
#endif

#ifdef HP5
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x4e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP5"
#endif

#ifdef HP6
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x1bf
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP6"
#endif

#ifdef HP7
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x1bf
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define CalDrvStr0_LPDDR4_HYNIX 			0x11
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x4e
#define MR22_LPDDR4_HYNIX 				0x4
#define ddr_test_name_LPDDR4_HYNIX		"HP7"
#endif

#ifdef HNDV
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR12_LPDDR4_HYNIX				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HNDV"
#endif

#ifdef HNDV0
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR12_LPDDR4_HYNIX				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HNDV0"
#endif

#ifdef HNDV1
#define TxSlewRate_LPDDR4_HYNIX 			0x15f
#define ATxSlewRate_LPDDR4_HYNIX 		0x17f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR12_LPDDR4_HYNIX				0x25
#define ddr_test_name_LPDDR4_HYNIX		"HNDV1"
#endif

#ifdef HNSV0
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR11_LPDDR4_HYNIX 				0x33
#define ddr_test_name_LPDDR4_HYNIX		"HNSV0"
#endif

#ifdef HNSV1
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR11_LPDDR4_HYNIX 				0x33
#define ddr_test_name_LPDDR4_HYNIX		"HNSV1"
#endif

#ifdef HNSV2
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x15f
#define ATxSlewRate_LPDDR4_HYNIX 		0x17f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR11_LPDDR4_HYNIX 				0x33
#define ddr_test_name_LPDDR4_HYNIX		"HNSV2"
#endif

#ifdef HNSV3
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe3f
#define MR14_LPDDR4_HYNIX 				0x52
#define MR11_LPDDR4_HYNIX 				0x64
#define MR12_LPDDR4_HYNIX 				0x2e
#define MR3_LPDDR4_HYNIX					0xb3
#define ddr_test_name_LPDDR4_HYNIX		"HNSV3"
#endif

#ifdef HNSV4
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x23f
#define MR14_LPDDR4_HYNIX 				0x5b
#define MR11_LPDDR4_HYNIX 				0x64
#define MR12_LPDDR4_HYNIX 				0x2e
#define MR3_LPDDR4_HYNIX					0xb3
#define ddr_test_name_LPDDR4_HYNIX		"HNSV4"
#endif

#ifdef HNSV10
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define ddr_test_name_LPDDR4_HYNIX		"HNSV10"
#endif

#ifdef HNSV11
#define ATxImpedance_LPDDR4_HYNIX    	0x3d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define ddr_test_name_LPDDR4_HYNIX		"HNSV11"
#endif

#ifdef HNSV12
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define MR3_LPDDR4_HYNIX					0xa3
#define ddr_test_name_LPDDR4_HYNIX		"HNSV12"
#endif

#ifdef HNSV13
#define ATxImpedance_LPDDR4_HYNIX    	0x3d
#define TxSlewRate_LPDDR4_HYNIX 			0x19f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define MR3_LPDDR4_HYNIX					0xa3
#define ddr_test_name_LPDDR4_HYNIX		"HNSV13"
#endif

#ifdef HNSV20
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x15f
#define ATxSlewRate_LPDDR4_HYNIX 		0x17f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define ddr_test_name_LPDDR4_HYNIX		"HNSV20"
#endif

#ifdef HNSV21
#define ATxImpedance_LPDDR4_HYNIX    	0x3d
#define TxSlewRate_LPDDR4_HYNIX 			0x15f
#define ATxSlewRate_LPDDR4_HYNIX 		0x17f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define ddr_test_name_LPDDR4_HYNIX		"HNSV21"
#endif

#ifdef HNSV22
#define ATxImpedance_LPDDR4_HYNIX    	0x7d
#define TxSlewRate_LPDDR4_HYNIX 			0x15f
#define ATxSlewRate_LPDDR4_HYNIX 		0x17f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define MR3_LPDDR4_HYNIX					0xa3
#define ddr_test_name_LPDDR4_HYNIX		"HNSV22"
#endif

#ifdef HNSV23
#define ATxImpedance_LPDDR4_HYNIX    	0x3d
#define TxSlewRate_LPDDR4_HYNIX 			0x15f
#define ATxSlewRate_LPDDR4_HYNIX 		0x17f
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61f
#define MR14_LPDDR4_HYNIX 				0x25
#define MR11_LPDDR4_HYNIX 				0x44
#define MR3_LPDDR4_HYNIX					0xa3
#define ddr_test_name_LPDDR4_HYNIX		"HNSV23"
#endif

#ifdef HS0
#define ddr_test_name_LPDDR4_HYNIX		"HS0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS1
#define ddr_test_name_LPDDR4_HYNIX		"HS1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS2
#define ddr_test_name_LPDDR4_HYNIX		"HS2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x1D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x21F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS3
#define ddr_test_name_LPDDR4_HYNIX		"HS3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x1C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x20F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x13
#define MR12_LPDDR4_HYNIX 				0x13
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS4
#define ddr_test_name_LPDDR4_HYNIX		"HS4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x13
#define MR12_LPDDR4_HYNIX 				0x13
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS5
#define ddr_test_name_LPDDR4_HYNIX		"HS5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS6
#define ddr_test_name_LPDDR4_HYNIX		"HS6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS7
#define ddr_test_name_LPDDR4_HYNIX		"HS7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x56
#define MR12_LPDDR4_HYNIX 				0x4E
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS8
#define ddr_test_name_LPDDR4_HYNIX		"HS8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x20
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS9
#define ddr_test_name_LPDDR4_HYNIX		"HS9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x20
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS10
#define ddr_test_name_LPDDR4_HYNIX		"HS10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x20
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xAB
#endif

#ifdef HS11
#define ddr_test_name_LPDDR4_HYNIX		"HS11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x20
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xAB
#endif

#ifdef HS12
#define ddr_test_name_LPDDR4_HYNIX		"HS12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x20
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xAB
#endif

#ifdef HS13
#define ddr_test_name_LPDDR4_HYNIX		"HS13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xAB
#endif

#ifdef HS14
#define ddr_test_name_LPDDR4_HYNIX		"HS14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xAB
#endif

#ifdef HS15
#define ddr_test_name_LPDDR4_HYNIX		"HS15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0xAA
#endif

#ifdef HS16
#define ddr_test_name_LPDDR4_HYNIX		"HS16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS17
#define ddr_test_name_LPDDR4_HYNIX		"HS17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x5
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS18
#define ddr_test_name_LPDDR4_HYNIX		"HS18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS19
#define ddr_test_name_LPDDR4_HYNIX		"HS19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x9A
#endif

#ifdef HS20
#define ddr_test_name_LPDDR4_HYNIX		"HS20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE0F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x1B
#define MR12_LPDDR4_HYNIX 				0x1B
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS21
#define ddr_test_name_LPDDR4_HYNIX		"HS21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x1B
#define MR12_LPDDR4_HYNIX 				0x1B
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS22
#define ddr_test_name_LPDDR4_HYNIX		"HS22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x1B
#define MR12_LPDDR4_HYNIX 				0x1B
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HNSV
#define ddr_test_name_LPDDR4_HYNIX		"HNSV"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x2E
#define MR12_LPDDR4_HYNIX 				0x2E
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif





#ifdef HS23
#define ddr_test_name_LPDDR4_HYNIX		"HS23"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x3C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x1B
#define MR12_LPDDR4_HYNIX 				0x1B
#define MR22_LPDDR4_HYNIX 				0x2
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS1A
#define ddr_test_name_LPDDR4_HYNIX		"HS1A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS1B
#define ddr_test_name_LPDDR4_HYNIX		"HS1B"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9A
#endif

#ifdef HS1C
#define ddr_test_name_LPDDR4_HYNIX		"HS1C"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS1D
#define ddr_test_name_LPDDR4_HYNIX		"HS1D"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HS1E
#define ddr_test_name_LPDDR4_HYNIX		"HS1E"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef SNPS
#define ddr_test_name_LPDDR4_HYNIX           "SNPS"
#define ATxSlewRate_LPDDR4_HYNIX             0x19F
#define ATxImpedance_LPDDR4_HYNIX            0x3D
#define TxSlewRate_LPDDR4_HYNIX              0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX           0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX        0x61F
#define MR11_LPDDR4_HYNIX                    0x24
#define MR14_LPDDR4_HYNIX                    0x25
#define MR12_LPDDR4_HYNIX                    0x25
#define MR22_LPDDR4_HYNIX                    0x2
#define MR3_LPDDR4_HYNIX                     0xA3
#endif

#ifdef HS1F
#define ddr_test_name_LPDDR4_HYNIX		"HS1F"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS1G
#define ddr_test_name_LPDDR4_HYNIX		"HS1G"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1AF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1AF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HS26
#define ddr_test_name_LPDDR4_HYNIX		"HS26"
#define MR11_LPDDR4_HYNIX 				0x62
#endif

#ifdef HB0
#define ddr_test_name_LPDDR4_HYNIX		"HB0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HB1
#define ddr_test_name_LPDDR4_HYNIX		"HB1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HB2
#define ddr_test_name_LPDDR4_HYNIX		"HB2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x40
#endif

#ifdef HB3
#define ddr_test_name_LPDDR4_HYNIX		"HB3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB4
#define ddr_test_name_LPDDR4_HYNIX		"HB4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB5
#define ddr_test_name_LPDDR4_HYNIX		"HB5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HB6
#define ddr_test_name_LPDDR4_HYNIX		"HB6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB7
#define ddr_test_name_LPDDR4_HYNIX		"HB7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB8
#define ddr_test_name_LPDDR4_HYNIX		"HB8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB9
#define ddr_test_name_LPDDR4_HYNIX		"HB9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HB10
#define ddr_test_name_LPDDR4_HYNIX		"HB10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB11
#define ddr_test_name_LPDDR4_HYNIX		"HB11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB12
#define ddr_test_name_LPDDR4_HYNIX		"HB12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HB13
#define ddr_test_name_LPDDR4_HYNIX		"HB13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HB14
#define ddr_test_name_LPDDR4_HYNIX		"HB14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x40
#endif

#ifdef HB15
#define ddr_test_name_LPDDR4_HYNIX		"HB15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x10
#endif

#ifdef HB16
#define ddr_test_name_LPDDR4_HYNIX		"HB16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB2
#endif

#ifdef HB17
#define ddr_test_name_LPDDR4_HYNIX		"HB17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HB18
#define ddr_test_name_LPDDR4_HYNIX		"HB18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x48
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef HB19
#define ddr_test_name_LPDDR4_HYNIX		"HB19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HB20
#define ddr_test_name_LPDDR4_HYNIX		"HB20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HC0
#define ddr_test_name_LPDDR4_HYNIX		"HC0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x60F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x11
#define MR12_LPDDR4_HYNIX 				0x11
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif


#ifdef HC1
#define ddr_test_name_LPDDR4_HYNIX		"HC1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x19
#define MR12_LPDDR4_HYNIX 				0x19
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HC2
#define ddr_test_name_LPDDR4_HYNIX		"HC2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x1E
#define MR12_LPDDR4_HYNIX 				0x1E
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HC3
#define ddr_test_name_LPDDR4_HYNIX		"HC3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x1C
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x20F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x11
#define MR12_LPDDR4_HYNIX 				0x11
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HC4
#define ddr_test_name_LPDDR4_HYNIX		"HC4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x1E
#define MR12_LPDDR4_HYNIX 				0x1E
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif


#ifdef HD0
#define ddr_test_name_LPDDR4_HYNIX		"HD0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x20
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD1
#define ddr_test_name_LPDDR4_HYNIX		"HD1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD2
#define ddr_test_name_LPDDR4_HYNIX		"HD2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD3
#define ddr_test_name_LPDDR4_HYNIX		"HD3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x1A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD4
#define ddr_test_name_LPDDR4_HYNIX		"HD4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD5
#define ddr_test_name_LPDDR4_HYNIX		"HD5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD6
#define ddr_test_name_LPDDR4_HYNIX		"HD6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD7
#define ddr_test_name_LPDDR4_HYNIX		"HD7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD8
#define ddr_test_name_LPDDR4_HYNIX		"HD8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD9
#define ddr_test_name_LPDDR4_HYNIX		"HD9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x48
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD10
#define ddr_test_name_LPDDR4_HYNIX		"HD10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD11
#define ddr_test_name_LPDDR4_HYNIX		"HD11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD12
#define ddr_test_name_LPDDR4_HYNIX		"HD12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD13
#define ddr_test_name_LPDDR4_HYNIX		"HD13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD14
#define ddr_test_name_LPDDR4_HYNIX		"HD14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD15
#define ddr_test_name_LPDDR4_HYNIX		"HD15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9A
#endif

#ifdef HD16
#define ddr_test_name_LPDDR4_HYNIX		"HD16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX     	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif


#ifdef HD17
#define ddr_test_name_LPDDR4_HYNIX		"HD17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0x9A
#endif

#ifdef HD18
#define ddr_test_name_LPDDR4_HYNIX		"HD18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD19
#define ddr_test_name_LPDDR4_HYNIX		"HD19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif


#ifdef HD20
#define ddr_test_name_LPDDR4_HYNIX		"HD20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HD21
#define ddr_test_name_LPDDR4_HYNIX		"HD21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef HD22
#define ddr_test_name_LPDDR4_HYNIX		"HD22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HD22A
#define ddr_test_name_LPDDR4_HYNIX		"HD22A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HD22B
#define ddr_test_name_LPDDR4_HYNIX		"HD22B"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HD22E
#define ddr_test_name_LPDDR4_HYNIX		"HD22E"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HD23
#define ddr_test_name_LPDDR4_HYNIX		"HD23"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD24
#define ddr_test_name_LPDDR4_HYNIX		"HD24"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD25
#define ddr_test_name_LPDDR4_HYNIX		"HD25"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD26
#define ddr_test_name_LPDDR4_HYNIX		"HD26"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA2
#endif

#ifdef HD27
#define ddr_test_name_LPDDR4_HYNIX		"HD27"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x52
#define MR12_LPDDR4_HYNIX 				0x52
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA2
#endif

#ifdef HD28
#define ddr_test_name_LPDDR4_HYNIX		"HD28"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD29
#define ddr_test_name_LPDDR4_HYNIX		"HD29"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HD30
#define ddr_test_name_LPDDR4_HYNIX		"HD30"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HD31
#define ddr_test_name_LPDDR4_HYNIX		"HD31"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD32
#define ddr_test_name_LPDDR4_HYNIX		"HD32"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x3
#define MR3_LPDDR4_HYNIX					0x93
#endif

#ifdef HG0
#define ddr_test_name_LPDDR4_HYNIX		"HG0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HG1
#define ddr_test_name_LPDDR4_HYNIX		"HG0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HG2
#define ddr_test_name_LPDDR4_HYNIX		"HG2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HG3
#define ddr_test_name_LPDDR4_HYNIX		"HG3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif



#ifdef HK0
#define ddr_test_name_LPDDR4_HYNIX		"HK0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HK1
#define ddr_test_name_LPDDR4_HYNIX		"HK1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HK2
#define ddr_test_name_LPDDR4_HYNIX		"HK2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HK3
#define ddr_test_name_LPDDR4_HYNIX		"HK3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK4
#define ddr_test_name_LPDDR4_HYNIX		"HK4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK5
#define ddr_test_name_LPDDR4_HYNIX		"HK5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9B
#endif

#ifdef HK6
#define ddr_test_name_LPDDR4_HYNIX		"HK6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x2E
#define MR12_LPDDR4_HYNIX 				0x2E
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK7
#define ddr_test_name_LPDDR4_HYNIX		"HK7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK8
#define ddr_test_name_LPDDR4_HYNIX		"HK8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK9
#define ddr_test_name_LPDDR4_HYNIX		"HK9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK10
#define ddr_test_name_LPDDR4_HYNIX		"HK10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK11
#define ddr_test_name_LPDDR4_HYNIX		"HK11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK12
#define ddr_test_name_LPDDR4_HYNIX		"HK12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK13
#define ddr_test_name_LPDDR4_HYNIX		"HK13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK14
#define ddr_test_name_LPDDR4_HYNIX		"HK14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK15
#define ddr_test_name_LPDDR4_HYNIX		"HK15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK16
#define ddr_test_name_LPDDR4_HYNIX		"HK16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HK17
#define ddr_test_name_LPDDR4_HYNIX		"HK17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB2
#endif

#ifdef HK18
#define ddr_test_name_LPDDR4_HYNIX		"HK18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA2
#endif

#ifdef HK19
#define ddr_test_name_LPDDR4_HYNIX		"HK19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9A
#endif

#ifdef HK20
#define ddr_test_name_LPDDR4_HYNIX		"HK20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0x9A
#endif

#ifdef HK21
#define ddr_test_name_LPDDR4_HYNIX		"HK21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x40
#endif

#ifdef HK22
#define ddr_test_name_LPDDR4_HYNIX		"HK22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x10
#endif

#ifdef HK23
#define ddr_test_name_LPDDR4_HYNIX		"HK23"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x40
#endif

#ifdef HK24
#define ddr_test_name_LPDDR4_HYNIX		"HK24"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x20
#endif

#ifdef HD18A
#define ddr_test_name_LPDDR4_HYNIX		"HD18A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18AA
#define ddr_test_name_LPDDR4_HYNIX		"HD18AA"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18AB
#define ddr_test_name_LPDDR4_HYNIX		"HD18AB"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18B
#define ddr_test_name_LPDDR4_HYNIX		"HD18B"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18C
#define ddr_test_name_LPDDR4_HYNIX		"HD18C"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1CF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1CF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18D
#define ddr_test_name_LPDDR4_HYNIX		"HD18D"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18E
#define ddr_test_name_LPDDR4_HYNIX		"HD18E"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1F9
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1F9
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18F
#define ddr_test_name_LPDDR4_HYNIX		"HD18F"
#define ATxSlewRate_LPDDR4_HYNIX 		0x199
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x199
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18G
#define ddr_test_name_LPDDR4_HYNIX		"HD18G"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1DD
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1DD
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HD18H
#define ddr_test_name_LPDDR4_HYNIX		"HD18H"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1EE
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1EE
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif


#ifdef HD18K
#define ddr_test_name_LPDDR4_HYNIX		"HD18K"
#define ATxSlewRate_LPDDR4_HYNIX 		0x17F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HK3A
#define ddr_test_name_LPDDR4_HYNIX		"HK3A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef HM0
#define ddr_test_name_LPDDR4_HYNIX		"HM0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM1
#define ddr_test_name_LPDDR4_HYNIX		"HM1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM2
#define ddr_test_name_LPDDR4_HYNIX		"HM2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM3
#define ddr_test_name_LPDDR4_HYNIX		"HM3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HM4
#define ddr_test_name_LPDDR4_HYNIX		"HM4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HM5
#define ddr_test_name_LPDDR4_HYNIX		"HM5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM6
#define ddr_test_name_LPDDR4_HYNIX		"HM6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM7
#define ddr_test_name_LPDDR4_HYNIX		"HM7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM8
#define ddr_test_name_LPDDR4_HYNIX		"HM8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HM9
#define ddr_test_name_LPDDR4_HYNIX		"HM9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HM10
#define ddr_test_name_LPDDR4_HYNIX		"HM10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x70
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM11
#define ddr_test_name_LPDDR4_HYNIX		"HM11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x70
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE04
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM12
#define ddr_test_name_LPDDR4_HYNIX		"HM12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE00
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef HM13
#define ddr_test_name_LPDDR4_HYNIX		"HM13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x20
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM14
#define ddr_test_name_LPDDR4_HYNIX		"HM14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x70
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM15
#define ddr_test_name_LPDDR4_HYNIX		"HM15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef HM16
#define ddr_test_name_LPDDR4_HYNIX		"HM16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xA3
#endif


#ifdef HM17
#define ddr_test_name_LPDDR4_HYNIX		"HM17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM17A
#define ddr_test_name_LPDDR4_HYNIX		"HM17A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM18
#define ddr_test_name_LPDDR4_HYNIX		"HM18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM19
#define ddr_test_name_LPDDR4_HYNIX		"HM19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HM20
#define ddr_test_name_LPDDR4_HYNIX		"HM20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM21
#define ddr_test_name_LPDDR4_HYNIX		"HM21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef HM22
#define ddr_test_name_LPDDR4_HYNIX		"HM22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A1
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM23
#define ddr_test_name_LPDDR4_HYNIX		"HM23"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef HM24
#define ddr_test_name_LPDDR4_HYNIX		"HM24"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH1
#define ddr_test_name_LPDDR4_HYNIX		"JH1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH2
#define ddr_test_name_LPDDR4_HYNIX		"JH2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif


//-----------------------------------------
// JH 3200
#ifdef JH32_A1
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A1R
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#define JH_LP4_32_A0R //Controller Setting
#endif

// for JH32_A1RA multi-file
#define ATxSlewRate_LPDDR4_HYNIX_JH32_A1RA 			0x15F
#define ATxImpedance_LPDDR4_HYNIX_JH32_A1RA      	0x7F
#define TxSlewRate_LPDDR4_HYNIX_JH32_A1RA 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX_JH32_A1RA 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX_JH32_A1RA 	0xE3F
#define MR11_LPDDR4_HYNIX_JH32_A1RA 				0x43
#define MR14_LPDDR4_HYNIX_JH32_A1RA 				0x4C
#define MR12_LPDDR4_HYNIX_JH32_A1RA 				0x4C
#define MR22_LPDDR4_HYNIX_JH32_A1RA 				0x14
#define MR3_LPDDR4_HYNIX_JH32_A1RA					0xB3

#ifdef JH32_A2
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef JH32_DA3
#define ddr_test_name_LPDDR4_HYNIX		"JH32_DA3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x62
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif


#ifdef JH32_A4
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A6
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A7
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A8
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A9
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A10
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A11
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH32_A12
#define ddr_test_name_LPDDR4_HYNIX		"JH32_A12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif


//-----------------------------------------
// JH 2666
#ifdef JH26_A1
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH26_A2
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH26_A3
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH26_A3P
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A3P"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x62
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH26_A4
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH26_A5
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH26_A6
#define ddr_test_name_LPDDR4_HYNIX		"JH26_A6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

//-----------------------------------------
// JH 3733
#ifdef JH37_A1
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A2
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A3
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A4
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A5
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A6
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A7
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A9
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A8
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A10
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A11
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A12
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef JH37_A13
#define ddr_test_name_LPDDR4_HYNIX		"JH37_A13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

//-----------------------------------------
// XH 3200
#ifdef XH32_A1
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A2
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A3
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A4
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A5
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A6
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A7
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A8
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef XH32_A9
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef XH32_A10
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xA3
#endif

#ifdef XH32_A11
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A12
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A13
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A14
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A15
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A16
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A17
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A18
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A19
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A20
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A21
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A22
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A23
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A23"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A24
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A24"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A25
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A25"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A26
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A26"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A27
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A27"
#define ATxSlewRate_LPDDR4_HYNIX 		0x1FF
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A28
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A28"
#define ATxSlewRate_LPDDR4_HYNIX 		0x19F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH32_A29
#define ddr_test_name_LPDDR4_HYNIX		"XH32_A29"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

//-----------------------------------------
// XH-3200 Set B: RL 28, WL 26
#ifdef XH32_B1
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif

#ifdef XH32_B2
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x62
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif

#ifdef XH32_B8
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif

#ifdef XH32_B13
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif

#ifdef XH32_B14
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif

#ifdef XH32_B21
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif

#ifdef XH32_B21R
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B21R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1R //Controller Setting
#endif


#ifdef XH32_B22
#define ddr_test_name_LPDDR4_HYNIX		"XH32_B22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_32_A1 //Controller Setting
#endif


//-----------------------------------------
// XH-2666 Set A : RL 24, WL 12
#ifdef XH26_A1
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x4C
#define MR12_LPDDR4_HYNIX 				0x4C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A2
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A3
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A4
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A4"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A5
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A5"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A6
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A6"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A7
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A7"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A8
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A9
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A10
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A10"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A11
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A11"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A12
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A12"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif

#ifdef XH26_A13
#define ddr_test_name_LPDDR4_HYNIX		"XH26_A13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#endif



//---------------------------------------------------------
// XH-2666 Set B : RL 24, WL 22
#ifdef XH26_B0
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B0"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B1
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B1"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B1A
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B1A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif


#ifdef XH26_B2
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B2"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x62
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B3
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B3"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B8
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B8"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX				0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B9
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B9"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B13
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B13"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B13A
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B13A"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B13B
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B13B"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B14
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B14"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B15
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B15"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B16
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B16"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B17
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B17"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX				0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B18
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B18"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B19
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B19"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B20
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B20"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x16
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B21
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif

#ifdef XH26_B22
#define ddr_test_name_LPDDR4_HYNIX		"XH26_B22"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0xE00
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x6
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_26_A1 //Controller Setting
#endif



//-----------------------------------------
// XH 3733
#ifdef XH37_B21
#define ddr_test_name_LPDDR4_HYNIX		"XH37_B21"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_37_A1 //Controller Setting
#endif

#ifdef XH37_B23
#define ddr_test_name_LPDDR4_HYNIX		"XH37_B23"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_37_A1 //Controller Setting
#endif

#ifdef XH37_B24
#define ddr_test_name_LPDDR4_HYNIX		"XH37_B24"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_37_A1 //Controller Setting
#endif

#ifdef XH37_B25
#define ddr_test_name_LPDDR4_HYNIX		"XH37_B25"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_37_A1 //Controller Setting
#endif

#ifdef XH37_B26
#define ddr_test_name_LPDDR4_HYNIX		"XH37_B26"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_37_A1 //Controller Setting
#endif

#ifdef XH37_B27
#define ddr_test_name_LPDDR4_HYNIX		"XH37_B27"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x60
#define TxSlewRate_LPDDR4_HYNIX 		0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x28
#define MR12_LPDDR4_HYNIX 				0x28
#define MR22_LPDDR4_HYNIX 				0x4
#define MR3_LPDDR4_HYNIX					0xB3
#define XH_LP4_37_A1 //Controller Setting
#endif

#ifdef ENABLE_DDR_CUSTOMER_SETTINGS
//Add LPDDR4 impedance related setting customization here
#define MR3_LPDDR4_HYNIX				0xb3
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR12_LPDDR4_HYNIX 				MR14_LPDDR4_HYNIX
#define MR22_LPDDR4_HYNIX 				0x4
#define sReserved00_LPDDR4_HYNIX 		0x40
#define sReserved0E_LPDDR4_HYNIX 		0x04
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x20
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x80
#define ATxImpedance_LPDDR4_HYNIX 		0x7f
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define TxSlewRate_LPDDR4_HYNIX  		0x1ff
#define ATxSlewRate_LPDDR4_HYNIX 		TxSlewRate_LPDDR4_HYNIX
#define ddr_test_name_LPDDR4_HYNIX		"CUSTOMER1"
#else
#ifdef DEFAULT_DDR_SETTING
#define MR3_LPDDR4_HYNIX				0xb3
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x2e
#define MR12_LPDDR4_HYNIX 				MR14_LPDDR4_HYNIX
#define MR22_LPDDR4_HYNIX 				0x4
#define sReserved00_LPDDR4_HYNIX 		0x40
#define sReserved0E_LPDDR4_HYNIX 		0x04
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x20
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x80
#define ATxImpedance_LPDDR4_HYNIX 		0x7f
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#define TxSlewRate_LPDDR4_HYNIX  		0x1ff
#define ATxSlewRate_LPDDR4_HYNIX 		TxSlewRate_LPDDR4_HYNIX
#define ddr_test_name_LPDDR4_HYNIX		"Hynix_lpddr4_default_setting"
#endif
#endif

/* JH26_A3 */
#define ddr_test_name_LPDDR4_HYNIX_JH26_A3		"JH26_A3"
#define ATxSlewRate_LPDDR4_HYNIX_JH26_A3 		0x15F
#define ATxImpedance_LPDDR4_HYNIX_JH26_A3      		0x7F
#define TxSlewRate_LPDDR4_HYNIX_JH26_A3 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX_JH26_A3 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX_JH26_A3 		0xE3F
#define MR11_LPDDR4_HYNIX_JH26_A3 			0x43
#define MR14_LPDDR4_HYNIX_JH26_A3 			0x4C
#define MR12_LPDDR4_HYNIX_JH26_A3 			0x4C
#define MR22_LPDDR4_HYNIX_JH26_A3 			0x14
#define MR3_LPDDR4_HYNIX_JH26_A3			0xB3

/* #JH32_A1 */
#define ddr_test_name_LPDDR4_HYNIX_JH32_A1		"JH32_A1"
#define ATxSlewRate_LPDDR4_HYNIX_JH32_A1 		0x15F
#define ATxImpedance_LPDDR4_HYNIX_JH32_A1      	0x7F
#define TxSlewRate_LPDDR4_HYNIX_JH32_A1 			0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX_JH32_A1 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX_JH32_A1 	0xE3F
#define MR11_LPDDR4_HYNIX_JH32_A1 				0x43
#define MR14_LPDDR4_HYNIX_JH32_A1 				0x4C
#define MR12_LPDDR4_HYNIX_JH32_A1 				0x4C
#define MR22_LPDDR4_HYNIX_JH32_A1 				0x14
#define MR3_LPDDR4_HYNIX_JH32_A1				0xB3

/* XH26_B13 */
#define ddr_test_name_LPDDR4_HYNIX_XH26_B13		"XH26_B13"
#define ATxSlewRate_LPDDR4_HYNIX_XH26_B13 		0x15F
#define ATxImpedance_LPDDR4_HYNIX_XH26_B13      	0x60
#define TxSlewRate_LPDDR4_HYNIX_XH26_B13 			0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX_XH26_B13 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX_XH26_B13 	0xE3F
#define MR11_LPDDR4_HYNIX_XH26_B13 				0x64
#define MR14_LPDDR4_HYNIX_XH26_B13 				0x28
#define MR12_LPDDR4_HYNIX_XH26_B13 				0x28
#define MR22_LPDDR4_HYNIX_XH26_B13 				0x6
#define MR3_LPDDR4_HYNIX_XH26_B13					0xB3
#define XH_LP4_26_A1_XH26_B13 //Controller Setting

#define ddr_test_name_LPDDR4_SAMSUNG_XS26_A1R		"XS26_A1R"
#define ATxSlewRate_LPDDR4_SAMSUNG_XS26_A1R 		0x15F
#define ATxImpedance_LPDDR4_SAMSUNG_XS26_A1R      	0x7F
#define TxSlewRate_LPDDR4_SAMSUNG_XS26_A1R 		0x19F
#define TxOdtDrvStren_LPDDR4_SAMSUNG_XS26_A1R 		0x600
#define TxImpedanceCtrl1_LPDDR4_SAMSUNG_XS26_A1R 	0xE3F
#define MR11_LPDDR4_SAMSUNG_XS26_A1R 			0x43
#define MR14_LPDDR4_SAMSUNG_XS26_A1R 			0x5C
#define MR12_LPDDR4_SAMSUNG_XS26_A1R 			0x54
#define MR22_LPDDR4_SAMSUNG_XS26_A1R 			0x14
#define MR3_LPDDR4_SAMSUNG_XS26_A1R			0xB3

/* #XS32_A1R LPDDR4 micorn default parameter */
#define ddr_test_name_LPDDR4_SAMSUNG_XS32_A1R		"XS32_A1R"

#define ATxSlewRate_LPDDR4_SAMSUNG_XS32_A1R 		0x15F
#define ATxImpedance_LPDDR4_SAMSUNG_XS32_A1R   		0x7F
#define TxSlewRate_LPDDR4_SAMSUNG_XS32_A1R 			0x19F
#define TxOdtDrvStren_LPDDR4_SAMSUNG_XS32_A1R		0x600
#define TxImpedanceCtrl1_LPDDR4_SAMSUNG_XS32_A1R 	0xE3F
#define CalDrvStr0_LPDDR4_SAMSUNG_XS32_A1R	 		0x11

#define MR11_LPDDR4_SAMSUNG_XS32_A1R 				0x43
#define MR14_LPDDR4_SAMSUNG_XS32_A1R 				0x5C
#define MR12_LPDDR4_SAMSUNG_XS32_A1R 				0x54
#define MR22_LPDDR4_SAMSUNG_XS32_A1R 				0x14
#define MR3_LPDDR4_SAMSUNG_XS32_A1R					0xB3

/*SAMSUNG LPDDR-8Gb XS36_A17R*/
#define ddr_test_name_LPDDR4_SAMSUNG_XS36_A17R		"XS36_A1R"

#define ATxSlewRate_LPDDR4_SAMSUNG_XS36_A17R 		0x15F
#define ATxImpedance_LPDDR4_SAMSUNG_XS36_A17R   	0x7F
#define TxSlewRate_LPDDR4_SAMSUNG_XS36_A17R 		0x19F
#define TxOdtDrvStren_LPDDR4_SAMSUNG_XS36_A17R		0x600
#define TxImpedanceCtrl1_LPDDR4_SAMSUNG_XS36_A17R 	0xE3F
#define CalDrvStr0_LPDDR4_SAMSUNG_XS36_A17R	 	0x11

#define MR11_LPDDR4_SAMSUNG_XS36_A17R 			0x54
#define MR14_LPDDR4_SAMSUNG_XS36_A17R 			0x54
#define MR12_LPDDR4_SAMSUNG_XS36_A17R 			0x51
#define MR22_LPDDR4_SAMSUNG_XS36_A17R 			0x14
#define MR3_LPDDR4_SAMSUNG_XS36_A17R			0xB3

/*SAMSUNG LPDDR-16Gb XS36_A17R*/
#define ddr_test_name_LPDDR4_HYNIX_XS36_A17R		"L4S16G_XS36_A17R"
#define ATxSlewRate_LPDDR4_HYNIX_XS36_A17R 		0x15F
#define ATxImpedance_LPDDR4_HYNIX_XS36_A17R      	0x7F
#define TxSlewRate_LPDDR4_HYNIX_XS36_A17R 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX_XS36_A17R 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX_XS36_A17R 	0xE3F
#define MR11_LPDDR4_HYNIX_XS36_A17R 		0x54
#define MR14_LPDDR4_HYNIX_XS36_A17R 		0x54
#define MR12_LPDDR4_HYNIX_XS36_A17R 		0x51
#define MR22_LPDDR4_HYNIX_XS36_A17R 		0x14
#define MR3_LPDDR4_HYNIX_XS36_A17R		0xB3

/*SAMSUNG LPDDR-16Gb XS32_A1R*/
#define ddr_test_name_LPDDR4_HYNIX_L4S16G_XS32_A1RA		"L4S16G_XS32_A1RA"
#define ATxSlewRate_LPDDR4_HYNIX_L4S16G_XS32_A1RA 		0x15F
#define ATxImpedance_LPDDR4_HYNIX_L4S16G_XS32_A1RA      	        0x7F
#define TxSlewRate_LPDDR4_HYNIX_L4S16G_XS32_A1RA 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX_L4S16G_XS32_A1RA 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX_L4S16G_XS32_A1RA 	        0xE3F
#define MR11_LPDDR4_HYNIX_L4S16G_XS32_A1RA 			0x43
#define MR14_LPDDR4_HYNIX_L4S16G_XS32_A1RA 			0x5c
#define MR12_LPDDR4_HYNIX_L4S16G_XS32_A1RA 			0x54
#define MR22_LPDDR4_HYNIX_L4S16G_XS32_A1RA 			0x14
#define MR3_LPDDR4_HYNIX_L4S16G_XS32_A1RA			0xB3
//----------------------------------------------------------------------------------------------
// Samsung LPDDR4-8Gb

//----------------------------------
// Samsung 3200
// Set A. enable derate
#ifdef XS32_A0R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A0R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A1R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A2R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A2R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A3R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A3R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A4R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A4R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x48
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A5R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A5R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x63
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A6R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A6R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A7R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A7R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A8R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A8R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A9R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A9R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4D
#define MR12_LPDDR4_HYNIX 				0x4D
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A10R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A10R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x4A
#define MR12_LPDDR4_HYNIX 				0x4A
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A11R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A11R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x48
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A12R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A12R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x53
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A13R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A13R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A14R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A14R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x5C
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A15R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A15R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x66
#define MR14_LPDDR4_HYNIX 				0x48
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A16R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A16R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x200
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A17R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A17R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x61F
#define MR11_LPDDR4_HYNIX 				0x33
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A18R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A18R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x13F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x15F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A19R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A19R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x13F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A20R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A20R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x13F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A21R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A21R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x13F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x1FF
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A22R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A22R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x48
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_A23R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_A23R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x3D
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_B1R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_B1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x7F
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x1F
#endif

#ifdef XS32_B2R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_B2R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x80
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x10
#endif

#ifdef XS32_B3R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_B3R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x17F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x80
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x10
#endif



#ifdef XS32_C1R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_C1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x63F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_C2R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_C2R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE1F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

#ifdef XS32_C3R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_C3R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0x23F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A0R //Controller Setting
#endif

//---------- Set B
#ifdef XS32_D0R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_D0R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x44
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A1R //Controller Setting
#endif


#ifdef XS32_D1R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_D1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A1R //Controller Setting
#endif

#ifdef XS32_D3R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_D3R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x64
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x48
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A1R //Controller Setting
#endif

#ifdef XS32_D7R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_D7R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A1R //Controller Setting
#endif

#ifdef XS32_D8R
#define ddr_test_name_LPDDR4_HYNIX		"XS32_D8R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x55
#define MR14_LPDDR4_HYNIX 				0x51
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_32_A1R //Controller Setting
#endif

//----------------------------------------------------------------------------------
// Samsung LPDDR4-8Gb 2666
// Set A. enable derate
#ifdef XS26_A1R
#define ddr_test_name_LPDDR4_HYNIX		"XS26_A1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_26_A0R //Controller Setting
#endif


#ifdef XS36_A17R
#define ddr_test_name_LPDDR4_HYNIX		"XS36_A17R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_36_A0R //Controller Setting
#endif


//----------------------------------------------------------------------------------------------
// Samsung LPDDR4-16Gb

//----------------------------------
// Samsung LPDDR4-16Gb 3200
// Set A. enable derate
#ifdef L4S16G_XS32_A1R
#define ddr_test_name_LPDDR4_HYNIX		"L4S16G_XS32_A1R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x43
#define MR14_LPDDR4_HYNIX 				0x5C
#define MR12_LPDDR4_HYNIX 				0x54
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_16Gb_32_A0R //Controller Setting
#endif

#ifdef L4S16G_XS36_A17R
#define ddr_test_name_LPDDR4_HYNIX		"L4S16G_XS36_A17R"
#define ATxSlewRate_LPDDR4_HYNIX 		0x15F
#define ATxImpedance_LPDDR4_HYNIX      	0x7F
#define TxSlewRate_LPDDR4_HYNIX 		0x19F
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xE3F
#define MR11_LPDDR4_HYNIX 				0x54
#define MR14_LPDDR4_HYNIX 				0x54
#define MR12_LPDDR4_HYNIX 				0x51
#define MR22_LPDDR4_HYNIX 				0x14
#define MR3_LPDDR4_HYNIX				0xB3
#define XS_LP4_16Gb_36_A0R //Controller Setting
#endif


// for samsung 4g lpddr4 3200 multi-file
#define ATxSlewRate_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 			0x15F
#define ATxImpedance_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA      	0x7F
#define TxSlewRate_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 			0x19F
#define TxOdtDrvStren_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 		0x600
#define TxImpedanceCtrl1_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 	0xE3F
#define MR11_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 				0x54
#define MR14_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 				0x54
#define MR12_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 				0x51
#define MR22_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA 				0x14
#define MR3_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA					0xB3

#ifndef CalDrvStr0_LPDDR4_SAMSUNG
#define CalDrvStr0_LPDDR4_SAMSUNG 		0x11
#endif

#ifndef ddr_test_name_LPDDR4_HYNIX
#define ddr_test_name_LPDDR4_HYNIX 		"Hynix_lpddr4_default_setting"
#endif

#ifndef TxSlewRate_LPDDR4_HYNIX
#define TxSlewRate_LPDDR4_HYNIX 		0x1ff
#endif

#ifndef ATxSlewRate_LPDDR4_HYNIX
#define ATxSlewRate_LPDDR4_HYNIX 		TxSlewRate_LPDDR4_HYNIX
#endif

#ifndef TxOdtDrvStren_LPDDR4_HYNIX
#define TxOdtDrvStren_LPDDR4_HYNIX 		0x600
#endif

#ifndef CalDrvStr0_LPDDR4_HYNIX
#define CalDrvStr0_LPDDR4_HYNIX 		0x11
#endif

#ifndef ATxImpedance_LPDDR4_HYNIX
#define ATxImpedance_LPDDR4_HYNIX    	0x7f
#endif

#ifndef TxImpedanceCtrl1_LPDDR4_HYNIX
#define TxImpedanceCtrl1_LPDDR4_HYNIX 	0xe1f
#endif

#ifndef MR3_LPDDR4_HYNIX
#define MR3_LPDDR4_HYNIX				0xb3
#endif

#ifndef MR11_LPDDR4_HYNIX
#define MR11_LPDDR4_HYNIX 				0x62
#endif

#ifndef MR14_LPDDR4_HYNIX
#define MR14_LPDDR4_HYNIX 				0x2e
#endif

#ifndef MR12_LPDDR4_HYNIX
#define MR12_LPDDR4_HYNIX 			MR14_LPDDR4_HYNIX
#endif

#ifndef MR22_LPDDR4_HYNIX
#define MR22_LPDDR4_HYNIX 				0x4
#endif

#ifndef sReserved00_LPDDR4_HYNIX
#define sReserved00_LPDDR4_HYNIX 		0x40
#endif

#ifndef sReserved0E_LPDDR4_HYNIX
#define sReserved0E_LPDDR4_HYNIX 		0x04
#endif

#ifndef sDelay_Weight2D_LPDDR4_HYNIX
#define sDelay_Weight2D_LPDDR4_HYNIX 	0x20
#endif

#ifndef sVoltage_Weight2D_LPDDR4_HYNIX
#define sVoltage_Weight2D_LPDDR4_HYNIX 	0x80
#endif

#define DRAMTMG2_LPDDR4_HYNIX 0x9121219
#define RFSHTMG_LPDDR4_HYNIX 0x82090095
#define RFSHTMG1_LPDDR4_HYNIX 0x610000

#define DRAMTMG2_LPDDR4_HYNIX_3200 0x70e1214
#define RFSHTMG_LPDDR4_HYNIX_3200 0x81c70083

#endif
