#include <common.h>
#include <sata.h>
#include <ahci.h>
#include <scsi.h>
#include <malloc.h>
#include <asm/io.h>

#include <asm/armv8/mmu.h>
#include <asm/arch/x2_reg.h>

DECLARE_GLOBAL_DATA_PTR;

static struct mm_region x2_mem_map[] = {
	{
		/* SDRAM space */
		.virt = 0x0UL,
		.phys = 0x0UL,
		.size = CONFIG_SYS_SDRAM_SIZE,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	},
	{
		/* SRAM space */
		.virt = 0x80000000UL,
		.phys = 0x80000000UL,
		.size = 0x200000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	},
	{
		/* GIC space */
		.virt = 0x90000000UL,
		.phys = 0x90000000UL,
		.size = 0x40000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	},{
		/* List terminator */
		0,
	}
};

struct mm_region *mem_map = x2_mem_map;

int dram_init(void)
{
	gd->ram_size = CONFIG_SYS_SDRAM_SIZE;
	return 0;
}

int board_init(void)
{
	return 0;
}

int timer_init(void)
{
	writel(0x1, PMU_SYSCNT_BASE);
	return 0;
}

int board_late_init(void)
{
#if 0
	qspi_flash_init();
#endif

#ifdef CONFIG_DDR_BOOT
	env_set("bootmode", "ddrboot");
#endif

#ifdef CONFIG_SD_BOOT
	env_set("bootmode", "sdboot");
#endif

#ifdef CONFIG_QSPI_BOOT
	env_set("bootmode", "qspiboot");
#endif
	return 0;
}
