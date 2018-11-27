#pragma once

#include "Direction.hpp"


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
    void direction(Direction);//Direction type in parameter
};