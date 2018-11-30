#include "Sword.hpp"
#include "Stick.hpp"
#include "DivineAxeRhitta.hpp"


class Inventory
{
private:
    int max_weight;
    int current_weight;

public:
    Inventory(): max_weight(50){}
    void addItem();
    void removeItem();
    int checkCapacity();
};