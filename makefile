SOURCE = $(wildcard src/*.cpp)

bin/bf.out: $(SOURCE)
	g++ $^ -o $@  -Wall -lncurses
