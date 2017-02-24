#!/bin/bash

mkdir results_arm;
mkdir results_dsp;
mkdir results_opt;

export TI_CBLAS_OFFLOAD=000;
./run_testsuite.sh
mv *.out results_arm;

export TI_CBLAS_OFFLOAD=001
./run_testsuite.sh
mv *.out results_dsp;

export TI_CBLAS_OFFLOAD=002
./run_testsuite.sh
mv *.out results_opt;

