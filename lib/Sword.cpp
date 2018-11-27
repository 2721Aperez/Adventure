#include "Sword.hpp"
#include <cstdlib>

Sword::Sword(){weight = 10;}

void Sword::setAttackDamage() {damage = rand()%50+1;}

int Sword::getAttackDamage()const{return damage;}