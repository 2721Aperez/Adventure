#pragma once

#include "../include/Enemy.hpp"
class Boss : public Enemy
{
private:
	int HP;
	int attack_power;
	int defense;
public:
	Boss();
	~Boss();
	void attack(Player player) override;
	void dodge() override;
	void takeDamage(int attack_power) override;
	void isDead();
	void transform();
	
};
