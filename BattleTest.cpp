#include "Battle.hpp"
#include "Character.hpp"
#include "Dice.hpp"
#include "Vampire.hpp"

int main()
{
    Battle battle;
    srand(time(NULL));
    rand();

    battle.playGame();

    return 0;
}
