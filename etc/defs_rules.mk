
ifneq (1,$(RULES))
VERSION:=0.4

ifneq (true,$(VERBOSE))
VERBOSE:=false
endif

ifneq (true,$(VEROSE))
Q:=@
endif

endif
