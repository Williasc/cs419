// implementation of class Room

#include "room.h"

#include <cstdio>

Room::Room( int roomId, int x, int y ) : id( roomId )
{
	dimensions = Coord( x, y );
	vector<Space> col( y, Space() );
	spaces = vector< vector<Space> >( x, col );
	name = "";
	description = "";
}

Room::Room( int roomId, int x, int y, string name, string description ) : id( roomId )
{
	dimensions = Coord( x, y );
	vector<Space> col( y, Space() );
	spaces = vector< vector<Space> >( x, col );
	this->name = name;
	this->description = description;
}

bool Room::removeAt( Coord xy, GameActor* obj )
{
	if (xy.x < 0 || xy.x > this->getDimensions().x || xy.y < 0 || xy.y > this->getDimensions().y) {
		throw( "location out of game map bounds" );
	}
	// if the object is in this location, remove it
	if (spaces[xy.x][xy.y].contents == obj) {
		spaces[xy.x][xy.y].contents = 0;
		return true;
	}
	else {
		return false;
	}
}

bool Room::insertAt( Coord xy, GameActor* obj)
{
	if (xy.x < 0 || xy.x > this->getDimensions().x || xy.y < 0 || xy.y > this->getDimensions().y) {
		throw( "location out of game map bounds" );
	}
	// if no object is in this location, insert the object
	if (spaces[xy.x][xy.y].contents == 0) {
		spaces[xy.x][xy.y].contents = obj;
		return true;
	} 
	else {
		return false;
	}
}

void Room::print() {
	printf("%s\n\n%s\n\n", name.c_str(), description.c_str());
	for(int j = 0; j < dimensions.y; j++) {
		for(int i = 0; i < dimensions.x; i++) {
			if(objectAt(i,j) == 0) {
				printf(" [ ] ");
			} else {
				printf(" [%c] ", objectAt(i,j)->symbol);
			}
		}
		printf("\n\n");
	}
}
