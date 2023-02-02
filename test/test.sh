#!/bin/bash

# compile test
echo "=== Compile test ==="
./test/compile/test.sh
if [ $? -ne 0 ]; then
    echo "Compile Test is faild"
    exit 1
fi

# run test
echo "=== Run test ==="
./test/run/test.sh
if [ $? -ne 0 ]; then
    echo "Run Test is faild"
    exit 1
fi

echo ""
echo "*** All tests are successful ***"