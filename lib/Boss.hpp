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
	int getHP() const override;
	int getAttackPower() const override;
	void takeDamage(int damage) override;
	void attack(Player *player) override;
	void dodge() override;
	bool isDead() override;
	void transform()override;
	~Boss() {}
};
