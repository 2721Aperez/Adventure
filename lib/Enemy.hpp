#pragma once

class Enemy
{
private:
    int HP;
    int attck_power;
    int defense;
public:
    void attack();
    void dodge();
};