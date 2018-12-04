#pragma once
#include "Potion.hpp"


class AttackPotion : public Potion
{
private:
    int attack_bonus;

public:
    AttackPotion() : attack_bonus(5) {}
    //void consume(Potion *potion) { delete potion; }
    void getPotionType() override { std::cout << "Potion Type: Attack Potion" << std::endl; }
    ~AttackPotion() {}
    int getAttack() override { return  attack_bonus;}
    std::string potionType = "attack";
};
