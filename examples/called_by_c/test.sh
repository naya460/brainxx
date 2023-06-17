cd $(dirname $0)

make
output=$(./build/called_by_c)
ret=$?

if [ $ret -ne 0 ]; then
    echo "return : $ret : failed"
    echo "test : failed"
    exit 1
fi
echo "return : $ret : ok"

if [ "$output" != "return number : 15" ]; then
    echo "output : '$output' : failed"
    echo "test : failed"
    exit 1
fi
echo "output : '$output' : ok"

echo "test : ok"
exit 0