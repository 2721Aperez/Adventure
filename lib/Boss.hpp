#pragma once

#include "../include/EnemyInterface.hpp"

class CTHULU: public EnemyInterface
{
private: 
    int HP;
    int attack_power;
    int defense;
public:
    CTHULU();
    ~CTHULU();
    void attack() override;
    void dodge() override;
    void transform();
};