#pragma once 
#include <iostream>
#include <cstdlib>

class Weapon
{
private:
    int base_damage;
public:
    Weapon(): base_damage(rand()%5+1){}
    virtual int getAttackDamage()const{ return base_damage; }
    virtual int getWeight()const = 0;
    virtual void getWeaponType() = 0;
    //virtual ~Weapon();
};