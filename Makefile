
CC=g++
CFLAGS=-Wall -Werror -std=c++11 -O3

all: src/main.cpp src/SnakeHead.cpp src/PositionalObject.cpp src/Fruit.cpp src/SnakeTailSegment.cpp
	$(CC) $(CFLAGS) $^ -lncurses -pthread

deb: src/main.cpp src/SnakeHead.cpp src/PositionalObject.cpp src/Fruit.cpp src/SnakeTailSegment.cpp
	$(CC) $(CFLAGS) $^ -o ./package/snake/usr/local/games/snake -lncurses -pthread
	chmod 775 ./package/snake/DEBIAN/postinst
	dpkg-deb --build ./package/snake

clean:
	$(RM) a.out
	$(RM) ./package/snake/usr/local/games/snake
	$(RM) ./package/snake.deb
