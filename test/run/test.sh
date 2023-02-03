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

# tests - 001-base
set_sd 001-base
expect 001-empty.xx 0
expect 002-ret.xx 1

# tests - 002-stack - 001-push
set_sd 002-stack/001-push
expect 001-zero.xx 0
expect 002-one.xx 1
expect 003-nine.xx 9
expect 004-ten.xx 10
expect 005-3digit.xx 253
expect 006-uint-overflow.xx 0

# tests - 002-stack - 002-add
set_sd 002-stack/002-add
expect 001-less.xx 8
expect 002-greater.xx 11
expect 003-equal.xx 26
expect 004-twice.xx 19
expect 005-double.xx 23

# tests - 002-stack - 003-sub
set_sd 002-stack/003-sub
expect 001-greater.xx 2
expect 002-less.xx 0
expect 003-equal.xx 0
expect 004-twice.xx 26
expect 005-double.xx 173

# tests - 002-stack - 004-mul
set_sd 002-stack/004-mul
expect 001-less.xx 96
expect 002-greater.xx 57
expect 003-equal.xx 121
expect 004-twice.xx 90
expect 005-double.xx 120

# tests - 002-stack - 005-div
set_sd 002-stack/005-div
expect 001-greater.xx 2
expect 002-less.xx 0
expect 003-equal.xx 1
expect 004-twice.xx 8
expect 005-double.xx 10
expect 006-round.xx 3

# tests - 002-stack - 006-mod
set_sd 002-stack/006-mod
expect 001-greater.xx 1
expect 002-less.xx 4
expect 003-equal.xx 0
expect 004-twice.xx 1
expect 005-double.xx 2

# tests - 002-stack - 007-cl
set_sd 002-stack/007-cl
expect 001-less.xx 1
expect 002-greater.xx 0
expect 003-equal.xx 0

# tests - 002-stack - 008-cg
set_sd 002-stack/008-cg
expect 001-less.xx 0
expect 002-greater.xx 1
expect 003-equal.xx 0

# tests - 002-stack - 008-eq
set_sd 002-stack/009-eq
expect 001-less.xx 0
expect 002-greater.xx 0
expect 003-equal.xx 1
