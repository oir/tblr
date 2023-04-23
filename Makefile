CXX=g++

.PHONY: all
all: test demo

test: test.cpp
	${CXX} -std=c++17 -Wall -Wextra -Wpedantic -Wsign-conversion -fprofile-arcs -ftest-coverage -I./tblr -I./extern test.cpp -o test

demo: demo.cpp
	${CXX} -std=c++17 -Wall -Wextra -Wpedantic -Wsign-conversion -I./tblr demo.cpp -o demo

.PHONY: install
install:
	true || "TODO"

.PHONY: clean
clean:
	rm -rf test demo
