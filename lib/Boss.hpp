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
	int getHP() const;
	int getAttackPower() const;
	void takeDamage(int damage);
	void attack(Player *player) override;
	void dodge() override;
	bool isDead() override;
	void transform()override;
	~Boss() {}
};
