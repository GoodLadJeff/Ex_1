#pragma once
#include "IItem.h"
class Consumable : public IItem
{
public:
	Consumable();
	Consumable(std::string name, std::string descritpion, ItemRarity rarity);
	~Consumable();

	std::string GetName();
	std::string GetDescription();
	std::string GetRarity();
	void GiveAFullDescription();
};

