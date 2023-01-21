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
        echo test 
        exit 1
    fi
}

# tests
expect sample.xx sample.s

echo all tests are successful
