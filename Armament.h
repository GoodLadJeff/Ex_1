#pragma once
#include "IItem.h"
class Armament : public IItem
{
public:
	Armament();
	Armament(std::string name, std::string descritpion = "null desc", ItemRarity rarity = ItemRarity::DEFAULT);
	~Armament();
	
	std::string GetName();
	std::string GetDescription();
	std::string GetRarity();
	void GiveAFullDescription();
};

