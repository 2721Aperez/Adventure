#include "Boss.hpp"

Boss::Boss()

{
    HP = 100;
    attack_power = 20;
    defense = 8;
}

int Boss::getHP() const
{
    return HP;
}

int Boss::getAttackPower() const
{
    return attack_power;
}

void Boss::takeDamage(int damage)
{
    bool isDead = false;

    srand(time(0));
    int dodgeChance = rand() % 10;
    if (dodgeChance == 2 || dodgeChance == 8)
    {
        dodge();
    }
    else
    {
        damage -= defense;
        HP -= damage;
    }
}

void Boss::attack(Player *player)
{
    player->takeDamage(attack_power);
}

void Boss::dodge()
{
    std::cout << "The Boss dodged you're attack!" << std::endl;
}

bool Boss::isDead()
{
    if (HP <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Boss::transform()
{
    if (HP <= (HP / 2))
    {
        attack_power = 80;
        HP += 30;
    }
}

