.PHONY : build
build :
	cmake -S . -B build/ -GNinja
	cmake --build build/

.PHONY : run
run :
	@./build/src/bxx ${ARG} ${arg}

.PHONY : test
test:
	@./test/test.sh

.PHONY : clean
clean :
	rm -rf build/