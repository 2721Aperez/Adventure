#include "Sword.hpp"


void Sword::setAttackDamage() {damage = rand()%40+10;}

int Sword::getAttackDamage()const
{
    return Weapon::getAttackDamage() + damage;
}

int Sword::getWeight()const{return weight;}