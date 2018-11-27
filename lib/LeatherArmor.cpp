#include "LeatherArmor.hpp"
#include <cstdlib>

void LeatherArmor::setDefense(){defense = rand() % 10 +1;}

int LeatherArmor::getDefense()const {return defense;}