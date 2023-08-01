#!/bin/bash

assembler=gcc

cd $(dirname $0)
bxx=../../build/src/bxx

is_ok() {
    if [ $? -eq $1 ]; then
        echo "-> ok"
    else
        echo "-> failed"
        exit 1
    fi
}

# no args
echo "* no args"
$bxx
is_ok 0

# no arg after -o
echo "* no arg after -o"
$bxx -o
is_ok 0

# compile with input file and output file
echo "* compile with input file and output file"
$bxx ret0.xx -o tmp.s
is_ok 0

# compile with other args order
echo "* compile with other args order"
$bxx -o tmp.s ret0.xx
is_ok 0

# compile with -s option
echo "* compile with -s option"
$bxx -s ret0.xx -o tmp.s

# 2 of input files
echo "* 2 of input files"
$bxx -s ret0.xx ret1.xx -o tmp.s
is_ok 0
$assembler tmp.s -o tmp.elf
./tmp.elf
is_ok 1

# 2 of output files
echo "* 2 of output files"
$bxx -s ret0.xx -o tmp1.s -o tmp2.s
is_ok 0
$assembler tmp2.s -o tmp.elf
./tmp.elf
is_ok 0