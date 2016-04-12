#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "gameMap.h"

// What phase of the game is the player in?
// Add more as needed
enum GameMode {
	Main, Combat
};

/***
 struct GameState

 the current state of the game

 Fields:
 GameMode mode						enum value specifying current game mode
 bool IsGameAlive					true > playing game, false > game over
 PlayerCharacter* playerCharacter	pointer to the player character object
 GameMap* currentMap					pointer to the game map being used
 Coord currentRoom					coords to room in map where player is

 Methods:
 ?
 ***/
struct GameState {
	GameMode mode;
	bool IsGameAlive; // false == game over
	PlayerCharacter* playerCharacter;
	GameMap* currentMap;
	Coord currentRoom;

	GameState( PlayerCharacter* pc, GameMap* gm ) {
		mode = Main;
		IsGameAlive = true;
		playerCharacter = pc;
		currentMap = gm;
		currentRoom = currentMap->getStartRoom();
	}
};

#endif
