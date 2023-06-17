cd $(dirname $0)

make
output=$(echo "Hello World!" | ./build/text_input)
ret=$?
except="Enter any text : Hello World!"

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