#pragma once

#include <stdlib.h>
#include <cmath.h>
#include "Direction.hpp"
<<<<<<< HEAD
#inlcude "Enemy.hpp"
=======
#include "Inventory.hpp"

>>>>>>> 5f18159f51c71d4f9f51ca6653acf0e9020e78c3

class Player
{
private:
    int HP;
    int attack_power;
    int defense;

public:
    Player();
<<<<<<< HEAD
    int getHP() const;
    int getAttackPower() const;
    void setHP(int hp);
    void takeDamage(Enemy *enemy);
    void attack(Enemy *enemy);
    void dodge();
    bool isDead();
    ~Player();
};
=======
    void attack();
    void pickUp();
    void drop();
    void useItem();//Item type in parameter
    void move(Direction);//Direction type in parameter
};
>>>>>>> 5f18159f51c71d4f9f51ca6653acf0e9020e78c3
