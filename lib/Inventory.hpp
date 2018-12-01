#include "Sword.hpp"
#include "Stick.hpp"
#include "DivineAxeRhitta.hpp"
#include "Potion.hpp"


class Inventory
{
private:
    int max_weight;
    int current_weight;

public:
    Inventory(): max_weight(50){}
    void addWeapon(Weapon *weaponType);
    void addPotion(Potion *potionType);
    void removeItem();
    int checkCapacity();
};