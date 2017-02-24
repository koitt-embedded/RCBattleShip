dlvl = ./.
ifeq ($(arch), ARM)
include $(dlvl)/Makefile.ARM
else ifeq ($(arch), C66)
include $(dlvl)/Makefile.C66
else ifeq ($(arch), LINUX)
include $(dlvl)/Makefile.LINUX
else ifeq ($(arch), ARMRBLIS)
include $(dlvl)/Makefile.ARMRBLIS
else ifeq ($(arch), ARMBLIS)
include $(dlvl)/Makefile.ARMBLIS
else
include $(dlvl)/Makefile.in
endif

TEMPCBLIB:= $(addprefix lib/$(arch)/, $(notdir $(CBLIB)))

all: alllib alltst 

help:
	@ echo $(arch)
	@ echo "Make sure you are using correct Makefile.in for your system."
	@ echo "At this level, assuming you have downloded all necessary    "
	@ echo "files and made an archive file of BLAS routines for your    "
	@ echo "system."
	@ echo " "
	@ echo "The Makefile compiles the routines of CBLAS (C interface of "
	@ echo "BLAS) and testers for all the precisions.                   "
	@ echo "If there is no directory for archives in CBLAS/lib, it      "
	@ echo "creates new directory with the name of the platform of your "
	@ echo "machine." 
	@ echo " "
	@ echo "To compile, you have to type as follows"
	@ echo "make <target>"
	@ echo " where <target> is one of:"
	@ echo "slib1 --- make an archive of level 1 REAL."
	@ echo "dlib1 --- make an archive of level 1 DOUBLE PRECISION."
	@ echo "clib1 --- make an archive of level 1 COMPLEX."
	@ echo "zlib1 --- make an archive of level 1 COMPLEX*16."
	@ echo "alllib1 - make an archive of level 1 all precisions."
	@ echo " "
	@ echo "slib2 --- make an archive of level 2 REAL."
	@ echo "dlib2 --- make an archive of level 2 DOUBLE PRECSION."
	@ echo "clib2 --- make an archive of level 2 COMPLEX."
	@ echo "zlib2 --- make an archive of level 2 COMPLEX*16."
	@ echo "alllib2 - make an archive of level 2 all precisions."
	@ echo " "
	@ echo "slib3 --- make an archive of level 3 REAL."
	@ echo "dlib3 --- make an archive of level 3 DOUBLE PRECISION ."
	@ echo "clib3 --- make an archive of level 3 COMPLEX."
	@ echo "zlib3 --- make an archive of level 3 COMPLEX*16."
	@ echo "alllib3 - make an archive of level 3 all precisions."
	@ echo " "
	@ echo "alllib -- make an archive for all precisions."
	@ echo " "
	@ echo "stest1 -- Compiles the tester for level 1 REAL."
	@ echo "dtest1 -- Compiles the tester for level 1 DOUBLE PRECISION. "
	@ echo "ctest1 -- Compiles the tester for level 1 COMPLEX."
	@ echo "ztest1 -- Compiles the tester for level 1 COMPLEX*16."
	@ echo "alltst1 - Compiles testers for all precisions of level 1." 
	@ echo " "
	@ echo "stest2 -- Compiles the tester for level 2 REAL."
	@ echo "dtest2 -- Compiles the tester for level 2 DOUBLE PRECISION. "
	@ echo "ctest2 -- Compiles the tester for level 2 COMPLEX."
	@ echo "ztest2 -- Compiles the tester for level 2 COMPLEX*16."
	@ echo "alltst2 - Compiles testers for all precisions of level 2." 
	@ echo " "
	@ echo "stest3 -- Compiles the tester for level 3 REAL."
	@ echo "dtest3 -- Compiles the tester for level 3 DOUBLE PRECISON. "
	@ echo "ctest3 -- Compiles the tester for level 3 COMPLEX."
	@ echo "ztest3 -- Compiles the tester for level 3 COMPLEX*16."
	@ echo "alltst3 - Compiles testers for all precisions of level 3." 
	@ echo " "
	@ echo "alltst -- Compiles testers for all CBLAS routines." 
	@ echo "runtst -- Execute testers for all CBLAS routines." 
	@ echo " "
	@ echo "all ----- Creates a library and testers for ALL." 
	@ echo " "
	@ echo "clean --- Erase all the .o and excutable files" 
	@ echo "cleanlib -- Erase all the .o  files" 
	@ echo "cleanexe -- Erase all the excutable files" 
	@ echo "rmlib --- Remove a library file." 
	@ echo " "
	@ echo "example -- Creates example1 and example2"
	@ echo "example1 -- A small example to exercise the interface "
	@ echo "example2 -- Test that cblas_xerbla() is working correctly"
	@ echo " "
	@ echo " ------- Warning ------- "
	@ echo "If you want just to make a tester, make sure you have"
	@ echo "already made an archive file out of CBLAS routines."
	@ echo " "
	@ echo "Written by Keita Teranishi"
	@ echo "3/4/98 "


# In general, the Makefile call other Makefiles in the sub-directories.

link: 
	$(LN_S) Makefile.$(arch) Makefile.in


clean: link
	( cd testing && make clean )
	( cd src && make clean )
	rm -f *.o cblas_ex1 cblas_ex2

cleanobj: link
	( cd testing && make cleanobj )
	( cd src && make clean )

cleanexe: link
	( cd testing && make cleanexe )

rmlib: link
	@echo $(TEMPCBLIB)
	( rm -f $(TEMPCBLIB) ) 
	
slib1:  link checkDir sreal1 
dlib1:  link checkDir dreal1
clib1:  link checkDir scplx1
zlib1:  link checkDir dcplx1
slib2:  link checkDir sreal2
dlib2:  link checkDir dreal2
clib2:  link checkDir scplx2
zlib2:  link checkDir dcplx2
slib3:  link checkDir sreal3
dlib3:  link checkDir dreal3
clib3:  link checkDir scplx3 
zlib3:  link checkDir dcplx3 
alllib1: link checkDir allprecision1
alllib2: link checkDir allprecision2
alllib3: link checkDir allprecision3
alllib: link checkDir allprecision libinstall


sreal1:
	( cd src && make slib1)
dreal1:
	( cd src && make dlib1)
scplx1:
	( cd src && make clib1)
dcplx1:
	( cd src && make zlib1)
allprecision1:
	( cd src && make all1)
sreal2:
	( cd src && make slib2)
dreal2:
	( cd src && make dlib2)
scplx2:
	( cd src && make clib2)
dcplx2:
	( cd src && make zlib2)
allprecision2:
	( cd src && make all2)
sreal3:
	( cd src && make slib3)
dreal3:
	( cd src && make dlib3)
scplx3:
	( cd src && make clib3)
dcplx3:
	( cd src && make zlib3)
allprecision3:
	( cd src && make all3)
allprecision:
	( cd src && make all)
libinstall:

stest1: link 
	( cd testing && make stest1 )
dtest1: link 
	( cd testing && make dtest1 )
ctest1: link 
	( cd testing && make ctest1 )
ztest1: link 
	( cd testing && make ztest1 )
alltst1: link 
	( cd testing && make all1 )
stest2: link 
	( cd testing && make stest2 )
dtest2: link 
	( cd testing && make dtest2 )
ctest2: link 
	( cd testing && make ctest2 )
ztest2: link 
	( cd testing && make ztest2 )
alltst2: link 
	( cd testing && make all2 )
stest3: link 
	( cd testing && make stest3 )
dtest3: link 
	( cd testing && make dtest3 )
ctest3: link 
	( cd testing && make ctest3 )
ztest3: link 
	( cd testing && make ztest3 )
alltst3: link 
	( cd testing && make all3 )
alltst: link 
	( cd testing && make all )
runtst: link 
	( cd testing && make run )
	
example: alllib
	( cd examples && make all )
example1: alllib
	( cd examples && make example1 )
example2: alllib
	( cd examples && make example1 )

   
cleanall: link
	( cd src && rm -f a.out core obj/$(PLAT)/*.o $(CBLIB) )
	( cd testing && rm -f *.out core *.o x[sdcz]cblat[123] )
	( cd examples && rm -f *.o cblas_ex1 cblas_ex2 )

checkDir:
ifeq ($(wildcard lib),)
	mkdir lib
endif
ifeq ($(wildcard lib/$(PLAT)),)
	mkdir lib/$(PLAT)
endif
ifeq ($(wildcard src/obj),)
	mkdir src/obj
endif
ifeq ($(wildcard src/obj/$(PLAT)),)
	mkdir src/obj/$(PLAT)
endif


