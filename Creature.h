#pragma once
#include "Attack.h"
#include <string>
#include <vector>

class Creature
{
private:
	std::string mName;
	int mLifePoint;
	std::vector<Attack> mAttackPool;
	int mDefense;

public:
	Creature();
	Creature(std::string name, int lifePoint, int defense);
	~Creature();

	std::string GetName();
	int GetLifePoint();
	std::vector<Attack> GetAttackPool();

	void AttackTarget(int attackSlot, Creature& target);
	void Heal(int amountToHeal);
	void LearnAttack(Attack attackToLearn);
	virtual void TakeDamage(int amountDealt);
};