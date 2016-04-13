/***
 Game class

 This class is the heart of the game model and should
 encompass/contain all aspects of the game state
 ***/

#ifndef GAME_H
#define GAME_H

#include "gameMap.h"
#include "move.h"
#include "event.h"

// GameMode
// What phase of the game is the player in?
// Add more as needed
enum GameMode {
	Exploration, Conversation, Combat
};

/***
 class Game

 "Master" model class

 Fields:
	 GameMode mode						enum value specifying current game mode
	 bool IsGameAlive					true > playing game, false > game over
	 PlayerCharacter* playerCharacter	pointer to the player character object
	 GameMap* currentMap					pointer to the game map being used
	 Coord currentRoom					coords to room in map where player is

 ***/

class Game {
private:
	GameMode mode;
	bool IsGameAlive; 	// false == game over
	PlayerCharacter* playerCharacter;
	GameMap* currentMap;
	Room* currentRoom;
	Coord currentRoomCoord;
	Coord playerLocationCoord;

	// move GameActor at this coord in direction d if possible
	// Should we have this method take GameActor* as argument instead?
	Event moveActor(Coord from, Direction d);

public:
	Game( PlayerCharacter* p, GameMap* m );

	// move player character in direction d
	Event movePlayer(Direction d);

	Event moveCharacter(Coord from, Direction d) {
		return moveActor(from, d);
	}

	// get/set methods
	GameMode getMode() {
		return mode;
	}
	void setMode(GameMode m) {
		mode = m;
	}
	GameMap* getMap() {
		return currentMap;
	}
	void setMap(GameMap* m);

	Coord getCurrentRoomCoord() {
		return currentRoomCoord;
	}
	Coord getPlayerLocationCoord() {
		return playerLocationCoord;
	}


};

#endif
