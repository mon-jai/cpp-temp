.PHONY: all
all: ut

ut: setup
	cmake --build bin --target ut_all

setup:
	cmake -B bin -DCMAKE_BUILD_TYPE=Debug

.PHONY: clean
clean:
	rm bin -rf
