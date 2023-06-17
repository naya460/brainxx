.PHONY: build
build: text_input.xx
	mkdir -p build
	../../build/src/bxx -s text_input.xx -o build/text_input.s
	$(CC) build/text_input.s -o build/text_input

.PHONY: run
run:
	@build/text_input

.PHONY: clean
clean:
	rm -rf build/

.PHONY: test
test:
	./test.sh
