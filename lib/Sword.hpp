#pragma once
#include "Weapon.hpp"

class Sword: public Weapon
{
private:
    int weight;
    int damage;
public:
    Sword(): weight(40){}
    void setAttackDamage();
    int getAttackDamage()const override;
    int getWeight()const override;
    void getWeaponType() override;
    //~Sword(); 
};