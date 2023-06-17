#!/bin/bash

cd $(dirname $0)

# args test
echo "*** args test ***"
./args/test.sh
if [ $? -ne 0 ]; then
    exit 1
fi
echo ""
echo "=> args test : ok"
echo ""

# run test
echo "*** run test ***"
./run/test.sh
if [ $? -ne 0 ]; then
    exit 1
fi
echo ""
echo "=> run test : ok"
echo ""

# example test
echo "*** example test***"
./example_test.sh
if [ $? -ne 0 ]; then
    exit 1
fi
echo ""
echo "=> example test : ok"
echo ""

echo "*** All tests are successful ***"
