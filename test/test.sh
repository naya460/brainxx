#!/bin/bash

# run test
./test/run/test.sh
if [ $? -ne 0 ]; then
    exit 1
fi

echo ""
echo "*** All tests are successful ***"