#pragma once

#include "Weapon.hpp"

class Stick:public Weapon
{
private:
    int weight;
    int damage;
    //int durability;
public:
    Stick(): weight(5){}
    void setAttackDamage();
    int getAttackDamage()const override;
    int getWeight()const override; 
    //~Stick();
};