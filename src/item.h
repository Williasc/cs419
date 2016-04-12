#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

/***
class Item

an object that can be possessed by a character

Fields:
	int id			ID number supplied in constructor
	string name		item name
	description		item description
	int weight		item weight
	int value		how many coins the item is worth
***/

class Item {
private:
	int id;
	string name, description;
	int weight;
	int value;

public:
	Item( int itemId, string itemName ) : id(itemId), name(itemName)
	{
	}

	Item( int itemId, string itemName, int itemWeight, int itemValue )
		: Item(itemId, itemName)
	{
		weight = itemWeight;
		value = itemValue;
	}
};

class Armor : public Item {
private:
	float protectFactor;

public:
	Armor( int itemId, string itemName, float armorFactor ) : Item( itemId, itemName )
	{
		setProtectFactor(armorFactor);
	}

	void setProtectFactor( float factor );

	float getProtectFactor()
	{
		return protectFactor;
	}
};

class Weapon : public Item {
private:
	int damage;		// default damage caused by weapon

public:
	Weapon( int itemId, string itemName, int weaponDamage ) : Item(itemId, itemName)
	{
		damage = weaponDamage;
	}

	int getDamage()
	{
		return damage;
	}
	void setDamage(int amount)
	{
		damage = amount;
	}
};

#endif
