#include "Armament.h"

Armament::Armament()
{
	mName = "Wooden Stick";
	mDescription = "Just a wooden stick found on the floor";
	mRarity = ItemRarity::COMMON;
}

Armament::Armament(std::string name, std::string descritpion, ItemRarity rarity)
{
	mName = name;
	mDescription = descritpion;
	mRarity = rarity;
}

Armament::~Armament()
{
}

std::string Armament::GetName()
{
	return mName;
}

std::string Armament::GetDescription()
{
	return mDescription;
}

std::string Armament::GetRarity()
{
	switch (mRarity)
	{
	case ItemRarity::DEFAULT:
		return "default";
		break;
	case ItemRarity::COMMON:
		return "common";
		break;
	case ItemRarity::RARE:
		return "rare";
		break;
	case ItemRarity::EPIC:
		return "epic";
		break;
	case ItemRarity::LEGENDARY:
		return "legendary";
		break;
	default:
		return "default";
		break;
	}
}

void Armament::GiveAFullDescription()
{
	std::cout << "The item is an armament called \"" << GetName() << "\"." << std::endl;
	std::cout << "Descritpion : \"" << GetDescription() << "\"." << std::endl;
	std::cout << "The armament is " << GetRarity() << std::endl;
}
