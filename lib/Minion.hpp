#pragma once

#include "../include/EnemyInterface.hpp"

class Minion: public EnemyInterface
{
private:
    int HP;
    int attck_power;
    int defense;
public:
    Minion();
    ~Minion();
    void attack() override;
    void dodge() override;
};