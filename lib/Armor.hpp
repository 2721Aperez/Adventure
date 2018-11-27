#pragma once
#include <cstdlib>

class Armor
{
private:
    int defense;
public:
    Armor(): defense(5) {} //base value for armor defense
    virtual int getDefense()const{return defense;}
};