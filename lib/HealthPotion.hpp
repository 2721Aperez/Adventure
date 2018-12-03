#include "Potion.hpp"

#pragma once

class HealthPotion : public Potion
{
private:
	int health_bonus;

public:
	HealthPotion() : health_bonus(5) {}
	void consume(Potion *potion) { delete potion; }
	void getPotionType() override { std::cout << "Potion Type: Health Potion" << std::endl; }
	~HealthPotion() {}
};
