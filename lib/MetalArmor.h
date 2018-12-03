#pragma once
#include "Armor.h"

class MetalArmor :public Armor
{
private:
    int defense;
    int weight;
public:
    MetalArmor() : weight(10) {} //Weight for MEtal Armor
    void setDefense();
    int getDefense()const override;
    int getWeight()const override;
};
