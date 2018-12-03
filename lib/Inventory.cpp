#include "Inventory.hpp"

void Inventory::addWeapon(Weapon *weaponType) 
{
	int remaining_weight = max_weight - current_weight;

	if (weaponType->getWeight() >= max_weight)
	{
		std::cout << "You don't have enough room for this weapon." << std::endl;
	}
	else if (remaining_weight < weaponType->getWeight())
	{
		std::cout << "You have no more room for this weapon.  Drop an Item or something you hoarder." << std::endl;
	}
	else
	{
		weapon = weaponType;
		current_weight += weaponType->getWeight();
	}
}

void Inventory::addPotion(Potion *potionType)
{
	int remaining_weight = max_weight - current_weight;

	if (potionType->getWeight() >= max_weight)
	{
		std::cout << "You don't have enough room for this potion." << std::endl;
	}
	else if (remaining_weight < potionType->getWeight())
	{
		std::cout << "You have no more room for this potion. Drop something you hoarder" << std::endl;
	}
	else
	{
		potion.push_back(potionType);
		current_weight += potionType->getWeight();
	}
}

void Inventory::removePotion(int i)
{
	int j = 0;
	for (auto it = potion.begin(); it != potion.end(); it++)
	{
		j++;
		if (j == i)
		{
			potion.erase(it);
			break;
		}
	}
}

void Inventory::removeWeapon()
{
	delete weapon;
}

int Inventory::checkCapacity()
{
	return current_weight;
}

void Inventory::checkInventory()
{
	if (weapon == nullptr) { std::cout << "You have no weapons." << std::endl; }
	else
	{
		std::cout << "Current Weapon: ";
		weapon->getWeaponType();
	}
	if (potion.empty()) { std::cout << "You have no potions." << std::endl; }

}