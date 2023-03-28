
ifdef CONFIG_SPL_BUILD

obj-$(CONFIG_SPL_BUILD) += clock.o ddr_common.o lpddr4_timing.o \
                           ddr4_timing.o dwc_ddrphy_init.o x3_ddr_init.o \
                           tests.o debug_tool.o ddr_retention.o \
                           ddr_perf.o ddrc_misc.o ddr_auto_detect.o

obj-$(CONFIG_SPL_BUILD) += hb_imem_parameter.o hb_dmem_parameter.o hb_ddrc_parameter.o \
                           hb_ddrp_parameter.o hb_pie_parameter.o hb_addrmap_parameter.o

# obj-$(CONFIG_SPL_BUILD) += ddr_phy_reg_dump.o ddr_umctl2_reg_dump.o
# obj-$(CONFIG_SPL_BUILD) += lpddr4_init.o lpddr4_timing.o clock.o

# obj-$(CONFIG_SPL_BUILD) += lpddr4_ate.o clock.o
else

obj-y += x3.o

endif

