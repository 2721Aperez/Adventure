#pragma once

#include "Armor.hpp"

class LeatherArmor:public Armor
{
private:
    int defense;
public:
    void setDefense()override;
    int getDefense()const;
};