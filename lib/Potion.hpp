#pragma once
#include <iostream>

class Potion
{
private:
	int weight;

public:
	Potion() : weight(5) {}
	virtual void consume(Potion *potion) = 0;
	int getWeight()const { return weight; }
	virtual void getPotionType() = 0;
	virtual ~Potion() {}
};

