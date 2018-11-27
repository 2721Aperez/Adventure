#pragma once

#include "Armor.hpp"

class MetalArmor:public Armor
{
private:
    int defense;
public:
    void setDefense();
    int getDefense()const;
};