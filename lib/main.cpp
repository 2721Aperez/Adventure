#include "Player.hpp"
#include "Enemy.hpp"
#include "Minion.hpp"
//#include "Direction.h"
#include "EnemyFactory.hpp"
#include <string>
#include <cstdlib>


char generateRoom();
bool generateBossEncounter(Player &Adventurer);
bool generateMinionEncounter(Player &Adventurer);
void battle(Player &Adventurer, Enemy &enemy);


int main() {
    bool startGame = false;
    bool bossEntered = false;
    bool exitGame = false;
    bool firstRoom = true;
    int roomsGenerated; //after 5 rooms generated, force boss
    int choice;
    char generatedRoom;
    std::cout << "Weapon and Potion is an Decorator" << std::endl;
    std::cout << "The above statement was for Alex, please DO NOT DELETE, thank you for understanding" << std::endl;

    while (!exitGame) {
        std::cout << "Greetings Adventurer!" << std::endl;
        std::cout << "Would you like to play The Dungeon of ZugZwang?" << std::endl;
        std::cout << "1. Enter ZugZwang." << std::endl;
        std::cout << "2. No I'm scared!" << std::endl;
        std::cout << "3. Exit Game" << std::endl;
        std::cin >> choice;
        if (choice == 1) {
            startGame = true;
        }
        else if (choice == 2) {
            std::cout << "Okay, maybe next time." << std::endl;
        }
        else if (choice == 3) {
            std::cout << "Thanks for playing, please restart application to play next time!." << std::endl;
            exitGame = true;
        }
        else {
            std::cout << "Thats not a valid choice." << std::endl;
        }
        while (startGame) {
            Player *adventurer = new Player;
            firstRoom = true;
            roomsGenerated = 0;
            std::cout << "Hello Adventurer, welcome to the dungeon of ZugZwang." << std::endl;
            std::cout << "You come to the end of the hallway, would you like to turn left or right? " << std::endl;
            std::cin >> generatedRoom; //for the feels.
            generatedRoom = generateRoom();
            roomsGenerated++;

            while (!bossEntered) { //check if player is dead in loop as well
                switch (generatedRoom) {
                    case 'r': //room
                        /*
                         * Generate an enemy to fight, loot chest after
                         */
                        std::cout << "You have found a room within the dungeon containing a chest!" << std::endl;
                        std::cout << "A random minion appears and attacks!" << std::endl;
                        if (generateMinionEncounter(*adventurer)) {
                            //Enters if player dies to minion
                        }
                        else {
                            //Enters if minion is defeated
                        }
                        break;
                    case 'h': //hallway
                        /*
                         * Generate enemy to fight to go on
                         */
                        break;
                    case 'b'://boss room
                        /*
                         * Cannot enter on first generation
                         */
                        std::cout << "Hello Adventurer, you have encounter the boss room!" << std::endl;
                        if (firstRoom) {
                            std::cout << "RNG was not on your side, we won't make you enter the boss this soon." << std::endl;
                            firstRoom = false;
                        }
                        else {
                            bossEntered = true;
                            std::cout << "Good luck Adventurer." << std::endl;
                            std::cout << "I hope you have had enough luck to gather some items, else this will be difficult." << std::endl;
                        }
                        break;
                    case 'd': //dead end
                        /*
                         * Do nothing, generate new room
                         */
                        break;
                    default:
                        break;
                }
                roomsGenerated++;
                if (roomsGenerated == 5) {
                    //time to face boss
                    generatedRoom = 'b';
                }
                else {
                    generatedRoom = generateRoom();
                }
            }
            //exit while loop due to entering boss fight or player dies
            if (adventurer->isDead()) { //check if player is dead
                std::cout << "You have fought bravely Adventurer, but alas the dungeon of ZugZwang has prevailed!." << std::endl;
                delete adventurer;
                startGame = false;
            }
            else {
                //generate boss fight
                if (generateBossEncounter(*adventurer)) {
                    std::cout << "Congratulations Adventurer!" << std::endl;
                    std::cout << "You have slain ZugZwang's greatest enemy, the dungeon now belongs to you!" << std::endl;
                }
                else {
                    std::cout << "The guardian of ZugZwang has claimed another victim." << std::endl;
                    delete adventurer;
                }
            }
        }
    }
    return 0;
}
char generateRoom() {
    char room;
    int random = rand() % 10;
    switch (random) {
        case 1: //1 - 3 generate a room
        case 2:
        case 3: room = 'r';
            break;
        case 4: //4 - 6 generate a hallway
        case 5:
        case 6: room = 'h';
            break;
        case 7: //7 generate boss room
            room = 'b';
            break;
        case 8: //dead end
        case 9:
        case 0: room = 'd';
            break;
    }
    return room;
}
bool generateMinionEncounter(Player &Adventurer) {
    /*
     * Returns true if player defeats minion, false if player dies
     */
    EnemyFactory enemyType;
    Enemy *minion = enemyType.make_chooser("minion");
    bool battleEnded = false;
    while(!battleEnded){
        //battle(&Adventurer, minion);

    }
    return true;
}
void generateLoot(Player &Adventurer) {
    int randItem = rand() % 10;
    char choice;
    std::cout << "You open the chest and find the following." << std::endl;
    switch(randItem){
        case 0: //Divine Axe
            std::cout << "You have been blessed by the Gods and found the Divine Axe Rhitta!" << std::endl;
            std::cout << "This axe is so heavy and powerful that it can be the only item equipped." << std::endl;
            std::cout << "Would you like to replace your current weapon and all your equipment? (Y) (N)" << std::endl;
            std::cin >> choice;
            if(choice == 'Y') {
                Adventurer.backpack.removeWeapon();
                Adventurer.backpack.removeArmor();
                for(int i = 0; i < Adventurer.backpack.potion.size() - 1; i++){
                    Adventurer.backpack.removePotion(i);
                }
                Adventurer.backpack.addWeapon(new Divine_Axe);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 1: //Sword
            std::cout << "You have found a sword in the chest!" << std::endl;
            std::cout << "Would you like to replace your current weapon? (Y) (N)" << std::endl;
            std::cin >> choice;
            if(choice == 'Y'){
                Adventurer.backpack.removeWeapon();
                Adventurer.backpack.addWeapon(new Sword);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 2: //Stick
            std::cout << "You have found a stick in the chest, not the best." << std::endl;
            std::cout << "Would you like to replace your current weapin? (Y) (N)" << std::endl;
            std::cin >> choice;
            if(choice == 'Y'){
                Adventurer.backpack.removeWeapon();
                Adventurer.backpack.addWeapon(new Stick);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 3: //Leather Armor
            std::cout << "You open the chest and find some Leather Armor." << std::endl;
            std::cout << "Would you like to take and equip the armor? (Y) (N)" << std::endl;
            std::cin >> choice;
            if(choice == 'Y'){
                Adventurer.backpack.removeArmor();
                Adventurer.backpack.addArmor(new LeatherArmor);
            }
            break;
        case 4: //Metal Armor
            std::cout << "You open the chest and find some shiny Metal Armor!" << std::endl;
            std::cout << "Would you like to take and equip the armor? (Y) (N)" << std::endl;
            std::cin >> choice;
            if(choice == 'Y'){
                Adventurer.backpack.removeArmor();
                Adventurer.backpack.addArmor(new MetalArmor);
            }
            break;
        case 5: //Attack Potion
            std::cout << "You open the chest to find a bright red potion used to boost your attack power!" << std::endl;
            std::cout << "Would you like to take the Attack potion? (Y) (N)" << std::endl;
            std::cin >> choice;
            if(choice == 'Y'){
                Adventurer.backpack.addPotion(new AttackPotion);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 6: //Health Potion
            std::cout << "You open the chest to find a deep green potion used to heal yourself." << std::endl;
            std::cout << "Would you like to take the Health potion? (Y) (N)" << std::endl;
            if(choice == 'Y'){
                Adventurer.backpack.addPotion(new HealthPotion);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 7:

        case 8:

        case 9:
            std::cout << "Unfortunately the chest was empty." << std::endl;
        default: break;
    }

}
bool generateBossEncounter(Player &Adventurer) {
    /*
     * Returns true if player defeats boss, false if player dies
     */
    EnemyFactory enemyType;
    Enemy *boss = enemyType.make_chooser("boss");
    return true;
}
void battle(Player &Adventurer, Enemy &enemy){
    Adventurer.takeDamage(enemy.getAttackPower());
    enemy.takeDamage(Adventurer.getAttackPower());
}



