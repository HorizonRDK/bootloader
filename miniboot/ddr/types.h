#ifndef __TYPES_H__
#define __TYPES_H__
/*
 * Very simple but very effective user-space memory tester.
 * Originally by Simon Kirby <sim@stormix.com> <sim@neato.org>
 * Version 2 by Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Version 3 not publicly released.
 * Version 4 rewrite:
 * Copyright (C) 2004-2010 Charles Cazabon <charlesc-memtester@pyropus.ca>
 * Licensed under the terms of the GNU General Public License version 2 (only).
 * See the file COPYING for details.
 *
 * This file contains typedefs, structure, and union definitions.
 *
 */

#include "sizes.h"

typedef unsigned long ul;
typedef unsigned long long ull;
typedef unsigned long volatile ulv;
typedef unsigned char volatile u8v;
typedef unsigned short volatile u16v;
//typedef unsigned long off_t;

struct test {
    char *name;
    int (*fp)(ulv *bufa, ulv *bufb, size_t count);
};

typedef struct ddr_fw_log {
	unsigned int id;
    char *str;
}ddr_fw_log_t;

#endif /* __TYPES_H__ */
