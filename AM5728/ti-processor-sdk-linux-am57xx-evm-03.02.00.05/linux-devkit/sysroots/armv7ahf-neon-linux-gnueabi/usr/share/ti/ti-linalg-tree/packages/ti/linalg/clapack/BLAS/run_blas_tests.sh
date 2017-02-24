#!/bin/bash

mkdir results_arm;
mkdir results_dsp;
mkdir results_opt;

export TI_CBLAS_OFFLOAD=000;
#make run_tests;
./run_tests_only.sh

mv *.out results_arm;
mv *.SNAP results_arm;

export TI_CBLAS_OFFLOAD=111;
#make run_tests;
./run_tests_only.sh

mv *.out results_dsp;
mv *.SNAP results_dsp;

export TI_CBLAS_OFFLOAD=002;
#make run_tests;
./run_tests_only.sh

mv *.out results_opt;
mv *.SNAP results_opt;
