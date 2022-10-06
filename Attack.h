#pragma once
#include <string>
#include <iostream>
class Attack
{
private:
	std::string mName;
	int mDamage;
	int mNumberOfDiceThrowPerAtk;

public:
	Attack();
	Attack(std::string name, int damage);
	~Attack();
	int RollDice(int diceMaxValue);
	int DamageDealt();
	std::string GetName();
};