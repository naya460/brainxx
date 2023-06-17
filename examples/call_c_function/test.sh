cd $(dirname $0)

make
output=$(./build/call_c_function)
ret=$?

if [ $ret -ne 0 ]; then
    echo "return : $ret : failed"
    echo "test : failed"
    exit 1
fi
echo "return : $ret : ok"

if [ "$output" != "6" ]; then
    echo "output : '$output' : failed"
    echo "test : failed"
    exit 1
fi
echo "output : '$output' : ok"

echo "test : ok"
exit 0