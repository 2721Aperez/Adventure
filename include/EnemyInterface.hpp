#pragma once

class EnemyInterface
{
private:
    int HP = 100;
    int attck_power = 10;
    int defense = 10;
public:
    virtual void attack() = 0;
    virtual void dodge() = 0;
    virtual ~EnemyInterface();
};