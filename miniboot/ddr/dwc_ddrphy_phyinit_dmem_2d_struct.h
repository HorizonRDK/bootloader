#ifndef __DWC_DDRPHY_PHYINIT_DMEM_STRUCT_2D_H__
#define __DWC_DDRPHY_PHYINIT_DMEM_STRUCT_2D_H__

struct DMEM_LPDDR4_2D_STRUCT {
		volatile uint8	Reserved00;
		volatile uint8	MsgMisc;
		volatile uint16	reserved_16_0; //
		volatile uint16	PmuRevision;
		volatile uint16	reserved_16_1; //
		volatile uint8	Pstate;
		volatile uint8	PllBypassEn;
		volatile uint16	reserved_16_2; //
		volatile uint16	DRAMFreq;
		volatile uint16	reserved_16_3; //
		volatile uint8	DfiFreqRatio;
		volatile uint8	BPZNResVal;
		volatile uint16	reserved_16_4; //
		volatile uint8	PhyOdtImpedance;
		volatile uint8	PhyDrvImpedance;
		volatile uint16	reserved_16_5; //
		volatile uint8	PhyVref;
		volatile uint8	Lp4Misc;
		volatile uint16	reserved_16_6; //
		volatile uint8	Reserved0E;
		volatile uint8	CsTestFail;
		volatile uint16	reserved_16_7; //
		volatile uint16	SequenceCtrl;
		volatile uint16	reserved_16_8; //
		volatile uint8	HdtCtrl;
		volatile uint8	Reserved13;
		volatile uint16	reserved_16_9; //
		volatile uint8	Reserved14;
		volatile uint8	Reserved15;
		volatile uint16	reserved_16_10; //
		volatile uint8	DFIMRLMargin;
		volatile uint8	Reserved17;
		volatile uint16	reserved_16_11; //
		volatile uint8	UseBroadcastMR;
		volatile uint8	Reserved19;
		volatile uint16	reserved_16_12; //
		volatile uint8	Reserved1A;
		volatile uint8	CATrainOpt;
		volatile uint16	reserved_16_13; //
		volatile uint8	X8Mode;
		volatile uint8	RX2D_TrainOpt;
		volatile uint16	reserved_16_14; //
		volatile uint8	TX2D_TrainOpt;
		volatile uint8	Share2DVrefResult;
		volatile uint16	reserved_16_15; //
		volatile uint8	Delay_Weight2D;
		volatile uint8	Voltage_Weight2D;
		volatile uint16	reserved_16_16; //
		volatile uint16	PhyConfigOverride;
		volatile uint16	reserved_16_17; //
		volatile uint8	EnabledDQsChA;
		volatile uint8	CsPresentChA;
		volatile uint16	reserved_16_18; //
		volatile int8	CDD_ChA_RR_1_0;
		volatile int8	CDD_ChA_RR_0_1;
		volatile uint16	reserved_16_19; //
		volatile int8	CDD_ChA_RW_1_1;
		volatile int8	CDD_ChA_RW_1_0;
		volatile uint16	reserved_16_20; //
		volatile int8	CDD_ChA_RW_0_1;
		volatile int8	CDD_ChA_RW_0_0;
		volatile uint16	reserved_16_21; //
		volatile int8	CDD_ChA_WR_1_1;
		volatile int8	CDD_ChA_WR_1_0;
		volatile uint16	reserved_16_22; //
		volatile int8	CDD_ChA_WR_0_1;
		volatile int8	CDD_ChA_WR_0_0;
		volatile uint16	reserved_16_23; //
		volatile int8	CDD_ChA_WW_1_0;
		volatile int8	CDD_ChA_WW_0_1;
		volatile uint16	reserved_16_24; //
		volatile uint8	MR1_A0;
		volatile uint8	MR2_A0;
		volatile uint16	reserved_16_25; //
		volatile uint8	MR3_A0;
		volatile uint8	MR4_A0;
		volatile uint16	reserved_16_26; //
		volatile uint8	MR11_A0;
		volatile uint8	MR12_A0;
		volatile uint16	reserved_16_27; //
		volatile uint8	MR13_A0;
		volatile uint8	MR14_A0;
		volatile uint16	reserved_16_28; //
		volatile uint8	MR16_A0;
		volatile uint8	MR17_A0;
		volatile uint16	reserved_16_29; //
		volatile uint8	MR22_A0;
		volatile uint8	MR24_A0;
		volatile uint16	reserved_16_30; //
		volatile uint8	MR1_A1;
		volatile uint8	MR2_A1;
		volatile uint16	reserved_16_31; //
		volatile uint8	MR3_A1;
		volatile uint8	MR4_A1;
		volatile uint16	reserved_16_32; //
		volatile uint8	MR11_A1;
		volatile uint8	MR12_A1;
		volatile uint16	reserved_16_33; //
		volatile uint8	MR13_A1;
		volatile uint8	MR14_A1;
		volatile uint16	reserved_16_34; //
		volatile uint8	MR16_A1;
		volatile uint8	MR17_A1;
		volatile uint16	reserved_16_35; //
		volatile uint8	MR22_A1;
		volatile uint8	MR24_A1;
		volatile uint16	reserved_16_36; //
		volatile uint8	CATerminatingRankChA;
		volatile uint8	Reserved4B;
		volatile uint16	reserved_16_37; //
		volatile uint8	Reserved4C;
		volatile uint8	TrainedVREFDQ_A0;
		volatile uint16	reserved_16_38; //
		volatile uint8	TrainedVREFDQ_A1;
		volatile uint8	RxClkDly_Margin_A0;
		volatile uint16	reserved_16_39; //
		volatile uint8	VrefDac_Margin_A0;
		volatile uint8	TxDqDly_Margin_A0;
		volatile uint16	reserved_16_40; //
		volatile uint8	DeviceVref_Margin_A0;
		volatile uint8	RxClkDly_Margin_A1;
		volatile uint16	reserved_16_41; //
		volatile uint8	VrefDac_Margin_A1;
		volatile uint8	TxDqDly_Margin_A1;
		volatile uint16	reserved_16_42; //
		volatile uint8	DeviceVref_Margin_A1;
		volatile uint8	EnabledDQsChB;
		volatile uint16	reserved_16_43; //
		volatile uint8	CsPresentChB;
		volatile int8	CDD_ChB_RR_1_0;
		volatile uint16	reserved_16_44; //
		volatile int8	CDD_ChB_RR_0_1;
		volatile int8	CDD_ChB_RW_1_1;
		volatile uint16	reserved_16_45; //
		volatile int8	CDD_ChB_RW_1_0;
		volatile int8	CDD_ChB_RW_0_1;
		volatile uint16	reserved_16_46; //
		volatile int8	CDD_ChB_RW_0_0;
		volatile int8	CDD_ChB_WR_1_1;
		volatile uint16	reserved_16_47; //
		volatile int8	CDD_ChB_WR_1_0;
		volatile int8	CDD_ChB_WR_0_1;
		volatile uint16	reserved_16_48; //
		volatile int8	CDD_ChB_WR_0_0;
		volatile int8	CDD_ChB_WW_1_0;
		volatile uint16	reserved_16_49; //
		volatile int8	CDD_ChB_WW_0_1;
		volatile uint8	MR1_B0;
		volatile uint16	reserved_16_50; //
		volatile uint8	MR2_B0;
		volatile uint8	MR3_B0;
		volatile uint16	reserved_16_51; //
		volatile uint8	MR4_B0;
		volatile uint8	MR11_B0;
		volatile uint16	reserved_16_52; //
		volatile uint8	MR12_B0;
		volatile uint8	MR13_B0;
		volatile uint16	reserved_16_53; //
		volatile uint8	MR14_B0;
		volatile uint8	MR16_B0;
		volatile uint16	reserved_16_54; //
		volatile uint8	MR17_B0;
		volatile uint8	MR22_B0;
		volatile uint16	reserved_16_55; //
		volatile uint8	MR24_B0;
		volatile uint8	MR1_B1;
		volatile uint16	reserved_16_56; //
		volatile uint8	MR2_B1;
		volatile uint8	MR3_B1;
		volatile uint16	reserved_16_57; //
		volatile uint8	MR4_B1;
		volatile uint8	MR11_B1;
		volatile uint16	reserved_16_58; //
		volatile uint8	MR12_B1;
		volatile uint8	MR13_B1;
		volatile uint16	reserved_16_59; //
		volatile uint8	MR14_B1;
		volatile uint8	MR16_B1;
		volatile uint16	reserved_16_60; //
		volatile uint8	MR17_B1;
		volatile uint8	MR22_B1;
		volatile uint16	reserved_16_61; //
		volatile uint8	MR24_B1;
		volatile uint8	CATerminatingRankChB;
		volatile uint16	reserved_16_62; //
		volatile uint8	Reserved7E;
		volatile uint8	Reserved7F;
		volatile uint16	reserved_16_63; //
		volatile uint8	TrainedVREFDQ_B0;
		volatile uint8	TrainedVREFDQ_B1;
		volatile uint16	reserved_16_64; //
		volatile uint8	RxClkDly_Margin_B0;
		volatile uint8	VrefDac_Margin_B0;
		volatile uint16	reserved_16_65; //
		volatile uint8	TxDqDly_Margin_B0;
		volatile uint8	DeviceVref_Margin_B0;
		volatile uint16	reserved_16_66; //
		volatile uint8	RxClkDly_Margin_B1;
		volatile uint8	VrefDac_Margin_B1;
		volatile uint16	reserved_16_67; //
		volatile uint8	TxDqDly_Margin_B1;
		volatile uint8	DeviceVref_Margin_B1;
		volatile uint16	reserved_16_68; //
};

struct DMEM_DDR4_2D_STRUCT {
		volatile uint8	Reserved00;
		volatile uint8	MsgMisc;
		volatile uint16	reserved_16_0; //
		volatile uint16	PmuRevision;
		volatile uint16	reserved_16_1; //
		volatile uint8	Pstate;
		volatile uint8	PllBypassEn;
		volatile uint16	reserved_16_2; //
		volatile uint16	DRAMFreq;
		volatile uint16	reserved_16_3; //
		volatile uint8	DfiFreqRatio;
		volatile uint8	BPZNResVal;
		volatile uint16	reserved_16_4; //
		volatile uint8	PhyOdtImpedance;
		volatile uint8	PhyDrvImpedance;
		volatile uint16	reserved_16_5; //
		volatile uint8	PhyVref;
		volatile uint8	DramType;
		volatile uint16	reserved_16_6; //
		volatile uint8	DisabledDbyte;
		volatile uint8	EnabledDQs;
		volatile uint16	reserved_16_7; //
		volatile uint8	CsPresent;
		volatile uint8	CsPresentD0;
		volatile uint16	reserved_16_8; //
		volatile uint8	CsPresentD1;
		volatile uint8	AddrMirror;
		volatile uint16	reserved_16_9; //
		volatile uint8	CsTestFail;
		volatile uint8	PhyCfg;
		volatile uint16	reserved_16_10; //
		volatile uint16	SequenceCtrl;
		volatile uint16	reserved_16_11; //
		volatile uint8	HdtCtrl;
		volatile uint8	RX2D_TrainOpt;
		volatile uint16	reserved_16_12; //
		volatile uint8	TX2D_TrainOpt;
		volatile uint8	Share2DVrefResult;
		volatile uint16	reserved_16_13; //
		volatile uint8	Delay_Weight2D;
		volatile uint8	Voltage_Weight2D;
		volatile uint16	reserved_16_14; //
		volatile uint8	Reserved1E;
		volatile uint8	Reserved1F;
		volatile uint16	reserved_16_15; //
		volatile uint8	Reserved20;
		volatile uint8	Reserved21;
		volatile uint16	reserved_16_16; //
		volatile uint16	PhyConfigOverride;
		volatile uint16	reserved_16_17; //
		volatile uint8	DFIMRLMargin;
		volatile uint8	R0_RxClkDly_Margin;
		volatile uint16	reserved_16_18; //
		volatile uint8	R0_VrefDac_Margin;
		volatile uint8	R0_TxDqDly_Margin;
		volatile uint16	reserved_16_19; //
		volatile uint8	R0_DeviceVref_Margin;
		volatile uint8	Reserved29;
		volatile uint16	reserved_16_20; //
		volatile uint16	Reserved2A;
		volatile uint16	reserved_16_21; //
		volatile uint8	Reserved2C;
		volatile uint8	Reserved2D;
		volatile uint16	reserved_16_22; //
		volatile uint8	Reserved2E;
		volatile uint8	Reserved2F;
		volatile uint16	reserved_16_23; //
		volatile uint8	Reserved30;
		volatile uint8	Reserved31;
		volatile uint16	reserved_16_24; //
		volatile uint8	Reserved32;
		volatile uint8	R1_RxClkDly_Margin;
		volatile uint16	reserved_16_25; //
		volatile uint8	R1_VrefDac_Margin;
		volatile uint8	R1_TxDqDly_Margin;
		volatile uint16	reserved_16_26; //
		volatile uint8	R1_DeviceVref_Margin;
		volatile uint8	Reserved37;
		volatile uint16	reserved_16_27; //
		volatile uint16	Reserved38;
		volatile uint16	reserved_16_28; //
		volatile uint8	Reserved3A;
		volatile uint8	Reserved3B;
		volatile uint16	reserved_16_29; //
		volatile uint8	Reserved3C;
		volatile uint8	Reserved3D;
		volatile uint16	reserved_16_30; //
		volatile uint8	Reserved3E;
		volatile uint8	Reserved3F;
		volatile uint16	reserved_16_31; //
		volatile uint8	Reserved40;
		volatile uint8	R2_RxClkDly_Margin;
		volatile uint16	reserved_16_32; //
		volatile uint8	R2_VrefDac_Margin;
		volatile uint8	R2_TxDqDly_Margin;
		volatile uint16	reserved_16_33; //
		volatile uint8	R2_DeviceVref_Margin;
		volatile uint8	Reserved45;
		volatile uint16	reserved_16_34; //
		volatile uint8	Reserved46;
		volatile uint8	Reserved47;
		volatile uint16	reserved_16_35; //
		volatile uint8	Reserved48;
		volatile uint8	Reserved49;
		volatile uint16	reserved_16_36; //
		volatile uint8	Reserved4A;
		volatile uint8	Reserved4B;
		volatile uint16	reserved_16_37; //
		volatile uint8	Reserved4C;
		volatile uint8	Reserved4D;
		volatile uint16	reserved_16_38; //
		volatile uint8	Reserved4E;
		volatile uint8	R3_RxClkDly_Margin;
		volatile uint16	reserved_16_39; //
		volatile uint8	R3_VrefDac_Margin;
		volatile uint8	R3_TxDqDly_Margin;
		volatile uint16	reserved_16_40; //
		volatile uint8	R3_DeviceVref_Margin;
		volatile uint8	Reserved53;
		volatile uint16	reserved_16_41; //
		volatile uint8	Reserved54;
		volatile uint8	Reserved55;
		volatile uint16	reserved_16_42; //
		volatile uint8	Reserved56;
		volatile uint8	Reserved57;
		volatile uint16	reserved_16_43; //
		volatile uint16	Reserved58;
		volatile uint16	reserved_16_44; //
		volatile uint8	Reserved5A;
		volatile uint8	Reserved5B;
		volatile uint16	reserved_16_45; //
		volatile uint8	Reserved5C;
		volatile uint8	Reserved5D;
		volatile uint16	reserved_16_46; //
		volatile uint16	MR_0;
		volatile uint16	reserved_16_47; //
		volatile uint16	MR_1;
		volatile uint16	reserved_16_48; //
		volatile uint16	MR_2;
		volatile uint16	reserved_16_49; //
		volatile uint16	MR_3;
		volatile uint16	reserved_16_50; //
		volatile uint16	MR_4;
		volatile uint16	reserved_16_51; //
		volatile uint16	MR_5;
		volatile uint16	reserved_16_52; //
		volatile uint16	MR_6;
		volatile uint16	reserved_16_53; //
		volatile uint8	X16Present;
		volatile uint8	CsSetupGDDec;
		volatile uint16	reserved_16_54; //
		volatile uint16	RTT_NOM_WR_PARK0;
		volatile uint16	reserved_16_55; //
		volatile uint16	RTT_NOM_WR_PARK1;
		volatile uint16	reserved_16_56; //
		volatile uint16	RTT_NOM_WR_PARK2;
		volatile uint16	reserved_16_57; //
		volatile uint16	RTT_NOM_WR_PARK3;
		volatile uint16	reserved_16_58; //
		volatile uint16	RTT_NOM_WR_PARK4;
		volatile uint16	reserved_16_59; //
		volatile uint16	RTT_NOM_WR_PARK5;
		volatile uint16	reserved_16_60; //
		volatile uint16	RTT_NOM_WR_PARK6;
		volatile uint16	reserved_16_61; //
		volatile uint16	RTT_NOM_WR_PARK7;
		volatile uint16	reserved_16_62; //
		volatile uint8	AcsmOdtCtrl0;
		volatile uint8	AcsmOdtCtrl1;
		volatile uint16	reserved_16_63; //
		volatile uint8	AcsmOdtCtrl2;
		volatile uint8	AcsmOdtCtrl3;
		volatile uint16	reserved_16_64; //
		volatile uint8	AcsmOdtCtrl4;
		volatile uint8	AcsmOdtCtrl5;
		volatile uint16	reserved_16_65; //
		volatile uint8	AcsmOdtCtrl6;
		volatile uint8	AcsmOdtCtrl7;
		volatile uint16	reserved_16_66; //
		volatile uint8	VrefDqR0Nib0;
		volatile uint8	VrefDqR0Nib1;
		volatile uint16	reserved_16_67; //
		volatile uint8	VrefDqR0Nib2;
		volatile uint8	VrefDqR0Nib3;
		volatile uint16	reserved_16_68; //
		volatile uint8	VrefDqR0Nib4;
		volatile uint8	VrefDqR0Nib5;
		volatile uint16	reserved_16_69; //
		volatile uint8	VrefDqR0Nib6;
		volatile uint8	VrefDqR0Nib7;
		volatile uint16	reserved_16_70; //
		volatile uint8	VrefDqR0Nib8;
		volatile uint8	VrefDqR0Nib9;
		volatile uint16	reserved_16_71; //
		volatile uint8	VrefDqR0Nib10;
		volatile uint8	VrefDqR0Nib11;
		volatile uint16	reserved_16_72; //
		volatile uint8	VrefDqR0Nib12;
		volatile uint8	VrefDqR0Nib13;
		volatile uint16	reserved_16_73; //
		volatile uint8	VrefDqR0Nib14;
		volatile uint8	VrefDqR0Nib15;
		volatile uint16	reserved_16_74; //
		volatile uint8	VrefDqR0Nib16;
		volatile uint8	VrefDqR0Nib17;
		volatile uint16	reserved_16_75; //
		volatile uint8	VrefDqR0Nib18;
		volatile uint8	VrefDqR0Nib19;
		volatile uint16	reserved_16_76; //
		volatile uint8	VrefDqR1Nib0;
		volatile uint8	VrefDqR1Nib1;
		volatile uint16	reserved_16_77; //
		volatile uint8	VrefDqR1Nib2;
		volatile uint8	VrefDqR1Nib3;
		volatile uint16	reserved_16_78; //
		volatile uint8	VrefDqR1Nib4;
		volatile uint8	VrefDqR1Nib5;
		volatile uint16	reserved_16_79; //
		volatile uint8	VrefDqR1Nib6;
		volatile uint8	VrefDqR1Nib7;
		volatile uint16	reserved_16_80; //
		volatile uint8	VrefDqR1Nib8;
		volatile uint8	VrefDqR1Nib9;
		volatile uint16	reserved_16_81; //
		volatile uint8	VrefDqR1Nib10;
		volatile uint8	VrefDqR1Nib11;
		volatile uint16	reserved_16_82; //
		volatile uint8	VrefDqR1Nib12;
		volatile uint8	VrefDqR1Nib13;
		volatile uint16	reserved_16_83; //
		volatile uint8	VrefDqR1Nib14;
		volatile uint8	VrefDqR1Nib15;
		volatile uint16	reserved_16_84; //
		volatile uint8	VrefDqR1Nib16;
		volatile uint8	VrefDqR1Nib17;
		volatile uint16	reserved_16_85; //
		volatile uint8	VrefDqR1Nib18;
		volatile uint8	VrefDqR1Nib19;
		volatile uint16	reserved_16_86; //
		volatile uint8	VrefDqR2Nib0;
		volatile uint8	VrefDqR2Nib1;
		volatile uint16	reserved_16_87; //
		volatile uint8	VrefDqR2Nib2;
		volatile uint8	VrefDqR2Nib3;
		volatile uint16	reserved_16_88; //
		volatile uint8	VrefDqR2Nib4;
		volatile uint8	VrefDqR2Nib5;
		volatile uint16	reserved_16_89; //
		volatile uint8	VrefDqR2Nib6;
		volatile uint8	VrefDqR2Nib7;
		volatile uint16	reserved_16_90; //
		volatile uint8	VrefDqR2Nib8;
		volatile uint8	VrefDqR2Nib9;
		volatile uint16	reserved_16_91; //
		volatile uint8	VrefDqR2Nib10;
		volatile uint8	VrefDqR2Nib11;
		volatile uint16	reserved_16_92; //
		volatile uint8	VrefDqR2Nib12;
		volatile uint8	VrefDqR2Nib13;
		volatile uint16	reserved_16_93; //
		volatile uint8	VrefDqR2Nib14;
		volatile uint8	VrefDqR2Nib15;
		volatile uint16	reserved_16_94; //
		volatile uint8	VrefDqR2Nib16;
		volatile uint8	VrefDqR2Nib17;
		volatile uint16	reserved_16_95; //
		volatile uint8	VrefDqR2Nib18;
		volatile uint8	VrefDqR2Nib19;
		volatile uint16	reserved_16_96; //
		volatile uint8	VrefDqR3Nib0;
		volatile uint8	VrefDqR3Nib1;
		volatile uint16	reserved_16_97; //
		volatile uint8	VrefDqR3Nib2;
		volatile uint8	VrefDqR3Nib3;
		volatile uint16	reserved_16_98; //
		volatile uint8	VrefDqR3Nib4;
		volatile uint8	VrefDqR3Nib5;
		volatile uint16	reserved_16_99; //
		volatile uint8	VrefDqR3Nib6;
		volatile uint8	VrefDqR3Nib7;
		volatile uint16	reserved_16_100; //
		volatile uint8	VrefDqR3Nib8;
		volatile uint8	VrefDqR3Nib9;
		volatile uint16	reserved_16_101; //
		volatile uint8	VrefDqR3Nib10;
		volatile uint8	VrefDqR3Nib11;
		volatile uint16	reserved_16_102; //
		volatile uint8	VrefDqR3Nib12;
		volatile uint8	VrefDqR3Nib13;
		volatile uint16	reserved_16_103; //
		volatile uint8	VrefDqR3Nib14;
		volatile uint8	VrefDqR3Nib15;
		volatile uint16	reserved_16_104; //
		volatile uint8	VrefDqR3Nib16;
		volatile uint8	VrefDqR3Nib17;
		volatile uint16	reserved_16_105; //
		volatile uint8	VrefDqR3Nib18;
		volatile uint8	VrefDqR3Nib19;
		volatile uint16	reserved_16_106; //
		volatile uint8	ReservedD6;
		volatile uint8	ReservedD7;
		volatile uint16	reserved_16_107; //
		volatile uint8	ReservedD8;
		volatile uint8	ReservedD9;
		volatile uint16	reserved_16_108; //
		volatile uint8	ReservedDA;
		volatile uint8	ReservedDB;
		volatile uint16	reserved_16_109; //
		volatile uint8	ReservedDC;
		volatile uint8	ReservedDD;
		volatile uint16	reserved_16_110; //
		volatile uint8	ReservedDE;
		volatile uint8	ReservedDF;
		volatile uint16	reserved_16_111; //
		volatile uint8	ReservedE0;
		volatile uint8	ReservedE1;
		volatile uint16	reserved_16_112; //
		volatile uint8	ReservedE2;
		volatile uint8	ReservedE3;
		volatile uint16	reserved_16_113; //
		volatile uint8	ReservedE4;
		volatile uint8	ReservedE5;
		volatile uint16	reserved_16_114; //
		volatile uint8	ReservedE6;
		volatile uint8	ReservedE7;
		volatile uint16	reserved_16_115; //
		volatile uint8	ReservedE8;
		volatile uint8	ReservedE9;
		volatile uint16	reserved_16_116; //
		volatile uint8	ReservedEA;
		volatile uint8	ReservedEB;
		volatile uint16	reserved_16_117; //
		volatile uint8	ReservedEC;
		volatile uint8	ReservedED;
		volatile uint16	reserved_16_118; //
		volatile uint8	ReservedEE;
		volatile uint8	ReservedEF;
		volatile uint16	reserved_16_119; //
		volatile uint8	ReservedF0;
		volatile uint8	ReservedF1;
		volatile uint16	reserved_16_120; //
		volatile uint8	ReservedF2;
		volatile uint8	ReservedF3;
		volatile uint16	reserved_16_121; //
		volatile uint8	ReservedF4;
		volatile uint8	ReservedF5;
		volatile uint16	reserved_16_122; //
		volatile uint8	ReservedF6;
		volatile uint8	ReservedF7;
		volatile uint16	reserved_16_123; //
		volatile uint8	ReservedF8;
		volatile uint8	ReservedF9;
		volatile uint16	reserved_16_124; //
		volatile uint8	ReservedFA;
		volatile uint8	ReservedFB;
		volatile uint16	reserved_16_125; //
		volatile uint8	ReservedFC;
		volatile uint8	ReservedFD;
		volatile uint16	reserved_16_126; //
		volatile uint8	ReservedFE;
		volatile uint8	ReservedFF;
		volatile uint16	reserved_16_127; //
		volatile uint8	Reserved100;
		volatile uint8	Reserved101;
		volatile uint16	reserved_16_128; //
		volatile uint8	Reserved102;
		volatile uint8	Reserved103;
		volatile uint16	reserved_16_129; //
		volatile uint8	Reserved104;
		volatile uint8	Reserved105;
		volatile uint16	reserved_16_130; //
		volatile uint8	Reserved106;
		volatile uint8	Reserved107;
		volatile uint16	reserved_16_131; //
		volatile uint8	Reserved108;
		volatile uint8	Reserved109;
		volatile uint16	reserved_16_132; //
		volatile uint8	Reserved10A;
		volatile uint8	Reserved10B;
		volatile uint16	reserved_16_133; //
		volatile uint8	Reserved10C;
		volatile uint8	Reserved10D;
		volatile uint16	reserved_16_134; //
		volatile uint8	Reserved10E;
		volatile uint8	Reserved10F;
		volatile uint16	reserved_16_135; //
		volatile uint8	Reserved110;
		volatile uint8	Reserved111;
		volatile uint16	reserved_16_136; //
		volatile uint8	Reserved112;
		volatile uint8	Reserved113;
		volatile uint16	reserved_16_137; //
		volatile uint8	Reserved114;
		volatile uint8	Reserved115;
		volatile uint16	reserved_16_138; //
		volatile uint8	Reserved116;
		volatile uint8	Reserved117;
		volatile uint16	reserved_16_139; //
		volatile uint8	Reserved118;
		volatile uint8	Reserved119;
		volatile uint16	reserved_16_140; //
		volatile uint8	Reserved11A;
		volatile uint8	Reserved11B;
		volatile uint16	reserved_16_141; //
		volatile uint8	Reserved11C;
		volatile uint8	Reserved11D;
		volatile uint16	reserved_16_142; //
		volatile uint8	Reserved11E;
		volatile uint8	Reserved11F;
		volatile uint16	reserved_16_143; //
		volatile uint8	Reserved120;
		volatile uint8	Reserved121;
		volatile uint16	reserved_16_144; //
		volatile uint8	Reserved122;
		volatile uint8	Reserved123;
		volatile uint16	reserved_16_145; //
		volatile uint8	Reserved124;
		volatile uint8	Reserved125;
		volatile uint16	reserved_16_146; //
		volatile uint8	Reserved126;
		volatile uint8	Reserved127;
		volatile uint16	reserved_16_147; //
		volatile uint8	Reserved128;
		volatile uint8	Reserved129;
		volatile uint16	reserved_16_148; //
		volatile uint8	Reserved12A;
		volatile uint8	Reserved12B;
		volatile uint16	reserved_16_149; //
		volatile uint8	Reserved12C;
		volatile uint8	Reserved12D;
		volatile uint16	reserved_16_150; //
		volatile uint8	Reserved12E;
		volatile uint8	Reserved12F;
		volatile uint16	reserved_16_151; //
		volatile uint8	Reserved130;
		volatile uint8	Reserved131;
		volatile uint16	reserved_16_152; //
		volatile uint8	Reserved132;
		volatile uint8	Reserved133;
		volatile uint16	reserved_16_153; //
		volatile uint8	Reserved134;
		volatile uint8	Reserved135;
		volatile uint16	reserved_16_154; //
		volatile uint8	Reserved136;
		volatile uint8	Reserved137;
		volatile uint16	reserved_16_155; //
		volatile uint8	Reserved138;
		volatile uint8	Reserved139;
		volatile uint16	reserved_16_156; //
		volatile uint8	Reserved13A;
		volatile uint8	Reserved13B;
		volatile uint16	reserved_16_157; //
		volatile uint8	Reserved13C;
		volatile uint8	Reserved13D;
		volatile uint16	reserved_16_158; //
		volatile uint8	Reserved13E;
		volatile uint8	Reserved13F;
		volatile uint16	reserved_16_159; //
		volatile uint8	Reserved140;
		volatile uint8	Reserved141;
		volatile uint16	reserved_16_160; //
		volatile uint8	Reserved142;
		volatile uint8	Reserved143;
		volatile uint16	reserved_16_161; //
		volatile uint8	Reserved144;
		volatile uint8	Reserved145;
		volatile uint16	reserved_16_162; //
		volatile uint8	Reserved146;
		volatile uint8	Reserved147;
		volatile uint16	reserved_16_163; //
		volatile uint8	Reserved148;
		volatile uint8	Reserved149;
		volatile uint16	reserved_16_164; //
		volatile uint8	Reserved14A;
		volatile uint8	Reserved14B;
		volatile uint16	reserved_16_165; //
		volatile uint8	Reserved14C;
		volatile uint8	Reserved14D;
		volatile uint16	reserved_16_166; //
		volatile uint8	Reserved14E;
		volatile uint8	Reserved14F;
		volatile uint16	reserved_16_167; //
		volatile uint8	Reserved150;
		volatile uint8	Reserved151;
		volatile uint16	reserved_16_168; //
		volatile uint8	Reserved152;
		volatile uint8	Reserved153;
		volatile uint16	reserved_16_169; //
		volatile uint8	Reserved154;
		volatile uint8	Reserved155;
		volatile uint16	reserved_16_170; //
		volatile uint8	Reserved156;
		volatile uint8	Reserved157;
		volatile uint16	reserved_16_171; //
		volatile uint8	Reserved158;
		volatile uint8	Reserved159;
		volatile uint16	reserved_16_172; //
		volatile uint8	Reserved15A;
		volatile uint8	Reserved15B;
		volatile uint16	reserved_16_173; //
		volatile uint8	Reserved15C;
		volatile uint8	Reserved15D;
		volatile uint16	reserved_16_174; //
		volatile uint8	Reserved15E;
		volatile uint8	Reserved15F;
		volatile uint16	reserved_16_175; //
		volatile uint8	Reserved160;
		volatile uint8	Reserved161;
		volatile uint16	reserved_16_176; //
		volatile uint8	Reserved162;
		volatile uint8	Reserved163;
		volatile uint16	reserved_16_177; //
		volatile uint8	Reserved164;
		volatile uint8	Reserved165;
		volatile uint16	reserved_16_178; //
		volatile uint8	Reserved166;
		volatile uint8	Reserved167;
		volatile uint16	reserved_16_179; //
		volatile uint8	Reserved168;
		volatile uint8	Reserved169;
		volatile uint16	reserved_16_180; //
		volatile uint8	Reserved16A;
		volatile uint8	Reserved16B;
		volatile uint16	reserved_16_181; //
		volatile uint8	Reserved16C;
		volatile uint8	Reserved16D;
		volatile uint16	reserved_16_182; //
		volatile uint8	Reserved16E;
		volatile uint8	Reserved16F;
		volatile uint16	reserved_16_183; //
		volatile uint8	Reserved170;
		volatile uint8	Reserved171;
		volatile uint16	reserved_16_184; //
		volatile uint8	Reserved172;
		volatile uint8	Reserved173;
		volatile uint16	reserved_16_185; //
		volatile uint8	Reserved174;
		volatile uint8	Reserved175;
		volatile uint16	reserved_16_186; //
		volatile uint8	Reserved176;
		volatile uint8	Reserved177;
		volatile uint16	reserved_16_187; //
		volatile uint8	Reserved178;
		volatile uint8	Reserved179;
		volatile uint16	reserved_16_188; //
		volatile uint8	Reserved17A;
		volatile uint8	Reserved17B;
		volatile uint16	reserved_16_189; //
		volatile uint8	Reserved17C;
		volatile uint8	Reserved17D;
		volatile uint16	reserved_16_190; //
		volatile uint8	Reserved17E;
		volatile uint8	Reserved17F;
		volatile uint16	reserved_16_191; //
		volatile uint8	Reserved180;
		volatile uint8	Reserved181;
		volatile uint16	reserved_16_192; //
		volatile uint8	Reserved182;
		volatile uint8	Reserved183;
		volatile uint16	reserved_16_193; //
		volatile uint8	Reserved184;
		volatile uint8	Reserved185;
		volatile uint16	reserved_16_194; //
		volatile uint8	Reserved186;
		volatile uint8	Reserved187;
		volatile uint16	reserved_16_195; //
		volatile uint8	Reserved188;
		volatile uint8	Reserved189;
		volatile uint16	reserved_16_196; //
		volatile uint8	Reserved18A;
		volatile uint8	Reserved18B;
		volatile uint16	reserved_16_197; //
		volatile uint8	Reserved18C;
		volatile uint8	Reserved18D;
		volatile uint16	reserved_16_198; //
		volatile uint8	Reserved18E;
		volatile uint8	Reserved18F;
		volatile uint16	reserved_16_199; //
		volatile uint8	Reserved190;
		volatile uint8	Reserved191;
		volatile uint16	reserved_16_200; //
		volatile uint8	Reserved192;
		volatile uint8	Reserved193;
		volatile uint16	reserved_16_201; //
		volatile uint8	Reserved194;
		volatile uint8	Reserved195;
		volatile uint16	reserved_16_202; //
		volatile uint8	Reserved196;
		volatile uint8	Reserved197;
		volatile uint16	reserved_16_203; //
		volatile uint8	Reserved198;
		volatile uint8	Reserved199;
		volatile uint16	reserved_16_204; //
		volatile uint8	Reserved19A;
		volatile uint8	Reserved19B;
		volatile uint16	reserved_16_205; //
		volatile uint8	Reserved19C;
		volatile uint8	Reserved19D;
		volatile uint16	reserved_16_206; //
		volatile uint8	Reserved19E;
		volatile uint8	Reserved19F;
		volatile uint16	reserved_16_207; //
		volatile uint8	Reserved1A0;
		volatile uint8	Reserved1A1;
		volatile uint16	reserved_16_208; //
		volatile uint8	Reserved1A2;
		volatile uint8	Reserved1A3;
		volatile uint16	reserved_16_209; //
		volatile uint8	Reserved1A4;
		volatile uint8	Reserved1A5;
		volatile uint16	reserved_16_210; //
		volatile uint8	Reserved1A6;
		volatile uint8	Reserved1A7;
		volatile uint16	reserved_16_211; //
		volatile uint8	Reserved1A8;
		volatile uint8	Reserved1A9;
		volatile uint16	reserved_16_212; //
		volatile uint8	Reserved1AA;
		volatile uint8	Reserved1AB;
		volatile uint16	reserved_16_213; //
		volatile uint8	Reserved1AC;
		volatile uint8	Reserved1AD;
		volatile uint16	reserved_16_214; //
		volatile uint8	Reserved1AE;
		volatile uint8	Reserved1AF;
		volatile uint16	reserved_16_215; //
		volatile uint8	Reserved1B0;
		volatile uint8	Reserved1B1;
		volatile uint16	reserved_16_216; //
		volatile uint8	Reserved1B2;
		volatile uint8	Reserved1B3;
		volatile uint16	reserved_16_217; //
		volatile uint8	Reserved1B4;
		volatile uint8	Reserved1B5;
		volatile uint16	reserved_16_218; //
		volatile uint8	Reserved1B6;
		volatile uint8	Reserved1B7;
		volatile uint16	reserved_16_219; //
		volatile uint8	Reserved1B8;
		volatile uint8	Reserved1B9;
		volatile uint16	reserved_16_220; //
		volatile uint8	Reserved1BA;
		volatile uint8	Reserved1BB;
		volatile uint16	reserved_16_221; //
		volatile uint8	Reserved1BC;
		volatile uint8	Reserved1BD;
		volatile uint16	reserved_16_222; //
		volatile uint8	Reserved1BE;
		volatile uint8	Reserved1BF;
		volatile uint16	reserved_16_223; //
		volatile uint8	Reserved1C0;
		volatile uint8	Reserved1C1;
		volatile uint16	reserved_16_224; //
		volatile uint8	Reserved1C2;
		volatile uint8	Reserved1C3;
		volatile uint16	reserved_16_225; //
		volatile uint8	Reserved1C4;
		volatile uint8	Reserved1C5;
		volatile uint16	reserved_16_226; //
		volatile uint8	Reserved1C6;
		volatile uint8	Reserved1C7;
		volatile uint16	reserved_16_227; //
		volatile uint8	Reserved1C8;
		volatile uint8	Reserved1C9;
		volatile uint16	reserved_16_228; //
		volatile uint8	Reserved1CA;
		volatile uint8	Reserved1CB;
		volatile uint16	reserved_16_229; //
		volatile uint8	Reserved1CC;
		volatile uint8	Reserved1CD;
		volatile uint16	reserved_16_230; //
		volatile uint8	Reserved1CE;
		volatile uint8	Reserved1CF;
		volatile uint16	reserved_16_231; //
		volatile uint8	Reserved1D0;
		volatile uint8	Reserved1D1;
		volatile uint16	reserved_16_232; //
		volatile uint8	Reserved1D2;
		volatile uint8	Reserved1D3;
		volatile uint16	reserved_16_233; //
		volatile uint8	Reserved1D4;
		volatile uint8	Reserved1D5;
		volatile uint16	reserved_16_234; //
		volatile uint8	Reserved1D6;
		volatile uint8	Reserved1D7;
		volatile uint16	reserved_16_235; //
		volatile uint8	Reserved1D8;
		volatile uint8	Reserved1D9;
		volatile uint16	reserved_16_236; //
		volatile uint8	Reserved1DA;
		volatile uint8	Reserved1DB;
		volatile uint16	reserved_16_237; //
		volatile uint8	Reserved1DC;
		volatile uint8	Reserved1DD;
		volatile uint16	reserved_16_238; //
		volatile uint8	Reserved1DE;
		volatile uint8	Reserved1DF;
		volatile uint16	reserved_16_239; //
		volatile uint8	Reserved1E0;
		volatile uint8	Reserved1E1;
		volatile uint16	reserved_16_240; //
		volatile uint8	Reserved1E2;
		volatile uint8	Reserved1E3;
		volatile uint16	reserved_16_241; //
		volatile uint8	Reserved1E4;
		volatile uint8	Reserved1E5;
		volatile uint16	reserved_16_242; //
		volatile uint8	Reserved1E6;
		volatile uint8	Reserved1E7;
		volatile uint16	reserved_16_243; //
		volatile uint8	Reserved1E8;
		volatile uint8	Reserved1E9;
		volatile uint16	reserved_16_244; //
		volatile uint8	Reserved1EA;
		volatile uint8	Reserved1EB;
		volatile uint16	reserved_16_245; //
		volatile uint8	Reserved1EC;
		volatile uint8	Reserved1ED;
		volatile uint16	reserved_16_246; //
		volatile uint8	Reserved1EE;
		volatile uint8	Reserved1EF;
		volatile uint16	reserved_16_247; //
		volatile uint8	Reserved1F0;
		volatile uint8	Reserved1F1;
		volatile uint16	reserved_16_248; //
		volatile uint8	Reserved1F2;
		volatile uint8	Reserved1F3;
		volatile uint16	reserved_16_249; //
		volatile uint8	Reserved1F4;
		volatile uint8	Reserved1F5;
		volatile uint16	reserved_16_250; //
		volatile uint8	Reserved1F6;
		volatile uint8	Reserved1F7;
		volatile uint16	reserved_16_251; //
		volatile uint8	Reserved1F8;
		volatile uint8	Reserved1F9;
		volatile uint16	reserved_16_252; //
		volatile uint8	Reserved1FA;
		volatile uint8	Reserved1FB;
		volatile uint16	reserved_16_253; //
		volatile uint8	Reserved1FC;
		volatile uint8	Reserved1FD;
		volatile uint16	reserved_16_254; //
		volatile uint8	Reserved1FE;
		volatile uint8	Reserved1FF;
		volatile uint16	reserved_16_255; //
		volatile uint8	Reserved200;
		volatile uint8	Reserved201;
		volatile uint16	reserved_16_256; //
		volatile uint8	Reserved202;
		volatile uint8	Reserved203;
		volatile uint16	reserved_16_257; //
		volatile uint8	Reserved204;
		volatile uint8	Reserved205;
		volatile uint16	reserved_16_258; //
		volatile uint8	Reserved206;
		volatile uint8	Reserved207;
		volatile uint16	reserved_16_259; //
		volatile uint8	Reserved208;
		volatile uint8	Reserved209;
		volatile uint16	reserved_16_260; //
		volatile uint8	Reserved20A;
		volatile uint8	Reserved20B;
		volatile uint16	reserved_16_261; //
		volatile uint8	Reserved20C;
		volatile uint8	Reserved20D;
		volatile uint16	reserved_16_262; //
		volatile uint8	Reserved20E;
		volatile uint8	Reserved20F;
		volatile uint16	reserved_16_263; //
		volatile uint8	Reserved210;
		volatile uint8	Reserved211;
		volatile uint16	reserved_16_264; //
		volatile uint8	Reserved212;
		volatile uint8	Reserved213;
		volatile uint16	reserved_16_265; //
		volatile uint8	Reserved214;
		volatile uint8	Reserved215;
		volatile uint16	reserved_16_266; //
		volatile uint8	Reserved216;
		volatile uint8	Reserved217;
		volatile uint16	reserved_16_267; //
		volatile uint8	Reserved218;
		volatile uint8	Reserved219;
		volatile uint16	reserved_16_268; //
		volatile uint8	Reserved21A;
		volatile uint8	Reserved21B;
		volatile uint16	reserved_16_269; //
		volatile uint8	Reserved21C;
		volatile uint8	Reserved21D;
		volatile uint16	reserved_16_270; //
		volatile uint8	Reserved21E;
		volatile uint8	Reserved21F;
		volatile uint16	reserved_16_271; //
		volatile uint8	Reserved220;
		volatile uint8	Reserved221;
		volatile uint16	reserved_16_272; //
		volatile uint8	Reserved222;
		volatile uint8	Reserved223;
		volatile uint16	reserved_16_273; //
		volatile uint8	Reserved224;
		volatile uint8	Reserved225;
		volatile uint16	reserved_16_274; //
		volatile uint8	Reserved226;
		volatile uint8	Reserved227;
		volatile uint16	reserved_16_275; //
		volatile uint8	Reserved228;
		volatile uint8	Reserved229;
		volatile uint16	reserved_16_276; //
		volatile uint8	Reserved22A;
		volatile uint8	Reserved22B;
		volatile uint16	reserved_16_277; //
		volatile uint8	Reserved22C;
		volatile uint8	Reserved22D;
		volatile uint16	reserved_16_278; //
		volatile uint8	Reserved22E;
		volatile uint8	Reserved22F;
		volatile uint16	reserved_16_279; //
		volatile uint8	Reserved230;
		volatile uint8	Reserved231;
		volatile uint16	reserved_16_280; //
		volatile uint8	Reserved232;
		volatile uint8	Reserved233;
		volatile uint16	reserved_16_281; //
		volatile uint8	Reserved234;
		volatile uint8	Reserved235;
		volatile uint16	reserved_16_282; //
		volatile uint8	Reserved236;
		volatile uint8	Reserved237;
		volatile uint16	reserved_16_283; //
		volatile uint8	Reserved238;
		volatile uint8	Reserved239;
		volatile uint16	reserved_16_284; //
		volatile uint8	Reserved23A;
		volatile uint8	Reserved23B;
		volatile uint16	reserved_16_285; //
		volatile uint8	Reserved23C;
		volatile uint8	Reserved23D;
		volatile uint16	reserved_16_286; //
		volatile uint8	Reserved23E;
		volatile uint8	Reserved23F;
		volatile uint16	reserved_16_287; //
		volatile uint8	Reserved240;
		volatile uint8	Reserved241;
		volatile uint16	reserved_16_288; //
		volatile uint8	Reserved242;
		volatile uint8	Reserved243;
		volatile uint16	reserved_16_289; //
		volatile uint8	Reserved244;
		volatile uint8	Reserved245;
		volatile uint16	reserved_16_290; //
		volatile uint8	Reserved246;
		volatile uint8	Reserved247;
		volatile uint16	reserved_16_291; //
		volatile uint8	Reserved248;
		volatile uint8	Reserved249;
		volatile uint16	reserved_16_292; //
		volatile uint8	Reserved24A;
		volatile uint8	Reserved24B;
		volatile uint16	reserved_16_293; //
		volatile uint8	Reserved24C;
		volatile uint8	Reserved24D;
		volatile uint16	reserved_16_294; //
		volatile uint8	Reserved24E;
		volatile uint8	Reserved24F;
		volatile uint16	reserved_16_295; //
		volatile uint8	Reserved250;
		volatile uint8	Reserved251;
		volatile uint16	reserved_16_296; //
		volatile uint8	Reserved252;
		volatile uint8	Reserved253;
		volatile uint16	reserved_16_297; //
		volatile uint8	Reserved254;
		volatile uint8	Reserved255;
		volatile uint16	reserved_16_298; //
		volatile uint8	Reserved256;
		volatile uint8	Reserved257;
		volatile uint16	reserved_16_299; //
		volatile uint8	Reserved258;
		volatile uint8	Reserved259;
		volatile uint16	reserved_16_300; //
		volatile uint8	Reserved25A;
		volatile uint8	Reserved25B;
		volatile uint16	reserved_16_301; //
		volatile uint8	Reserved25C;
		volatile uint8	Reserved25D;
		volatile uint16	reserved_16_302; //
		volatile uint8	Reserved25E;
		volatile uint8	Reserved25F;
		volatile uint16	reserved_16_303; //
		volatile uint8	Reserved260;
		volatile uint8	Reserved261;
		volatile uint16	reserved_16_304; //
		volatile uint8	Reserved262;
		volatile uint8	Reserved263;
		volatile uint16	reserved_16_305; //
		volatile uint8	Reserved264;
		volatile uint8	Reserved265;
		volatile uint16	reserved_16_306; //
		volatile uint8	Reserved266;
		volatile uint8	Reserved267;
		volatile uint16	reserved_16_307; //
		volatile uint8	Reserved268;
		volatile uint8	Reserved269;
		volatile uint16	reserved_16_308; //
		volatile uint8	Reserved26A;
		volatile uint8	Reserved26B;
		volatile uint16	reserved_16_309; //
		volatile uint8	Reserved26C;
		volatile uint8	Reserved26D;
		volatile uint16	reserved_16_310; //
		volatile uint8	Reserved26E;
		volatile uint8	Reserved26F;
		volatile uint16	reserved_16_311; //
		volatile uint8	Reserved270;
		volatile uint8	Reserved271;
		volatile uint16	reserved_16_312; //
		volatile uint8	Reserved272;
		volatile uint8	Reserved273;
		volatile uint16	reserved_16_313; //
		volatile uint8	Reserved274;
		volatile uint8	Reserved275;
		volatile uint16	reserved_16_314; //
		volatile uint8	Reserved276;
		volatile uint8	Reserved277;
		volatile uint16	reserved_16_315; //
		volatile uint8	Reserved278;
		volatile uint8	Reserved279;
		volatile uint16	reserved_16_316; //
		volatile uint8	Reserved27A;
		volatile uint8	Reserved27B;
		volatile uint16	reserved_16_317; //
		volatile uint8	Reserved27C;
		volatile uint8	Reserved27D;
		volatile uint16	reserved_16_318; //
		volatile uint8	Reserved27E;
		volatile uint8	Reserved27F;
		volatile uint16	reserved_16_319; //
		volatile uint8	Reserved280;
		volatile uint8	Reserved281;
		volatile uint16	reserved_16_320; //
		volatile uint8	Reserved282;
		volatile uint8	Reserved283;
		volatile uint16	reserved_16_321; //
		volatile uint8	Reserved284;
		volatile uint8	Reserved285;
		volatile uint16	reserved_16_322; //
		volatile uint8	Reserved286;
		volatile uint8	Reserved287;
		volatile uint16	reserved_16_323; //
		volatile uint8	Reserved288;
		volatile uint8	Reserved289;
		volatile uint16	reserved_16_324; //
		volatile uint8	Reserved28A;
		volatile uint8	Reserved28B;
		volatile uint16	reserved_16_325; //
		volatile uint8	Reserved28C;
		volatile uint8	Reserved28D;
		volatile uint16	reserved_16_326; //
		volatile uint8	Reserved28E;
		volatile uint8	Reserved28F;
		volatile uint16	reserved_16_327; //
		volatile uint8	Reserved290;
		volatile uint8	Reserved291;
		volatile uint16	reserved_16_328; //
		volatile uint8	Reserved292;
		volatile uint8	Reserved293;
		volatile uint16	reserved_16_329; //
		volatile uint8	Reserved294;
		volatile uint8	Reserved295;
		volatile uint16	reserved_16_330; //
		volatile uint8	Reserved296;
		volatile uint8	Reserved297;
		volatile uint16	reserved_16_331; //
		volatile uint8	Reserved298;
		volatile uint8	Reserved299;
		volatile uint16	reserved_16_332; //
		volatile uint8	Reserved29A;
		volatile uint8	Reserved29B;
		volatile uint16	reserved_16_333; //
		volatile uint8	Reserved29C;
		volatile uint8	Reserved29D;
		volatile uint16	reserved_16_334; //
		volatile uint8	Reserved29E;
		volatile uint8	Reserved29F;
		volatile uint16	reserved_16_335; //
		volatile uint8	Reserved2A0;
		volatile uint8	Reserved2A1;
		volatile uint16	reserved_16_336; //
		volatile uint8	Reserved2A2;
		volatile uint8	Reserved2A3;
		volatile uint16	reserved_16_337; //
		volatile uint8	Reserved2A4;
		volatile uint8	Reserved2A5;
		volatile uint16	reserved_16_338; //
		volatile uint8	Reserved2A6;
		volatile uint8	Reserved2A7;
		volatile uint16	reserved_16_339; //
		volatile uint8	Reserved2A8;
		volatile uint8	Reserved2A9;
		volatile uint16	reserved_16_340; //
		volatile uint8	Reserved2AA;
		volatile uint8	Reserved2AB;
		volatile uint16	reserved_16_341; //
		volatile uint8	Reserved2AC;
		volatile uint8	Reserved2AD;
		volatile uint16	reserved_16_342; //
		volatile uint8	Reserved2AE;
		volatile uint8	Reserved2AF;
		volatile uint16	reserved_16_343; //
		volatile uint8	Reserved2B0;
		volatile uint8	Reserved2B1;
		volatile uint16	reserved_16_344; //
		volatile uint8	Reserved2B2;
		volatile uint8	Reserved2B3;
		volatile uint16	reserved_16_345; //
		volatile uint8	Reserved2B4;
		volatile uint8	Reserved2B5;
		volatile uint16	reserved_16_346; //
		volatile uint8	Reserved2B6;
		volatile uint8	Reserved2B7;
		volatile uint16	reserved_16_347; //
		volatile uint8	Reserved2B8;
		volatile uint8	Reserved2B9;
		volatile uint16	reserved_16_348; //
		volatile uint8	Reserved2BA;
		volatile uint8	Reserved2BB;
		volatile uint16	reserved_16_349; //
		volatile uint8	Reserved2BC;
		volatile uint8	Reserved2BD;
		volatile uint16	reserved_16_350; //
		volatile uint8	Reserved2BE;
		volatile uint8	Reserved2BF;
		volatile uint16	reserved_16_351; //
		volatile uint8	Reserved2C0;
		volatile uint8	Reserved2C1;
		volatile uint16	reserved_16_352; //
		volatile uint8	Reserved2C2;
		volatile uint8	Reserved2C3;
		volatile uint16	reserved_16_353; //
		volatile uint8	Reserved2C4;
		volatile uint8	Reserved2C5;
		volatile uint16	reserved_16_354; //
		volatile uint8	Reserved2C6;
		volatile uint8	Reserved2C7;
		volatile uint16	reserved_16_355; //
		volatile uint8	Reserved2C8;
		volatile uint8	Reserved2C9;
		volatile uint16	reserved_16_356; //
		volatile uint8	Reserved2CA;
		volatile uint8	Reserved2CB;
		volatile uint16	reserved_16_357; //
		volatile uint8	Reserved2CC;
		volatile uint8	Reserved2CD;
		volatile uint16	reserved_16_358; //
		volatile uint8	Reserved2CE;
		volatile uint8	Reserved2CF;
		volatile uint16	reserved_16_359; //
		volatile uint8	Reserved2D0;
		volatile uint8	Reserved2D1;
		volatile uint16	reserved_16_360; //
		volatile uint8	Reserved2D2;
		volatile uint8	Reserved2D3;
		volatile uint16	reserved_16_361; //
		volatile uint8	Reserved2D4;
		volatile uint8	Reserved2D5;
		volatile uint16	reserved_16_362; //
		volatile uint8	Reserved2D6;
		volatile uint8	Reserved2D7;
		volatile uint16	reserved_16_363; //
		volatile uint8	Reserved2D8;
		volatile uint8	Reserved2D9;
		volatile uint16	reserved_16_364; //
		volatile uint8	Reserved2DA;
		volatile uint8	Reserved2DB;
		volatile uint16	reserved_16_365; //
		volatile uint8	Reserved2DC;
		volatile uint8	Reserved2DD;
		volatile uint16	reserved_16_366; //
		volatile uint8	Reserved2DE;
		volatile uint8	Reserved2DF;
		volatile uint16	reserved_16_367; //
		volatile uint8	Reserved2E0;
		volatile uint8	Reserved2E1;
		volatile uint16	reserved_16_368; //
		volatile uint8	Reserved2E2;
		volatile uint8	Reserved2E3;
		volatile uint16	reserved_16_369; //
		volatile uint8	Reserved2E4;
		volatile uint8	Reserved2E5;
		volatile uint16	reserved_16_370; //
		volatile uint8	Reserved2E6;
		volatile uint8	Reserved2E7;
		volatile uint16	reserved_16_371; //
		volatile uint8	Reserved2E8;
		volatile uint8	Reserved2E9;
		volatile uint16	reserved_16_372; //
		volatile uint8	Reserved2EA;
		volatile uint8	Reserved2EB;
		volatile uint16	reserved_16_373; //
		volatile uint8	Reserved2EC;
		volatile uint8	Reserved2ED;
		volatile uint16	reserved_16_374; //
		volatile uint8	Reserved2EE;
		volatile uint8	Reserved2EF;
		volatile uint16	reserved_16_375; //
		volatile uint8	Reserved2F0;
		volatile uint8	Reserved2F1;
		volatile uint16	reserved_16_376; //
		volatile uint8	Reserved2F2;
		volatile uint8	Reserved2F3;
		volatile uint16	reserved_16_377; //
		volatile uint8	Reserved2F4;
		volatile uint8	Reserved2F5;
		volatile uint16	reserved_16_378; //
		volatile uint8	Reserved2F6;
		volatile uint8	Reserved2F7;
		volatile uint16	reserved_16_379; //
		volatile uint8	Reserved2F8;
		volatile uint8	Reserved2F9;
		volatile uint16	reserved_16_380; //
		volatile uint8	Reserved2FA;
		volatile uint8	Reserved2FB;
		volatile uint16	reserved_16_381; //
		volatile uint8	Reserved2FC;
		volatile uint8	Reserved2FD;
		volatile uint16	reserved_16_382; //
		volatile uint8	Reserved2FE;
		volatile uint8	Reserved2FF;
		volatile uint16	reserved_16_383; //
		volatile uint8	Reserved300;
		volatile uint8	Reserved301;
		volatile uint16	reserved_16_384; //
		volatile uint8	Reserved302;
		volatile uint8	Reserved303;
		volatile uint16	reserved_16_385; //
		volatile uint8	Reserved304;
		volatile uint8	Reserved305;
		volatile uint16	reserved_16_386; //
		volatile uint8	Reserved306;
		volatile uint8	Reserved307;
		volatile uint16	reserved_16_387; //
		volatile uint8	Reserved308;
		volatile uint8	Reserved309;
		volatile uint16	reserved_16_388; //
		volatile uint8	Reserved30A;
		volatile uint8	Reserved30B;
		volatile uint16	reserved_16_389; //
		volatile uint8	Reserved30C;
		volatile uint8	Reserved30D;
		volatile uint16	reserved_16_390; //
		volatile uint8	Reserved30E;
		volatile uint8	Reserved30F;
		volatile uint16	reserved_16_391; //
		volatile uint8	Reserved310;
		volatile uint8	Reserved311;
		volatile uint16	reserved_16_392; //
		volatile uint8	Reserved312;
		volatile uint8	Reserved313;
		volatile uint16	reserved_16_393; //
		volatile uint8	Reserved314;
		volatile uint8	Reserved315;
		volatile uint16	reserved_16_394; //
		volatile uint8	Reserved316;
		volatile uint8	Reserved317;
		volatile uint16	reserved_16_395; //
		volatile uint8	Reserved318;
		volatile uint8	Reserved319;
		volatile uint16	reserved_16_396; //
		volatile uint8	Reserved31A;
		volatile uint8	Reserved31B;
		volatile uint16	reserved_16_397; //
		volatile uint8	Reserved31C;
		volatile uint8	Reserved31D;
		volatile uint16	reserved_16_398; //
		volatile uint8	Reserved31E;
		volatile uint8	Reserved31F;
		volatile uint16	reserved_16_399; //
		volatile uint8	Reserved320;
		volatile uint8	Reserved321;
		volatile uint16	reserved_16_400; //
		volatile uint8	Reserved322;
		volatile uint8	Reserved323;
		volatile uint16	reserved_16_401; //
		volatile uint8	Reserved324;
		volatile uint8	Reserved325;
		volatile uint16	reserved_16_402; //
		volatile uint8	Reserved326;
		volatile uint8	Reserved327;
		volatile uint16	reserved_16_403; //
		volatile uint8	Reserved328;
		volatile uint8	Reserved329;
		volatile uint16	reserved_16_404; //
		volatile uint8	Reserved32A;
		volatile uint8	Reserved32B;
		volatile uint16	reserved_16_405; //
		volatile uint8	Reserved32C;
		volatile uint8	Reserved32D;
		volatile uint16	reserved_16_406; //
		volatile uint8	Reserved32E;
		volatile uint8	Reserved32F;
		volatile uint16	reserved_16_407; //
		volatile uint8	Reserved330;
		volatile uint8	Reserved331;
		volatile uint16	reserved_16_408; //
		volatile uint8	Reserved332;
		volatile uint8	Reserved333;
		volatile uint16	reserved_16_409; //
		volatile uint8	Reserved334;
		volatile uint8	Reserved335;
		volatile uint16	reserved_16_410; //
		volatile uint8	Reserved336;
		volatile uint8	Reserved337;
		volatile uint16	reserved_16_411; //
		volatile uint8	Reserved338;
		volatile uint8	Reserved339;
		volatile uint16	reserved_16_412; //
		volatile uint8	Reserved33A;
		volatile uint8	Reserved33B;
		volatile uint16	reserved_16_413; //
		volatile uint8	Reserved33C;
		volatile uint8	Reserved33D;
		volatile uint16	reserved_16_414; //
		volatile uint8	Reserved33E;
		volatile uint8	Reserved33F;
		volatile uint16	reserved_16_415; //
		volatile uint8	Reserved340;
		volatile uint8	Reserved341;
		volatile uint16	reserved_16_416; //
		volatile uint8	Reserved342;
		volatile uint8	Reserved343;
		volatile uint16	reserved_16_417; //
		volatile uint8	Reserved344;
		volatile uint8	Reserved345;
		volatile uint16	reserved_16_418; //
		volatile uint8	Reserved346;
		volatile uint8	Reserved347;
		volatile uint16	reserved_16_419; //
		volatile uint8	Reserved348;
		volatile uint8	Reserved349;
		volatile uint16	reserved_16_420; //
		volatile uint8	Reserved34A;
		volatile uint8	Reserved34B;
		volatile uint16	reserved_16_421; //
		volatile uint8	Reserved34C;
		volatile uint8	Reserved34D;
		volatile uint16	reserved_16_422; //
		volatile uint8	Reserved34E;
		volatile uint8	Reserved34F;
		volatile uint16	reserved_16_423; //
		volatile uint8	Reserved350;
		volatile uint8	Reserved351;
		volatile uint16	reserved_16_424; //
		volatile uint8	Reserved352;
		volatile uint8	Reserved353;
		volatile uint16	reserved_16_425; //
		volatile uint8	Reserved354;
		volatile uint8	Reserved355;
		volatile uint16	reserved_16_426; //
		volatile uint8	Reserved356;
		volatile uint8	Reserved357;
		volatile uint16	reserved_16_427; //
		volatile uint8	Reserved358;
		volatile uint8	Reserved359;
		volatile uint16	reserved_16_428; //
		volatile uint8	Reserved35A;
		volatile uint8	Reserved35B;
		volatile uint16	reserved_16_429; //
		volatile uint8	Reserved35C;
		volatile uint8	Reserved35D;
		volatile uint16	reserved_16_430; //
		volatile uint8	Reserved35E;
		volatile uint8	Reserved35F;
		volatile uint16	reserved_16_431; //
		volatile uint8	Reserved360;
		volatile uint8	Reserved361;
		volatile uint16	reserved_16_432; //
		volatile uint8	Reserved362;
		volatile uint8	Reserved363;
		volatile uint16	reserved_16_433; //
		volatile uint8	Reserved364;
		volatile uint8	Reserved365;
		volatile uint16	reserved_16_434; //
		volatile uint8	Reserved366;
		volatile uint8	Reserved367;
		volatile uint16	reserved_16_435; //
		volatile uint8	Reserved368;
		volatile uint8	Reserved369;
		volatile uint16	reserved_16_436; //
		volatile uint8	Reserved36A;
		volatile uint8	Reserved36B;
		volatile uint16	reserved_16_437; //
		volatile uint8	Reserved36C;
		volatile uint8	Reserved36D;
		volatile uint16	reserved_16_438; //
		volatile uint8	Reserved36E;
		volatile uint8	Reserved36F;
		volatile uint16	reserved_16_439; //
		volatile uint8	Reserved370;
		volatile uint8	Reserved371;
		volatile uint16	reserved_16_440; //
		volatile uint8	Reserved372;
		volatile uint8	Reserved373;
		volatile uint16	reserved_16_441; //
		volatile uint8	Reserved374;
		volatile uint8	Reserved375;
		volatile uint16	reserved_16_442; //
		volatile uint8	Reserved376;
		volatile uint8	Reserved377;
		volatile uint16	reserved_16_443; //
		volatile uint8	Reserved378;
		volatile uint8	Reserved379;
		volatile uint16	reserved_16_444; //
		volatile uint8	Reserved37A;
		volatile uint8	Reserved37B;
		volatile uint16	reserved_16_445; //
		volatile uint8	Reserved37C;
		volatile uint8	Reserved37D;
		volatile uint16	reserved_16_446; //
		volatile uint8	Reserved37E;
		volatile uint8	Reserved37F;
		volatile uint16	reserved_16_447; //
		volatile uint8	Reserved380;
		volatile uint8	Reserved381;
		volatile uint16	reserved_16_448; //
		volatile uint8	Reserved382;
		volatile uint8	Reserved383;
		volatile uint16	reserved_16_449; //
		volatile uint8	Reserved384;
		volatile uint8	Reserved385;
		volatile uint16	reserved_16_450; //
		volatile uint8	Reserved386;
		volatile uint8	Reserved387;
		volatile uint16	reserved_16_451; //
		volatile uint8	Reserved388;
		volatile uint8	Reserved389;
		volatile uint16	reserved_16_452; //
		volatile uint8	Reserved38A;
		volatile uint8	Reserved38B;
		volatile uint16	reserved_16_453; //
		volatile uint8	Reserved38C;
		volatile uint8	Reserved38D;
		volatile uint16	reserved_16_454; //
		volatile uint8	Reserved38E;
		volatile uint8	Reserved38F;
		volatile uint16	reserved_16_455; //
		volatile uint8	Reserved390;
		volatile uint8	Reserved391;
		volatile uint16	reserved_16_456; //
		volatile uint8	Reserved392;
		volatile uint8	Reserved393;
		volatile uint16	reserved_16_457; //
		volatile uint8	Reserved394;
		volatile uint8	Reserved395;
		volatile uint16	reserved_16_458; //
		volatile uint8	Reserved396;
		volatile uint8	Reserved397;
		volatile uint16	reserved_16_459; //
		volatile uint8	Reserved398;
		volatile uint8	Reserved399;
		volatile uint16	reserved_16_460; //
		volatile uint8	Reserved39A;
		volatile uint8	Reserved39B;
		volatile uint16	reserved_16_461; //
		volatile uint8	Reserved39C;
		volatile uint8	Reserved39D;
		volatile uint16	reserved_16_462; //
		volatile uint8	Reserved39E;
		volatile uint8	Reserved39F;
		volatile uint16	reserved_16_463; //
		volatile uint8	Reserved3A0;
		volatile uint8	Reserved3A1;
		volatile uint16	reserved_16_464; //
		volatile uint8	Reserved3A2;
		volatile uint8	Reserved3A3;
		volatile uint16	reserved_16_465; //
		volatile uint8	Reserved3A4;
		volatile uint8	Reserved3A5;
		volatile uint16	reserved_16_466; //
		volatile uint8	Reserved3A6;
		volatile uint8	Reserved3A7;
		volatile uint16	reserved_16_467; //
		volatile uint8	Reserved3A8;
		volatile uint8	Reserved3A9;
		volatile uint16	reserved_16_468; //
		volatile uint8	Reserved3AA;
		volatile uint8	Reserved3AB;
		volatile uint16	reserved_16_469; //
		volatile uint8	Reserved3AC;
		volatile uint8	Reserved3AD;
		volatile uint16	reserved_16_470; //
		volatile uint8	Reserved3AE;
		volatile uint8	Reserved3AF;
		volatile uint16	reserved_16_471; //
		volatile uint8	Reserved3B0;
		volatile uint8	Reserved3B1;
		volatile uint16	reserved_16_472; //
		volatile uint8	Reserved3B2;
		volatile uint8	Reserved3B3;
		volatile uint16	reserved_16_473; //
		volatile uint8	Reserved3B4;
		volatile uint8	Reserved3B5;
		volatile uint16	reserved_16_474; //
		volatile uint8	Reserved3B6;
		volatile uint8	Reserved3B7;
		volatile uint16	reserved_16_475; //
		volatile uint8	Reserved3B8;
		volatile uint8	Reserved3B9;
		volatile uint16	reserved_16_476; //
		volatile uint8	Reserved3BA;
		volatile uint8	Reserved3BB;
		volatile uint16	reserved_16_477; //
		volatile uint8	Reserved3BC;
		volatile uint8	Reserved3BD;
		volatile uint16	reserved_16_478; //
		volatile uint8	Reserved3BE;
		volatile uint8	Reserved3BF;
		volatile uint16	reserved_16_479; //
		volatile uint8	Reserved3C0;
		volatile uint8	Reserved3C1;
		volatile uint16	reserved_16_480; //
		volatile uint8	Reserved3C2;
		volatile uint8	Reserved3C3;
		volatile uint16	reserved_16_481; //
		volatile uint8	Reserved3C4;
		volatile uint8	Reserved3C5;
		volatile uint16	reserved_16_482; //
		volatile uint8	Reserved3C6;
		volatile uint8	Reserved3C7;
		volatile uint16	reserved_16_483; //
		volatile uint8	Reserved3C8;
		volatile uint8	Reserved3C9;
		volatile uint16	reserved_16_484; //
		volatile uint8	Reserved3CA;
		volatile uint8	Reserved3CB;
		volatile uint16	reserved_16_485; //
		volatile uint8	Reserved3CC;
		volatile uint8	Reserved3CD;
		volatile uint16	reserved_16_486; //
		volatile uint8	Reserved3CE;
		volatile uint8	Reserved3CF;
		volatile uint16	reserved_16_487; //
		volatile uint8	Reserved3D0;
		volatile uint8	Reserved3D1;
		volatile uint16	reserved_16_488; //
		volatile uint8	Reserved3D2;
		volatile uint8	Reserved3D3;
		volatile uint16	reserved_16_489; //
		volatile uint8	Reserved3D4;
		volatile uint8	Reserved3D5;
		volatile uint16	reserved_16_490; //
		volatile uint8	Reserved3D6;
		volatile uint8	Reserved3D7;
		volatile uint16	reserved_16_491; //
		volatile uint8	Reserved3D8;
		volatile uint8	Reserved3D9;
		volatile uint16	reserved_16_492; //
		volatile uint8	Reserved3DA;
		volatile uint8	Reserved3DB;
		volatile uint16	reserved_16_493; //
		volatile uint8	Reserved3DC;
		volatile uint8	Reserved3DD;
		volatile uint16	reserved_16_494; //
		volatile uint8	Reserved3DE;
		volatile uint8	Reserved3DF;
		volatile uint16	reserved_16_495; //
		volatile uint8	Reserved3E0;
		volatile uint8	Reserved3E1;
		volatile uint16	reserved_16_496; //
		volatile uint8	Reserved3E2;
		volatile uint8	Reserved3E3;
		volatile uint16	reserved_16_497; //
		volatile uint8	Reserved3E4;
		volatile uint8	Reserved3E5;
		volatile uint16	reserved_16_498; //
		volatile uint8	Reserved3E6;
		volatile uint8	Reserved3E7;
		volatile uint16	reserved_16_499; //
		volatile uint8	Reserved3E8;
		volatile uint8	Reserved3E9;
		volatile uint16	reserved_16_500; //
		volatile uint8	Reserved3EA;
		volatile uint8	Reserved3EB;
		volatile uint16	reserved_16_501; //
		volatile uint8	Reserved3EC;
		volatile uint8	Reserved3ED;
		volatile uint16	reserved_16_502; //
		volatile uint8	Reserved3EE;
		volatile uint8	Reserved3EF;
		volatile uint16	reserved_16_503; //
		volatile uint8	Reserved3F0;
		volatile uint8	Reserved3F1;
		volatile uint16	reserved_16_504; //
		volatile uint8	Reserved3F2;
		volatile uint8	Reserved3F3;
		volatile uint16	reserved_16_505; //
		volatile uint8	Reserved3F4;
		volatile uint8	Reserved3F5;
		volatile uint16	reserved_16_506; //
		volatile uint16	ALT_CAS_L;
		volatile uint16	reserved_16_507; //
		volatile uint8	ALT_WCAS_L;
		volatile uint8	D4Misc;
		volatile uint16	reserved_16_508; //
};
#endif
