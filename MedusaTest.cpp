#include <iostream>
#include "Character.hpp"
#include "Battle.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"

void printChars(Character*, Character*);

int main()
{
    srand(time(NULL));
    Battle* battle = new Battle;

    Character* medusa = new Medusa(battle);
    Character* opponent = new Vampire(battle);

    printChars(medusa, opponent);

    
    for(int i = 0; i < 5; i++)
    {
        std::cout << "\n\nMedusa attacks opponent:\n";
        medusa->attack(opponent);
        printChars(medusa, opponent);
    } 


    delete opponent;
    delete medusa;
    delete battle;
    return 0;
}


void printChars(Character* medusa, Character* opponent)
{
    std::cout << "******************************\n" <<
        "medusa:\n" << medusa << "\n******************************\n";

    std::cout << "******************************\n" <<
        "opponent:\n" << opponent << "\n******************************\n";
}

