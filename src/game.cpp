// Game class implemented

#include "game.h"
#include "gameExceptions.h"
//#include "gameState.h"

Game::Game( PlayerCharacter* p, GameMap* m ) {
	mode = Exploration;
	IsGameAlive = true;
	playerCharacter = p;
	setMap(m);
}

void Game::setMap( GameMap* m ) {
	currentMap = m;
	currentRoomCoord = currentMap->getStartRoomCoord();
	currentRoom = currentMap->at(currentRoomCoord);
	playerLocationCoord = currentMap->at(currentRoomCoord)->spawnPoint;
	if(!currentRoom->insertAt(playerLocationCoord, playerCharacter)) {
		throw(unableToSpawnException("Can't insert player character at spawn point"));
	}
}

// attempt to move the actor (located at from) in Direction d
Event Game::moveActor( Coord from, Direction d ) {
	if (!currentRoom->isInBounds(from)) {
		return Event(NullEvent, 0);
	}
	GameActor* actor = currentRoom->objectAt(from);
	Coord target = move(from, d);
	if (!currentRoom->isInBounds(target)) {
		return Event(NullEvent, actor);
	}
	if (currentRoom->objectAt(target) == 0) {
		currentRoom->removeAt(from, actor);
		currentRoom->insertAt(target, actor);
		return Event(Move, actor);
	} else {
		return Event(Collision, currentRoom->objectAt(target));
	}
}

Event Game::movePlayer( Direction d ) {
	Event r = moveActor(playerLocationCoord, d);
	if(r.event == Move) {
		playerLocationCoord = move(playerLocationCoord, d);
	}
	return r;
}
