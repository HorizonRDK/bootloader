#include <stdio.h>
#include "hb_ddr_oem.h"

unsigned short int phyinit_dmem_lpddr4[] = {
	0x0600, 0x0000, 0x0000, 0x10aa, 0x0002, 0x0000, 0x0014, 0x0000,
	0x131f, 0x00c8, 0x0000, 0x0002, 0x0001, 0x0000, 0x0000, 0x0100,
	0x0000, 0x0000, 0x0310, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x3f74, 0x0033, 0x4d64, 0x4f08, 0x0000, 0x0004, 0x3f74,
	0x0033, 0x4d64, 0x4f08, 0x0000, 0x0004, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x1000, 0x0003, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x7400, 0x333f, 0x6400, 0x084d, 0x004f, 0x0400,
	0x7400, 0x333f, 0x6400, 0x084d, 0x004f, 0x0400, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00ff, 0x0000, 0x0000,
	0x014a, 0x0181, 0x0118, 0x0118, 0x016f, 0x016f, 0x0159, 0x0181,
	0x0120, 0x0120, 0x0000, 0x0000, 0x701c, 0x61a8, 0x35ac, 0x35ac,
	0x125c, 0x125c, 0xc738, 0xb0f4, 0x6590, 0x6590, 0x0000, 0x0000,
	0x8b26, 0x0039, 0x0000, 0x0000, 0x2820, 0x140f, 0x0002, 0x0000,
	0xf01f, 0x0001, 0x0000, 0xffb4, 0x0001, 0x0001, 0xf0b4, 0x0001,
	0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9, 0x0001, 0x0000, 0xf0ba,
	0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf001, 0x0001, 0x0000,
	0xf011, 0x0001, 0x0001, 0xf012, 0x0001, 0xf000, 0xf018, 0x0001,
	0x0001, 0xf013, 0x0001, 0x0000, 0xf0f9, 0x0004, 0x0200, 0xf0fa,
	0x0004, 0x0000, 0xf0fb, 0x0004, 0x0400, 0xff62, 0x0001, 0x0000,
	0xf062, 0x0001, 0x000f, 0xf462, 0x0001, 0x00f0, 0xf002, 0x0001,
	0x0204, 0x0000, 0xf01f, 0x0001, 0x0000, 0xffb4, 0x0001, 0x0001,
	0xf0b4, 0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9, 0x0001,
	0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf001,
	0x0001, 0x0000, 0xf013, 0x0001, 0x0000, 0xf0f9, 0x0004, 0x0200,
	0xf0fa, 0x0004, 0x0000, 0xf0fb, 0x0004, 0x0400, 0xf060, 0x0007,
	0x0008, 0xf065, 0x0007, 0x0000, 0xff62, 0x0001, 0x0000, 0xf002,
	0x0001, 0x0220, 0x10f8, 0x20e8, 0xf01f, 0x0001, 0x0000, 0xf03b,
	0x0002, 0x0001, 0xffb2, 0x0001, 0x0000, 0xf0b2, 0x0001, 0x0001,
	0xffb4, 0x0001, 0x0001, 0xf0b4, 0x0001, 0x0000, 0xf0b9, 0x0001,
	0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf001,
	0x0001, 0x0000, 0xf060, 0x0007, 0x0001, 0xf065, 0x0007, 0x01ff,
	0xff26, 0x0007, 0x0000, 0xff27, 0x0007, 0x0000, 0xf013, 0x0001,
	0x0002, 0xff32, 0x0001, 0x0800, 0xff62, 0x0001, 0x0000, 0xf062,
	0x0001, 0x0001, 0xf462, 0x0001, 0x0001, 0xf002, 0x0001, 0x0208,
	0xf01f, 0x0001, 0x0000, 0xffb2, 0x0001, 0x0000, 0xf0b2, 0x0001,
	0x0001, 0xf4b2, 0x0001, 0x0001, 0xffb4, 0x0001, 0x0001, 0xf0b4,
	0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9, 0x0001, 0x0000,
	0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf011, 0x0001,
	0x0101, 0xf012, 0x0001, 0x0001, 0xf013, 0x0001, 0x0002, 0xf018,
	0x0001, 0x0001, 0xf060, 0x0007, 0x0001, 0xf065, 0x0007, 0x01ff,
	0xff26, 0x0007, 0xffff, 0xff27, 0x0007, 0xffff, 0xff62, 0x0001,
	0x0000, 0xf062, 0x0001, 0x0001, 0xf462, 0x0001, 0x0010, 0xff32,
	0x0001, 0x0800, 0xf002, 0x0001, 0x0210, 0x0000, 0x0a06, 0x140e,
	0x1c18, 0x2420, 0x0c06, 0x1610, 0x201c, 0x2824, 0x0a06, 0x1610,
	0x201a, 0x2824, 0x0c06, 0x1812, 0x241e, 0x2c28, 0x020d, 0x0301,
	0x0c0b, 0x160e, 0x1004, 0x1811, 0x006e, 0x0002, 0x0001, 0x00fd,
	0x0004, 0x000f, 0x0060, 0x0007, 0x0000, 0x00e8, 0x0004, 0x00ff,
	0x00fc, 0x0004, 0x0404, 0x003a, 0x0002, 0x0002, 0x0011, 0x0007,
	0x0000, 0x0000,
};

uint32_t get_sizeof_phyinit_dmem_lpddr4(void)
{
	return ARRAY_SIZE(phyinit_dmem_lpddr4);
}

unsigned short int phyinit_dmem_ddr4[] = {
	0x0060, 0x0000, 0x0000, 0x0a6a, 0x0002, 0x0000, 0x0260, 0x2000,
	0x0101, 0x0a00, 0x0100, 0x031f, 0x00c8, 0x0100, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0a44,
	0x0603, 0x0830, 0x0200, 0x1800, 0x0440, 0x0c18, 0x0101, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1221,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x00ff, 0x0000, 0x0000,
	0x014a, 0x0181, 0x0118, 0x0118, 0x016f, 0x016f, 0x0159, 0x0181,
	0x0120, 0x0120, 0x0000, 0x0000, 0x701c, 0x61a8, 0x35ac, 0x35ac,
	0x125c, 0x125c, 0xc738, 0xb0f4, 0x6590, 0x6590, 0x8b26, 0x0039,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0xf01f, 0x0001, 0x0000, 0xffb4, 0x0001, 0x0001, 0xf0b4, 0x0001,
	0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9, 0x0001, 0x0000, 0xf0ba,
	0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf001, 0x0001, 0x0000,
	0xf011, 0x0001, 0x0001, 0xf012, 0x0001, 0xf000, 0xf018, 0x0001,
	0x0001, 0xf013, 0x0001, 0x0000, 0xf0f9, 0x0004, 0x0200, 0xf0fa,
	0x0004, 0x0000, 0xf0fb, 0x0004, 0x0100, 0xff62, 0x0001, 0x0000,
	0xf062, 0x0001, 0x000f, 0xf462, 0x0001, 0x00f0, 0xf002, 0x0001,
	0x0204, 0x0000, 0xf01f, 0x0001, 0x0000, 0xffb4, 0x0001, 0x0001,
	0xf0b4, 0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9, 0x0001,
	0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf001,
	0x0001, 0x0000, 0xf0f9, 0x0004, 0x0200, 0xf0fa, 0x0004, 0x0000,
	0xf0fb, 0x0004, 0x0100, 0xf060, 0x0007, 0x0005, 0xf065, 0x0007,
	0x01ff, 0xf011, 0x0007, 0x0010, 0xff62, 0x0001, 0x0000, 0xf862,
	0x0001, 0x00fd, 0xf002, 0x0001, 0x0220, 0x0000, 0xf01f, 0x0001,
	0x0000, 0xffb4, 0x0001, 0x0001, 0xf0b4, 0x0001, 0x0000, 0xf4b4,
	0x0001, 0x0000, 0xf0b9, 0x0001, 0x0000, 0xf0ba, 0x0001, 0x0000,
	0xf0bb, 0x0001, 0x0000, 0xf001, 0x0001, 0x0000, 0xf013, 0x0001,
	0x0000, 0xf0f9, 0x0004, 0x0200, 0xf0fa, 0x0004, 0x0000, 0xf0fb,
	0x0004, 0x0100, 0xf060, 0x0007, 0x0008, 0xf065, 0x0007, 0x0000,
	0xff62, 0x0001, 0x0000, 0xf002, 0x0001, 0x0220, 0x10f8, 0x20e8,
	0xf01f, 0x0001, 0x0000, 0xf03b, 0x0002, 0x0001, 0xffb2, 0x0001,
	0x0000, 0xf0b2, 0x0001, 0x0001, 0xf4b2, 0x0001, 0x0001, 0xffb4,
	0x0001, 0x0001, 0xf0b4, 0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000,
	0xf0b9, 0x0001, 0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001,
	0x0000, 0xf001, 0x0001, 0x0000, 0xf060, 0x0007, 0x0001, 0xf065,
	0x0007, 0x01ff, 0xff26, 0x0007, 0xffff, 0xff27, 0x0007, 0xffff,
	0xf013, 0x0001, 0x0002, 0xff32, 0x0001, 0x1000, 0xff62, 0x0001,
	0x0000, 0xf062, 0x0001, 0x0001, 0xf462, 0x0001, 0x0010, 0xf002,
	0x0001, 0x0208, 0xf01f, 0x0001, 0x0000, 0xffb2, 0x0001, 0x0000,
	0xf0b2, 0x0001, 0x0001, 0xf4b2, 0x0001, 0x0001, 0xffb4, 0x0001,
	0x0001, 0xf0b4, 0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9,
	0x0001, 0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000,
	0xf011, 0x0001, 0x0101, 0xf012, 0x0001, 0x0001, 0xf013, 0x0001,
	0x0002, 0xf018, 0x0001, 0x0001, 0xf060, 0x0007, 0x0001, 0xf065,
	0x0007, 0x01ff, 0xff26, 0x0007, 0xffff, 0xff27, 0x0007, 0xffff,
	0xff62, 0x0001, 0x0000, 0xf062, 0x0001, 0x0001, 0xf462, 0x0001,
	0x0010, 0xff32, 0x0001, 0x0800, 0xf002, 0x0001, 0x0210, 0x0000,
	0x006e, 0x0002, 0x0001, 0x00fd, 0x0004, 0x000f, 0x0060, 0x0007,
	0x0000, 0x00e8, 0x0004, 0x00ff, 0x00fc, 0x0004, 0x0404, 0x003a,
	0x0002, 0x0002, 0x0011, 0x0007, 0x0008, 0x0000, 0x0603, 0x0405,
	0x0102, 0x0000,
};

uint32_t get_sizeof_phyinit_dmem_ddr4(void)
{
	return ARRAY_SIZE(phyinit_dmem_ddr4);
}

unsigned short int phyinit_dmem_lpddr4_2D[] = {
	0x0600, 0x0000, 0x0000, 0x10aa, 0x0002, 0x0000, 0x0014, 0x0000,
	0x0061, 0x00c8, 0x0000, 0x0002, 0x0001, 0x0000, 0x0000, 0x0100,
	0x8020, 0x0000, 0x0310, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x3f74, 0x0033, 0x4d64, 0x4f08, 0x0000, 0x0004, 0x3f74,
	0x0033, 0x4d64, 0x4f08, 0x0000, 0x0004, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x1000, 0x0003, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x7400, 0x333f, 0x6400, 0x084d, 0x004f, 0x0400,
	0x7400, 0x333f, 0x6400, 0x084d, 0x004f, 0x0400, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x014a, 0x0181, 0x0118, 0x0118, 0x016f, 0x016f,
	0x0159, 0x0181, 0x0120, 0x0120, 0x0000, 0x0000, 0x701c, 0x61a8,
	0x35ac, 0x35ac, 0x125c, 0x125c, 0xc738, 0xb0f4, 0x6590, 0x6590,
	0x0000, 0x0000, 0x0000, 0x0000, 0x8b5a, 0x0039, 0x0000, 0x0000,
	0x321e, 0x0100, 0x0000, 0x0000, 0x0100, 0x0302, 0x0706, 0x0b0a,
	0x0f0e, 0x1b1a, 0x1f1e, 0x3b3a, 0x3f3e, 0x0000, 0xffff, 0x01e0,
	0x00f0, 0x00a0, 0x0078, 0x0060, 0x0050, 0x0043, 0x003c, 0x0035,
	0x0030, 0x002c, 0x0028, 0x0025, 0x0022, 0x0020, 0x001e, 0x001c,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x2820, 0x140f, 0x0002, 0x0000, 0xf01f, 0x0001, 0x0000, 0xffb4,
	0x0001, 0x0001, 0xf0b4, 0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000,
	0xf0b9, 0x0001, 0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001,
	0x0000, 0xf001, 0x0001, 0x0000, 0xf013, 0x0001, 0x0000, 0xf0f9,
	0x0004, 0x0200, 0xf0fa, 0x0004, 0x0000, 0xf0fb, 0x0004, 0x0400,
	0xf060, 0x0007, 0x0008, 0xf065, 0x0007, 0x0000, 0xff62, 0x0001,
	0x0000, 0xf002, 0x0001, 0x0220, 0x10f8, 0x20e8, 0x0a06, 0x140e,
	0x1c18, 0x2420, 0x0c06, 0x1610, 0x201c, 0x2824, 0x0a06, 0x1610,
	0x201a, 0x2824, 0x0c06, 0x1812, 0x241e, 0x2c28, 0x020d, 0x0301,
	0x0c0b, 0x160e, 0x1004, 0x1811, 0x006e, 0x0002, 0x0001, 0x00fd,
	0x0004, 0x000f, 0x0060, 0x0007, 0x0000, 0x00e8, 0x0004, 0x00ff,
	0x00fc, 0x0004, 0x0404, 0x003a, 0x0002, 0x0002, 0x0011, 0x0007,
	0x0000, 0x0000,
};

uint32_t get_sizeof_phyinit_dmem_lpddr4_2D(void)
{
	return ARRAY_SIZE(phyinit_dmem_lpddr4_2D);
}

unsigned short int phyinit_dmem_ddr4_2D[] = {
	0x0060, 0x0000, 0x0000, 0x0a6a, 0x0002, 0x0000, 0x0256, 0x2000,
	0x0101, 0x0a00, 0x0100, 0x0061, 0x00c8, 0x0100, 0x8020, 0x0000,
	0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0a44,
	0x0603, 0x0830, 0x0200, 0x1800, 0x0440, 0x0c18, 0x0101, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1221,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x014a, 0x0181, 0x0118, 0x0118, 0x016f, 0x016f,
	0x0159, 0x0181, 0x0120, 0x0120, 0x0000, 0x0000, 0x701c, 0x61a8,
	0x35ac, 0x35ac, 0x125c, 0x125c, 0xc738, 0xb0f4, 0x6590, 0x6590,
	0x0000, 0x0000, 0x8b5a, 0x0039, 0x0000, 0x0000, 0x0000, 0x0000,
	0x3217, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0100, 0x0302, 0x0706, 0x0b0a, 0x0f0e, 0x1b1a, 0x1f1e, 0x3b3a,
	0x3f3e, 0x0000, 0xffff, 0x01e0, 0x00f0, 0x00a0, 0x0078, 0x0060,
	0x0050, 0x0043, 0x003c, 0x0035, 0x0030, 0x002c, 0x0028, 0x0025,
	0x0022, 0x0020, 0x001e, 0x001c, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xf01f, 0x0001,
	0x0000, 0xffb4, 0x0001, 0x0001, 0xf0b4, 0x0001, 0x0000, 0xf4b4,
	0x0001, 0x0000, 0xf0b9, 0x0001, 0x0000, 0xf0ba, 0x0001, 0x0000,
	0xf0bb, 0x0001, 0x0000, 0xf001, 0x0001, 0x0000, 0xf0f9, 0x0004,
	0x0200, 0xf0fa, 0x0004, 0x0000, 0xf0fb, 0x0004, 0x0100, 0xf060,
	0x0007, 0x0005, 0xf065, 0x0007, 0x01ff, 0xf011, 0x0007, 0x0010,
	0xff62, 0x0001, 0x0000, 0xf862, 0x0001, 0x00fd, 0xf002, 0x0001,
	0x0220, 0x0000, 0xf01f, 0x0001, 0x0000, 0xffb4, 0x0001, 0x0001,
	0xf0b4, 0x0001, 0x0000, 0xf4b4, 0x0001, 0x0000, 0xf0b9, 0x0001,
	0x0000, 0xf0ba, 0x0001, 0x0000, 0xf0bb, 0x0001, 0x0000, 0xf001,
	0x0001, 0x0000, 0xf013, 0x0001, 0x0000, 0xf0f9, 0x0004, 0x0200,
	0xf0fa, 0x0004, 0x0000, 0xf0fb, 0x0004, 0x0100, 0xf060, 0x0007,
	0x0008, 0xf065, 0x0007, 0x0000, 0xff62, 0x0001, 0x0000, 0xf002,
	0x0001, 0x0220, 0x10f8, 0x20e8, 0x006e, 0x0002, 0x0001, 0x00fd,
	0x0004, 0x000f, 0x0060, 0x0007, 0x0000, 0x00e8, 0x0004, 0x00ff,
	0x00fc, 0x0004, 0x0404, 0x003a, 0x0002, 0x0002, 0x0011, 0x0007,
	0x0008, 0x0000, 0x0603, 0x0405, 0x0102, 0x0000,
};

uint32_t get_sizeof_phyinit_dmem_ddr4_2D(void)
{
	return ARRAY_SIZE(phyinit_dmem_ddr4_2D);
}

struct DMEM_DDR4_STRUCT_16B *p_dmem_ddr4_16b = NULL;
struct DMEM_LPDDR4_STRUCT_16B *p_dmem_lpddr4_16b = NULL;
struct DMEM_DDR4_2D_STRUCT_16B *p_dmem_ddr4_2d_16b = NULL;
struct DMEM_LPDDR4_2D_STRUCT_16B *p_dmem_lpddr4_2d_16b = NULL;

#ifdef SPL_DDR_PKG
extern unsigned int g_ddr_vendor;
#endif

void ddr4_show_dmem_reconfig(void)
{
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	printf("***********************************************\n");

	if(ddr_vendor == DDR_MANU_MICRON) {
#if defined(ddr_test_name_DDR4_MICRON)
		printf("Micron DDR4 setting: %s\n", ddr_test_name_DDR4_MICRON);
#else
		printf("No Micron DDR4 resetting!\n");
#endif
		printf("DDR4_TxImpedance   : %x\n", TxImpedance_DDR4_MICRON);
		printf("DDR4_ATxImpedance  : %x\n", ATxImpedance_DDR4_MICRON);
		printf("DDR4_TxSlewRate    : %x\n", TxSlewRate_DDR4_MICRON);
		printf("DDR4_ATxSlewRate   : %x\n", ATxSlewRate_DDR4_MICRON);
		printf("DDR4_ATxSlewRate45 : %x\n", ATxSlewRate_DDR4_MICRON_45);
		printf("DDR4_VrefInGlobal  : %x\n", VrefInGlobal_DDR4_MICRON);
	} else if(ddr_vendor == DDR_MANU_SAMSUNG) {
#if defined(ddr_test_name_DDR4_SAMSUNG)
		printf("Samsung DDR4 setting: %s\n", ddr_test_name_DDR4_SAMSUNG);
#else
		printf("No SAMSUNG DDR4 resetting!\n");
#endif
		printf("DDR4_TxOdtDrvStren : %x\n", TxOdtDrvStren_DDR4_SAMSUNG);
		printf("DDR4_ATxImpedance  : %x\n", ATxImpedance_DDR4_SAMSUNG);
		printf("DDR4_TxImpedance   : %x\n", TxImpedance_DDR4_SAMSUNG);
		printf("DDR4_TxSlewRate    : %x\n", TxSlewRate_DDR4_SAMSUNG);
		printf("DDR4_ATxSlewRate   : %x\n", ATxSlewRate_DDR4_SAMSUNG);
		printf("DDR4_ATxSlewRate45 : %x\n", ATxSlewRate_DDR4_SAMSUNG_45);
		printf("DDR4_VrefInGlobal  : %x\n", VrefInGlobal_DDR4_SAMSUNG);
	}

	printf("MR_0: %x\n", p_dmem_ddr4_16b->MR_0);
	printf("MR_1: %x\n", p_dmem_ddr4_16b->MR_1);
	printf("MR_2: %x\n", p_dmem_ddr4_16b->MR_2);
	printf("MR_3: %x\n", p_dmem_ddr4_16b->MR_3);
	printf("MR_4: %x\n", p_dmem_ddr4_16b->MR_4);
	printf("MR_5: %x\n", p_dmem_ddr4_16b->MR_5);
	printf("MR_6: %x\n", p_dmem_ddr4_16b->MR_6);

	printf("HdtCtrl:%x\n", p_dmem_ddr4_16b->HdtCtrl);
	printf("Reserved00:%x\n", p_dmem_ddr4_16b->Reserved00);

	printf("***********************************************\n");
}

void ddr4_dmem_reconfig_1600(void)
{
	p_dmem_ddr4_16b->DRAMFreq = 0x640;
	p_dmem_ddr4_16b->MR_0 = 0x215;
	p_dmem_ddr4_16b->MR_1 = 0x201;
	p_dmem_ddr4_16b->MR_2 = 0x210;
	p_dmem_ddr4_16b->MR_3 = 0x200;
	p_dmem_ddr4_16b->MR_4 = 0x800;
	p_dmem_ddr4_16b->MR_5 = 0x440;
	p_dmem_ddr4_16b->MR_6 = 0x418;

	p_dmem_ddr4_16b->PhyVref = 0x60;
	p_dmem_ddr4_16b->DramType = 0x2;
	p_dmem_ddr4_16b->HdtCtrl = 0xc8;
	p_dmem_ddr4_16b->Reserved00 = 0x60;
	ddr4_show_dmem_reconfig();
}

void ddr4_dmem_2d_reconfig_1600(void)
{
	p_dmem_ddr4_2d_16b->DRAMFreq = 0x640;
	p_dmem_ddr4_2d_16b->MR_0 = 0x215;
	p_dmem_ddr4_2d_16b->MR_1 = 0x201;
	p_dmem_ddr4_2d_16b->MR_2 = 0x210;
	p_dmem_ddr4_2d_16b->MR_3 = 0x200;
	p_dmem_ddr4_2d_16b->MR_4 = 0x800;
	p_dmem_ddr4_2d_16b->MR_5 = 0x440;
	p_dmem_ddr4_2d_16b->MR_6 = 0x418;

	p_dmem_ddr4_2d_16b->PhyVref = 0x56;
	p_dmem_ddr4_2d_16b->DramType = 0x2;
	p_dmem_ddr4_2d_16b->HdtCtrl = 0xc8;
	p_dmem_ddr4_2d_16b->Reserved00 = 0x60;
}

void ddr4_dmem_reconfig_2640(void)
{
	uint16 mr1 = 0;
	uint16 mr2 = 0;
	uint16 mr5 = 0;
	uint16 mr6 = 0;
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	if(ddr_vendor == DDR_MANU_MICRON) {
		mr1 = MR1_DDR4_MICRON;
		mr2 = MR2_DDR4_MICRON;
		mr5 = MR5_DDR4_MICRON;
		mr6 = MR6_DDR4_MICRON;
	}else if(ddr_vendor == DDR_MANU_SAMSUNG) {
		mr1 = MR1_DDR4_SAMSUNG;
		mr2 = MR2_DDR4_SAMSUNG;
		mr5 = MR5_DDR4_SAMSUNG;
		mr6 = MR6_DDR4_SAMSUNG;
	}

	p_dmem_ddr4_16b->DRAMFreq = 0xa50;
#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_16b->MR_0 = 0xa74; // CL=21 tCK
#else
	p_dmem_ddr4_16b->MR_0 = 0xE70;
#endif

	p_dmem_ddr4_16b->MR_1 = mr1;
	p_dmem_ddr4_16b->MR_2 = mr2;
	p_dmem_ddr4_16b->MR_3 = 0x200;

#if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	p_dmem_ddr4_16b->MR_4 = 0x1800;
#elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x1000;
#elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x0800;
#else
	p_dmem_ddr4_16b->MR_4 = 0x0000;
#endif
	p_dmem_ddr4_16b->MR_5 = mr5;
	p_dmem_ddr4_16b->MR_6 = mr6;
	p_dmem_ddr4_16b->PhyVref = 0x60;
	p_dmem_ddr4_16b->DramType = 0x2;
	p_dmem_ddr4_16b->HdtCtrl = 0x4;
	p_dmem_ddr4_16b->Reserved00 = 0x60;

#ifdef DDR4_A8
	p_dmem_ddr4_16b->TX2D_TrainOpt = 0x00;
	p_dmem_ddr4_16b->RX2D_TrainOpt = 0x13;
#endif
}

void ddr4_dmem_reconfig_2666(void)
{
	uint16 mr1 = 0;
	uint16 mr2 = 0;
	uint16 mr5 = 0;
	uint16 mr6 = 0;
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	if(ddr_vendor == DDR_MANU_MICRON) {
		mr1 = MR1_DDR4_MICRON;
		mr2 = MR2_DDR4_MICRON;
		mr5 = MR5_DDR4_MICRON;
		mr6 = MR6_DDR4_MICRON;
	}else if(ddr_vendor == DDR_MANU_SAMSUNG) {
		mr1 = MR1_DDR4_SAMSUNG;
		mr2 = MR2_DDR4_SAMSUNG;
		mr5 = MR5_DDR4_SAMSUNG;
		mr6 = MR6_DDR4_SAMSUNG;
	}

	p_dmem_ddr4_16b->DRAMFreq = 0xa6a;
#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_16b->MR_0 = 0xa74; // CL=21 tCK
#else
#if defined(M_D4_26_A1)
	p_dmem_ddr4_16b->MR_0 = 0xE40;
#elif defined(M_D4_26_A2)
	p_dmem_ddr4_16b->MR_0 = 0xA40;
#elif defined(M_D4_26_A3)
	p_dmem_ddr4_16b->MR_0 = 0xE40;
#elif (defined(S_D4_26_A0) || defined(S_D4_26_A3) || defined(M_D4_26_A0) || defined(M_D4_8Gb_26_A1))
	p_dmem_ddr4_16b->MR_0 = 0xE70;
#elif ( defined(S_D4_26_A1) || defined(S_D4_26_A1R) || defined(M_D4_8Gb_26_A0) )
	p_dmem_ddr4_16b->MR_0 = 0xE44;
#else
	if (ddr_vendor == DDR_MANU_MICRON)
		p_dmem_ddr4_16b->MR_0 = 0xa44; // CL= tCK 20 xzg
	else if(ddr_vendor == DDR_MANU_SAMSUNG)
		p_dmem_ddr4_16b->MR_0 = 0xE70;
#endif
#endif
	p_dmem_ddr4_16b->MR_1 = mr1;
	p_dmem_ddr4_16b->MR_2 = mr2;
	p_dmem_ddr4_16b->MR_3 = 0x200;

#if (defined(S_D4_26_A0) || defined(S_D4_26_A1)  || defined(S_D4_26_A3) || defined(S_D4_26_A1R) || defined(M_D4_8Gb_26_A0) || defined(M_D4_26_A0) || defined(M_D4_8Gb_26_A1))
#if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	p_dmem_ddr4_16b->MR_4 = 0x1800;
#elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x1000;
#elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x0800;
#else
	p_dmem_ddr4_16b->MR_4 = 0x0000;
#endif
#else
#if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	if (ddr_vendor == DDR_MANU_MICRON)
		p_dmem_ddr4_16b->MR_4 = 0x1810;
	else if(ddr_vendor == DDR_MANU_SAMSUNG)
		p_dmem_ddr4_16b->MR_4 = 0x1800;
#elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x1010;
#elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x0810;
#else
	p_dmem_ddr4_16b->MR_4 = 0x0010;
#endif
#endif

	p_dmem_ddr4_16b->MR_5 = mr5;
	p_dmem_ddr4_16b->MR_6 = mr6;
	p_dmem_ddr4_16b->PhyVref = 0x60;
	p_dmem_ddr4_16b->DramType = 0x2;
	p_dmem_ddr4_16b->HdtCtrl = 0x4;
	p_dmem_ddr4_16b->Reserved00 = 0x60;

	ddr4_show_dmem_reconfig();
}

void ddr4_dmem_2d_reconfig_2666(void)
{
	uint16 mr1 = 0;
	uint16 mr2 = 0;
	uint16 mr5 = 0;
	uint16 mr6 = 0;
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	if(ddr_vendor == DDR_MANU_MICRON) {
		mr1 = MR1_DDR4_MICRON;
		mr2 = MR2_DDR4_MICRON;
		mr5 = MR5_DDR4_MICRON;
		mr6 = MR6_DDR4_MICRON;
	}else if(ddr_vendor == DDR_MANU_SAMSUNG) {
		mr1 = MR1_DDR4_SAMSUNG;
		mr2 = MR2_DDR4_SAMSUNG;
		mr5 = MR5_DDR4_SAMSUNG;
		mr6 = MR6_DDR4_SAMSUNG;
	}

	p_dmem_ddr4_2d_16b->DRAMFreq = 0xa6a;
#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_2d_16b->MR_0 = 0xa74; // CL=21 tCK
#else
#if defined(M_D4_26_A1)
	p_dmem_ddr4_2d_16b->MR_0 = 0xE40;
#elif defined(M_D4_26_A2)
	p_dmem_ddr4_2d_16b->MR_0 = 0xA40;
#elif defined(M_D4_26_A3)
	p_dmem_ddr4_2d_16b->MR_0 = 0xE40;
#elif (defined(S_D4_26_A0) || defined(S_D4_26_A3) || defined(M_D4_26_A0) || defined(M_D4_8Gb_26_A1))
	p_dmem_ddr4_2d_16b->MR_0 = 0xE70;
#elif (defined(S_D4_26_A1) || defined(S_D4_26_A1R) || defined(M_D4_8Gb_26_A0))
	p_dmem_ddr4_2d_16b->MR_0 = 0xE44;
#else
	if(ddr_vendor == DDR_MANU_MICRON)
		p_dmem_ddr4_2d_16b->MR_0 = 0xa44; // CL= tCK 20 xzg
	else if(ddr_vendor == DDR_MANU_SAMSUNG)
		p_dmem_ddr4_2d_16b->MR_0 = 0xE70;
#endif
#endif
	p_dmem_ddr4_2d_16b->MR_1 = mr1;
	p_dmem_ddr4_2d_16b->MR_2 = mr2;
	p_dmem_ddr4_2d_16b->MR_3 = 0x200;

#if (defined(S_D4_26_A0) || defined(S_D4_26_A1) || defined(S_D4_26_A3) || defined(S_D4_26_A1R) || defined(M_D4_8Gb_26_A0) || defined(M_D4_26_A0) || defined(M_D4_8Gb_26_A1))
#if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	p_dmem_ddr4_2d_16b->MR_4 = 0x1800;
#elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x1000;
#elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x0800;
#else
	p_dmem_ddr4_2d_16b->MR_4 = 0x0000;
#endif
#else
#if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	if(ddr_vendor == DDR_MANU_MICRON)
		p_dmem_ddr4_2d_16b->MR_4 = 0x1810;
	else if(ddr_vendor == DDR_MANU_SAMSUNG)
		p_dmem_ddr4_2d_16b->MR_4 = 0x1800;
#elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x1010;
#elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x0810;
#else
	p_dmem_ddr4_2d_16b->MR_4 = 0x0010;
#endif
#endif

	p_dmem_ddr4_2d_16b->MR_5 = mr5;
	p_dmem_ddr4_2d_16b->MR_6 = mr6;
	p_dmem_ddr4_2d_16b->PhyVref = 0x60;
	p_dmem_ddr4_2d_16b->DramType = 0x2;
	p_dmem_ddr4_2d_16b->HdtCtrl = 0x4;
	p_dmem_ddr4_2d_16b->Reserved00 = 0x60;
#ifdef DDR4_A8
	p_dmem_ddr4_2d_16b->TX2D_TrainOpt = 0x00;
	p_dmem_ddr4_2d_16b->RX2D_TrainOpt = 0x13;
#endif

}

void ddr4_dmem_2d_reconfig_2640(void)
{
	uint16 mr1 = 0;
	uint16 mr2 = 0;
	uint16 mr5 = 0;
	uint16 mr6 = 0;
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	if(ddr_vendor == DDR_MANU_MICRON) {
		mr1 = MR1_DDR4_MICRON;
		mr2 = MR2_DDR4_MICRON;
		mr5 = MR5_DDR4_MICRON;
		mr6 = MR6_DDR4_MICRON;
	}else if(ddr_vendor == DDR_MANU_SAMSUNG) {
		mr1 = MR1_DDR4_SAMSUNG;
		mr2 = MR2_DDR4_SAMSUNG;
		mr5 = MR5_DDR4_SAMSUNG;
		mr6 = MR6_DDR4_SAMSUNG;
	}

	p_dmem_ddr4_2d_16b->DRAMFreq = 0xa50;
#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_2d_16b->MR_0 = 0xa74; // CL=21 tCK
#else
	p_dmem_ddr4_2d_16b->MR_0 = 0xE70;
#endif

	p_dmem_ddr4_2d_16b->MR_1 = mr1;
	p_dmem_ddr4_2d_16b->MR_2 = mr2;
	p_dmem_ddr4_2d_16b->MR_3 = 0x200;

#if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	p_dmem_ddr4_2d_16b->MR_4 = 0x1800;
#elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x1000;
#elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x0800;
#else
	p_dmem_ddr4_2d_16b->MR_4 = 0x0000;
#endif
	p_dmem_ddr4_2d_16b->MR_5 = mr5;
	p_dmem_ddr4_2d_16b->MR_6 = mr6;
	p_dmem_ddr4_2d_16b->PhyVref = 0x60;
	p_dmem_ddr4_2d_16b->DramType = 0x2;
	p_dmem_ddr4_2d_16b->HdtCtrl = 0x4;
	p_dmem_ddr4_2d_16b->Reserved00 = 0x60;

#ifdef DDR4_A8
	p_dmem_ddr4_2d_16b->TX2D_TrainOpt = 0x00;
	p_dmem_ddr4_2d_16b->RX2D_TrainOpt = 0x13;
#endif
	ddr4_show_dmem_reconfig();
}

void ddr4_dmem_reconfig_2400(void)
{
	uint16 mr1 = 0;
	uint16 mr2 = 0;
	uint16 mr5 = 0;
	uint16 mr6 = 0;
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	if(ddr_vendor == DDR_MANU_MICRON) {
		mr1 = MR1_DDR4_MICRON;
		mr2 = MR2_DDR4_MICRON;
		mr5 = MR5_DDR4_MICRON;
		mr6 = MR6_DDR4_MICRON;
	}else if(ddr_vendor == DDR_MANU_SAMSUNG) {
		mr1 = MR1_DDR4_SAMSUNG;
		mr2 = MR2_DDR4_SAMSUNG;
		mr5 = MR5_DDR4_SAMSUNG;
		mr6 = MR6_DDR4_SAMSUNG;
	}

	p_dmem_ddr4_16b->DRAMFreq = 0x960;

#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_16b->MR_0 = 0xa70; // CL=19 tCK
#else
#if defined(S_D4_24_A0)
	p_dmem_ddr4_16b->MR_0 = 0xa64;
#else
	p_dmem_ddr4_16b->MR_0 = 0xa34; // CL=16 tCK
#endif
#endif
	p_dmem_ddr4_16b->MR_1 = mr1;
	p_dmem_ddr4_16b->MR_2 = mr2;
	p_dmem_ddr4_16b->MR_3 = 0x200;
	p_dmem_ddr4_16b->MR_4 = 0x1800;
	p_dmem_ddr4_16b->MR_5 = mr5;
	p_dmem_ddr4_16b->MR_6 = mr6;
	p_dmem_ddr4_16b->PhyVref = 0x60;
	p_dmem_ddr4_16b->DramType = 0x2;
	p_dmem_ddr4_16b->HdtCtrl = 0x4;
	p_dmem_ddr4_16b->Reserved00 = 0x60;

	ddr4_show_dmem_reconfig();

}

void ddr4_dmem_2d_reconfig_2400(void)
{
	uint16 mr1 = 0;
	uint16 mr2 = 0;
	uint16 mr5 = 0;
	uint16 mr6 = 0;
	unsigned int ddr_vendor = 0;

#ifdef SPL_DDR_PKG
	ddr_vendor = g_ddr_vendor;;
#else
	ddr_vendor = hb_ddr_vendor;
#endif

	if(ddr_vendor == DDR_MANU_MICRON) {
		mr1 = MR1_DDR4_MICRON;
		mr2 = MR2_DDR4_MICRON;
		mr5 = MR5_DDR4_MICRON;
		mr6 = MR6_DDR4_MICRON;
	}else if(ddr_vendor == DDR_MANU_SAMSUNG) {
		mr1 = MR1_DDR4_SAMSUNG;
		mr2 = MR2_DDR4_SAMSUNG;
		mr5 = MR5_DDR4_SAMSUNG;
		mr6 = MR6_DDR4_SAMSUNG;
	}

	p_dmem_ddr4_2d_16b->DRAMFreq = 0x960;

#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_2d_16b->MR_0 = 0xa70; // CL=19 tCK
#else
#if defined(S_D4_24_A0)
	p_dmem_ddr4_2d_16b->MR_0 = 0xa64;
#else
	p_dmem_ddr4_2d_16b->MR_0 = 0xa34; // CL=16 tCK
#endif
#endif
	p_dmem_ddr4_2d_16b->MR_1 = mr1;
	p_dmem_ddr4_2d_16b->MR_2 = mr2;
	p_dmem_ddr4_2d_16b->MR_3 = 0x200;
	p_dmem_ddr4_2d_16b->MR_4 = 0x1800;
	p_dmem_ddr4_2d_16b->MR_5 = mr5;
	p_dmem_ddr4_2d_16b->MR_6 = mr6;
	p_dmem_ddr4_2d_16b->PhyVref = 0x60;
	p_dmem_ddr4_2d_16b->DramType = 0x2;
	p_dmem_ddr4_2d_16b->HdtCtrl = 0x4;
	p_dmem_ddr4_2d_16b->Reserved00 = 0x60;

}

void ddr4_dmem_reconfig_3200(void)
{
	p_dmem_ddr4_16b->DRAMFreq = 0xc80;
#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_16b->MR_0 = 0xa74;
#else
    #if ( defined(M_D4_8Gb_32_A0) || defined(M_D4_8Gb_32_A1) || defined(M_D4_32_A2) || defined(M_D4_32_A2R))
        p_dmem_ddr4_16b->MR_0 = 0x2050;
    #else
	p_dmem_ddr4_16b->MR_0 = 0x2050;//
    #endif
#endif
	p_dmem_ddr4_16b->MR_1 = 0x0001;//
	p_dmem_ddr4_16b->MR_2 = 0x0830;//
	p_dmem_ddr4_16b->MR_3 = 0x0400;//

#if ( defined(M_D4_8Gb_32_A0) || defined(M_D4_8Gb_32_A1) || defined(M_D4_32_A2) || defined(M_D4_32_A2R))
    #if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	    p_dmem_ddr4_16b->MR_4 = 0x1800;//
    #elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x1000;
    #elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_16b->MR_4 = 0x0800;
    #else
	p_dmem_ddr4_16b->MR_4 = 0x0000;
    #endif
#else
    #if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	    p_dmem_ddr4_16b->MR_4 = 0x1810;//
    #elif ( WR_PRE_2T == 1 )
	    p_dmem_ddr4_16b->MR_4 = 0x1010;
    #elif ( RD_PRE_2T == 1 )
	    p_dmem_ddr4_16b->MR_4 = 0x0810;
    #else
	    p_dmem_ddr4_16b->MR_4 = 0x0010;
    #endif
#endif

	p_dmem_ddr4_16b->MR_5 = 0x0500;//
	p_dmem_ddr4_16b->MR_6 = 0x100A;//
	p_dmem_ddr4_16b->PhyVref=0x60;
	p_dmem_ddr4_16b->DramType=0x2;
	p_dmem_ddr4_16b->HdtCtrl=0x4;
	p_dmem_ddr4_16b->Reserved00=0x60;

	ddr4_show_dmem_reconfig();
}

void ddr4_dmem_2d_reconfig_3200(void)
{
	p_dmem_ddr4_2d_16b->DRAMFreq = 0xc80;
#if ( RD_DBI_EN == 1 )
	p_dmem_ddr4_2d_16b->MR_0 = 0xa74;
#else
	#if ( defined(M_D4_8Gb_32_A0) || defined(M_D4_8Gb_32_A1) || defined(M_D4_32_A2) || defined(M_D4_32_A2R))
        p_dmem_ddr4_2d_16b->MR_0 = 0x2050;
	#else
	p_dmem_ddr4_2d_16b->MR_0 = 0x2050; //
	#endif
#endif
	p_dmem_ddr4_2d_16b->MR_1 = 0x0001;//
	p_dmem_ddr4_2d_16b->MR_2 = 0x0830;//
	p_dmem_ddr4_2d_16b->MR_3 = 0x0400;//

#if ( defined(M_D4_8Gb_32_A0) || defined(M_D4_8Gb_32_A1) || defined(M_D4_32_A2) || defined(M_D4_32_A2R))
    #if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	    p_dmem_ddr4_2d_16b->MR_4 = 0x1800;//
    #elif ( WR_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x1000;
    #elif ( RD_PRE_2T == 1 )
	p_dmem_ddr4_2d_16b->MR_4 = 0x0800;
    #else
	p_dmem_ddr4_2d_16b->MR_4 = 0x0000;
    #endif
#else
    #if ( (WR_PRE_2T == 1) && (RD_PRE_2T == 1) )
	    p_dmem_ddr4_2d_16b->MR_4 = 0x1810;//
    #elif ( WR_PRE_2T == 1 )
	    p_dmem_ddr4_2d_16b->MR_4 = 0x1010;
    #elif ( RD_PRE_2T == 1 )
	    p_dmem_ddr4_2d_16b->MR_4 = 0x0810;
    #else
	    p_dmem_ddr4_2d_16b->MR_4 = 0x0010;
    #endif
#endif

	p_dmem_ddr4_2d_16b->MR_5 = 0x0500;//
	p_dmem_ddr4_2d_16b->MR_6 = 0x100A;//
	p_dmem_ddr4_2d_16b->PhyVref=0x60;
	p_dmem_ddr4_2d_16b->DramType=0x2;
	p_dmem_ddr4_2d_16b->HdtCtrl=0x4;
	p_dmem_ddr4_2d_16b->Reserved00=0x60;

	ddr4_show_dmem_reconfig();
}

void ddr4_dmem_reconfig_silicon(void)
{
	p_dmem_ddr4_16b->MsgMisc &= (~(0x3 << 1));
	p_dmem_ddr4_2d_16b->MsgMisc &= (~(0x3 << 1));

	p_dmem_ddr4_16b->CsPresent = 0x1;
	p_dmem_ddr4_16b->CsPresentD0 = 0x1;
	p_dmem_ddr4_2d_16b->CsPresent = 0x1;
	p_dmem_ddr4_2d_16b->CsPresentD0 = 0x1;

#ifdef DDRPHY_DBG
	p_dmem_ddr4_16b->HdtCtrl = 0x05;
	p_dmem_ddr4_2d_16b->HdtCtrl = 0x05;
#endif
}

/*
 * call this function after umctrl configed, before train start.
 * If you want enable write dbi
 */
void ddr4_write_dbi_cfg (uint32 data)
{
	if (1 == data) {
		p_dmem_ddr4_16b->MR_5 |= (1 << 11);
		p_dmem_ddr4_2d_16b->MR_5 |= (1 << 11);
	} else {
		p_dmem_ddr4_16b->MR_5 &= (~(1 << 11));
		p_dmem_ddr4_2d_16b->MR_5 &= (~(1 << 11));
	}
}

void ddr4_dmem_reconfig_init(unsigned int freq, unsigned int part_number)
{
	ddr4_write_dbi_cfg(WR_DBI_EN_DDR4);
	ddr4_dmem_reconfig_silicon();

	/* 3200 2666 2400 1600 */
	if (freq == DDR_FREQC_3200) {
		printf("ddr4 data rate: 3200\n");
		ddr4_dmem_reconfig_3200();
		ddr4_dmem_2d_reconfig_3200();
	} else if (freq == DDR_FREQC_2666) {
		printf("ddr4 data rate: 2666\n");
		ddr4_dmem_reconfig_2666();
		ddr4_dmem_2d_reconfig_2666();
	} else if (freq == DDR_FREQC_2640) {
		printf("ddr4 data rate: 2640\n");
		ddr4_dmem_reconfig_2640();
		ddr4_dmem_2d_reconfig_2640();
	} else if (freq == DDR_FREQC_2400) {
		printf("ddr4 data rate: 2400\n");
		ddr4_dmem_reconfig_2400();
		ddr4_dmem_2d_reconfig_2400();
	} else if (freq == DDR_FREQC_1600) {
		printf("ddr4 data rate: 1600\n");
		ddr4_dmem_reconfig_1600();
		ddr4_dmem_2d_reconfig_1600();
	}
	switch(part_number) {
	case K4A4G165WF_BCTD:
			if (freq == DDR_FREQC_2640){
				printf("%s %d %x\n",__FUNCTION__,__LINE__,part_number);
				p_dmem_ddr4_16b->MR_0 = 0xE70;
				p_dmem_ddr4_16b->MR_1 = MR1_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_16b->MR_2 = MR2_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_16b->MR_5 = MR5_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_16b->MR_6 = MR6_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_2d_16b->MR_0 = 0xE70;
				p_dmem_ddr4_2d_16b->MR_1 = MR1_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_2d_16b->MR_2 = MR2_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_2d_16b->MR_5 = MR5_DDR4_SAMSUNG_D4S512M_S2640_A3;
				p_dmem_ddr4_2d_16b->MR_6 = MR6_DDR4_SAMSUNG_D4S512M_S2640_A3;
			} else if (freq == DDR_FREQC_2400) {
				printf("%s %d %x\n",__FUNCTION__,__LINE__,part_number);
				p_dmem_ddr4_16b->MR_0 = 0xa64;
				p_dmem_ddr4_16b->MR_1 = MR1_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_16b->MR_2 = MR2_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_16b->MR_5 = MR5_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_16b->MR_6 = MR6_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_2d_16b->MR_0 = 0xa64;
				p_dmem_ddr4_2d_16b->MR_1 = MR1_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_2d_16b->MR_2 = MR2_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_2d_16b->MR_5 = MR5_DDR4_SAMSUNG_D4S512M_S24_A3;
				p_dmem_ddr4_2d_16b->MR_6 = MR6_DDR4_SAMSUNG_D4S512M_S24_A3;
			}
		break;
	default:
		printf("%s %d error part_number %x not found\n",__FUNCTION__, __LINE__, part_number);
		return;
	}
}

#ifdef SPL_DDR_PKG
void ddr4_dmem_micron_write_to_bin(char *file, unsigned int index)
{
	FILE *fp = NULL;
	int dmem1_size = 0, dmem2_size = 0;
	int padding_size = 0, i;
	int padding_value = 0;
	int *p = (int *)phyinit_dmem_lpddr4;

	fp = fopen(file, "ab+");
	if (NULL == fp)	{
		printf("File open fail!\n");
		return ;
	}

	dmem1_size = sizeof(phyinit_dmem_ddr4);
	printf("phyinit dmem ddr4:  size = %d\n", dmem1_size);
	write_data_to_bin(fp, phyinit_dmem_ddr4, dmem1_size);

	dmem2_size = sizeof(phyinit_dmem_ddr4_2D);
	printf("phyinit dmem ddr4 2D:  size = %d\n", dmem2_size);
	write_data_to_bin(fp, phyinit_dmem_ddr4_2D, dmem2_size);

	hdr_uart.dmem1.addr = hdr_uart.imem2.addr +
		ALIGN_512(hdr_uart.imem2.size);
	hdr_uart.dmem1.size = dmem1_size;
	hdr_uart.dmem2.addr = hdr_uart.dmem1.addr +
		ALIGN_512(hdr_uart.dmem1.size);
	hdr_uart.dmem2.size = dmem2_size;

	hdr_ddr.ddr[index].dmem1.size = dmem1_size;
	hdr_ddr.ddr[index].dmem2.addr = hdr_ddr.ddr[index].dmem1.addr +
		ALIGN_512(hdr_ddr.ddr[index].dmem1.size);
	hdr_ddr.ddr[index].dmem2.size = dmem2_size;

	pclose(fp);
	return;
}
#endif

void lpddr4_dmem_reconfig_667(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x1;
	p_dmem_lpddr4_16b->DRAMFreq = 0x29a;
	p_dmem_lpddr4_16b->MR1_A0 = 0x14;
	p_dmem_lpddr4_16b->MR2_A0 = 0x9;
	p_dmem_lpddr4_16b->MR1_A1 = 0x14;
	p_dmem_lpddr4_16b->MR2_A1 = 0x9;
	p_dmem_lpddr4_16b->MR1_B0 = 0x14;
	p_dmem_lpddr4_16b->MR2_B0 = 0x9;
	p_dmem_lpddr4_16b->MR1_B1 = 0x14;
	p_dmem_lpddr4_16b->MR2_B1 = 0x9;

	p_dmem_lpddr4_16b->MR11_A0 = 0x64;
	p_dmem_lpddr4_16b->MR11_A1 = 0x64;
	p_dmem_lpddr4_16b->MR11_B0 = 0x64;
	p_dmem_lpddr4_16b->MR11_B1 = 0x64;
}

void lpddr4_dmem_reconfig_2666(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_16b->DRAMFreq = 0xa6a;
	#if defined(XH_LP4_26_A1)
	p_dmem_lpddr4_16b->MR1_A0 = 0x44;
	p_dmem_lpddr4_16b->MR2_A0 = 0x64;
	p_dmem_lpddr4_16b->MR1_A1 = 0x44;
	p_dmem_lpddr4_16b->MR2_A1 = 0x64;
	p_dmem_lpddr4_16b->MR1_B0 = 0x44;
	p_dmem_lpddr4_16b->MR2_B0 = 0x64;
	p_dmem_lpddr4_16b->MR1_B1 = 0x44;
	p_dmem_lpddr4_16b->MR2_B1 = 0x64;
	#else
	p_dmem_lpddr4_16b->MR1_A0 = 0x44;
	p_dmem_lpddr4_16b->MR2_A0 = 0x24;
	p_dmem_lpddr4_16b->MR1_A1 = 0x44;
	p_dmem_lpddr4_16b->MR2_A1 = 0x24;
	p_dmem_lpddr4_16b->MR1_B0 = 0x44;
	p_dmem_lpddr4_16b->MR2_B0 = 0x24;
	p_dmem_lpddr4_16b->MR1_B1 = 0x44;
	p_dmem_lpddr4_16b->MR2_B1 = 0x24;
	#endif
}

void lpddr4_dmem_reconfig_2666_xh(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_16b->DRAMFreq = 0xa6a;
	p_dmem_lpddr4_16b->MR1_A0 = 0x44;
	p_dmem_lpddr4_16b->MR2_A0 = 0x64;
	p_dmem_lpddr4_16b->MR1_A1 = 0x44;
	p_dmem_lpddr4_16b->MR2_A1 = 0x64;
	p_dmem_lpddr4_16b->MR1_B0 = 0x44;
	p_dmem_lpddr4_16b->MR2_B0 = 0x64;
	p_dmem_lpddr4_16b->MR1_B1 = 0x44;
	p_dmem_lpddr4_16b->MR2_B1 = 0x64;
}

void lpddr4_dmem_reconfig_3200(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_16b->DRAMFreq = 0xc80;
	#if ( defined(XH_LP4_32_A1) || defined(XH_LP4_32_A1R) || defined(XS_LP4_32_A1R) )
	p_dmem_lpddr4_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_16b->MR2_A0 = 0x6d;
	p_dmem_lpddr4_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_16b->MR2_A1 = 0x6d;
	p_dmem_lpddr4_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_16b->MR2_B0 = 0x6d;
	p_dmem_lpddr4_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_16b->MR2_B1 = 0x6d;
	#else
	p_dmem_lpddr4_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_16b->MR2_A0 = 0x2d;
	p_dmem_lpddr4_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_16b->MR2_A1 = 0x2d;
	p_dmem_lpddr4_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_16b->MR2_B0 = 0x2d;
	p_dmem_lpddr4_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_16b->MR2_B1 = 0x2d;
	#endif
}

void lpddr4_dmem_reconfig_3200_xh(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_16b->DRAMFreq = 0xc80;
	p_dmem_lpddr4_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_16b->MR2_A0 = 0x6d;
	p_dmem_lpddr4_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_16b->MR2_A1 = 0x6d;
	p_dmem_lpddr4_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_16b->MR2_B0 = 0x6d;
	p_dmem_lpddr4_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_16b->MR2_B1 = 0x6d;
}

void lpddr4_dmem_reconfig_3200_xg(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_16b->DRAMFreq = 0xc80;
	p_dmem_lpddr4_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_16b->MR2_A0 = 0x2d;
	p_dmem_lpddr4_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_16b->MR2_A1 = 0x2d;
	p_dmem_lpddr4_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_16b->MR2_B0 = 0x2d;
	p_dmem_lpddr4_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_16b->MR2_B1 = 0x2d;
}

void lpddr4_dmem_reconfig_3733(void)
{
	p_dmem_lpddr4_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_16b->DRAMFreq = 0xe94;
	#if defined(XH_LP4_37_A1)
	p_dmem_lpddr4_16b->MR1_A0 = 0x64;
	p_dmem_lpddr4_16b->MR2_A0 = 0x76;
	p_dmem_lpddr4_16b->MR1_A1 = 0x64;
	p_dmem_lpddr4_16b->MR2_A1 = 0x76;
	p_dmem_lpddr4_16b->MR1_B0 = 0x64;
	p_dmem_lpddr4_16b->MR2_B0 = 0x76;
	p_dmem_lpddr4_16b->MR1_B1 = 0x64;
	p_dmem_lpddr4_16b->MR2_B1 = 0x76;
	#else
	p_dmem_lpddr4_16b->MR1_A0 = 0x64;
	p_dmem_lpddr4_16b->MR2_A0 = 0x36;
	p_dmem_lpddr4_16b->MR1_A1 = 0x64;
	p_dmem_lpddr4_16b->MR2_A1 = 0x36;
	p_dmem_lpddr4_16b->MR1_B0 = 0x64;
	p_dmem_lpddr4_16b->MR2_B0 = 0x36;
	p_dmem_lpddr4_16b->MR1_B1 = 0x64;
	p_dmem_lpddr4_16b->MR2_B1 = 0x36;
	#endif
}

void lpddr4_dmem_reconfig_3600(void)
{
        p_dmem_lpddr4_16b->PllBypassEn = 0x0;
        p_dmem_lpddr4_16b->DRAMFreq = 0xe10;
        p_dmem_lpddr4_16b->MR1_A0 = 0x64;
        p_dmem_lpddr4_16b->MR2_A0 = 0x36;
        p_dmem_lpddr4_16b->MR1_A1 = 0x64;
        p_dmem_lpddr4_16b->MR2_A1 = 0x36;
        p_dmem_lpddr4_16b->MR1_B0 = 0x64;
        p_dmem_lpddr4_16b->MR2_B0 = 0x36;
        p_dmem_lpddr4_16b->MR1_B1 = 0x64;
        p_dmem_lpddr4_16b->MR2_B1 = 0x36;
}

void lpddr4_dmem_2d_reconfig_667(void)
{
	p_dmem_lpddr4_2d_16b->PllBypassEn = 0x1;
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0x29a;
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x14;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x9;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x14;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x9;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x14;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x9;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x14;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x9;
}

void lpddr4_dmem_2d_reconfig_2666(void)
{
	p_dmem_lpddr4_2d_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0xa6a;
	#if defined(XH_LP4_26_A1)
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x64;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x64;
	#else
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x24;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x24;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x24;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x24;
	#endif
}

void lpddr4_dmem_2d_reconfig_2666_xh(void)
{
	p_dmem_lpddr4_2d_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0xa6a;
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x64;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x44;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x64;
}

void lpddr4_dmem_2d_reconfig_3200(void)
{
	p_dmem_lpddr4_2d_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0xc80;
	#if ( defined(XH_LP4_32_A1) || defined(XH_LP4_32_A1R) || defined(XS_LP4_32_A1R) )
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x6d;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x6d;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x6d;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x6d;
	#else
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x2d;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x2d;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x2d;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x2d;
	#endif
}

void lpddr4_dmem_2d_reconfig_3200_xh(void)
{
	p_dmem_lpddr4_2d_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0xc80;
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x6d;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x6d;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x6d;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x6d;
}

void lpddr4_dmem_2d_reconfig_3200_xg(void)
{
	p_dmem_lpddr4_2d_16b->PllBypassEn = 0x0;
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0xc80;
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x2d;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x2d;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x2d;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x54;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x2d;
}

void lpddr4_dmem_2d_reconfig_3600(void)
{
        p_dmem_lpddr4_2d_16b->DRAMFreq = 0xe10;
        p_dmem_lpddr4_2d_16b->MR1_A0 = 0x64;
        p_dmem_lpddr4_2d_16b->MR2_A0 = 0x36;
        p_dmem_lpddr4_2d_16b->MR1_A1 = 0x64;
        p_dmem_lpddr4_2d_16b->MR2_A1 = 0x36;
        p_dmem_lpddr4_2d_16b->MR1_B0 = 0x64;
        p_dmem_lpddr4_2d_16b->MR2_B0 = 0x36;
        p_dmem_lpddr4_2d_16b->MR1_B1 = 0x64;
        p_dmem_lpddr4_2d_16b->MR2_B1 = 0x36;
}

void lpddr4_dmem_2d_reconfig_3733(void)
{
	p_dmem_lpddr4_2d_16b->DRAMFreq = 0xe94;
	#if defined(XH_LP4_37_A1)
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x76;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x76;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x76;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x76;
	#else
	p_dmem_lpddr4_2d_16b->MR1_A0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_A0 = 0x36;
	p_dmem_lpddr4_2d_16b->MR1_A1 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_A1 = 0x36;
	p_dmem_lpddr4_2d_16b->MR1_B0 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_B0 = 0x36;
	p_dmem_lpddr4_2d_16b->MR1_B1 = 0x64;
	p_dmem_lpddr4_2d_16b->MR2_B1 = 0x36;
	#endif
}

void lpddr4_micron_dmem_reconfig_silicon (unsigned int part_number,
	unsigned int alter_para, unsigned int freq)
{
	uint8 Reserved00 = sReserved00_LPDDR4_MICRON;
	uint8 Reserved0E = sReserved0E_LPDDR4_MICRON;
	uint8 Delay_Weight2D = sDelay_Weight2D_LPDDR4_MICRON;
	uint8 Voltage_Weight2D = sVoltage_Weight2D_LPDDR4_MICRON;
	uint8 mr3 = MR3_LPDDR4_MICRON;
	uint8 mr11 = MR11_LPDDR4_MICRON;
	uint8 mr12 = MR12_LPDDR4_MICRON;
	uint8 mr14 = MR14_LPDDR4_MICRON;
	uint8 mr22 = MR22_LPDDR4_MICRON;

#if !defined(WARM_BOOT_SPL)
	unsigned int ATxSlewRate = ATxSlewRate_LPDDR4_MICRON;
	unsigned int ATxImpedance = ATxImpedance_LPDDR4_MICRON;
	unsigned int TxSlewRate = TxSlewRate_LPDDR4_MICRON;
	unsigned int TxOdtDrvStren = TxOdtDrvStren_LPDDR4_MICRON;
	unsigned int TxImpedanceCtrl1 = TxImpedanceCtrl1_LPDDR4_MICRON;
	unsigned int CalDrvStr0 = CalDrvStr0_LPDDR4_MICRON;
	unsigned int DRAMTMG2=DRAMTMG2_LPDDR4_MICRON;
	unsigned int RFSHTMG=RFSHTMG_LPDDR4_MICRON;
	unsigned int RFSHTMG1=RFSHTMG1_LPDDR4_MICRON;
#endif

	if (part_number == MT53E1G32D2FW_046AUTA) {
		mr3  = MR3_LPDDR4_MICRON_L4M32GR1_M32_A17RA;
		mr11 = MR11_LPDDR4_MICRON_L4M32GR1_M32_A17RA;
		mr12 = MR12_LPDDR4_MICRON_L4M32GR1_M32_A17RA;
		mr14 = MR14_LPDDR4_MICRON_L4M32GR1_M32_A17RA;
		mr22 = MR22_LPDDR4_MICRON_L4M32GR1_M32_A17RA;
	} else if (part_number == MT53D512M32D2DT_046AAT) {
		mr3  = MR3_LPDDR4_MICRON_L4M16G_M32_A1RA;
		mr11 = MR11_LPDDR4_MICRON_L4M16G_M32_A1RA;
		mr12 = MR12_LPDDR4_MICRON_L4M16G_M32_A1RA;
		mr14 = MR14_LPDDR4_MICRON_L4M16G_M32_A1RA;
		mr22 = MR22_LPDDR4_MICRON_L4M16G_M32_A1RA;
	} else if (MT53E256M32D2DS_053AAT == part_number) {
		mr3  = MR3_LPDDR4_MICRON_L4M8GR1_M32_A17R_WDQS;
		mr11 = MR11_LPDDR4_MICRON_L4M8GR1_M32_A17R_WDQS;
		mr12 = MR12_LPDDR4_MICRON_L4M8GR1_M32_A17R_WDQS;
		mr14 = MR14_LPDDR4_MICRON_L4M8GR1_M32_A17R_WDQS;
		mr22 = MR22_LPDDR4_MICRON_L4M8GR1_M32_A17R_WDQS;
	}
	p_dmem_lpddr4_16b->Reserved00 = Reserved00;
	p_dmem_lpddr4_16b->Reserved0E = Reserved0E;
	p_dmem_lpddr4_2d_16b->Reserved00 = Reserved00;
	p_dmem_lpddr4_2d_16b->Reserved0E = Reserved0E;
	p_dmem_lpddr4_2d_16b->Delay_Weight2D = Delay_Weight2D;
	p_dmem_lpddr4_2d_16b->Voltage_Weight2D = Voltage_Weight2D;

	p_dmem_lpddr4_16b->MR11_A0 = mr11;
	p_dmem_lpddr4_16b->MR11_A1 = mr11;
	p_dmem_lpddr4_16b->MR11_B0 = mr11;
	p_dmem_lpddr4_16b->MR11_B1 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_A0 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_A1 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_B0 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_B1 = mr11;

	p_dmem_lpddr4_16b->MR12_A0 = mr12;
	p_dmem_lpddr4_16b->MR12_A1 = mr12;
	p_dmem_lpddr4_16b->MR12_B0 = mr12;
	p_dmem_lpddr4_16b->MR12_B1 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_A0 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_A1 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_B0 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_B1 = mr12;

	p_dmem_lpddr4_16b->MR14_A0 = mr14;
	p_dmem_lpddr4_16b->MR14_A1 = mr14;
	p_dmem_lpddr4_16b->MR14_B0 = mr14;
	p_dmem_lpddr4_16b->MR14_B1 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_A0 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_A1 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_B0 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_B1 = mr14;

	p_dmem_lpddr4_16b->MR22_A0 = mr22;
	p_dmem_lpddr4_16b->MR22_A1 = mr22;
	p_dmem_lpddr4_16b->MR22_B0 = mr22;
	p_dmem_lpddr4_16b->MR22_B1 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_A0 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_A1 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_B0 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_B1 = mr22;

	p_dmem_lpddr4_16b->MR3_A0 = mr3;
	p_dmem_lpddr4_16b->MR3_A1 = mr3;
	p_dmem_lpddr4_16b->MR3_B0 = mr3;
	p_dmem_lpddr4_16b->MR3_B1 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_A0 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_A1 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_B0 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_B1 = mr3;

#if !defined(WARM_BOOT_SPL)
	printf("***********************************************\n");
#if defined(ddr_test_name_LPDDR4_MICRON)
	printf("LPDDR4 setting: %s\n",ddr_test_name_LPDDR4_MICRON);
#else
	printf("No ddr_test_name_LPDDR4_MICRON resetting!\n");
#endif
	printf("ATxSlewRate:%x\n",ATxSlewRate);
	printf("ATxImpedance:%x\n",ATxImpedance);
	printf("TxSlewRate:%x\n",TxSlewRate);
	printf("TxOdtDrvStren:%x\n",TxOdtDrvStren);
	printf("TxImpedanceCtrl1:%x\n",TxImpedanceCtrl1);
	printf("CalDrvStr0:%x\n\n",CalDrvStr0);

	printf("p_dmem_lpddr4_2d_16b->MR11_A0:%x\n", p_dmem_lpddr4_2d_16b->MR11_A0);
	printf("p_dmem_lpddr4_2d_16b->MR14_A0:%x\n", p_dmem_lpddr4_2d_16b->MR14_A0);
	printf("p_dmem_lpddr4_2d_16b->MR12_A0:%x\n", p_dmem_lpddr4_2d_16b->MR12_A0);
	printf("p_dmem_lpddr4_2d_16b->MR22_A0:%x\n\n", p_dmem_lpddr4_2d_16b->MR22_A0);


	printf("p_dmem_lpddr4_2d_16b->MR3_A0:%x\n", p_dmem_lpddr4_2d_16b->MR3_A0);
	printf("p_dmem_lpddr4_2d_16b->Reserved00:%x\n", p_dmem_lpddr4_2d_16b->Reserved00);
	printf("p_dmem_lpddr4_2d_16b->Reserved0E:%x\n", p_dmem_lpddr4_2d_16b->Reserved0E);
	printf("p_dmem_lpddr4_2d_16b->Delay_Weight2D:%x\n", p_dmem_lpddr4_2d_16b->Delay_Weight2D);
	printf("p_dmem_lpddr4_2d_16b->Voltage_Weight2D:%x\n", p_dmem_lpddr4_2d_16b->Voltage_Weight2D);

	printf("Controller:\n");
	printf("DRAMTMG2 :%x\n",DRAMTMG2);
	printf("RFSHTMG  :%x\n",RFSHTMG);
	printf("RFSHTMG1 :%x\n",RFSHTMG1);
	printf("***********************************************\n");
#endif

	if(WR_DBI_EN_LPDDR4) {
		p_dmem_lpddr4_16b->MR3_A0 |= 0x80;
		p_dmem_lpddr4_16b->MR3_A1 |= 0x80;
		p_dmem_lpddr4_16b->MR3_B0 |= 0x80;
		p_dmem_lpddr4_16b->MR3_B1 |= 0x80;
	} else {
		p_dmem_lpddr4_16b->MR3_A0 &= ~0x80;
		p_dmem_lpddr4_16b->MR3_A1 &= ~0x80;
		p_dmem_lpddr4_16b->MR3_B0 &= ~0x80;
		p_dmem_lpddr4_16b->MR3_B1 &= ~0x80;
	}
	if(WR_DBI_EN_LPDDR4) {
		p_dmem_lpddr4_2d_16b->MR3_A0 |= 0x80;
		p_dmem_lpddr4_2d_16b->MR3_A1 |= 0x80;
		p_dmem_lpddr4_2d_16b->MR3_B0 |= 0x80;
		p_dmem_lpddr4_2d_16b->MR3_B1 |= 0x80;
	} else {
		p_dmem_lpddr4_2d_16b->MR3_A0 &= ~0x80;
		p_dmem_lpddr4_2d_16b->MR3_A1 &= ~0x80;
		p_dmem_lpddr4_2d_16b->MR3_B0 &= ~0x80;
		p_dmem_lpddr4_2d_16b->MR3_B1 &= ~0x80;
	}
	if ((part_number == MT53E1G32D2FW_046AUTA)||(part_number == MT53D512M32D2DT_046AAT) ||
		(MT53E256M32D2DS_053AAT == part_number)) {
		p_dmem_lpddr4_16b->CsPresentChA = 0x1;
		p_dmem_lpddr4_16b->CsPresentChB = 0x1;
		p_dmem_lpddr4_2d_16b->CsPresentChA = 0x1;
		p_dmem_lpddr4_2d_16b->CsPresentChB = 0x1;

	} else {
		p_dmem_lpddr4_16b->CsPresentChA = 0x3;
		p_dmem_lpddr4_16b->CsPresentChB = 0x3;
		p_dmem_lpddr4_2d_16b->CsPresentChA = 0x3;
		p_dmem_lpddr4_2d_16b->CsPresentChB = 0x3;
	}

	p_dmem_lpddr4_16b->MsgMisc &= (~(0x3 << 1));
	p_dmem_lpddr4_2d_16b->MsgMisc &= (~(0x3 << 1));

#ifdef DDRPHY_DBG
	p_dmem_lpddr4_16b->HdtCtrl = 0x05;
	p_dmem_lpddr4_2d_16b->HdtCtrl = 0x05;
#endif

}

void lpddr4_hynix_dmem_reconfig_silicon (unsigned int part_number,
	unsigned int alter_para, unsigned int freq)
{
	uint8 Reserved00 = sReserved00_LPDDR4_HYNIX;
	uint8 Reserved0E = sReserved0E_LPDDR4_HYNIX;
	uint8 Delay_Weight2D = sDelay_Weight2D_LPDDR4_HYNIX;
	uint8 Voltage_Weight2D = sVoltage_Weight2D_LPDDR4_HYNIX;
	uint8 mr3 = MR3_LPDDR4_HYNIX;
	uint8 mr11 = MR11_LPDDR4_HYNIX;
	uint8 mr12 = MR12_LPDDR4_HYNIX;
	uint8 mr14 = MR14_LPDDR4_HYNIX;
	uint8 mr22 = MR22_LPDDR4_HYNIX;

#if !defined(WARM_BOOT_SPL)
	unsigned int ATxSlewRate = ATxSlewRate_LPDDR4_HYNIX;
	unsigned int ATxImpedance = ATxImpedance_LPDDR4_HYNIX;
	unsigned int TxSlewRate = TxSlewRate_LPDDR4_HYNIX;
	unsigned int TxOdtDrvStren = TxOdtDrvStren_LPDDR4_HYNIX;
	unsigned int TxImpedanceCtrl1 = TxImpedanceCtrl1_LPDDR4_HYNIX;
	unsigned int CalDrvStr0 = CalDrvStr0_LPDDR4_HYNIX;
	unsigned int DRAMTMG2 = DRAMTMG2_LPDDR4_HYNIX;
	unsigned int RFSHTMG = RFSHTMG_LPDDR4_HYNIX;
	unsigned int RFSHTMG1=RFSHTMG1_LPDDR4_HYNIX;
#endif

	if (part_number == H9HCNNN8KUMLHR) {
		/* X3 hynix */
		mr3 = MR3_LPDDR4_HYNIX_XH26_B13;
		mr11 = MR11_LPDDR4_HYNIX_XH26_B13;
		mr12 = MR12_LPDDR4_HYNIX_XH26_B13;
		mr14 = MR14_LPDDR4_HYNIX_XH26_B13;
		mr22 = MR22_LPDDR4_HYNIX_XH26_B13;
	} else if(part_number == H9HCNNNBKUMLHR) {
		if (freq == DDR_FREQC_3200) {
			/* J3 hynix 3200 */
			mr3 = MR3_LPDDR4_HYNIX_JH32_A1RA;
			mr11 = MR11_LPDDR4_HYNIX_JH32_A1RA;
			mr12 = MR12_LPDDR4_HYNIX_JH32_A1RA;
			mr14 = MR14_LPDDR4_HYNIX_JH32_A1RA;
			mr22 = MR22_LPDDR4_HYNIX_JH32_A1RA;
		} else {
			/* J3 hynix 2666 */
			mr3 = MR3_LPDDR4_HYNIX_JH26_A3;
			mr11 = MR11_LPDDR4_HYNIX_JH26_A3;
			mr12 = MR12_LPDDR4_HYNIX_JH26_A3;
			mr14 = MR14_LPDDR4_HYNIX_JH26_A3;
			mr22 = MR22_LPDDR4_HYNIX_JH26_A3;
		}
	} else if (part_number == K4F8E304HBMGCJ) {
		/* XG 1G */
		if (freq == DDR_FREQC_2666) {
			/* XG Samsung 2666*/
			mr3 = MR3_LPDDR4_SAMSUNG_XS26_A1R;
			mr11 = MR11_LPDDR4_SAMSUNG_XS26_A1R;
			mr12 = MR12_LPDDR4_SAMSUNG_XS26_A1R;
			mr14 = MR14_LPDDR4_SAMSUNG_XS26_A1R;
			mr22 = MR22_LPDDR4_SAMSUNG_XS26_A1R;
		} else if (freq == DDR_FREQC_3200) {
			mr3 = MR3_LPDDR4_SAMSUNG_XS32_A1R;
			mr11 = MR11_LPDDR4_SAMSUNG_XS32_A1R;
			mr12 = MR12_LPDDR4_SAMSUNG_XS32_A1R;
			mr14 = MR14_LPDDR4_SAMSUNG_XS32_A1R;
			mr22 = MR22_LPDDR4_SAMSUNG_XS32_A1R;
		} else if (freq == DDR_FREQC_3600) {
			mr3 = MR3_LPDDR4_SAMSUNG_XS36_A17R;
			mr11 = MR11_LPDDR4_SAMSUNG_XS36_A17R;
			mr12 = MR12_LPDDR4_SAMSUNG_XS36_A17R;
			mr14 = MR14_LPDDR4_SAMSUNG_XS36_A17R;
			mr22 = MR22_LPDDR4_SAMSUNG_XS36_A17R;
		}
	} else if (part_number == K4F6E3S4HMMGCJ) {
		/* XG 2G */
		if (freq == DDR_FREQC_3200) {
			mr3 = MR3_LPDDR4_HYNIX_L4S16G_XS32_A1RA;
			mr11 = MR11_LPDDR4_HYNIX_L4S16G_XS32_A1RA;
			mr12 = MR12_LPDDR4_HYNIX_L4S16G_XS32_A1RA;
			mr14 = MR14_LPDDR4_HYNIX_L4S16G_XS32_A1RA;
			mr22 = MR22_LPDDR4_HYNIX_L4S16G_XS32_A1RA;
		} else if (freq == DDR_FREQC_3600) {
			mr3 = MR3_LPDDR4_HYNIX_XS36_A17R;
			mr11 = MR11_LPDDR4_HYNIX_XS36_A17R;
			mr12 = MR12_LPDDR4_HYNIX_XS36_A17R;
			mr14 = MR14_LPDDR4_HYNIX_XS36_A17R;
			mr22 = MR22_LPDDR4_HYNIX_XS36_A17R;
		}
	} else if (K4FBE3D4HM_THCL == part_number) {
		if (DDR_FREQC_3200 == freq) {
			mr3 = MR3_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA;
			mr11 = MR11_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA;
			mr12 = MR12_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA;
			mr14 = MR14_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA;
			mr22 = MR22_LPDDR4_SAMSUNG_L4S32G2R_JS32_A17RA;
		}
	}

	p_dmem_lpddr4_16b->Reserved00 = Reserved00;
	p_dmem_lpddr4_16b->Reserved0E = Reserved0E;
	p_dmem_lpddr4_2d_16b->Reserved00 = Reserved00;
	p_dmem_lpddr4_2d_16b->Reserved0E = Reserved0E;
	p_dmem_lpddr4_2d_16b->Delay_Weight2D = Delay_Weight2D;
	p_dmem_lpddr4_2d_16b->Voltage_Weight2D = Voltage_Weight2D;

	p_dmem_lpddr4_16b->MR11_A0 = mr11;
	p_dmem_lpddr4_16b->MR11_A1 = mr11;
	p_dmem_lpddr4_16b->MR11_B0 = mr11;
	p_dmem_lpddr4_16b->MR11_B1 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_A0 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_A1 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_B0 = mr11;
	p_dmem_lpddr4_2d_16b->MR11_B1 = mr11;

	p_dmem_lpddr4_16b->MR12_A0 = mr12;
	p_dmem_lpddr4_16b->MR12_A1 = mr12;
	p_dmem_lpddr4_16b->MR12_B0 = mr12;
	p_dmem_lpddr4_16b->MR12_B1 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_A0 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_A1 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_B0 = mr12;
	p_dmem_lpddr4_2d_16b->MR12_B1 = mr12;

	p_dmem_lpddr4_16b->MR14_A0 = mr14;
	p_dmem_lpddr4_16b->MR14_A1 = mr14;
	p_dmem_lpddr4_16b->MR14_B0 = mr14;
	p_dmem_lpddr4_16b->MR14_B1 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_A0 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_A1 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_B0 = mr14;
	p_dmem_lpddr4_2d_16b->MR14_B1 = mr14;

	p_dmem_lpddr4_16b->MR22_A0 = mr22;
	p_dmem_lpddr4_16b->MR22_A1 = mr22;
	p_dmem_lpddr4_16b->MR22_B0 = mr22;
	p_dmem_lpddr4_16b->MR22_B1 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_A0 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_A1 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_B0 = mr22;
	p_dmem_lpddr4_2d_16b->MR22_B1 = mr22;

	p_dmem_lpddr4_16b->MR3_A0 = mr3;
	p_dmem_lpddr4_16b->MR3_A1 = mr3;
	p_dmem_lpddr4_16b->MR3_B0 = mr3;
	p_dmem_lpddr4_16b->MR3_B1 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_A0 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_A1 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_B0 = mr3;
	p_dmem_lpddr4_2d_16b->MR3_B1 = mr3;

	#if !defined(WARM_BOOT_SPL)
	printf("***********************************************\n");
#if defined(ddr_test_name_LPDDR4_HYNIX)
	printf("LPDDR4 setting: %s\n",ddr_test_name_LPDDR4_HYNIX);
#else
	printf("No ddr_test_name_LPDDR4_HYNIX resetting!\n");
#endif
	printf("ATxSlewRate:%x\n",ATxSlewRate);
	printf("ATxImpedance:%x\n",ATxImpedance);
	printf("TxSlewRate:%x\n",TxSlewRate);
	printf("TxOdtDrvStren:%x\n",TxOdtDrvStren);
	printf("TxImpedanceCtrl1:%x\n",TxImpedanceCtrl1);
	printf("CalDrvStr0:%x\n\n",CalDrvStr0);

	printf("p_dmem_lpddr4_2d_16b->MR11_A0:%x\n", p_dmem_lpddr4_2d_16b->MR11_A0);
	printf("p_dmem_lpddr4_2d_16b->MR14_A0:%x\n", p_dmem_lpddr4_2d_16b->MR14_A0);
	printf("p_dmem_lpddr4_2d_16b->MR12_A0:%x\n", p_dmem_lpddr4_2d_16b->MR12_A0);
	printf("p_dmem_lpddr4_2d_16b->MR22_A0:%x\n\n", p_dmem_lpddr4_2d_16b->MR22_A0);


	printf("p_dmem_lpddr4_2d_16b->MR3_A0:%x\n", p_dmem_lpddr4_2d_16b->MR3_A0);
	printf("p_dmem_lpddr4_2d_16b->Reserved00:%x\n", p_dmem_lpddr4_2d_16b->Reserved00);
	printf("p_dmem_lpddr4_2d_16b->Reserved0E:%x\n", p_dmem_lpddr4_2d_16b->Reserved0E);
	printf("p_dmem_lpddr4_2d_16b->Delay_Weight2D:%x\n", p_dmem_lpddr4_2d_16b->Delay_Weight2D);
	printf("p_dmem_lpddr4_2d_16b->Voltage_Weight2D:%x\n", p_dmem_lpddr4_2d_16b->Voltage_Weight2D);

	printf("Controller:\n");
	printf("DRAMTMG2 :%x\n",DRAMTMG2);
	printf("RFSHTMG  :%x\n",RFSHTMG);
	printf("RFSHTMG1 :%x\n",RFSHTMG1);
	printf("***********************************************\n");
#endif

	if(WR_DBI_EN_LPDDR4) {
		p_dmem_lpddr4_16b->MR3_A0 |= 0x80;
		p_dmem_lpddr4_16b->MR3_A1 |= 0x80;
		p_dmem_lpddr4_16b->MR3_B0 |= 0x80;
		p_dmem_lpddr4_16b->MR3_B1 |= 0x80;
	} else {
		p_dmem_lpddr4_16b->MR3_A0 &= ~0x80;
		p_dmem_lpddr4_16b->MR3_A1 &= ~0x80;
		p_dmem_lpddr4_16b->MR3_B0 &= ~0x80;
		p_dmem_lpddr4_16b->MR3_B1 &= ~0x80;
	}
	if(WR_DBI_EN_LPDDR4) {
		p_dmem_lpddr4_2d_16b->MR3_A0 |= 0x80;
		p_dmem_lpddr4_2d_16b->MR3_A1 |= 0x80;
		p_dmem_lpddr4_2d_16b->MR3_B0 |= 0x80;
		p_dmem_lpddr4_2d_16b->MR3_B1 |= 0x80;
	} else {
		p_dmem_lpddr4_2d_16b->MR3_A0 &= ~0x80;
		p_dmem_lpddr4_2d_16b->MR3_A1 &= ~0x80;
		p_dmem_lpddr4_2d_16b->MR3_B0 &= ~0x80;
		p_dmem_lpddr4_2d_16b->MR3_B1 &= ~0x80;
	}
	if (K4FBE3D4HM_THCL == part_number) {
		p_dmem_lpddr4_16b->CsPresentChA = 0x3;
		p_dmem_lpddr4_16b->CsPresentChB = 0x3;
		p_dmem_lpddr4_2d_16b->CsPresentChA = 0x3;
		p_dmem_lpddr4_2d_16b->CsPresentChB = 0x3;
	} else {
		p_dmem_lpddr4_16b->CsPresentChA = 0x1;
		p_dmem_lpddr4_16b->CsPresentChB = 0x1;
		p_dmem_lpddr4_2d_16b->CsPresentChA = 0x1;
		p_dmem_lpddr4_2d_16b->CsPresentChB = 0x1;
	}
	p_dmem_lpddr4_16b->MsgMisc &= (~(0x3 << 1));
	p_dmem_lpddr4_2d_16b->MsgMisc &= (~(0x3 << 1));

#ifdef DDRPHY_DBG
	p_dmem_lpddr4_16b->HdtCtrl = 0x05;
	p_dmem_lpddr4_2d_16b->HdtCtrl = 0x05;
#endif
}


/*
 * call this function after umctrl configed, before train start.
 * If you want enable read dbi
 */
void  lpddr4_read_dbi_cfg (uint32 data)
{
	if (1 == data) {
		p_dmem_lpddr4_16b->MR3_A0 |= (1 << 6);
		p_dmem_lpddr4_16b->MR3_A1 |= (1 << 6);
		p_dmem_lpddr4_16b->MR3_B0 |= (1 << 6);
		p_dmem_lpddr4_16b->MR3_B1 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_A0 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_A1 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_B0 |= (1 << 6);
		p_dmem_lpddr4_2d_16b->MR3_B1 |= (1 << 6);

		p_dmem_lpddr4_16b->MR3_A0 &= (~(1 << 6));
		p_dmem_lpddr4_16b->MR3_A1 &= (~(1 << 6));
		p_dmem_lpddr4_16b->MR3_B0 &= (~(1 << 6));
		p_dmem_lpddr4_16b->MR3_B1 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_A0 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_A1 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_B0 &= (~(1 << 6));
		p_dmem_lpddr4_2d_16b->MR3_B1 &= (~(1 << 6));
	}
}

/*
 * call this function after umctrl configed, before train start.
 * If you want enable write dbi
 */
void lpddr4_write_dbi_cfg (uint32 data)
{
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
}

/*
 * call this function after umctrl configed, before train start.
 * If you want enable write dbi
 */
void lpddr4_mask_write_cfg (void)
{
	p_dmem_lpddr4_16b->MR13_A0 &= (~(1 << 5));
	p_dmem_lpddr4_16b->MR13_A1 &= (~(1 << 5));
	p_dmem_lpddr4_16b->MR13_B0 &= (~(1 << 5));
	p_dmem_lpddr4_16b->MR13_B1 &= (~(1 << 5));
	p_dmem_lpddr4_2d_16b->MR13_A0 &= (~(1 << 5));
	p_dmem_lpddr4_2d_16b->MR13_A1 &= (~(1 << 5));
	p_dmem_lpddr4_2d_16b->MR13_B0 &= (~(1 << 5));
	p_dmem_lpddr4_2d_16b->MR13_B1 &= (~(1 << 5));
}

void lpddr4_cfg_init(void)
{
	lpddr4_read_dbi_cfg(RD_DBI_EN);
	lpddr4_write_dbi_cfg(WR_DBI_EN_LPDDR4);
	lpddr4_mask_write_cfg();
}

void lpddr4_micron_dmem_reconfig_init(unsigned int freq,
	unsigned int part_number, unsigned int alter_para)
{
	lpddr4_micron_dmem_reconfig_silicon(part_number,alter_para,freq);

	/* 3733 3200 2666 667 */
	if (freq == DDR_FREQC_3733) {
		lpddr4_dmem_reconfig_3733();
		lpddr4_dmem_2d_reconfig_3733();
	} else if (freq == DDR_FREQC_3200) {
		lpddr4_dmem_reconfig_3200();
		lpddr4_dmem_2d_reconfig_3200();
	} else if (freq == DDR_FREQC_2666) {
		lpddr4_dmem_reconfig_2666();
		lpddr4_dmem_2d_reconfig_2666();
	} else if ((freq == DDR_FREQC_667) || (freq == DDR_FREQC_100)) {
		lpddr4_dmem_reconfig_667();
		lpddr4_dmem_2d_reconfig_667();
	}
}

void lpddr4_hynix_dmem_reconfig_init(unsigned int freq,
	unsigned int part_number, unsigned int alter_para)
{
	lpddr4_hynix_dmem_reconfig_silicon(part_number, alter_para, freq);

	/* 3733 3200 2666 667 */
	if (freq == DDR_FREQC_3733) {
		lpddr4_dmem_reconfig_3733();
		lpddr4_dmem_2d_reconfig_3733();
	} else if (freq == DDR_FREQC_3200) {
		if (part_number == H9HCNNN8KUMLHR) {
			lpddr4_dmem_reconfig_3200_xh();
			lpddr4_dmem_2d_reconfig_3200_xh();
		} else {
			lpddr4_dmem_reconfig_3200();
			lpddr4_dmem_2d_reconfig_3200();
		}
	} else if (freq == DDR_FREQC_2666) {
		if (part_number == H9HCNNN8KUMLHR) {
			lpddr4_dmem_reconfig_2666_xh();
			lpddr4_dmem_2d_reconfig_2666_xh();
		} else {
			lpddr4_dmem_reconfig_2666();
			lpddr4_dmem_2d_reconfig_2666();
		}
	} else if (freq == DDR_FREQC_667) {
		lpddr4_dmem_reconfig_667();
		lpddr4_dmem_2d_reconfig_667();
	} else if (freq == DDR_FREQC_100) {
		lpddr4_dmem_reconfig_667();
		lpddr4_dmem_2d_reconfig_667();
	}
}

void lpddr4_samsung_dmem_reconfig_init(unsigned int freq,
	unsigned int part_number, unsigned int alter_para)
{
	lpddr4_hynix_dmem_reconfig_silicon(part_number, alter_para, freq);

	/* 3733 3200 2666 667 */
	if (freq == DDR_FREQC_3733) {
		lpddr4_dmem_reconfig_3733();
		lpddr4_dmem_2d_reconfig_3733();
	} else if (freq == DDR_FREQC_3600) {
		lpddr4_dmem_reconfig_3600();
		lpddr4_dmem_2d_reconfig_3600();
	} else if (freq == DDR_FREQC_3200) {
		if (part_number == K4F8E304HBMGCJ || part_number == K4F6E3S4HMMGCJ) {
			lpddr4_dmem_reconfig_3200_xg();
			lpddr4_dmem_2d_reconfig_3200_xg();
		} else {
			lpddr4_dmem_reconfig_3200();
			lpddr4_dmem_2d_reconfig_3200();
		}
	} else if (freq == DDR_FREQC_2666) {
		lpddr4_dmem_reconfig_2666();
		lpddr4_dmem_2d_reconfig_2666();
	} else if (freq == DDR_FREQC_667) {
		lpddr4_dmem_reconfig_667();
		lpddr4_dmem_2d_reconfig_667();
	} else if (freq == DDR_FREQC_100) {
		lpddr4_dmem_reconfig_667();
		lpddr4_dmem_2d_reconfig_667();
	}
}

#ifdef SPL_DDR_PKG
void lpddr4_dmem_write_to_bin(char *file, unsigned int index)
{
	FILE *fp = NULL;
	int dmem1_size = 0, dmem2_size = 0;

	fp = fopen(file, "ab+");
	if (NULL == fp)	{
		printf("File open fail!\n");
		return ;
	}

	dmem1_size = sizeof(phyinit_dmem_lpddr4);
	printf("phyinit dmem lpddr4:  size = %d\n", dmem1_size);
	write_data_to_bin(fp, phyinit_dmem_lpddr4, dmem1_size);

	dmem2_size = sizeof(phyinit_dmem_lpddr4_2D);
	printf("phyinit dmem lpddr4 2D:  size = %d\n", dmem2_size);
	write_data_to_bin(fp, phyinit_dmem_lpddr4_2D, dmem2_size);

	hdr_uart.dmem1.addr = hdr_uart.imem2.addr +
		ALIGN_512(hdr_uart.imem2.size);
	hdr_uart.dmem1.size = dmem1_size;
	hdr_uart.dmem2.addr = hdr_uart.dmem1.addr +
		ALIGN_512(hdr_uart.dmem1.size);
	hdr_uart.dmem2.size = dmem2_size;

	/* lpddr4 micron dmem1/dmem2 */
	hdr_ddr.ddr[index].dmem1.size = dmem1_size;
	hdr_ddr.ddr[index].dmem2.addr = hdr_ddr.ddr[index].dmem1.addr +
		ALIGN_512(hdr_ddr.ddr[index].dmem1.size);
	hdr_ddr.ddr[index].dmem2.size = dmem2_size;

	pclose(fp);
	return;
}
#endif

void ddr_p_dmem_init(void) {
	p_dmem_ddr4_16b = (struct DMEM_DDR4_STRUCT_16B *)phyinit_dmem_ddr4;
	p_dmem_lpddr4_16b = (struct DMEM_LPDDR4_STRUCT_16B *)phyinit_dmem_lpddr4;
	p_dmem_ddr4_2d_16b = (struct DMEM_DDR4_2D_STRUCT_16B *)phyinit_dmem_ddr4_2D;
	p_dmem_lpddr4_2d_16b = (struct DMEM_LPDDR4_2D_STRUCT_16B *)phyinit_dmem_lpddr4_2D;
}
