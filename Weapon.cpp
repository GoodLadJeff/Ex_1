#include "Weapon.h"

Weapon::Weapon()
{
	mName = "default name";
	mType = WeaponType::DEFAULT;
	mDamage = 0;
}

Weapon::Weapon(std::string name, WeaponType type, int damage) 
{
	mName = name;
	mType = type;
	mDamage = damage;
}

Weapon::~Weapon(){}
