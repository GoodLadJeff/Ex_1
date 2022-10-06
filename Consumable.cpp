#include "Consumable.h"

Consumable::Consumable()
{
	mName = "Water Bottle";
	mDescription = "Bottle with a bit of water left inside it";
	mRarity = ItemRarity::COMMON;
}

Consumable::Consumable(std::string name, std::string descritpion, ItemRarity rarity)
{
	mName = name;
	mDescription = descritpion;
	mRarity = rarity;
}

Consumable::~Consumable()
{
}

std::string Consumable::GetName()
{
	return mName;
}

std::string Consumable::GetDescription()
{
	return mDescription;
}

std::string Consumable::GetRarity()
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

void Consumable::GiveAFullDescription()
{
	std::cout << "The item is an armament called \"" << GetName() << "\"." << std::endl;
	std::cout << "Descritpion : \"" << GetDescription() << "\"." << std::endl;
	std::cout << "The armament is " << GetRarity() << std::endl;
}
