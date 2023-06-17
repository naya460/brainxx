.PHONY: build
build: fizzbuzz.xx
	mkdir -p build
	../../build/src/bxx -s fizzbuzz.xx -o build/fizzbuzz.s
	$(CC) build/fizzbuzz.s -o build/fizzbuzz

.PHONY: run
run:
	@build/fizzbuzz

.PHONY: clean
clean:
	rm -rf build/

.PHONY: test
test:
	./test.sh
