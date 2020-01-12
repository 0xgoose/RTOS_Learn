BUILDTARGET = libkernel.a

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPEND)
endif

all: $(BUILDTARGET) size

test: $(BUILDTARGET) 
    @$(MAKE) --no-print-directory -C test

testrun: test
    @$(MAKE) --no-print-directory -C testrun
