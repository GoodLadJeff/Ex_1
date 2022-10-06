#pragma once
#include <string>
#include "WeaponType.h"
class Weapon
{
private:
	std::string mName;
	WeaponType mType;
	int mDamage;
public:
	Weapon();
	Weapon(std::string name, WeaponType type, int damage);
	~Weapon();
};

