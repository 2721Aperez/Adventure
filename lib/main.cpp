#include "Player.hpp"
#include "Enemy.hpp"
#include "Minion.hpp"
#include "EnemyFactory.hpp"
#include <string>
#include <cstdlib>


char generateRoom();
bool generateBossEncounter(Player &Adventurer);
bool generateMinionEncounter(Player &Adventurer);
void generateLoot(Player &Adventurer);
bool programFlowWait();

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
                            //Enters if minion is defeated
                            std::cout << "For defeating the minion, you are able to loot the chest." << std::endl;
                            generateLoot(*adventurer);
                            std::cout << "You exit the room and proceed deeper into the dungeon." <<std::endl;
                            generatedRoom = generateRoom();
                        }
                        else {
                            //Enters if player is defeated
                            std::cout << "You were slain to a minion, you would have had no chance against the boss." << std::endl;
                            bossEntered = true; //to exit loop
                        }
                        programFlowWait();
                        break;
                    case 'h': //hallway
                        /*
                         * Generate enemy to fight to go on
                         */
                        if(generateMinionEncounter(*adventurer)){
                            //play defeats minion
                            std::cout << "Congratulations for defeating the enemy! " << std::endl;
                            std::cout << "With it out of the way, you are able to proceed." << std::endl;

                        }
                        else {
                            //player dies
                            std::cout << "Unfortunately you have perished to a mere minion." <<std::endl;
                            bossEntered = true; //exits loop

                        }
                        programFlowWait();
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
                        programFlowWait();
                        break;
                    case 'd': //dead end
                        /*
                         * Do nothing, generate new room
                         */
                        std::cout << "The dungeons of ZugZwang are full of deadends! You turn around and head deeper into the dungeon." << std::endl;
                        programFlowWait();
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
                programFlowWait();
                startGame = false;
            }
            else {
                //generate boss fight
                if (generateBossEncounter(*adventurer)) {
                    std::cout << "Congratulations Adventurer!" << std::endl;
                    std::cout << "You have slain ZugZwang's greatest enemy, the dungeon now belongs to you!" << std::endl;
                    startGame = false;
                }
                else {
                    std::cout << "The guardian of ZugZwang has claimed another victim." << std::endl;
                    programFlowWait();
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
    //std::cout << "generated: " << room << std::endl;
    return room;
}
bool generateMinionEncounter(Player &Adventurer) {
    /*
     * Returns true if player defeats minion, false if player dies
     */
    EnemyFactory enemyType;
    Enemy *minion = enemyType.make_chooser("minion");
    bool onGoingBattle = true;
    char potion;
    int potion_damage;

    while(onGoingBattle){
        std::cout << "Adventurer HP: " << Adventurer.getHP() << std::endl;
        std::cout << "Minion HP: " << minion->getHP() << std::endl;
        if(Adventurer.backpack.potion.empty()){
            //No potions available
            potion_damage = 0;
        }
        else
        {
            std::cout << "You have potions available to use, would you like to use them during this fight?" << std::endl;
            std::cout << "Enter (A) to use Attack Potion, (H) for Health Potion, (N) for no potion." << std::endl;
            Adventurer.backpack.checkInventory();
            std::cin >> potion;
            if(potion == 'A'){
                //check for attack potion
                bool potionFound = false;
                int potion_index;
                for(int i = 0; i < Adventurer.backpack.potion.size(); i++){
                    if(Adventurer.backpack.potion[i]->potionType == "attack"){
                        potion_index = i;
                        potionFound = true;
                    }
                }
                if(potionFound){
                    potion_damage = Adventurer.backpack.potion[potion_index]->getAttack();
                    Adventurer.backpack.consume(potion_index);
                }
                else
                {
                    std::cout << "That potion was not found in your inventory." << std::endl;
                }
            }
            else if(potion == 'H'){
                bool potionFound = false;
                int potion_index;
                for(int i = 0; i < Adventurer.backpack.potion.size(); i++){
                    if(Adventurer.backpack.potion[i]->potionType == "health"){
                        potion_index = i;
                        potionFound = true;
                    }
                }
                if(potionFound){
                    Adventurer.setHP(Adventurer.getHP() + 5);
                    Adventurer.backpack.consume(potion_index);
                }
                else
                {
                    std::cout << "That potion was not found in your inventory." << std::endl;
                }
            }
        }
        minion->takeDamage(Adventurer.getAttackPower() + Adventurer.backpack.getWeaponAttack() + potion_damage);
        //Check if minion is dead
        if(minion->isDead()){
            std::cout << "Congratulations! You have slain the minion!" << std::endl;
            std::cout << "You have " << Adventurer.getHP() << " HP left after defeating the minion." << std::endl;
            onGoingBattle = false; //only way to exit loop other than player dying
        }
        else
        {
            Adventurer.takeDamage(minion->getAttackPower());
            //check if player died
            if(Adventurer.isDead()){
                return false;
            }
        }
        programFlowWait();
    }
    return true;
}
void generateLoot(Player &Adventurer) {
    int randItem = rand() % 10;
    char take_choice;
    std::cout << "You open the chest and find the following." << std::endl;
    switch(randItem){
        case 0: //Divine Axe
            std::cout << "You have been blessed by the Gods and found the Divine Axe Rhitta!" << std::endl;
            std::cout << "This axe is so heavy and powerful that it can be the only item equipped." << std::endl;
            std::cout << "Would you like to replace your current weapon and all your equipment? (Y) (N)" << std::endl;
            std::cin >> take_choice;
            if(take_choice == 'Y') {
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
            std::cin >> take_choice;
            if(take_choice == 'Y'){
                Adventurer.backpack.removeWeapon();
                Adventurer.backpack.addWeapon(new Sword);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 2: //Stick
            std::cout << "You have found a stick in the chest, not the best." << std::endl;
            std::cout << "Would you like to replace your current weapon? (Y) (N)" << std::endl;
            std::cin >> take_choice;
            if(take_choice == 'Y'){
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
            std::cin >> take_choice;
            if(take_choice == 'Y'){
                Adventurer.backpack.removeArmor();
                Adventurer.backpack.addArmor(new LeatherArmor);
            }
            break;
        case 4: //Metal Armor
            std::cout << "You open the chest and find some shiny Metal Armor!" << std::endl;
            std::cout << "Would you like to take and equip the armor? (Y) (N)" << std::endl;
            std::cin >> take_choice;
            if(take_choice == 'Y'){
                Adventurer.backpack.removeArmor();
                Adventurer.backpack.addArmor(new MetalArmor);
            }
            break;
        case 5: //Attack Potion
            std::cout << "You open the chest to find a bright red potion used to boost your attack power!" << std::endl;
            std::cout << "Would you like to take the Attack potion? (Y) (N)" << std::endl;
            std::cin >> take_choice;
            if(take_choice == 'Y'){
                Adventurer.backpack.addPotion(new AttackPotion);
            }
            else {
                std::cout << "You leave behind the item in the chest." << std::endl;
            }
            break;
        case 6: //Health Potion
            std::cout << "You open the chest to find a deep green potion used to heal yourself." << std::endl;
            std::cout << "Would you like to take the Health potion? (Y) (N)" << std::endl;
            if(take_choice == 'Y'){
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
    int potion_damage;
    char potion_choice;
    bool currentBattle;
    EnemyFactory enemyType;
    Enemy *boss = enemyType.make_chooser("boss");
    std::cout << "Welcome to the deepest chamber within ZugZwang" << std::endl;
    std::cout << "Not many can make it this far, but no one has yet defeated me!" << std::endl;
    while(currentBattle){
        if(Adventurer.backpack.potion.empty()){
            //no potions to use
            potion_damage = 0;
        }
        else {
            std::cout << "You have potions available for use, would you like use any?" << std::endl;
            std::cout << "Enter (A) to use Attack Potion, (H) for Health Potion, (N) for no potion." << std::endl;
            Adventurer.backpack.checkInventory();
            std::cin >> potion_choice;
            if(potion_choice == 'A'){
                //check for attack potion
                bool potionFound = false;
                int potion_index;
                for(int i = 0; i < Adventurer.backpack.potion.size(); i++){
                    if(Adventurer.backpack.potion[i]->potionType == "attack"){
                        potion_index = i;
                        potionFound = true;
                    }
                }
                if(potionFound){
                    potion_damage = Adventurer.backpack.potion[potion_index]->getAttack();
                    Adventurer.backpack.consume(potion_index);
                }
                else
                {
                    std::cout << "That potion was not found in your inventory." << std::endl;
                }
            }
            else if(potion_choice == 'H'){
                bool potionFound = false;
                int potion_index;
                for(int i = 0; i < Adventurer.backpack.potion.size(); i++){
                    if(Adventurer.backpack.potion[i]->potionType == "health"){
                        potion_index = i;
                        potionFound = true;
                    }
                }
                if(potionFound){
                    Adventurer.setHP(Adventurer.getHP() + 5);
                    Adventurer.backpack.consume(potion_index);
                }
                else
                {
                    std::cout << "That potion was not found in your inventory." << std::endl;
                }
            }
            boss->takeDamage(Adventurer.getAttackPower() + Adventurer.backpack.getWeaponAttack() + potion_damage);
            programFlowWait();
            if(boss->getHP() <= 50){
                std::cout << "It has been a long time since anyone has pushed me this far! You shall pay!" << std::endl;
                boss->transform();
                std::cout << "You see the boss has transformed to its true form! A tentacle'd beast known at Cthulu!!" << std::endl;
                std::cout << "In this form, the boss has increased attack power, be careful Adventurer!" << std::endl;
            }
            Adventurer.takeDamage(boss->getAttackPower());
            programFlowWait();
        }
        programFlowWait();
    }
    return true;
}
bool programFlowWait(){
    /*
     * Without some sort of wait, things such as battles happen to quickly if user doesn't have potions
     */
    int uselessVariable = 0;
    std::cout << "Please press enter (1) to continue." << std::endl;
    std::cin >> uselessVariable;
    return uselessVariable;

}




