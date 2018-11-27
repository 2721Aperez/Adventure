#pragma once
#include "Weapon.hpp"

class Sword: public Weapon
{
private:
    int weight;
    int damage;
public:
    Sword();
    void setAttackDamage()override;
    int getAttackDamage()const;
};