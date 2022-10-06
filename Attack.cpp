#include "Attack.h"

Attack::Attack()
{
	mName = "default name";
	mDamage = 1;
}

Attack::Attack(std::string name, int damage)
{
	mName = name;
	mDamage = damage;
}

Attack::~Attack() {}

int Attack::RollDice(int max) 
{
	int result = rand() % max + 1;
	std::cout << "A dice with " << max << " faces rolls !" << std::endl;
	std::cout << "The result is " << result << " !" << std::endl;

	return result;
}

int Attack::DamageDealt()
{
	int totalDmg = 0;

	for (size_t i = 0; i < 2; i++)
	{
		totalDmg += RollDice(6);
	}

	totalDmg += 2 + mDamage;
	return totalDmg;
}

std::string Attack::GetName()
{
	return mName;
}
