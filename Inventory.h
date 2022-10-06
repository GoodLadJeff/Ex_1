#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "IItem.h"
#include "Armament.h"

class Inventory
{
private:
	std::string mName;
	std::vector<Armament> mItemsStored;

public:
	Inventory(std::string name, std::vector<Armament> itemsStored);
	~Inventory();

	int GetSize();

	void Summarise();
	void RemoveObjectAtLocation(int location);
	void SwapObjects(int location1, int location2);
};

