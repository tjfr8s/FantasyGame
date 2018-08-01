#include "Battle.hpp"
#include "Character.hpp"
#include "Dice.hpp"
#include "Vampire.hpp"

int main()
{
    Battle battle;
    srand(time(NULL));
    rand();
    for(int i = 0; i < 3; i++)
    {
        battle.playGame();
    }

    return 0;
}
