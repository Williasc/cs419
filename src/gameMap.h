#ifndef GAMEMAP_H
#define GAMEMAP_H
/***
 class GameMap

 contains all the rooms in the game

 Fields:
 dimensions	Coord						how many rooms in X and Y dimensions
 rooms		vector< vector<Room*> >		grid of rooms
 startRoom	Coord						on entering map, player should be
 spawned into room at these coords
 ***/

#include "room.h"

using namespace std;

class GameMap {
	Coord dimensions;
	vector<vector<Room*> > rooms;
	Coord startRoomCoord; // default player spawn point

public:
	GameMap( Coord );

	void insertRoom( Room* r, Coord xy );

	Coord getDimensions() {
		return dimensions;
	}
	void setStartRoom(Coord xy) {
		startRoomCoord = xy;
	}
	Coord getStartRoomCoord() {
		return startRoomCoord;
	}
	Room* at(Coord loc) {
		return rooms.at(loc.x).at(loc.y);
	}

	void print();
};

#endif
