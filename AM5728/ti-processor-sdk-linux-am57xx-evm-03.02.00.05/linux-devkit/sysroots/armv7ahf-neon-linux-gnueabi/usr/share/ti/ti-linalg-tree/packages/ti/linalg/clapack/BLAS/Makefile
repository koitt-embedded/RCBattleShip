
.PHONY: level1
level1: $(LIBS)
	cd TESTING; make -f Makeblat1 clean
	cd TESTING; make -f Makeblat1

.PHONY: level2
level2: $(LIBS)
	cd TESTING; make -f Makeblat2 clean
	cd TESTING; make -f Makeblat2
	
.PHONY: level3
level3: $(LIBS)
	cd TESTING; make -f Makeblat3 clean
	cd TESTING; make -f Makeblat3

.PHONY: test1
test1: level1
	@rm -f [sdcz]blat1.out
	@echo "Now testing BLAS Level 1"
	@echo -n "single precision real.. " ;    ./xblat1s_ARM > sblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
	@echo -n "double precision real.. " ;    ./xblat1d_ARM > dblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
	@echo -n "single precision complex.. " ; ./xblat1c_ARM > cblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
	@echo -n "double precision complex.. " ; ./xblat1z_ARM > zblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
	@echo
	@(grep FAIL [sdcz]blat1.out && echo "ABOVE LEVEL 1 TESTS FAILED") || (echo "ALL LEVEL 1 TESTS PASSED. Summary follows:"; egrep 'PASS|FAIL|Test' [scdz]blat1.out; echo "ALL LEVEL 1 TESTS PASSED.")
	@echo "You can view the results in ?blat1.out"

.PHONY: test2
test2: level2
	@rm -f [sdcz]blat2.out
	@echo "Now testing BLAS Level 2"
	@echo -n "single precision real.. " ;    ./xblat2s_ARM < sblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
	@echo -n "double precision real.. " ;    ./xblat2d_ARM < dblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
	@echo -n "single precision complex.. " ; ./xblat2c_ARM < cblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
	@echo -n "double precision complex.. " ; ./xblat2z_ARM < zblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
	@echo
	@(grep FAILED [sdcz]blat2.out && echo "ABOVE LEVEL 2 TESTS FAILED") || (echo "ALL LEVEL 2 TESTS PASSED. Summary follows:"; grep PASSED [scdz]blat2.out; echo "ALL LEVEL 2 TESTS PASSED.")
	@echo "You can view the results in ?blat2.out"

.PHONY: test3
test3: level3
	@rm -f [sdcz]blat3.out
	@echo "Now testing BLAS Level 3"
	@echo -n "single precision real.. " ;    ./xblat3s_ARM < sblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
	@echo -n "double precision real.. " ;    ./xblat3d_ARM < dblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
	@echo -n "single precision complex.. " ; ./xblat3c_ARM < cblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
	@echo -n "double precision complex.. " ; ./xblat3z_ARM < zblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
	@echo
	@(grep FAILED [sdcz]blat3.out && echo "ABOVE LEVEL 3 TESTS FAILED") || (echo "ALL LEVEL 3 TESTS PASSED. Summary follows:"; grep PASSED [scdz]blat3.out; echo "ALL LEVEL 3 TESTS PASSED.")
	@echo "You can view the results in ?blat3.out"

.PHONY: test
run_tests: test1 test2 test3
	@(grep FAILED [sdcz]blat[123].out && echo "ABOVE TESTS FAILED") || (echo "ALL BLAS TESTS PASSED.")

clean:
	cd TESTING; make -f Makeblat1 clean ; make -f Makeblat2 clean ; make -f Makeblat3 clean
	rm -fv x* *.out ; rm -f /tmp/opencl*
