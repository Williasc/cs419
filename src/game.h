/***
main Game class

This class implements the basic mechanics of game play.
***/

#ifndef GAME_H
#define GAME_H

#include "gameState.h"

/***
class Game

"Master" game class

Fields:
	GameState* gameState		the current game state
***/
class Game {
private:
	GameState* gameState;
	
public:
	Game( PlayerCharacter* p, GameMap* m );

	// TODO: methods

};

#endif
