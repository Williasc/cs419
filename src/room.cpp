// implementation of class Room

#include "room.h"
#include <exception>
#include <cstdio>

Room::Room( int roomId, Coord dim ) :
		id(roomId) {
	dimensions = dim;
	vector<Space> col(dim.y, Space());
	spaces = vector<vector<Space> >(dim.x, col);
	name = "";
	description = "";
	spawnPoint = Coord(0, 0);
}

Room::Room( int roomId, Coord dim, Coord sPoint, string name,
		string description ) :
		id(roomId) {
	dimensions =  dim;
	vector<Space> col(dim.y, Space());
	spaces = vector<vector<Space> >(dim.x, col);
	this->name = name;
	this->description = description;
	if (sPoint.x >= 0 && sPoint.x < dimensions.x &&
			sPoint.y >= 0 && sPoint.y < dimensions.y) {
		spawnPoint = sPoint;
	} else {
		throw(exception());
	}
}

bool Room::removeAt( Coord xy, GameActor* obj ) {
	if (xy.x < 0 || xy.x > this->getDimensions().x || xy.y < 0
			|| xy.y > this->getDimensions().y) {
		throw("location out of game map bounds");
	}
	// if the object is in this location, remove it
	if (spaces[xy.x][xy.y].contents == obj) {
		spaces[xy.x][xy.y].contents = 0;
		return true;
	} else {
		return false;
	}
}

bool Room::insertAt( Coord xy, GameActor* obj ) {
	if (xy.x < 0 || xy.x > this->getDimensions().x || xy.y < 0
			|| xy.y > this->getDimensions().y) {
		throw("location out of game map bounds");
	}
	// if no object is in this location, insert the object
	if (spaces[xy.x][xy.y].contents == 0) {
		spaces[xy.x][xy.y].contents = obj;
		return true;
	} else {
		return false;
	}
}

// for testing purposes
void Room::print() {
	printf("%s\n\n%s\n\n", name.c_str(), description.c_str());
	for (int j = 0; j < dimensions.y; j++) {
		for (int i = 0; i < dimensions.x; i++) {
			if (objectAt(i, j) == 0) {
				printf(" [ ] ");
			} else {
				printf(" [%c] ", objectAt(i, j)->symbol);
			}
		}
		printf("\n\n");
	}
}
