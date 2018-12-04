#include "Sword.hpp"
#include "Stick.hpp"
#include "DivineAxeRhitta.hpp"
#include "AttackPotion.hpp"
#include "HealthPotion.hpp"
#include "vector"
#include "LeatherArmor.hpp"
#include "MetalArmor.hpp"


#pragma once
using std::vector;

class Inventory
{
private:
	int max_weight;
	int current_weight;
	Weapon *weapon;
	Armor *armor;

public:
	Inventory() : max_weight(50), weapon(nullptr), armor(nullptr), current_weight(0) {}
	void addWeapon(Weapon *weaponType);
	void addPotion(Potion *potionType);
	void addArmor(Armor *armorType);
	void removePotion(int i);
	void removeWeapon();
	void removeArmor();
	int getWeaponAttack();
	int checkCapacity();
	void checkInventory();
	vector<Potion*> potion;
	void consume(int index); //removes a potion at a given index
};