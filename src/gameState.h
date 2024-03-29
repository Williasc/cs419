// ignore this file: PROBABLY GETTING RID OF GameState STRUCT

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
	Room* currentRoom;
	Coord currentRoomCoord;
	Coord playerLocationCoord;

	GameState( PlayerCharacter* pc, GameMap* gm ) {
		mode = Main;
		IsGameAlive = true;
		playerCharacter = pc;
		currentMap = gm;

		currentRoomCoord = currentMap->getStartRoomCoord();
		currentRoom = currentMap->at(currentRoomCoord);
		playerLocationCoord = currentMap->at(currentRoomCoord)->spawnPoint;
	}
};

#endif
