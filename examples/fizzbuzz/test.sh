cd $(dirname $0)

make
output=$(echo 20 | ./build/fizzbuzz)
ret=$?
except="End : 001
002
Fizz
004
Buzz
Fizz
007
008
Fizz
Buzz
011
Fizz
013
014
FizzBuzz
016
017
Fizz
019
Buzz"

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