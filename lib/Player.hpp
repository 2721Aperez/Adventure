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
	void attack(Enemy enemy);
	void takeDamage(int damage);
	void dodge();
	bool isDead();
	//~Player();
};
