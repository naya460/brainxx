#!/bin/bash

assembler=gcc

cd $(dirname $0)
bxx=../../build/src/bxx
sd=.

# set subdirectory
set_sd() {
    sd=$1
}

# compile and run
# (input file path, expected return number)
expect() {
    input=$sd/$1
    expect=$2

    $bxx $input > tmp.s
    $assembler tmp.s -o tmp.elf

    ./tmp.elf
    ret_num=$?

    if [ $ret_num -eq $expect ]; then
        echo $input ":" $expect "=" $ret_num : ok
    else
        echo $input ":" $expect "=" $ret_num : failed
        exit 1
    fi
}

# tests - base
set_sd base
expect 001-empty.xx 0
expect 002-ret.xx 1