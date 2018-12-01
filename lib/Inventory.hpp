#include "Sword.hpp"
#include "Stick.hpp"
#include "DivineAxeRhitta.hpp"
#include "Potion.hpp"

#pragma once

class Inventory
{
private:
    int max_weight;
    int current_weight;
    Weapon *weapon;
    Potion *potion;
public:
    Inventory(): max_weight(50){}
    void addWeapon(Weapon *weaponType);
    void addPotion(Potion *potionType);
    void removePotion();
    void removeWeapon();
    int checkCapacity();
};