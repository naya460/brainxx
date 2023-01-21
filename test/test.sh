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

# tests - stack
expect t-stack-push-001.xx t-stack-push-001.s
expect t-stack-push-002.xx t-stack-push-002.s
expect t-stack-push-003.xx t-stack-push-003.s

expect t-stack-op-add-001.xx t-stack-op-add-001.s
expect t-stack-op-sub-001.xx t-stack-op-sub-001.s

echo all tests are successful
