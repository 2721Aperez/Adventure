#include "Sword.hpp"
#include "Stick.hpp"
#include "DivineAxeRhitta.hpp"
#include "AttackPotion.hpp"
#include "HealthPotion.hpp"
#include "vector"

#pragma once

using std::vector;

class Inventory
{
private:
	int max_weight;
	int current_weight;
	Weapon *weapon;
	vector<Potion*> potion;
public:
	Inventory() : max_weight(50), weapon(nullptr), potion{nullptr}, current_weight(0) {}
	void addWeapon(Weapon *weaponType);
	void addPotion(Potion *potionType);
	void removePotion(int i);
	void removeWeapon();
	int checkCapacity();
	void checkInventory();
};