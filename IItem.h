#pragma once
#include <iostream>
#include <string>
#include"ItemRarity.h"

using namespace std;

class IItem
{
protected:
	std::string mName;
	std::string mDescription;
	ItemRarity mRarity;

public:
	virtual std::string GetName() = 0;
	virtual std::string GetDescription() = 0;
	virtual std::string GetRarity() = 0;
	virtual void GiveAFullDescription() = 0;
};