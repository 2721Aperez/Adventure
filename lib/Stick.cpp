#include "Stick.hpp"



void Stick::setAttackDamage(){damage = rand()%5+1;}

int Stick::getAttackDamage()const
{
    return Weapon::getAttackDamage() + damage;
}

int Stick::getWeight()const
{
    return weight;
}