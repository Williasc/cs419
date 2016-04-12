// class GameActor and the classes that inherit from GameActor

#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "coord.h"

#include <set>
#include <string>

using namespace std;

/***
class GameActor

base class for all objects and characters found in game

Fields:
	id			int			ID as assigned in constructor call
	name		string		name of the object

Methods:
	get/set methods:
	int getId()
	void setName(string name)
	string getName()
***/
class GameActor {
private:
	int id;
	string name;

public:
	GameActor( int id, string name )
	{
		this->id = id;
		this->name = name;
		symbol = ' ';
	}

	int getId()
	{
		return id;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}

	// temporary representation
	char symbol;
};



/* ***
class Item

game object that can be possessed by a character

Fields
	value			int		how many coins the item is worth
	description		string	text describing item

// Actually, I think maybe this shouldn't be a GameActor
// commenting this class out

class Item : public GameActor {
private:
	int value;

public:
	Item( int objId, string objName, int itemValue )
		: GameActor( objId, objName )
	{
		value = itemValue;
	}
};
***/


/***
class Character

game object with capabilities for interaction, fighting, etc.

Fields:
	level			int			level achieved by character
	health			int			amount of health the character has
	magic			int			amount of magic the character has
	inventory		multiset	all items the character possesses

Methods:
	int alterMagic( int amount )
	add amount points to character's magic

	int alterHealth( int amount )
	add amount points to character health

	int takeDamage( int damage )
	subtract amount points from character health

	bool isAlive()
	returns true if character health greater than 0, false otherwise

getter/setter methods:
	int getHealth()
	int getMagic()
	int getLevel()
	void setHealth(int h)
	void setMagic( int m )
	void setLevel( int l )

***/
class Character : public GameActor {
private:
	int level;
	int health;
	int magic;


public:
	Character( int objId, string objName, int initHealth, int initMagic )
		: GameActor( objId, objName )
	{
		level = 1;
		health = initHealth;
		magic = initMagic;

		symbol = 'C';
	}

	/*
	// not sure how to do this copy constructor
	Character( Character& c ) : GameActor(c.getId, c.getName)
	{
		level = c.level;
		health = c.health;
		magic = c.magic;
	}
	*/

	void setHealth( int h )
	{
		health = h;
	}
	void setMagic( int m )
	{
		magic = m;
	}
	void setLevel( int l )
	{
		level = l;
	}

	int getHealth()
	{
		return health;
	}
	int getMagic()
	{
		return magic;
	}
	int getLevel()
	{
		return level;
	}

	bool isAlive()
	{
		return health > 0;
	}

	// add amount to character magic
	int alterMagic( int amount );

	// add amount to character health
	int alterHealth( int amount );

	// if character's health is damaged, subtract damage amount
	int takeDamage( int damage )
	{
		return alterHealth( -damage );
	}
};

/***
class PlayerCharacter

the player character
***/
class PlayerCharacter : public Character {
private:
	//Fields?
public:
	PlayerCharacter( string playerName, int initPlayerHealth, int initPlayerMagic )
		: Character( 0, playerName, initPlayerHealth, initPlayerMagic )
	{
		symbol = 'P';
	}
};

#endif
