#include "LeatherArmor.hpp"

void LeatherArmor::setDefense()
{
    defense = rand() % 10 +1; //Value randomly chosen from 1-10
}

int LeatherArmor::getDefense()const 
{
    return Armor::getDefense() + defense;
}

int LeatherArmor::getWeight()const {return weight;}