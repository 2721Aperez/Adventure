#include "Player.hpp"

Player::Player()
{
    HP = 100;
    attack_power = 10;
    defense = 10;
}

int Player::getHP() const
{
    return HP;
}

void Player::setHP(int hp)
{
    HP = hp;
}

int Player::getAttackPower() const
{
    return attack_power;
}

void Player::takeDamage(Enemy *enemy)
{
    srand(time(0));
    int dodgeChance = rand() % 10;
    if(dodgeChance == 3 || dodgeChance == 7)
    {
        dodge();
    }
    else
    {
        int damage = enemy.getAttackPower();
        damage -= defense;
        HP -= damage;
    }
}

void Player::attack(Enemy *enemy)
{
    enemy.takeDamage(attack_power);
}

void Player::dodge()
{
    std::cout << "You dodged the attack!" << endl;
}

<<<<<<< HEAD
bool Player::isDead()
=======
void Player::move(Direction dir)
>>>>>>> 5f18159f51c71d4f9f51ca6653acf0e9020e78c3
{
    if(HP <= 0)
    {
      return true;
    }
    else
    {
      return false;
    }
}
