
ifneq (1,$(RULES))

PSI_SRC_DIR := $(shell cd $(dir $(lastword $(MAKEFILE_LIST))); pwd)
PSI_BUILDDIR := $(BUILDDIR)/psi

LIBXML_VERSION:=2.9.3
LIBXML_SRC:=$(PKGS_SRCDIR)/libxml2-sources-$(LIBXML_VERSION).tar.gz
LIBXML_URL:=ftp://xmlsoft.org/libxml2/libxml2-sources-$(LIBXML_VERSION).tar.gz

PSS_SCHEMA_O=PSSModelXsd.o

# ifeq (Cygwin,$(UNAME_O))
# PSI_SRC_DIR := $(shell cygpath -w $(PSI_SRC_DIR) | sed -e 's^\\^/^g')
# endif

LIB_TARGETS += $(LIBDIR)/libpsi.a $(LIBDIR)/libpsi_apps.a

PSI_API_HEADERS := $(notdir $(wildcard $(PSI_SRC_DIR)/psi/api/*.h))
PSI_CL_HEADERS := $(notdir $(wildcard $(PSI_SRC_DIR)/psi/classlib/*.h))
PSI_APPS_HEADERS := $(notdir $(wildcard $(PSI_SRC_DIR)/apps/*.h))

PSI_CL_SRC := $(notdir $(wildcard $(PSI_SRC_DIR)/psi/classlib/*.cpp))
PSI_APPS_SRC += $(notdir $(wildcard $(PSI_SRC_DIR)/apps/*.cpp))
PSI_APPS_SRC += PSSModel.cpp

INST_TARGETS += $(foreach h,$(PSI_API_HEADERS),$(INCDIR)/api/$(h))
INST_TARGETS += $(foreach h,$(PSI_APPS_HEADERS),$(INCDIR)/apps/$(h))
INST_TARGETS += $(INCDIR)/psi.h $(INCDIR)/psi_api.h

else

$(BUILDDIR)/libxml2.build : $(LIBXML_SRC)
	$(Q)if test ! -d $(BUILDDIR); then mkdir -p $(BUILDDIR); fi
	$(Q)cd $(BUILDDIR) ; rm -rf build_libxml2 ; mkdir build_libxml2
	$(Q)cd $(BUILDDIR)/build_libxml2; tar xvf $^
	$(Q)cd $(BUILDDIR)/build_libxml2; `pwd`/libxml2-$(LIBXML_VERSION)/configure \
	    --prefix=`pwd`/inst --disable-shared
	$(Q)cd $(BUILDDIR)/build_libxml2; $(MAKE) ; $(MAKE) install
	$(Q)touch $@

$(LIBXML_SRC) : 
	$(Q)if test ! -d `dirname $@`; then mkdir -p `dirname $@`; fi
	$(Q)cd `dirname $@`; wget --no-check-certificate $(LIBXML_URL)

$(INCDIR)/api/%.h : $(PSI_SRC_DIR)/psi/api/%.h
	$(DO_INST)
	
$(INCDIR)/apps/%.h : $(PSI_SRC_DIR)/apps/%.h
	$(DO_INST)

$(INCDIR)/%.h : $(PSI_SRC_DIR)/psi/%.h
	$(DO_INST)

$(LIBDIR)/libpsi.a : $(foreach o,$(PSI_CL_SRC:.cpp=.o),$(PSI_BUILDDIR)/classlib/$(o))
	$(MKDIRS)
	$(MK_AR)

$(PSI_BUILDDIR)/classlib/%.o : $(PSI_SRC_DIR)/psi/classlib/%.cpp
	$(Q)if test ! -d $(PSI_BUILDDIR)/classlib; then mkdir -p $(PSI_BUILDDIR)/classlib; fi
	$(DO_CXX) -I$(PSI_SRC_DIR)/psi 
	
#$(PSI_BUILDDIR)/%.o : $(PSI_BUILDDIR)/%.cpp
#	$(Q)if test ! -d $(PSI_BUILDDIR); then mkdir -p $(PSI_BUILDDIR); fi	
#	$(DO_CXX) -I$(PSI_SRC_DIR)/psi 

$(PSI_BUILDDIR)/apps/PSSModel.cpp :
	$(Q)cat $(PSI_SRC_DIR)/../schema/PSSModel.xsd | perl $(PSI_SRC_DIR)/../scripts/stringify.pl $(basename $(notdir $(PSI_SRC_DIR)/../schema/PSSModel.xsd)) > $@
	
$(LIBDIR)/libpsi_apps.a : $(foreach o,$(PSI_APPS_SRC:.cpp=.o),$(PSI_BUILDDIR)/apps/$(o))
	$(MKDIRS)
	$(MK_AR)

$(PSI_BUILDDIR)/apps/%.o : $(PSI_SRC_DIR)/apps/%.cpp
	$(Q)if test ! -d $(PSI_BUILDDIR)/apps; then mkdir -p $(PSI_BUILDDIR)/apps; fi
	$(DO_CXX) -I$(PSI_SRC_DIR)/psi -I$(PSI_SRC_DIR)/apps 

endif
