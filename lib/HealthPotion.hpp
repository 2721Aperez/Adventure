#include "Potion.hpp"


class HealthPotion: public Potion
{
private:
    int health_bonus;

public:
    HealthPotion() : health_bonus(5) {}
    void consume(Potion *potion){ delete potion; }
    ~HealthPotion();
};
