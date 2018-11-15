#pragma once

#include <iostream>
using namespace std;

class Item
{
private:
    int weight;
public:
    virtual void displayStats();
};