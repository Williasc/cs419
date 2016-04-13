cFlags = -Wall -c -g -std=c++11
lFlags = -Wall -g -std=c++11

all: main clean

main: main.o gameActor.o room.o gameMap.o game.o equipment.o move.o gameExceptions.o
	g++ $(lFlags) -o main main.o gameActor.o room.o gameMap.o game.o equipment.o move.o

gameActor.o: gameActor.cpp gameActor.h
	g++ $(cFlags) gameActor.cpp

room.o: room.cpp room.h
	g++ $(cFlags) room.cpp

gameMap.o: gameMap.cpp gameMap.h
	g++ $(cFlags) gameMap.cpp

game.o: game.cpp game.h
	g++ $(cFlags) game.cpp

equipment.o: equipment.cpp equipment.h
	g++ $(cFlags) equipment.cpp
	
move.o: move.h move.cpp
	g++ $(cFlags) move.cpp

main.o: main.cpp game.h
	g++ $(cFlags) main.cpp
	
gameExceptions.o: gameExceptions.h gameExceptions.cpp
	g++ $(cFlags) gameExceptions.cpp
	
clean:
	rm *.o