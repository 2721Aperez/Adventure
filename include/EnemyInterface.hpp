#pragma once

class EnemyInterface
{
public:
    virtual void attack() = 0;
    virtual void dodge() = 0;
    virtual ~EnemyInterface();
};