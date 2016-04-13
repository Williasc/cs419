// Game class implemented

#include "game.h"
#include "gameState.h"

Game::Game( PlayerCharacter* p, GameMap* m ) {
	gameState = new GameState(p, m);
	gameState->currentRoom->insertAt(gameState->playerLocationCoord, gameState->playerCharacter);
}

// attempt to move the character in Direction d
bool Game::moveActor( Coord from, Direction d ) {
	if (!gameState->currentRoom->isInBounds(from)) {
		return false;
	}
	GameActor* actor = gameState->currentRoom->objectAt(from);
	Coord target = move(from, d);
	if (!gameState->currentRoom->isInBounds(target)) {
		return false;
	}
	if (gameState->currentRoom->objectAt(target) == 0) {
		gameState->currentRoom->removeAt(from, actor);
		gameState->currentRoom->insertAt(target, actor);
		return true;
	} else {
		return false;
	}
}

bool Game::movePlayer( Direction d ) {
	if (moveActor(gameState->playerLocationCoord, d)) {
		gameState->playerLocationCoord = move(gameState->playerLocationCoord, d);
		return true;
	} else {
		return false;
	}

}
