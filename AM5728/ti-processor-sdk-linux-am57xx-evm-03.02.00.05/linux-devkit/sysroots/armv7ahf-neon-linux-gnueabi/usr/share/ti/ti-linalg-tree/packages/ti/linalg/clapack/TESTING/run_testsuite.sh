#!/bin/bash

echo Testing REAL LAPACK linear equation routines
./xlintsts_ARM < stest.in > stest.out 2>&1
echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
./xeigtsts_ARM < nep.in > snep.out 2>&1
echo SEP: Testing Symmetric Eigenvalue Problem routines
./xeigtsts_ARM < sep.in > ssep.out 2>&1
echo SVD: Testing Singular Value Decomposition routines
./xeigtsts_ARM < svd.in > ssvd.out 2>&1
echo SEC: Testing REAL Eigen Condition Routines
./xeigtsts_ARM < sec.in > sec.out 2>&1
echo SEV: Testing REAL Nonsymmetric Eigenvalue Driver
./xeigtsts_ARM < sed.in > sed.out 2>&1
echo SGG: Testing REAL Nonsymmetric Generalized Eigenvalue Problem routines
./xeigtsts_ARM < sgg.in > sgg.out 2>&1
echo SGD: Testing REAL Nonsymmetric Generalized Eigenvalue Problem driver routines
./xeigtsts_ARM < sgd.in > sgd.out 2>&1
echo SSB: Testing REAL Symmetric Eigenvalue Problem routines
./xeigtsts_ARM < ssb.in > ssb.out 2>&1
echo SSG: Testing REAL Symmetric Generalized Eigenvalue Problem routines
./xeigtsts_ARM < ssg.in > ssg.out 2>&1
echo SGEBAL: Testing the balancing of a REAL general matrix
./xeigtsts_ARM < sbal.in > sbal.out 2>&1
echo SGEBAK: Testing the back transformation of a REAL balanced matrix
./xeigtsts_ARM < sbak.in > sbak.out 2>&1
echo SGGBAL: Testing the balancing of a pair of REAL general matrices
./xeigtsts_ARM < sgbal.in > sgbal.out 2>&1
echo SGGBAK: Testing the back transformation of a pair of REAL balanced matrices
./xeigtsts_ARM < sgbak.in > sgbak.out 2>&1
echo SBB: Testing banded Singular Value Decomposition routines
./xeigtsts_ARM < sbb.in > sbb.out 2>&1
echo GLM: Testing Generalized Linear Regression Model routines
./xeigtsts_ARM < glm.in > sglm.out 2>&1
echo GQR: Testing Generalized QR and RQ factorization routines
./xeigtsts_ARM < gqr.in > sgqr.out 2>&1
echo GSV: Testing Generalized Singular Value Decomposition routines
./xeigtsts_ARM < gsv.in > sgsv.out 2>&1
echo LSE: Testing Constrained Linear Least Squares routines
./xeigtsts_ARM < lse.in > slse.out 2>&1
echo Testing COMPLEX LAPACK linear equation routines
./xlintstc_ARM < ctest.in > ctest.out 2>&1
echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
./xeigtstc_ARM < nep.in > cnep.out 2>&1
echo SEP: Testing Symmetric Eigenvalue Problem routines
./xeigtstc_ARM < sep.in > csep.out 2>&1
echo SVD: Testing Singular Value Decomposition routines
./xeigtstc_ARM < svd.in > csvd.out 2>&1
echo CEC: Testing COMPLEX Eigen Condition Routines
./xeigtstc_ARM < cec.in > cec.out 2>&1
echo CES: Testing COMPLEX Nonsymmetric Schur Form Driver
./xeigtstc_ARM < ced.in > ced.out 2>&1
echo CGG: Testing COMPLEX Nonsymmetric Generalized Eigenvalue Problem routines
./xeigtstc_ARM < cgg.in > cgg.out 2>&1
echo CGD: Testing COMPLEX Nonsymmetric Generalized Eigenvalue Problem driver routines
./xeigtstc_ARM < cgd.in > cgd.out 2>&1
echo CHB: Testing Hermitian Eigenvalue Problem routines
./xeigtstc_ARM < csb.in > csb.out 2>&1
echo CSG: Testing Symmetric Generalized Eigenvalue Problem routines
./xeigtstc_ARM < csg.in > csg.out 2>&1
echo CGEBAL: Testing the balancing of a COMPLEX general matrix
./xeigtstc_ARM < cbal.in > cbal.out 2>&1
echo CGEBAK: Testing the back transformation of a COMPLEX balanced matrix
./xeigtstc_ARM < cbak.in > cbak.out 2>&1
echo CGGBAL: Testing the balancing of a pair of COMPLEX general matrices
./xeigtstc_ARM < cgbal.in > cgbal.out 2>&1
echo CGGBAK: Testing the back transformation of a pair of COMPLEX balanced matrices
./xeigtstc_ARM < cgbak.in > cgbak.out 2>&1
echo CBB: Testing banded Singular Value Decomposition routines
./xeigtstc_ARM < cbb.in > cbb.out 2>&1
echo GLM: Testing Generalized Linear Regression Model routines
./xeigtstc_ARM < glm.in > cglm.out 2>&1
echo GQR: Testing Generalized QR and RQ factorization routines
./xeigtstc_ARM < gqr.in > cgqr.out 2>&1
echo GSV: Testing Generalized Singular Value Decomposition routines
./xeigtstc_ARM < gsv.in > cgsv.out 2>&1
echo LSE: Testing Constrained Linear Least Squares routines
./xeigtstc_ARM < lse.in > clse.out 2>&1
echo Testing DOUBLE PRECISION LAPACK linear equation routines
./xlintstd_ARM < dtest.in > dtest.out 2>&1
echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
./xeigtstd_ARM < nep.in > dnep.out 2>&1
echo SEP: Testing Symmetric Eigenvalue Problem routines
./xeigtstd_ARM < sep.in > dsep.out 2>&1
echo SVD: Testing Singular Value Decomposition routines
./xeigtstd_ARM < svd.in > dsvd.out 2>&1
echo DEC: Testing DOUBLE PRECISION Eigen Condition Routines
./xeigtstd_ARM < dec.in > dec.out 2>&1
echo DEV: Testing DOUBLE PRECISION Nonsymmetric Eigenvalue Driver
./xeigtstd_ARM < ded.in > ded.out 2>&1
echo DGG: Testing DOUBLE PRECISION Nonsymmetric Generalized Eigenvalue Problem routines
./xeigtstd_ARM < dgg.in > dgg.out 2>&1
echo DGD: Testing DOUBLE PRECISION Nonsymmetric Generalized Eigenvalue Problem driver routines
./xeigtstd_ARM < dgd.in > dgd.out 2>&1
echo DSB: Testing DOUBLE PRECISION Symmetric Eigenvalue Problem routines
./xeigtstd_ARM < dsb.in > dsb.out 2>&1
echo DSG: Testing DOUBLE PRECISION Symmetric Generalized Eigenvalue Problem routines
./xeigtstd_ARM < dsg.in > dsg.out 2>&1
echo DGEBAL: Testing the balancing of a DOUBLE PRECISION general matrix
./xeigtstd_ARM < dbal.in > dbal.out 2>&1
echo DGEBAK: Testing the back transformation of a DOUBLE PRECISION balanced matrix
./xeigtstd_ARM < dbak.in > dbak.out 2>&1
echo DGGBAL: Testing the balancing of a pair of DOUBLE PRECISION general matrices
./xeigtstd_ARM < dgbal.in > dgbal.out 2>&1
echo DGGBAK: Testing the back transformation of a pair of DOUBLE PRECISION balanced matrices
./xeigtstd_ARM < dgbak.in > dgbak.out 2>&1
echo DBB: Testing banded Singular Value Decomposition routines
./xeigtstd_ARM < dbb.in > dbb.out 2>&1
echo GLM: Testing Generalized Linear Regression Model routines
./xeigtstd_ARM < glm.in > dglm.out 2>&1
echo GQR: Testing Generalized QR and RQ factorization routines
./xeigtstd_ARM < gqr.in > dgqr.out 2>&1
echo GSV: Testing Generalized Singular Value Decomposition routines
./xeigtstd_ARM < gsv.in > dgsv.out 2>&1
echo LSE: Testing Constrained Linear Least Squares routines
./xeigtstd_ARM < lse.in > dlse.out 2>&1
echo Testing COMPLEX16 LAPACK linear equation routines
./xlintstz_ARM < ztest.in > ztest.out 2>&1
echo NEP: Testing Nonsymmetric Eigenvalue Problem routines
./xeigtstz_ARM < nep.in > znep.out 2>&1
echo SEP: Testing Symmetric Eigenvalue Problem routines
./xeigtstz_ARM < sep.in > zsep.out 2>&1
echo SVD: Testing Singular Value Decomposition routines
./xeigtstz_ARM < svd.in > zsvd.out 2>&1
echo ZEC: Testing COMPLEX16 Eigen Condition Routines
./xeigtstz_ARM < zec.in > zec.out 2>&1
echo ZES: Testing COMPLEX16 Nonsymmetric Schur Form Driver
./xeigtstz_ARM < zed.in > zed.out 2>&1
echo ZGG: Testing COMPLEX16 Nonsymmetric Generalized Eigenvalue Problem routines
./xeigtstz_ARM < zgg.in > zgg.out 2>&1
echo ZGD: Testing COMPLEX16 Nonsymmetric Generalized Eigenvalue Problem driver routines
./xeigtstz_ARM < zgd.in > zgd.out 2>&1
echo ZHB: Testing Hermitian Eigenvalue Problem routines
./xeigtstz_ARM < zsb.in > zsb.out 2>&1
echo ZSG: Testing Symmetric Generalized Eigenvalue Problem routines
./xeigtstz_ARM < zsg.in > zsg.out 2>&1
echo ZGEBAL: Testing the balancing of a COMPLEX16 general matrix
./xeigtstz_ARM < zbal.in > zbal.out 2>&1
echo ZGEBAK: Testing the back transformation of a COMPLEX16 balanced matrix
./xeigtstz_ARM < zbak.in > zbak.out 2>&1
echo ZGGBAL: Testing the balancing of a pair of COMPLEX general matrices
./xeigtstz_ARM < zgbal.in > zgbal.out 2>&1
echo ZGGBAK: Testing the back transformation of a pair of COMPLEX16 balanced matrices
./xeigtstz_ARM < zgbak.in > zgbak.out 2>&1
echo ZBB: Testing banded Singular Value Decomposition routines
./xeigtstz_ARM < zbb.in > zbb.out 2>&1
echo GLM: Testing Generalized Linear Regression Model routines
./xeigtstz_ARM < glm.in > zglm.out 2>&1
echo GQR: Testing Generalized QR and RQ factorization routines
./xeigtstz_ARM < gqr.in > zgqr.out 2>&1
echo GSV: Testing Generalized Singular Value Decomposition routines
./xeigtstz_ARM < gsv.in > zgsv.out 2>&1
echo LSE: Testing Constrained Linear Least Squares routines
./xeigtstz_ARM < lse.in > zlse.out 2>&1
echo Testing REAL LAPACK RFP protoype linear equation routines
./xlintstrfs_ARM < stest_rfp.in > stest_rfp.out 2>&1
echo Testing SINGLE-DOUBLE PRECISION LAPACK prototype linear equation routines
./xlintstds_ARM < dstest.in > dstest.out 2>&1
echo Testing DOUBLE PRECISION LAPACK RFP protoype linear equation routines
./xlintstrfd_ARM < dtest_rfp.in > dtest_rfp.out 2>&1
echo Testing COMPLEX LAPACK RFP protoype linear equation routines
./xlintstrfc_ARM < ctest_rfp.in > ctest_rfp.out 2>&1
echo Testing COMPLEX-COMPLEX16 LAPACK protoype linear equation routines
./xlintstzc_ARM < zctest.in > zctest.out 2>&1
echo Testing COMPLEX16 LAPACK RFP protoype linear equation routines
./xlintstrfz_ARM < ztest_rfp.in > ztest_rfp.out 2>&1
