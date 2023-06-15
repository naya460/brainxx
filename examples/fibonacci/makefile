.PHONY: build
build: fibonacci.xx
	mkdir -p build
	../../build/src/bxx fibonacci.xx build/fibonacci.s
	$(CC) build/fibonacci.s -o build/fibonacci

.PHONY: run
run:
	@build/fibonacci

.PHONY: clean
clean:
	rm -rf build/