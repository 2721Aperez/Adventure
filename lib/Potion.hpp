#pragma once
#include <iostream>

class Potion
{
private:
    int weight;
    int bonus;

public:
    Potion() : weight (1), bonus (0) {}
    virtual void consume(Potion *potion) = 0;
    virtual ~Potion();
};
