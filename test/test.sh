#!/bin/bash

cd $(dirname $0)
bxx=../build/src/bxx
sd=.

# set subdirectory
set_sd() {
    sd=$1
}

# compile and check output
# (intput file path, expected output file)
expect() {
    input=$sd/$1
    expect=$sd/$2

    $bxx $input > tmp.s
    diff tmp.s $expect
    
    if [ $? -ne 0 ]; then
        echo $input "->" $expect : failed
        exit 1
    else
        echo $input "->" $expect : ok
    fi
}

# call expect function without file extension
file_test() {
    input=$1.xx
    expect=$1.s
    expect $input $expect
}

# tests - stack - push
set_sd stack/push
file_test 001
file_test 002
file_test 003

# tests - stack - op
set_sd stack/op
file_test add-001
file_test sub-001
file_test mul-001
file_test div-001
file_test mod-001
file_test eq-001
file_test el-001
file_test eg-001
file_test cl-001
file_test cg-001

# tests - ctrl
set_sd ctrl
file_test ret-001
file_test rep-001
file_test rep-002
file_test rep-003

echo all tests are successful
