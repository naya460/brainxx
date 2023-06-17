#!/bin/bash

cd $(dirname $0)

test() {
    $1/test.sh
    if [ $? -ne 0 ]; then
        exit 1
    fi
}

test ../examples/call_c_function
test ../examples/called_by_c
test ../examples/fibonacci
test ../examples/fizzbuzz
test ../examples/text_input