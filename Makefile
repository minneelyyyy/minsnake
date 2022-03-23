
CC=g++
CFLAGS=-Wall -Werror -std=c++11 -O3

all: src/main.cpp src/SnakeHead.cpp src/PositionalObject.cpp src/Fruit.cpp src/SnakeTailSegment.cpp
	$(CC) $(CFLAGS) $^ -lncurses -pthread

clean:
	$(RM) a.out
