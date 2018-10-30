#pragma once

#include "Direction.hpp"
#include "Item.hpp"

class Player
{
private:
    int HP;
    int attack_power;
    int defense;

public:
    void attack(int);
    void pickUp();
    void drop();
    void useItem();//Item type in parameter
    void direction(Direction);//Direction type in parameter
};