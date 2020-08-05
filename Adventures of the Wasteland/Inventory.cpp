#include "Inventory.h"

Inventory::Inventory()
{
	for (int i = 0; i < 14; i++)
	{
		inventorySpace.push_back(&item[i]);
	}
}

void Inventory::add(Item item)
{
	EmptyLine();
	if (isFull())
	{
		Write("Your inventory is full!");
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (inventorySpace.at(i)->getType() == ItemTypes::none)
			{
				inventorySpace.at(i)->copy(item);
				usedSpace++;
				break;
			}
		}
	}
	EmptyLine();
}

void Inventory::remove(int itemNum)
{
	EmptyLine();
	if ((itemNum) <= 13)
	{
		if (inventorySpace.at(itemNum - 1)->getType() == ItemTypes::none)
		{
			Write("There is not item in that space!");
		}
		else
		{
			std::cout << "Dropped " << inventorySpace.at(itemNum - 1)->getName();
			inventorySpace.at(itemNum - 1)->setType(ItemTypes::none);
			usedSpace--;
		}
	}
	else
	{
		Write("The item slot you chose is invalid!");
	}
	EmptyLine();
}

void Inventory::equip(int itemNum)
{
	if ((itemNum) <= 10)
	{
		int item = itemNum - 1;
		inventorySpace.at(13)->copy(inventorySpace.at(item)->getDuplicateObject()); //Moving the item to be equipped to temporary space
		switch (inventorySpace.at(item)->getType())
		{
			case ItemTypes::none:
				Write("Are you an idiot! There is no item in this slot to be equipped!!");
				break;

			case ItemTypes::sword:
				if (inventorySpace.at(10)->getType() == ItemTypes::none) usedSpace--; // Inventory space increment id nothing was equipped
				inventorySpace.at(item)->copy(inventorySpace.at(10)->getDuplicateObject());//Moving currently equipped item into inventory
				inventorySpace.at(10)->copy(inventorySpace.at(13)->getDuplicateObject());//Moving the item to be equipped from temporary space into the equipped slot
				std::cout << "\nEquipped " << inventorySpace.at(10)->getName();
				break;

			case ItemTypes::armour:
				if (inventorySpace.at(11)->getType() == ItemTypes::none) usedSpace--; // Inventory space increment id nothing was equipped
				inventorySpace.at(item)->copy(inventorySpace.at(11)->getDuplicateObject());//Moving currently equipped item into inventory
				inventorySpace.at(11)->copy(inventorySpace.at(13)->getDuplicateObject());//Moving the item to be equipped from temporary space into the equipped slot
				std::cout << "\nEquipped " << inventorySpace.at(11)->getName();
				break;

			case ItemTypes::shield:
				if (inventorySpace.at(12)->getType() == ItemTypes::none) usedSpace--; // Inventory space increment id nothing was equipped
				inventorySpace.at(item)->copy(inventorySpace.at(12)->getDuplicateObject());//Moving currently equipped item into inventory
				inventorySpace.at(12)->copy(inventorySpace.at(13)->getDuplicateObject());//Moving the item to be equipped from temporary space into the equipped slot
				std::cout << "\nEquipped " << inventorySpace.at(12)->getName();
				break;

			default:
				Write("This item is unequipable");
				break;
		}
	}
	else
	{
		Write("The item slot you chose is invalid!");
	}
	EmptyLine();

}

void Inventory::check()
{
	EmptyLine();
	int i = 0;
	if (usedSpace == 0)
	{
		Write("Your inventory is Empty!");
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (inventorySpace.at(i)->getType() == ItemTypes::none)
			{
				std::cout << std::endl << i+1 << ". Empty Space";
			}
			else
			{
				std::cout << std::endl << i+1 << ". " << inventorySpace.at(i)->getName();
			}
		}
	}

	EmptyLine();
	Write("Equipment Stats: (Sword, Armour and Shield)");
	EmptyLine();
	if (inventorySpace.at(10)->getType() == ItemTypes::none && inventorySpace.at(11)->getType() == ItemTypes::none && inventorySpace.at(12)->getType() == ItemTypes::none)
	{
		Write("You don't have anything equipped!");
	}
	else
	{
		for (i = 10; i < 13; i++)
		{
			if (inventorySpace.at(i)->getType() == ItemTypes::none)
			{
				std::cout << std::endl << i + 1 << ". Unequipped Slot";
			}
			else
			{
				std::cout << std::endl << i + 1 << ". " << inventorySpace.at(i)->getName();
			}
		}
	}
	EmptyLine();
}

void Inventory::setItemCapacity(int itemNum, int cap)
{
	inventorySpace.at(itemNum)->setCurrentCapacity(cap);
}

bool Inventory::isFull()
{
	return ((this->usedSpace == capacity)? true : false);
}

int Inventory::totalCapacity()
{
	return capacity;
}

int Inventory::used()
{
	return usedSpace;
}

int Inventory::useHealthPotion()
{
	int i, healing = 0;
	for (i = 0; i < 10; i++)
	{
		if (inventorySpace.at(i)->getType() == ItemTypes::healthPotion)
		{
			healing = inventorySpace.at(i)->getHeal();
			inventorySpace.at(i)->setType(ItemTypes::none);
			break;
		}
	}
	return healing;
}

int Inventory::getHealthPotionCount()
{
	int i, count=0;
	for (i = 0; i < 10; i++)
	{
		if (inventorySpace.at(i)->getType() == ItemTypes::healthPotion)
		{
			count++;
		}
	}
	return count;
}

int Inventory::getItemCapacity(int itemPos)
{
	return this->inventorySpace.at(itemPos)->getCurrentCapacity();
}

int Inventory::getItemDamage(int itemPos)
{
	return this->inventorySpace.at(itemPos)->getDamage();
}