#pragma once

#include <stdlib.h>
#include "Direction.hpp"
#include "../include/Enemy.hpp" 

class Player
{
private:
    int HP;
    int attack_power;
    int defense;

public:
    Player();
    int getHP() const;
    int getAttackPower() const;
    void setHP(int hp);
    void takeDamage(Enemy *enemy);
    void dodge();
    bool isDead();
    ~Player();
};
