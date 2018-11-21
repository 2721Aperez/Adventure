#include "Armor.hpp"

Armor::Armor()
{

}

void Armor::setDefense(int defense_value)
{
    defense = defense_value;
}

int Armor::getDefense()const{return defense;}