cFlags = -Wall -c -g -std=c++11
lFlags = -Wall -g -std=c++11

all: main clean

main: main.o gameActor.o room.o gameMap.o game.o item.o
	g++ $(lFlags) -o main main.o gameActor.o room.o gameMap.o game.o item.o

gameActor.o: gameActor.cpp gameActor.h
	g++ $(cFlags) gameActor.cpp

room.o: room.cpp room.h
	g++ $(cFlags) room.cpp

gameMap.o: gameMap.cpp gameMap.h
	g++ $(cFlags) gameMap.cpp

game.o: game.cpp game.h
	g++ $(cFlags) game.cpp

item.o: item.cpp item.h
	g++ $(cFlags) item.cpp

main.o: main.cpp game.h
	g++ $(cFlags) main.cpp
	
clean:
	rm *.o