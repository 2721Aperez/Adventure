#pragma once
#include <iostream>
#include <cmath.h>
#include "Player.hpp"

class Enemy
{
public:
    Enemy();
    virtual void attack(Player *player) = 0;
    virtual void dodge() = 0;
    virtual ~Enemy();
};
