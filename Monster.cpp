#include "Monster.h"
#include <iostream>

Monster::Monster():Creature() {}

Monster::Monster(std::string name, int lifePoint, int defense):Creature(name,lifePoint,defense) {}

void Monster::TakeDamage(int amountDealt)
{
	Creature::TakeDamage(amountDealt);

	if (GetLifePoint() <= 0)
	{
		std::cout << GetName() << " is dead\n";
		std::cout << GetName() << " dropped some loot !\n";
	}
}