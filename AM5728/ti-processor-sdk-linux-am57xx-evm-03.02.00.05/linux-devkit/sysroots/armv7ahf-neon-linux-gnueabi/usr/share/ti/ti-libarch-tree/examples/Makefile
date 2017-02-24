.PHONY: clean all


ifeq ($(LIBOS), LIB_OPENCL)
examp_dir = arm+dsp
else
examp_dir = dsponly
endif

all: 
	cd $(examp_dir); make TARGET=$(TARGET) LIBOS=$(LIBOS)

clean:
	cd arm+dsp; make clean; cd ../dsp-only; make clean;

