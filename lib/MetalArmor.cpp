#include "MetalArmor.hpp"

void MetalArmor::setDefense() { defense = rand() % 50 + 1; }



int MetalArmor::getDefense()const
{
    return Armor::getDefense() + defense;
}



int MetalArmor::getWeight()const { return weight; }