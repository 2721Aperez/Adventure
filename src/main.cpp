#include <iostream>
#include "../lib/Armor.hpp"
using namespace std;

int main() {

    Armor armor;

    cout << "Base defense is " << armor.getDefense() << endl;

    cout << "Weapon and Potion is an Decorator" << endl;

    return 0;
}