PSI_DIR  := $(shell cd $(dir $(lastword $(MAKEFILE_LIST))); pwd)

ifneq (1,$(RULES))

include $(PSI_DIR)/src/rules_defs.mk

LIB_TARGETS += $(LIBDIR)/libpsi_impl.a

PSI_IMPL_SRC := $(notdir $(wildcard $(PSI_DIR)/impl/*.cpp))

ifneq ("$(VENDOR)", "")
include $(PSI_DIR)/rules_defs_$(VENDOR).mk
endif

else

psi : $(LIBDIR)/libpsi.a $(LIBDIR)/libpsi_apps.a $(LIBDIR)/libpsi_impl.a $(VENDOR_TARGETS)

$(PSI_BUILDDIR)/impl/%.o : $(PSI_DIR)/impl/%.cpp
	$(Q)if test ! -d $(PSI_BUILDDIR)/impl; then mkdir -p $(PSI_BUILDDIR)/impl; fi
	$(DO_CXX) -I$(PSI_DIR)/impl -I$(PSI_DIR)/src/psi
	
$(LIBDIR)/libpsi_impl.a : $(foreach o,$(PSI_IMPL_SRC:.cpp=.o),$(PSI_BUILDDIR)/impl/$(o))
	$(Q)if test ! -d $(LIBDIR); then mkdir -p $(LIBDIR); fi
	$(MK_AR)

include $(PSI_DIR)/src/rules_defs.mk

endif
