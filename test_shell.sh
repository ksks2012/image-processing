#!/usr/bin/env bash
test_list=(test_ppm_rw test_transforms test_pgm_rw test_compare)

for test_target in ${test_list[@]} 
do
    echo ${test_target}
    make all target=${test_target}
done

