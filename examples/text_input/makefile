.PHONY: build
build: text_input.xx
	mkdir -p build
	../../build/src/bxx text_input.xx build/text_input.s
	$(CC) build/text_input.s -o build/text_input

.PHONY: run
run:
	@build/text_input

.PHONY: clean
clean:
	rm -rf build/