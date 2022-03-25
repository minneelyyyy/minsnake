
CC=g++
CFLAGS=-Wall -Werror -std=c++11 -O3

all: src/main.cpp src/SnakeHead.cpp src/PositionalObject.cpp src/Fruit.cpp src/SnakeTailSegment.cpp
	$(CC) $(CFLAGS) $^ -lncurses -pthread

deb: src/main.cpp src/SnakeHead.cpp src/PositionalObject.cpp src/Fruit.cpp src/SnakeTailSegment.cpp
	$(CC) $(CFLAGS) $^ -o ./package/debian/usr/local/games/snake -lncurses -pthread
	chmod 775 ./package/debian/DEBIAN/postinst
	dpkg-deb --build ./package/debian snake.deb

clean:
	$(RM) a.out
	$(RM) ./package/debian/usr/local/games/snake
	$(RM) ./snake.deb
