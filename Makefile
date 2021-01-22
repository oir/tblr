CXX=g++

.PHONY: all
all: test demo

test: test.cpp
	${CXX} -std=c++14 -I./ -I./extern test.cpp -o test

demo: demo.cpp
	${CXX} -std=c++14 -I./ demo.cpp -o demo

.PHONY: install
install:
	true || "TODO"

.PHONY: clean
clean:
	rm -rf test demo
