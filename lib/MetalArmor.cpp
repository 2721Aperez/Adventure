#include "MetalArmor.hpp"
#include <cstdlib>

void MetalArmor::setDefense(){defense = rand() % 50+1;}

int MetalArmor::getDefense()const {return defense;}