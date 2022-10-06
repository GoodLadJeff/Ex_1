#include "Inventory.h"
Inventory::Inventory(std::string name, std::vector<Armament> itemsStored)
{
	mName = name;
	mItemsStored = itemsStored;
}

Inventory::~Inventory()
{
}

int Inventory::GetSize()
{
	return mItemsStored.size();
}

void Inventory::Summarise()
{
	std::cout << std::endl;

	std::cout << mName << " contains " << GetSize() << " elements" << std::endl;
	for (int i = 0; i < GetSize(); i++) 
	{
		std::cout << i+1 << ": " << mItemsStored[i].GetName();
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void Inventory::RemoveObjectAtLocation(int location)
{
	if (location >= GetSize() || location < 0) 
	{
		cout << "There is no item number " << location << std::endl;
		return;
	}

	std::vector<Armament>::iterator i;

	/*i = mItemsStored.begin();
	i += location;*/

	i = mItemsStored.begin();
	std::advance(i, location);

	std::cout << mItemsStored[location].GetName() << " has been removed from inventory." << std::endl;
	mItemsStored.erase(i);


	/*mItemsStored[location].~Armament();*/
}

void Inventory::SwapObjects(int location1, int location2)
{
	std::vector<Armament>::iterator i = mItemsStored.begin();
	std::vector<Armament>::iterator j = mItemsStored.begin();

	std::advance(i, location1);
	std::advance(j, location2);

	std::cout << i -> GetName() << " has been swapped with " << j->GetName() << std::endl;

	std::swap(*i, *j);

	//std::swap(mItemsStored[location1], mItemsStored[location2]);
}