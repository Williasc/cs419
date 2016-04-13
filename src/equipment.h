#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <string>

using namespace std;

/***
class Equipment

an object that can be possessed by a character

Fields:
	int id			ID number supplied in constructor
	string name		item name
	description		item description
	int weight		item weight
	int value		how many coins the item is worth
***/

class Equipment {
private:
	int id;
	string name, description;
	int weight;
	int value;

public:
	Equipment( int itemId, string itemName ) : id(itemId), name(itemName)
	{
	}

	Equipment( int itemId, string itemName, int itemWeight, int itemValue )
		: Equipment(itemId, itemName)
	{
		weight = itemWeight;
		value = itemValue;
	}
};

class Armor : public Equipment {
private:
	float protectFactor;

public:
	Armor( int itemId, string itemName, float armorFactor ) : Equipment( itemId, itemName )
	{
		setProtectFactor(armorFactor);
	}

	void setProtectFactor( float factor );

	float getProtectFactor()
	{
		return protectFactor;
	}
};

class Weapon : public Equipment {
private:
	int damage;		// default damage caused by weapon

public:
	Weapon( int itemId, string itemName, int weaponDamage ) : Equipment(itemId, itemName)
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
