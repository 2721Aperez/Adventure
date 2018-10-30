#pragma once

class Item
{
private:
    int weight;
public:
    virtual void displayStats() = 0;
};