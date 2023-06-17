cd $(dirname $0)

make
output=$(echo 15 | ./build/fibonacci)
ret=$?
except="Count : 001
001
002
003
005
008
013
021
034
055
089
144
233
377
610"

if [ $ret -ne 0 ]; then
    echo "return : $ret : failed"
    echo "test : failed"
    exit 1
fi
echo "return : $ret : ok"

if [ "$output" != "$except" ]; then
    echo "output : '$output' : failed"
    echo "test : failed"
    exit 1
fi
echo "output : '$output' : ok"

echo "test : ok"
exit 0