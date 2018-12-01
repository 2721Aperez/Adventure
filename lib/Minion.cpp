#include "Minion.hpp"

Minion::Minion()
{
	HP = 100;
	attack_power = 35;
	defense = 5;
}

int Minion::getHP() const
{
	return HP;
}

int Minion::getAttackPower() const
{
	return attack_power;
}

void Minion::takeDamage(int damage) 
{
	bool isDead = false;

	srand(time(0));
	int dodgeChance = rand() % 10;
	if (dodgeChance == 2 || dodgeChance == 8)
	{
		dodge();
	}
	else
	{
		damage -= defense;
		HP -= damage;
	}
}

void Minion::attack(Player *player)
{
	player->takeDamage(attack_power);
}

void Minion::dodge()
{
	std::cout << "Minion dodged you're attack!" << std::endl;
}

bool Minion::isDead()
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
