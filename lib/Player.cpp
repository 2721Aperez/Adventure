#include "Player.hpp"
#include "../include/Enemy.hpp"

Player::Player()
{
	HP = 100;
	attack_power = 10;
	defense = 10;
}

int Player::getHP() const
{
	return HP;
}

void Player::setHP(int hp)
{
	HP = hp;
}

int Player::getAttackPower() const
{
	return attack_power;
}

void Player::takeDamage(int damage)
{
	srand(time(0));
	int dodgeChance = rand() % 10;
	if (dodgeChance == 3 || dodgeChance == 7)
	{
		dodge();
	}
	else
	{
		damage -= defense;
		HP -= damage;
	}
}

void Player::attack(Enemy *enemy)
{
	enemy->takeDamage(attack_power);
}

void Player::dodge()
{
	std::cout << "You dodged the attack!" << std::endl;
}

bool Player::isDead()
{
	if (HP <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
