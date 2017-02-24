#
#  Top Level Makefile for LAPACK
#  Version 3.2.1
#  June 2009
#

include make.inc

all: f2clib lapack_install lib lapack_testing blas_testing
#all: f2clib lapack_install lib lapack_testing blas_testing variants_testing

#lib: lapacklib tmglib
#lib: f2clib lapacklib tmglib
lib: f2clib variants lapacklib tmglib

clean: cleanlib cleantesting cleanblas_testing 

lapack_install:
	( cd INSTALL; $(MAKE); ./testlsame; ./testslamch; \
	  ./testdlamch; ./testsecond; ./testdsecnd; ./testversion )

blaslib:
	( cd BLAS/SRC; $(MAKE) )

cblaswrap: 
	( cd BLAS/WRAP; $(MAKE) libcblaswr$(PLAT).a; cp libcblaswr$(PLAT).a ../.. )

fblaswrap: 
	( cd BLAS/WRAP; $(MAKE) libfblaswr$(PLAT).a; cp libfblaswr$(PLAT).a ../.. )

lapacklib:	lapack_install
	( cd SRC; $(MAKE) )

variants:
	( cd SRC/VARIANTS ; $(MAKE))
	
tmglib:
	( cd TESTING/MATGEN; $(MAKE) )

f2clib:
	    ( cd F2CLIBS/libf2c; $(MAKE) )

lapack_testing:	f2clib lapacklib tmglib
	( cd TESTING ; $(MAKE) )

variants_testing: lib
	( cd TESTING ; rm -f xlintst* ; $(MAKE)  VARLIB='SRC/VARIANTS/LIB/cholrl.a' ; \
	mv stest.out stest_cholrl.out ; mv dtest.out dtest_cholrl.out ; mv ctest.out ctest_cholrl.out ; mv ztest.out ztest_cholrl.out )
	( cd TESTING ; rm -f xlintst* ; $(MAKE)  VARLIB='SRC/VARIANTS/LIB/choltop.a' ; \
	mv stest.out stest_choltop.out ; mv dtest.out dtest_choltop.out ; mv ctest.out ctest_choltop.out ; mv ztest.out ztest_choltop.out )
	( cd TESTING ; rm -f xlintst* ; $(MAKE)  VARLIB='SRC/VARIANTS/LIB/lucr.a' ; \
	mv stest.out stest_lucr.out ; mv dtest.out dtest_lucr.out ; mv ctest.out ctest_lucr.out ; mv ztest.out ztest_lucr.out )
	( cd TESTING ;  rm -f xlintst* ; $(MAKE)  VARLIB='SRC/VARIANTS/LIB/lull.a' ; \
	mv stest.out stest_lull.out ; mv dtest.out dtest_lull.out ; mv ctest.out ctest_lull.out ; mv ztest.out ztest_lull.out )
	( cd TESTING ;  rm -f xlintst* ; $(MAKE)  VARLIB='SRC/VARIANTS/LIB/lurec.a' ; \
	mv stest.out stest_lurec.out ; mv dtest.out dtest_lurec.out ; mv ctest.out ctest_lurec.out ; mv ztest.out ztest_lurec.out )
	( cd TESTING ;  rm -f xlintst* ; $(MAKE)  VARLIB='SRC/VARIANTS/LIB/qrll.a' ; \
	mv stest.out stest_qrll.out ; mv dtest.out dtest_qrll.out ; mv ctest.out ctest_qrll.out ; mv ztest.out ztest_qrll.out )
		
blas_testing:
	( cd BLAS/TESTING; $(MAKE) -f Makeblat1 )
	( cd BLAS; ./xblat1s$(PLAT) > sblat1.out    ; \
	           ./xblat1d$(PLAT) > dblat1.out    ; \
	           ./xblat1c$(PLAT) > cblat1.out    ; \
	           ./xblat1z$(PLAT) > zblat1.out    ) 
	( cd BLAS/TESTING; $(MAKE) -f Makeblat2 )
	( cd BLAS; ./xblat2s$(PLAT) < sblat2.in     ; \
	           ./xblat2d$(PLAT) < dblat2.in     ; \
	           ./xblat2c$(PLAT) < cblat2.in     ; \
	           ./xblat2z$(PLAT) < zblat2.in     )
	( cd BLAS/TESTING; $(MAKE) -f Makeblat3 )
	( cd BLAS; ./xblat3s$(PLAT) < sblat3.in     ; \
	           ./xblat3d$(PLAT) < dblat3.in     ; \
	           ./xblat3c$(PLAT) < cblat3.in     ; \
	           ./xblat3z$(PLAT) < zblat3.in     ) 

cleanlib:
	( cd INSTALL; $(MAKE) clean )
	( cd BLAS/SRC; $(MAKE) clean )
	( cd SRC; $(MAKE) clean )
	( cd SRC/VARIANTS; $(MAKE) clean )
	( cd TESTING/MATGEN; $(MAKE) clean )
	( cd F2CLIBS/libf2c; $(MAKE) clean )
	( cd F2CLIBS; rm -f *$(PLAT).a)

cleanblas_testing:	
	( cd BLAS/TESTING; $(MAKE) -f Makeblat1 clean )
	( cd BLAS/TESTING; $(MAKE) -f Makeblat2 clean )
	( cd BLAS/TESTING; $(MAKE) -f Makeblat3 clean )
	( cd BLAS; rm -f xblat* )

cleantesting:
	( cd TESTING/LIN; $(MAKE) clean )
	( cd TESTING/EIG; $(MAKE) clean )
	( cd TESTING; rm -f xlin* xeig* )

cleanall: cleanlib cleanblas_testing cleantesting 
	rm -f *$(PLAT).a TESTING/*.out INSTALL/test*  BLAS/*.out BLAS/WRAP/*.o BLAS/WRAP/*$(PLAT).a
	
cleanobjs: 
	( cd F2CLIBS/libf2c; rm -f  *.o )
	( cd BLAS/WRAP; rm -f *.o )
	( cd SRC; rm -f *.o ) 
	( cd TESTING/MATGEN; rm -f *.o )
	( cd TESTING/LIN; rm -f *.o )
	( cd TESTING/EIG; rm -f *.o )
	( cd INSTALL; $(MAKE) clean )
	( cd BLAS/TESTING; $(MAKE) -f Makeblat1 clean )
	( cd BLAS/TESTING; $(MAKE) -f Makeblat2 clean )
	( cd BLAS/TESTING; $(MAKE) -f Makeblat3 clean )
	rm -f TESTING/*.out INSTALL/test*  BLAS/*.out 
