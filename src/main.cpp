// main program

#include <cstdio>

#include "coord.h"
#include "game.h"
#include "gameMap.h"
#include "gameActor.h"
#include "gameState.h"
#include "room.h"

int main() {
	// testing some data structures
	PlayerCharacter* pc = new PlayerCharacter("hero", 100, 200);
	Character* c = new Character(1, "enemy", 50, 0);
	Room* r = new Room(3, 5, 6, "my room", "an awesome room");
	GameMap* gm = new GameMap(Coord(7, 5));

	r->insertAt(Coord(0,4), c);

	gm->insertRoom(r, Coord(2, 1));
	gm->setStartRoom(Coord(0, 2));
	gm->print();

	printf("\n\n\n");

	r->print();

	Game* g = new Game(pc, gm);
}
