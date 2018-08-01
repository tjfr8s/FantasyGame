#include <iostream>
#include "Character.hpp"
#include "Battle.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"

void printChars(Character*, Character*);

int main()
{
    srand(time(NULL));
    Battle* battle = new Battle;

    Character* barbarian = new Barbarian(battle);
    Character* opponent = new Vampire(battle);

    printChars(barbarian, opponent);

    
    for(int i = 0; i < 5; i++)
    {
        std::cout << "\n\nBarbarian attacks opponent:\n";
        barbarian->attack(opponent);
        printChars(barbarian, opponent);
    } 


    delete opponent;
    delete barbarian;
    delete battle;
    return 0;
}


void printChars(Character* barbarian, Character* opponent)
{
    std::cout << "******************************\n" <<
        "barbarian:\n" << barbarian << "\n******************************\n";

    std::cout << "******************************\n" <<
        "opponent:\n" << opponent << "\n******************************\n";
}

