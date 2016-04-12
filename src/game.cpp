// Game class implemented

#include "game.h"
#include "gameState.h"

Game::Game( PlayerCharacter* p, GameMap* m )
{
	gameState = new GameState(p, m);
}
