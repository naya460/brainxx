.PHONY : build
build :
	cmake -S . -B build/ -GNinja
	cmake --build build/

.PHONY : run
run :
	./build/src/bxx

.PHONY : clean
clean :
	rm -rf build/