#pragma once
#include "Weapon.hpp"

class Sword: public Weapon
{
private:
    int weight;
    int damage;
public:
    Sword(): weight(20){}
    void setAttackDamage();
    int getAttackDamage()const override;
    int getWeight()const;
};