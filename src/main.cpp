// main program

#include <cstdio>
#include <iostream>

using namespace std;

#include "coord.h"
#include "gameActor.h"
#include "room.h"
#include "gameMap.h"
#include "gameState.h"
#include "game.h"

int main() {
	// testing some data structures
	// to create a Game object, you must first create a PlayerCharacter and a GameMap object
	PlayerCharacter* pc = new PlayerCharacter(string("hero"), 100, 200);
	GameMap* gm = new GameMap(Coord(7, 5));

	// Let's also create another character
	Character* c = new Character(1, string("enemy"), 50, 0);
	c->symbol = 'E';

	// Create a room to put into the map
	Room* r = new Room(3, Coord(5, 6), Coord(2, 3), string("my room"),
			string("You find yourself in the middle of a large field surrounded by hills. To the "
					"north and east is a dense forest. An enemy lurks above you to the west."));
	// place our "enemy" character into our room
	r->insertAt(Coord(0, 4), c);

	// place our room into the game map
	gm->insertRoom(r, Coord(2, 1));
	gm->setStartRoom(Coord(2, 1));

	// instantiate a Game object with the player character and game map
	Game* g = new Game(pc, gm);

	// print a representation of the game map and room we've created
	gm->print();
	printf("\n\n\n");
	r->print();

	while (true) {
		Direction d;
		int c = getchar();
		switch (c) {
		case 'w':
			d = Up;
			break;
		case 's':
			d = Down;
			break;
		case 'a':
			d = Left;
			break;
		case 'd':
			d = Right;
			break;
		default:
			continue;
		}
		g->movePlayer(d);
		r->print();
	}

}
