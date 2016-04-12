// main program

#include <cstdio>

#include "coord.h"
#include "gameActor.h"
#include "room.h"
#include "gameMap.h"
#include "gameState.h"
#include "game.h"

int main() {
	// testing some data structures
	PlayerCharacter* pc = new PlayerCharacter(string("hero"), 100, 200);
	Character* c = new Character(1, string("enemy"), 50, 0);
	c->symbol = 'E';
	Room* r = new Room(3, Coord(5, 6), Coord(2, 3), string("my room"),
					string("You find yourself in the middle of a large field surrounded by hills. To the north and east is a dense forest. An enemy lurks to the west."));
	GameMap* gm = new GameMap(Coord(7, 5));
	r->insertAt(Coord(0, 4), c);

	gm->insertRoom(r, Coord(2, 1));
	gm->setStartRoom(Coord(2, 1));

	Game* g = new Game(pc, gm);
	gm->print();
	printf("\n\n\n");
	r->print();
}
