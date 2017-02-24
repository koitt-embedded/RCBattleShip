#######################################################################
#  This makefile runs the test programs for the linear equation routines
#  and the eigenvalue routines in LAPACK.  The test output files
#  are grouped as follows:
#
#       SLINTST,SEIGTST  -- Single precision real test routines
#       CLINTST,CEIGTST  -- Single precision complex test routines
#       DLINTST,DEIGTST  -- Double precision real test routines
#       ZLINTST,ZEIGTST  -- Double precision complex test routines
#
#  Test programs can be executed for all or some of the four different
#  precisions.  Enter 'make' followed by one or more of the data types
#  desired.
#  Some examples:
#       make single
#       make single complex
#       make single double complex complex16
#  Alternatively, the command
#       make
#  without any arguments runs all eight test programs.
#  The executable files are called:
#       xlintsts, xlintstd, xlintstc, and xlintstz for LIN
#       xeigtsts, xeigtstd, xeigtstc, and xeigtstz for EIG
#  and exist in the current directory level.
#
#  To remove the output files after the tests have been run, enter
#       make clean
#
#  To re-run specific tests after a make, enter (for example):
#       'rm ssvd.out; make'  or:
#       'make ssvd.out' or:
#       'touch svd.in; make' (to re-run the single precision SVD tests.)
#
#       'rm *svd.out; make'  (to re-run all the SVD tests.)
#
#######################################################################

TOPDIR=..
include $(TOPDIR)/make.inc

ifneq ($(strip $(VARLIB)),)
    LAPACKLIB :=  $(VARLIB) ../$(LAPACKLIB)
endif


all:     single complex double complex16 singleproto doubleproto complexproto complex16proto

SEIGTST= snep.out \
         ssep.out \
         ssvd.out \
         sec.out \
         sed.out \
         sgg.out \
         sgd.out \
         ssb.out \
	 ssg.out \
         sbal.out \
         sbak.out \
         sgbal.out \
         sgbak.out \
         sbb.out \
         sglm.out \
         sgqr.out \
         sgsv.out \
         slse.out

CEIGTST= cnep.out \
         csep.out \
         csvd.out \
         cec.out \
         ced.out \
         cgg.out \
         cgd.out \
         csb.out \
	 csg.out \
         cbal.out \
         cbak.out \
         cgbal.out \
         cgbak.out \
         cbb.out \
         cglm.out \
         cgqr.out \
         cgsv.out \
         clse.out

DEIGTST= dnep.out \
         dsep.out \
         dsvd.out \
         dec.out \
         ded.out \
         dgg.out \
         dgd.out \
         dsb.out \
	 dsg.out \
         dbal.out \
         dbak.out \
         dgbal.out \
         dgbak.out \
         dbb.out \
         dglm.out \
         dgqr.out \
         dgsv.out \
         dlse.out

ZEIGTST= znep.out \
         zsep.out \
         zsvd.out \
         zec.out \
         zed.out \
         zgg.out \
         zgd.out \
         zsb.out \
	 zsg.out \
         zbal.out \
         zbak.out \
         zgbal.out \
         zgbak.out \
         zbb.out \
         zglm.out \
         zgqr.out \
         zgsv.out \
         zlse.out


SLINTST= stest.out

SLINTSTPROTO= stest_rfp.out

CLINTST= ctest.out

CLINTSTPROTO= ctest_rfp.out

DLINTST= dtest.out

DLINTSTPROTO= dstest.out dtest_rfp.out

ZLINTST= ztest.out

ZLINTSTPROTO= zctest.out ztest_rfp.out

single:         $(SLINTST) $(SEIGTST)
complex:        $(CLINTST) $(CEIGTST)
double:         $(DLINTST) $(DEIGTST)
complex16:      $(ZLINTST) $(ZEIGTST)
singleproto:    $(SLINTSTPROTO)
complexproto:   $(CLINTSTPROTO)
doubleproto:    $(DLINTSTPROTO)
complex16proto: $(ZLINTSTPROTO)

#
# ======== SINGLE LIN TESTS ===========================

stest.out: stest.in xlintsts$(PLAT)
	@echo Testing REAL LAPACK linear equation routines
	./xlintsts$(PLAT) < stest.in > $@ 2>&1
#
# ======== COMPLEX LIN TESTS ==========================

ctest.out: ctest.in xlintstc$(PLAT)
	@echo Testing COMPLEX LAPACK linear equation routines
	./xlintstc$(PLAT) < ctest.in > $@ 2>&1
#
# ======== DOUBLE LIN TESTS ===========================

dtest.out: dtest.in xlintstd$(PLAT)
	@echo Testing DOUBLE PRECISION LAPACK linear equation routines
	./xlintstd$(PLAT) < dtest.in > $@ 2>&1
#
# ======== COMPLEX16 LIN TESTS ========================

ztest.out: ztest.in xlintstz$(PLAT)
	@echo Testing COMPLEX16 LAPACK linear equation routines
	./xlintstz$(PLAT) < ztest.in > $@ 2>&1
#
# ======== SINGLE-DOUBLE PROTO LIN TESTS ==============

dstest.out: dstest.in xlintstds$(PLAT)
	@echo Testing SINGLE-DOUBLE PRECISION LAPACK prototype linear equation routines
	./xlintstds$(PLAT) < dstest.in > $@ 2>&1
#
# ======== COMPLEX-COMPLEX16 LIN TESTS ========================

zctest.out: zctest.in xlintstzc$(PLAT)
	@echo Testing COMPLEX-COMPLEX16 LAPACK protoype linear equation routines
	./xlintstzc$(PLAT) < zctest.in > $@ 2>&1
#
# ======== SINGLE RFP LIN TESTS ========================

stest_rfp.out: stest_rfp.in xlintstrfs$(PLAT)
	@echo Testing REAL LAPACK RFP protoype linear equation routines
	./xlintstrfs$(PLAT) < stest_rfp.in > $@ 2>&1
#
# ======== COMPLEX16 RFP LIN TESTS ========================

dtest_rfp.out: dtest_rfp.in xlintstrfd$(PLAT)
	@echo Testing DOUBLE PRECISION LAPACK RFP protoype linear equation routines
	./xlintstrfd$(PLAT) < dtest_rfp.in > $@ 2>&1
#
# ======== COMPLEX16 RFP LIN TESTS ========================

ctest_rfp.out: ctest_rfp.in xlintstrfc$(PLAT)
	@echo Testing COMPLEX LAPACK RFP protoype linear equation routines
	./xlintstrfc$(PLAT) < ctest_rfp.in > $@ 2>&1
#
# ======== COMPLEX16 RFP LIN TESTS ========================

ztest_rfp.out: ztest_rfp.in xlintstrfz$(PLAT)
	@echo Testing COMPLEX16 LAPACK RFP protoype linear equation routines
	./xlintstrfz$(PLAT) < ztest_rfp.in > $@ 2>&1
#
#
# ======== SINGLE EIG TESTS ===========================
#

snep.out: nep.in xeigtsts$(PLAT)
	@echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
	./xeigtsts$(PLAT) < nep.in > $@ 2>&1

ssep.out: sep.in xeigtsts$(PLAT)
	@echo SEP: Testing Symmetric Eigenvalue Problem routines
	./xeigtsts$(PLAT) < sep.in > $@ 2>&1

ssvd.out: svd.in xeigtsts$(PLAT)
	@echo SVD: Testing Singular Value Decomposition routines
	./xeigtsts$(PLAT) < svd.in > $@ 2>&1

sec.out: sec.in xeigtsts$(PLAT)
	@echo SEC: Testing REAL Eigen Condition Routines
	./xeigtsts$(PLAT) < sec.in > $@ 2>&1

sed.out: sed.in xeigtsts$(PLAT)
	@echo SEV: Testing REAL Nonsymmetric Eigenvalue Driver
	./xeigtsts$(PLAT) < sed.in > $@ 2>&1

sgg.out: sgg.in xeigtsts$(PLAT)
	@echo SGG: Testing REAL Nonsymmetric Generalized Eigenvalue Problem routines
	./xeigtsts$(PLAT) < sgg.in > $@ 2>&1

sgd.out: sgd.in xeigtsts$(PLAT)
	@echo SGD: Testing REAL Nonsymmetric Generalized Eigenvalue Problem driver routines
	./xeigtsts$(PLAT) < sgd.in > $@ 2>&1

ssb.out: ssb.in xeigtsts$(PLAT)
	@echo SSB: Testing REAL Symmetric Eigenvalue Problem routines
	./xeigtsts$(PLAT) < ssb.in > $@ 2>&1

ssg.out: ssg.in xeigtsts$(PLAT)
	@echo SSG: Testing REAL Symmetric Generalized Eigenvalue Problem routines
	./xeigtsts$(PLAT) < ssg.in > $@ 2>&1

sbal.out: sbal.in xeigtsts$(PLAT)
	@echo SGEBAL: Testing the balancing of a REAL general matrix
	./xeigtsts$(PLAT) < sbal.in > $@ 2>&1

sbak.out: sbak.in xeigtsts$(PLAT)
	@echo SGEBAK: Testing the back transformation of a REAL balanced matrix
	./xeigtsts$(PLAT) < sbak.in > $@ 2>&1

sgbal.out: sgbal.in xeigtsts$(PLAT)
	@echo SGGBAL: Testing the balancing of a pair of REAL general matrices
	./xeigtsts$(PLAT) < sgbal.in > $@ 2>&1

sgbak.out: sgbak.in xeigtsts$(PLAT)
	@echo SGGBAK: Testing the back transformation of a pair of REAL balanced matrices
	./xeigtsts$(PLAT) < sgbak.in > $@ 2>&1

sbb.out: sbb.in xeigtsts$(PLAT)
	@echo SBB:  Testing banded Singular Value Decomposition routines
	./xeigtsts$(PLAT) < sbb.in > $@ 2>&1

sglm.out: glm.in xeigtsts$(PLAT)
	@echo GLM: Testing Generalized Linear Regression Model routines
	./xeigtsts$(PLAT) < glm.in > $@ 2>&1

sgqr.out: gqr.in xeigtsts$(PLAT)
	@echo GQR: Testing Generalized QR and RQ factorization routines
	./xeigtsts$(PLAT) < gqr.in > $@ 2>&1

sgsv.out: gsv.in xeigtsts$(PLAT)
	@echo GSV: Testing Generalized Singular Value Decomposition routines
	./xeigtsts$(PLAT) < gsv.in > $@ 2>&1

slse.out: lse.in xeigtsts$(PLAT)
	@echo LSE: Testing Constrained Linear Least Squares routines
	./xeigtsts$(PLAT) < lse.in > $@ 2>&1
#
# ======== COMPLEX EIG TESTS ===========================

cnep.out: nep.in xeigtstc$(PLAT)
	@echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
	./xeigtstc$(PLAT) < nep.in > $@ 2>&1

csep.out: sep.in xeigtstc$(PLAT)
	@echo SEP: Testing Symmetric Eigenvalue Problem routines
	./xeigtstc$(PLAT) < sep.in > $@ 2>&1

csvd.out: svd.in xeigtstc$(PLAT)
	@echo SVD: Testing Singular Value Decomposition routines
	./xeigtstc$(PLAT) < svd.in > $@ 2>&1

cec.out: cec.in xeigtstc$(PLAT)
	@echo CEC: Testing COMPLEX Eigen Condition Routines
	./xeigtstc$(PLAT) < cec.in > $@ 2>&1

ced.out: ced.in xeigtstc$(PLAT)
	@echo CES: Testing COMPLEX Nonsymmetric Schur Form Driver
	./xeigtstc$(PLAT) < ced.in > $@ 2>&1

cgg.out: cgg.in xeigtstc$(PLAT)
	@echo CGG: Testing COMPLEX Nonsymmetric Generalized Eigenvalue Problem routines
	./xeigtstc$(PLAT) < cgg.in > $@ 2>&1

cgd.out: cgd.in xeigtstc$(PLAT)
	@echo CGD: Testing COMPLEX Nonsymmetric Generalized Eigenvalue Problem driver routines
	./xeigtstc$(PLAT) < cgd.in > $@ 2>&1

csb.out: csb.in xeigtstc$(PLAT)
	@echo CHB: Testing Hermitian Eigenvalue Problem routines
	./xeigtstc$(PLAT) < csb.in > $@ 2>&1

csg.out: csg.in xeigtstc$(PLAT)
	@echo CSG: Testing Symmetric Generalized Eigenvalue Problem routines
	./xeigtstc$(PLAT) < csg.in > $@ 2>&1

cbal.out: cbal.in xeigtstc$(PLAT)
	@echo CGEBAL: Testing the balancing of a COMPLEX general matrix
	./xeigtstc$(PLAT) < cbal.in > $@ 2>&1

cbak.out: cbak.in xeigtstc$(PLAT)
	@echo CGEBAK: Testing the back transformation of a COMPLEX balanced matrix
	./xeigtstc$(PLAT) < cbak.in > $@ 2>&1

cgbal.out: cgbal.in xeigtstc$(PLAT)
	@echo CGGBAL: Testing the balancing of a pair of COMPLEX general matrices
	./xeigtstc$(PLAT) < cgbal.in > $@ 2>&1

cgbak.out: cgbak.in xeigtstc$(PLAT)
	@echo CGGBAK: Testing the back transformation of a pair of COMPLEX balanced matrices
	./xeigtstc$(PLAT) < cgbak.in > $@ 2>&1

cbb.out: cbb.in xeigtstc$(PLAT)
	@echo CBB:  Testing banded Singular Value Decomposition routines
	./xeigtstc$(PLAT) < cbb.in > $@ 2>&1

cglm.out: glm.in xeigtstc$(PLAT)
	@echo GLM: Testing Generalized Linear Regression Model routines
	./xeigtstc$(PLAT) < glm.in > $@ 2>&1

cgqr.out: gqr.in xeigtstc$(PLAT)
	@echo GQR: Testing Generalized QR and RQ factorization routines
	./xeigtstc$(PLAT) < gqr.in > $@ 2>&1

cgsv.out: gsv.in xeigtstc$(PLAT)
	@echo GSV: Testing Generalized Singular Value Decomposition routines
	./xeigtstc$(PLAT) < gsv.in > $@ 2>&1

clse.out: lse.in xeigtstc$(PLAT)
	@echo LSE: Testing Constrained Linear Least Squares routines
	./xeigtstc$(PLAT) < lse.in > $@ 2>&1
#
# ======== DOUBLE EIG TESTS ===========================

dnep.out: nep.in xeigtstd$(PLAT)
	@echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
	./xeigtstd$(PLAT) < nep.in > $@ 2>&1

dsep.out: sep.in xeigtstd$(PLAT)
	@echo SEP: Testing Symmetric Eigenvalue Problem routines
	./xeigtstd$(PLAT) < sep.in > $@ 2>&1

dsvd.out: svd.in xeigtstd$(PLAT)
	@echo SVD: Testing Singular Value Decomposition routines
	./xeigtstd$(PLAT) < svd.in > $@ 2>&1

dec.out: dec.in xeigtstd$(PLAT)
	@echo DEC: Testing DOUBLE PRECISION Eigen Condition Routines
	./xeigtstd$(PLAT) < dec.in > $@ 2>&1

ded.out: ded.in xeigtstd$(PLAT)
	@echo DEV: Testing DOUBLE PRECISION Nonsymmetric Eigenvalue Driver
	./xeigtstd$(PLAT) < ded.in > $@ 2>&1

dgg.out: dgg.in xeigtstd$(PLAT)
	@echo DGG: Testing DOUBLE PRECISION Nonsymmetric Generalized Eigenvalue Problem routines
	./xeigtstd$(PLAT) < dgg.in > $@ 2>&1

dgd.out: dgd.in xeigtstd$(PLAT)
	@echo DGD: Testing DOUBLE PRECISION Nonsymmetric Generalized Eigenvalue Problem driver routines
	./xeigtstd$(PLAT) < dgd.in > $@ 2>&1

dsb.out: dsb.in xeigtstd$(PLAT)
	@echo DSB: Testing DOUBLE PRECISION Symmetric Eigenvalue Problem routines
	./xeigtstd$(PLAT) < dsb.in > $@ 2>&1

dsg.out: dsg.in xeigtstd$(PLAT)
	@echo DSG: Testing DOUBLE PRECISION Symmetric Generalized Eigenvalue Problem routines
	./xeigtstd$(PLAT) < dsg.in > $@ 2>&1

dbal.out: dbal.in xeigtstd$(PLAT)
	@echo DGEBAL: Testing the balancing of a DOUBLE PRECISION general matrix
	./xeigtstd$(PLAT) < dbal.in > $@ 2>&1

dbak.out: dbak.in xeigtstd$(PLAT)
	@echo DGEBAK:  Testing the back transformation of a DOUBLE PRECISION balanced matrix
	./xeigtstd$(PLAT) < dbak.in > $@ 2>&1

dgbal.out: dgbal.in xeigtstd$(PLAT)
	@echo DGGBAL: Testing the balancing of a pair of DOUBLE PRECISION general matrices
	./xeigtstd$(PLAT) < dgbal.in > $@ 2>&1

dgbak.out: dgbak.in xeigtstd$(PLAT)
	@echo DGGBAK: Testing the back transformation of a pair of DOUBLE PRECISION balanced matrices
	./xeigtstd$(PLAT) < dgbak.in > $@ 2>&1

dbb.out: dbb.in xeigtstd$(PLAT)
	@echo DBB:  Testing banded Singular Value Decomposition routines
	./xeigtstd$(PLAT) < dbb.in > $@ 2>&1

dglm.out: glm.in xeigtstd$(PLAT)
	@echo GLM: Testing Generalized Linear Regression Model routines
	./xeigtstd$(PLAT) < glm.in > $@ 2>&1

dgqr.out: gqr.in xeigtstd$(PLAT)
	@echo GQR: Testing Generalized QR and RQ factorization routines
	./xeigtstd$(PLAT) < gqr.in > $@ 2>&1

dgsv.out: gsv.in xeigtstd$(PLAT)
	@echo GSV: Testing Generalized Singular Value Decomposition routines
	./xeigtstd$(PLAT) < gsv.in > $@ 2>&1

dlse.out: lse.in xeigtstd$(PLAT)
	@echo LSE: Testing Constrained Linear Least Squares routines
	./xeigtstd$(PLAT) < lse.in > $@ 2>&1
#
# ======== COMPLEX16 EIG TESTS ===========================

znep.out: nep.in xeigtstz$(PLAT)
	@echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
	./xeigtstz$(PLAT) < nep.in > $@ 2>&1

zsep.out: sep.in xeigtstz$(PLAT)
	@echo SEP: Testing Symmetric Eigenvalue Problem routines
	./xeigtstz$(PLAT) < sep.in > $@ 2>&1

zsvd.out: svd.in xeigtstz$(PLAT)
	@echo SVD: Testing Singular Value Decomposition routines
	./xeigtstz$(PLAT) < svd.in > $@ 2>&1

zec.out: zec.in xeigtstz$(PLAT)
	@echo ZEC: Testing COMPLEX16 Eigen Condition Routines
	./xeigtstz$(PLAT) < zec.in > $@ 2>&1

zed.out: zed.in xeigtstz$(PLAT)
	@echo ZES: Testing COMPLEX16 Nonsymmetric Schur Form Driver
	./xeigtstz$(PLAT) < zed.in > $@ 2>&1

zgg.out: zgg.in xeigtstz$(PLAT)
	@echo ZGG: Testing COMPLEX16 Nonsymmetric Generalized Eigenvalue Problem routines
	./xeigtstz$(PLAT) < zgg.in > $@ 2>&1

zgd.out: zgd.in xeigtstz$(PLAT)
	@echo ZGD: Testing COMPLEX16 Nonsymmetric Generalized Eigenvalue Problem driver routines
	./xeigtstz$(PLAT) < zgd.in > $@ 2>&1

zsb.out: zsb.in xeigtstz$(PLAT)
	@echo ZHB: Testing Hermitian Eigenvalue Problem routines
	./xeigtstz$(PLAT) < zsb.in > $@ 2>&1

zsg.out: zsg.in xeigtstz$(PLAT)
	@echo ZSG: Testing Symmetric Generalized Eigenvalue Problem routines
	./xeigtstz$(PLAT) < zsg.in > $@ 2>&1

zbal.out: zbal.in xeigtstz$(PLAT)
	@echo ZGEBAL: Testing the balancing of a COMPLEX16 general matrix
	./xeigtstz$(PLAT) < zbal.in > $@ 2>&1

zbak.out: zbak.in xeigtstz$(PLAT)
	@echo ZGEBAK: Testing the back transformation of a COMPLEX16 balanced matrix
	./xeigtstz$(PLAT) < zbak.in > $@ 2>&1

zgbal.out: zgbal.in xeigtstz$(PLAT)
	@echo ZGGBAL: Testing the balancing of a pair of COMPLEX general matrices
	./xeigtstz$(PLAT) < zgbal.in > $@ 2>&1

zgbak.out: zgbak.in xeigtstz$(PLAT)
	@echo ZGGBAK: Testing the back transformation of a pair of COMPLEX16 balanced matrices
	./xeigtstz$(PLAT) < zgbak.in > $@ 2>&1

zbb.out: zbb.in xeigtstz$(PLAT)
	@echo ZBB: Testing banded Singular Value Decomposition routines
	./xeigtstz$(PLAT) < zbb.in > $@ 2>&1

zglm.out: glm.in xeigtstz$(PLAT)
	@echo GLM: Testing Generalized Linear Regression Model routines
	./xeigtstz$(PLAT) < glm.in > $@ 2>&1

zgqr.out: gqr.in xeigtstz$(PLAT)
	@echo GQR: Testing Generalized QR and RQ factorization routines
	./xeigtstz$(PLAT) < gqr.in > $@ 2>&1

zgsv.out: gsv.in xeigtstz$(PLAT)
	@echo GSV: Testing Generalized Singular Value Decomposition routines
	./xeigtstz$(PLAT) < gsv.in > $@ 2>&1

zlse.out: lse.in xeigtstz$(PLAT)
	@echo LSE: Testing Constrained Linear Least Squares routines
	./xeigtstz$(PLAT) < lse.in > $@ 2>&1
# ==============================================================================

xlintsts$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) single

xlintstc$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) complex

xlintstd$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) double

xlintstz$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) complex16

xlintstrfs$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) proto-single

xlintstrfc$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) proto-complex

xlintstrfd$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) proto-double

xlintstrfz$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) proto-complex16

xlintstds$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) proto-double

xlintstzc$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCLIN) $(FRC)
	cd LIN ; $(MAKE) proto-complex16

xeigtsts$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCEIG) $(FRC)
	cd EIG ; $(MAKE) single

xeigtstc$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCEIG) $(FRC)
	cd EIG ; $(MAKE) complex

xeigtstd$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCEIG) $(FRC)
	cd EIG ; $(MAKE) double

xeigtstz$(PLAT):	../$(LAPACKLIB) ../$(TMGLIB) $(FRCEIG) $(FRC)
	cd EIG ; $(MAKE) complex16

clean:
	rm -f *.out core

cleanup:
	rm -f x* *.out core

FRCLIN:
	@FRCLIN=$(FRCLIN)

FRCEIG:
	@FRCEIG=$(FRCEIG)

FRC:
	@FRC=$(FRC)
