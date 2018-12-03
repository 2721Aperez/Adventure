#pragma once
#include "Weapon.hpp"

class Divine_Axe: public Weapon
{
private:
    int weight;
    int damage;
public:
    Divine_Axe():weight(50), damage(100){}
    int getAttackDamage()const override;
    int getWeight()const override;  
    void getWeaponType() override;
    //~Divine_Axe();  
};