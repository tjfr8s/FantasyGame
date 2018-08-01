#include <iostream>
#include "Character.hpp"
#include "Battle.hpp"
#include "Vampire.hpp"

void printChars(Character*, Character*);

int main()
{
    srand(time(NULL));
    Battle* battle = new Battle;

    Character* vampire = new Vampire(battle);
    Character* opponent = new Vampire(battle);

    printChars(vampire, opponent);

    
    for(int i = 0; i < 5; i++)
    {
        std::cout << "\n\nVampire attacks opponent:\n";
        vampire->attack(opponent);
        printChars(vampire, opponent);
    } 

    for(int i = 0; i < 10; i++)
    {
        if(vampire->specDefend())
        {
            std::cout << "\ncharm\n";
        } 
        else
        {
            std::cout << "\nno charm\n";
        }
    }

    delete opponent;
    delete vampire;
    delete battle;
    return 0;
}


void printChars(Character* vampire, Character* opponent)
{
    std::cout << "******************************\n" <<
        "vampire:\n" << vampire << "\n******************************\n";

    std::cout << "******************************\n" <<
        "opponent:\n" << opponent << "\n******************************\n";
}
