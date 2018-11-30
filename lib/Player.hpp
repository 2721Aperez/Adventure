#pragma once

#include <stdlib.h>
#include <cmath.h>
#include "Direction.hpp"
#inlcude "Enemy.hpp"

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
    void attack(Enemy *enemy);
    void dodge();
    bool isDead();
    ~Player();
};
