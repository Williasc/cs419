#include "gameMap.h"
#include <cstdio>

GameMap::GameMap( Coord xy ) {
	dimensions = xy;
	vector<Room*> col(dimensions.y, 0);
	rooms = vector<vector<Room*> >(dimensions.x, col);
	startRoom = Coord(0, 0);
}

void GameMap::insertRoom( Room* r, Coord xy ) {
	if (xy.x < 0 || xy.x >= dimensions.x || xy.y < 0 || xy.y >= dimensions.y) {
		throw("Room coordinates outside game map");

	}
	rooms[xy.x][xy.y] = r;
}

void GameMap::print()
{
	printf("Map\n\n");
	for(int j = 0; j < dimensions.y; j++) {
		for(int i = 0; i < dimensions.x; i++) {
			printf(" ");
			if(i == startRoom.x && j == startRoom.y) {
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
