/***
 main Game class

 This class implements the basic mechanics of game play.
 ***/

#ifndef GAME_H
#define GAME_H

#include "gameState.h"
#include "move.h"

/***
 class Game

 "Master" game class

 Fields:
 GameState* gameState		the current game state

 ***/

class Game {
private:
	GameState* gameState;

	// move GameActor at this coord in direction d if possible
	// Should we have this method take GameActor* as argument instead?
	bool moveActor(Coord from, Direction d);

public:
	Game( PlayerCharacter* p, GameMap* m );

	// move player character in direction d
	bool movePlayer(Direction d);

	bool moveCharacter(Coord from, Direction d) {
		moveActor(from, d);
	}

	// get/set methods
	GameMode getMode() {
		return gameState->mode;
	}
	void setMode(GameMode m) {
		gameState->mode = m;
	}
	GameMap* getMap() {
			return gameState->currentMap;
	}
	void setMap(GameMap* m) {
		gameState->currentMap = m;
	}
	Coord getCurrentRoomCoord() {
		return gameState->currentRoomCoord;
	}
	Coord getPlayerLocationCoord() {
		return gameState->playerLocationCoord;
	}


};

#endif
