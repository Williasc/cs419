// implementation of GameActor class

#include "gameActor.h"
#include "coord.h"
#include "gameMap.h"

int Character::alterHealth( int amount )
{
	if (health + amount >= 0) {
		health += amount;
		return amount;
	}
	else {
		int change = health;
		health = 0;
		return change;
	}
}

int Character::alterMagic( int amount )
{
	if (magic + amount >= 0) {
		magic += amount;
		return amount;
	}
	else {
		int change = magic;
		magic = 0;
		return change;
	}
}

