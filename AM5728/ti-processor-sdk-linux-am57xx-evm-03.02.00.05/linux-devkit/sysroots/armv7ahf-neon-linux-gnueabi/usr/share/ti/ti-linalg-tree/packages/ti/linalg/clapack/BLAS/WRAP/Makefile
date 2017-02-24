TOPDIR=../..
include $(TOPDIR)/make.inc

#######################################################################
#  This is the makefile to create a wrapper for the CBLAS.
#######################################################################

all: libcblaswr$(PLAT).a

libcblaswr$(PLAT).a: cblaswr.o
	$(ARCH) $(ARCHFLAGS) libcblaswr$(PLAT).a cblaswr.o
	$(RANLIB) libcblaswr$(PLAT).a
	
libfblaswr$(PLAT).a: fblaswr$(PLAT).o
	$(ARCH) $(ARCHFLAGS) libfblaswr$(PLAT).a fblaswr.o
	$(RANLIB) libfblaswr$(PLAT).a

clean:
	rm -f *.o *$(PLAT).a

.c.o: 
	$(CC) $(CFLAGS) -c $*.c

