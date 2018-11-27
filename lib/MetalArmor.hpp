#pragma once

#include "Armor.hpp"

class MetalArmor:public Armor
{
private:
    int defense;
public:
    void setDefense()override;
    int getDefense()const;
};