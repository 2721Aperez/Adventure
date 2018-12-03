#pragma once

#include <iostream>
#include "../lib/Player.hpp"


class Enemy
{
public:
	Enemy() {}
	virtual int getHP() const = 0;
	virtual int getAttackPower() const = 0;
	virtual void attack(Player *player) = 0;
	virtual void takeDamage(int attack_power) = 0;
	virtual void dodge() = 0;
	virtual void transform() = 0;
	virtual bool isDead() = 0;
	virtual ~Enemy() {}
};