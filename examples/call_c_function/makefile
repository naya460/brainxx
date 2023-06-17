.PHONY: build
build: main.xx fn10.c
	mkdir -p build
	../../build/src/bxx -s main.xx -o build/main.s
	$(CC) fn10.c build/main.s -o build/call_c_function

.PHONY: run
run:
	@build/call_c_function

.PHONY: clean
clean:
	rm -rf build/

.PHONY: test
test:
	./test.sh
