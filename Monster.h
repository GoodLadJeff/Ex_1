#pragma once
#include "Creature.h"
#include <string>
class Monster : public Creature
{

public:
    Monster();
    Monster(std::string name, int lifePoint, int defense);

    void TakeDamage(int amountDealt);
};

