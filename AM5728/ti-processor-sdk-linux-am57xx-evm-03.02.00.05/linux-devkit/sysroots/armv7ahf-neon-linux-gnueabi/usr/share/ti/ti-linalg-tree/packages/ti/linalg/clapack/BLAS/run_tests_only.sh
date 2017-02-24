#!/bin/bash

echo "Now testing BLAS Level 1"
echo -n "single precision real.. " ;    ./xblat1s_ARM > sblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
echo -n "double precision real.. " ;    ./xblat1d_ARM > dblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
echo -n "single precision complex.. " ; ./xblat1c_ARM > cblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
echo -n "double precision complex.. " ; ./xblat1z_ARM > zblat1.out 2> /dev/null ; rm -f /tmp/opencl* ; echo done
echo
(grep FAIL [sdcz]blat1.out && echo "ABOVE LEVEL 1 TESTS FAILED") || (echo "ALL LEVEL 1 TESTS PASSED. Summary follows:"; 
egrep 'PASS|FAIL|Test' [scdz]blat1.out; echo "ALL LEVEL 1 TESTS PASSED.")
echo

echo "Now testing BLAS Level 2"
echo -n "single precision real.. " ;    ./xblat2s_ARM < sblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
echo -n "double precision real.. " ;    ./xblat2d_ARM < dblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
echo -n "single precision complex.. " ; ./xblat2c_ARM < cblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
echo -n "double precision complex.. " ; ./xblat2z_ARM < zblat2.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
echo
(grep FAILED [sdcz]blat2.out && echo "ABOVE LEVEL 2 TESTS FAILED") || (echo "ALL LEVEL 2 TESTS PASSED. Summary follows:"; grep PASSED [scdz]blat2.out; echo "ALL LEVEL 2 TESTS PASSED.")
echo

echo "Now testing BLAS Level 3"
echo -n "single precision real.. " ;    ./xblat3s_ARM < sblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
echo -n "double precision real.. " ;    ./xblat3d_ARM < dblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl* ; echo done
echo -n "single precision complex.. " ; ./xblat3c_ARM < cblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
echo -n "double precision complex.. " ; ./xblat3z_ARM < zblat3.in > /dev/null 2>&1 ; rm -f /tmp/opencl*; echo done
echo
(grep FAILED [sdcz]blat3.out && echo "ABOVE LEVEL 3 TESTS FAILED") || (echo "ALL LEVEL 3 TESTS PASSED. Summary follows:"; grep PASSED [scdz]blat3.out; echo "ALL LEVEL 3 TESTS PASSED.")

