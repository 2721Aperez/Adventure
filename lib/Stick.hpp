#pragma once

#include "Weapon.hpp"

class Stick:public Weapon
{
private:
    int weight;
    int damage;
    int durability;
public:
    void attack();

};