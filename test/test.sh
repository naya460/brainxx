#!/bin/bash

# args test
echo "*** args test ***"
./test/args/test.sh
if [ $? -ne 0 ]; then
    exit 1
fi
echo ""
echo "=> args test : ok"
echo ""

# run test
echo "*** run test ***"
./test/run/test.sh
if [ $? -ne 0 ]; then
    exit 1
fi
echo ""
echo "=> run test : ok"
echo ""

echo "*** All tests are successful ***"