#pragma once

#include "Direction.hpp"
#include "Inventory.hpp"


class Player
{
private:
    int HP;
    int attack_power;
    int defense;

public:
    Player();
    void attack();
    void pickUp();
    void drop();
    void useItem();//Item type in parameter
    void move(Direction);//Direction type in parameter
};