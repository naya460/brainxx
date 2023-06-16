.PHONY: build
build: main.c fn15.xx
	mkdir -p build
	../../build/src/bxx fn15.xx -o build/fn15.s
	$(CC) main.c build/fn15.s -o build/called_by_c

.PHONY: run
run:
	@build/called_by_c

.PHONY: clean
clean:
	rm -rf build/