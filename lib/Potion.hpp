#pragma once
#include <iostream>

class Potion
{
private:
    int weight;

public:
    Potion() : weight (5) {}
    virtual void consume(Potion *potion) = 0;
    virtual ~Potion();
};
