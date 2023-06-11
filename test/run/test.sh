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

    echo "$4" | ./tmp.elf >> /dev/null
    ret_num=$?

    if [ $ret_num -eq $expect ]; then
        echo $input ":" $expect "=" $ret_num : ok
    else
        echo $input ":" $expect "=" $ret_num : failed
        exit 1
    fi

    if [ -z "$3" ]; then
        return 0
    fi

    out_text="$(echo "$4" | ./tmp.elf | tr -d '\0')"
    if [ "$3" = "$out_text" ]; then
        echo $input ":" "output text" "=" $out_text : ok
    else
        echo $input ":" "output text" "=" $out_text : false
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

# tests - 002-stack - 009-eq
set_sd 002-stack/009-eq
expect 001-less.xx 0
expect 002-greater.xx 0
expect 003-equal.xx 1

# tests - 002-stack - 010-el
set_sd 002-stack/010-el
expect 001-less.xx 1
expect 002-greater.xx 0
expect 003-equal.xx 1

# tests - 002-stack - 011-eg
set_sd 002-stack/011-eg
expect 001-less.xx 0
expect 002-greater.xx 1
expect 003-equal.xx 1

# tests - 002-stack - 012-ne
set_sd 002-stack/012-ne
expect 001-less.xx 1
expect 002-greater.xx 1
expect 003-equal.xx 0

# tests - 002-stack - 013-ptr
set_sd 002-stack/013-ptr
expect 001-base-mov.xx 5
expect 002-cur-mov.xx 48

# tests - 002-stack - 014-inc_dec
set_sd 002-stack/014-inc_dec
expect 001-inc.xx 7
expect 002-dec.xx 9

# tests - 002-stack - 015-dup
set_sd 002-stack/015-dup
expect 001-dup.xx 25

# tests - 003-ctrl - 001-spl
set_sd 003-ctrl/001-spl
expect 001-single.xx 4
expect 002-double.xx 5
expect 003-inner.xx 15

# tests - 003-ctrl - 002-spr
set_sd 003-ctrl/002-spr
expect 001-single.xx 7
expect 002-double.xx 13
expect 003-inner.xx 104

# tests - 003-ctrl - 003-rep
set_sd 003-ctrl/003-rep
expect 001-if-true.xx 1
expect 002-if-false.xx 3
expect 003-if-else.xx 12
expect 004-rep.xx 32
expect 005-rep-if.xx 15

# tests - 004-io
set_sd 004-io
expect 001-cout.xx 0 "OK"
expect 002-cin.xx 0 "Hello World!" "Hello World!"

#tests - 005-tag
set_sd 005-tag
expect 001-def-jmp.xx 0

# tests - 006-fn
set_sd 006-fn
expect 001-call-single.xx 0 "OK"
expect 002-call-number.xx 15
expect 003-call-double.xx 20