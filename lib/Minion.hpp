#pragma once

#include <stdlib.h>
#include <time.h>
#include "../include/Enemy.hpp"

class Minion: public Enemy
{
private:
    int HP;
    int attack_power;
    int defense;
public:
    Minion();
    int getHP() const;
    int getAttackPower() const;
    void takeDamage(int damage);
    void attack(Player *player) override;
    void dodge() override;
    bool isDead();
    ~Minion();
};
