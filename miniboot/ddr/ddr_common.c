


#include "ddr_common.h"


void while_loop (void)
{
	while(1);
}

void reg32_write(unsigned long addr, uint32 val)
{
	writel(val, addr);
}

uint32 reg32_read(unsigned long addr)
{
	return readl(addr);
}

void reg32_bits_clear(unsigned long reg, uint32 value)
{
	uint32 v = readl(reg);
	v &= ~(value);
	writel(v, reg);
}

void reg32_bits_set(unsigned long reg, uint32 value)
{
	uint32 v = readl(reg);
	v |= value;
	writel(v, reg);
}

void reg32_bits_write(unsigned long addr, uint32 start_bit, uint32 bits_num, uint32 val)
{
	uint64 mask;
	uint32 reg32_value;
	mask = (1 << bits_num) - 1;
	reg32_value = reg32_read(addr);
	reg32_value &= ~(mask << start_bit);
	reg32_value |= ((val&mask) << start_bit);
	reg32_write(addr,reg32_value);
}

uint32 reg32_bits_read(unsigned long addr, uint32 start_bit, uint32 bits_num)
{
	uint64 mask;
	uint32 reg32_value, bits_value;
	mask = (1 << bits_num) - 1;
	reg32_value = reg32_read(addr);
	bits_value = (reg32_value >> start_bit) & (mask);
	return bits_value;
}

//void swap(uint32 *x, uint32 *y)
//{
//     uint32 t = *x;
//     *x = *y;
//     *y = t;
//}


