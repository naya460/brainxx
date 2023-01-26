#!/bin/bash

cd $(dirname $0)
bxx=../build/src/bxx

# compile and check output
# (intput file path, expected output file)
expect() {
    input=$1
    expect=$2

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

# tests - stack
file_test t-stack-push-001
file_test t-stack-push-002
file_test t-stack-push-003

file_test t-stack-op-add-001
file_test t-stack-op-sub-001
file_test t-stack-op-mul-001
file_test t-stack-op-div-001
file_test t-stack-op-mod-001
file_test t-stack-op-equal-001
file_test t-stack-op-eqless-001
file_test t-stack-op-eqgreater-001
file_test t-stack-op-cl-001
file_test t-stack-op-cg-001

echo all tests are successful
