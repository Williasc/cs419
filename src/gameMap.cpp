#include "gameMap.h"
#include "gameExceptions.h"
#include <cstdio>

GameMap::GameMap( Coord xy ) {
	dimensions = xy;
	vector<Room*> col(dimensions.y, 0);
	rooms = vector<vector<Room*> >(dimensions.x, col);
	startRoomCoord = Coord(0, 0);
}

void GameMap::insertRoom( Room* r, Coord xy ) {
	if (xy.x < 0 || xy.x >= dimensions.x || xy.y < 0 || xy.y >= dimensions.y) {
		throw(invalidCoordException("Room coordinates outside game map"));

	}
	rooms[xy.x][xy.y] = r;
}

// for testing purposes
void GameMap::print()
{
	printf("Map\n\n");
	for(int j = 0; j < dimensions.y; j++) {
		for(int i = 0; i < dimensions.x; i++) {
			printf(" ");
			if(i == startRoomCoord.x && j == startRoomCoord.y) {
				printf("[S]");
			}
			else if(rooms[i][j] == 0) {
				printf("[X]");
			}
			else {
				printf("[ ]");
			}
			printf(" ");
		}
		printf("\n\n");
	}
}
