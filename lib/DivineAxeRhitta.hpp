#pragma once
#include "Weapon.hpp"

class Divine_Axe: public Weapon
{
private:
    int weight;
    int damage;
public:
    Divine_Axe():weight(70), damage(100){}
    // void setAttackDamage();
    int getAttackDamage()const override;
    int getWeight()const;    
};