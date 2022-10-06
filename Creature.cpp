#include "Creature.h"
#include <iostream>

Creature::Creature()
{
	mName = "default name";
	mLifePoint = 0;
	mDefense = 0;
}

Creature::Creature(std::string name, int lifePoint, int defense)
{
	mName = name;
	mLifePoint = lifePoint;
	mDefense = defense;
}

Creature::~Creature()
{
}

std::string Creature::GetName() 
{
	return mName;
}

int Creature::GetLifePoint()
{
	return mLifePoint;
}

std::vector<Attack> Creature::GetAttackPool()
{
	return mAttackPool;
}

void Creature::AttackTarget(int attackSlot, Creature& target)
{
	std::cout << " " << std::endl;

	int dmgDealt;

	if (attackSlot < 0 || attackSlot > mAttackPool.size()) {
		std::cout << "The attack is out of the pool size, a default attack will be selected\n";
		attackSlot = 0;
	}

	dmgDealt = mAttackPool[attackSlot].DamageDealt();

	std::cout << " " << std::endl;
	std::cout << mName << " attacks " << target.GetName() << " with \"" << mAttackPool[attackSlot].GetName() << "\" and deals " << dmgDealt << " points of damage\n";

	target.TakeDamage(dmgDealt);

	std::cout << " " << std::endl;
}


void Creature::Heal(int amountToHeal)
{
	mLifePoint += amountToHeal;
	std::cout << mName << " healed for " << amountToHeal << " points and now have " << mLifePoint << " points of health\n";
}

void Creature::LearnAttack(Attack attackToLearn)
{
	mAttackPool.push_back(attackToLearn);
	std::cout << (mName + " learned " + attackToLearn.GetName()) << std::endl;
}

void Creature::TakeDamage(int amountDealt)
{
	mLifePoint -= amountDealt;
}

std::string GetName()
{
	return std::string();
}
