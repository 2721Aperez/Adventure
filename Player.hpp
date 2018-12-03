#pragma once

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Inventory.hpp"


class Enemy;

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
    void attack(Enemy *enemy);
    void takeDamage(int damage);
    void dodge();
    bool isDead();
    Inventory backpack;
    //~Player();
};
