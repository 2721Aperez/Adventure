#include "Stick.hpp"
#include <cstdlib>

Stick::Stick(){weight = 5;}

void Stick::setAttackDamage(){damage = rand()%5+1;}

int Stick::getAttackDamage()const{return damage;}