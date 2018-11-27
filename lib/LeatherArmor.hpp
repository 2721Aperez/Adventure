#pragma once

#include "Armor.hpp"

class LeatherArmor:public Armor
{
private:
    int defense;
    int weight;
public:
    LeatherArmor():weight(5){}
    void setDefense();
    int getDefense()const override;
    int getWeight()const;
};