
#ifndef __DDR_COMMON_H__
#define __DDR_COMMON_H__

#ifndef NULL
#define NULL 0
#endif
#define ARRAY_SIZE(x)		(sizeof(x) / sizeof((x)[0]))

#define LIST_END_ADDR 0xFFFFFFFF
#define LIST_END_DATA 0xFFFFFFFF

typedef unsigned long long int uint64;
typedef unsigned int uint32;
typedef unsigned short int uint16;
typedef unsigned char uint8;

typedef signed char int8;


#define __arch_getl(a)          (*(volatile unsigned int *)(a))
#define __arch_putl(v,a)        (*(volatile unsigned int *)(a) = (v))
#define __arch_putq(v,a)		(*(volatile unsigned long long *)(a) = (v))

/*
 * TODO: The kernel offers some more advanced versions of barriers, it might
 * have some advantages to use them instead of the simple one here.
 */
#define ISB asm volatile ("isb sy" : : : "memory")
#define DSB asm volatile ("dsb sy" : : : "memory")
#define DMB asm volatile ("dmb sy" : : : "memory")

#define isb()   ISB
#define dsb()   DSB
#define dmb()   DMB

#define __iormb()   dmb()
#define __iowmb()   dmb()

#define writel(v,c) ({ uint32 __v = v; __iowmb(); __arch_putl(__v,c); __v; })
#define writeq(v,c)	({ uint64 __v = v; __iowmb(); __arch_putq(__v,c); __v; })

#define readl(c)    ({ uint32 __v = __arch_getl(c); __iormb(); __v; })


/*
 * min()/max()/clamp() macros that also do
 * strict type-checking.. See the
 * "unnecessary" pointer comparison.
 */
#define min(x, y) ({				\
	typeof(x) _min1 = (x);			\
	typeof(y) _min2 = (y);			\
	(void) (&_min1 == &_min2);		\
	_min1 < _min2 ? _min1 : _min2; })

#define max(x, y) ({				\
	typeof(x) _max1 = (x);			\
	typeof(y) _max2 = (y);			\
	(void) (&_max1 == &_max2);		\
	_max1 > _max2 ? _max1 : _max2; })

#define min3(x, y, z) min((typeof(x))min(x, y), z)
#define max3(x, y, z) max((typeof(x))max(x, y), z)

#define ABS(x) (((x)>0)? (x) : -(x))

//#define reg32_write(addr, val) writel(val, addr)
//#define reg32_read(addr) readl(addr)
#define SETREG32(x, y) reg32_write(x, y)
#define GETREG32(x) reg32_read(x)

#define	BIT0	(0)
#define	BIT1	(1)
#define	BIT2	(2)
#define	BIT3	(3)
#define	BIT4	(4)
#define	BIT5	(5)
#define	BIT6	(6)
#define	BIT7	(7)
#define	BIT8	(8)
#define	BIT9	(9)
#define	BIT10	(10)
#define	BIT11	(11)
#define	BIT12	(12)
#define	BIT13	(13)
#define	BIT14	(14)
#define	BIT15	(15)
#define	BIT16	(16)
#define	BIT17	(17)
#define	BIT18	(18)
#define	BIT19	(19)
#define	BIT20	(20)
#define	BIT21	(21)
#define	BIT22	(22)
#define	BIT23	(23)
#define	BIT24	(24)
#define	BIT25	(25)
#define	BIT26	(26)
#define	BIT27	(27)
#define	BIT28	(28)
#define	BIT29	(29)
#define	BIT30	(30)
#define	BIT31	(31)

void while_loop (void);

void reg32_write(unsigned long addr, uint32 val);

uint32 reg32_read(unsigned long addr);

void reg32_bits_clear(unsigned long reg, uint32 value);

void reg32_bits_set(unsigned long reg, uint32 value);

void reg32_bits_write(unsigned long addr, uint32 start_bit, uint32 bits_num, uint32 val);

uint32 reg32_bits_read(unsigned long addr, uint32 start_bit, uint32 bits_num);


#endif
