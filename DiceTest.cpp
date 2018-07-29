#include <cstdio>
#include "Dice.hpp"

int main()
{
    srand(time(NULL));
    rand();
    int numDice = 2;
    int numSides = 4;
    int roll = rollDice(numDice, numSides);
    printf("Rolling %i dice with %i sides: %i\n", numDice, numSides, roll);
    numDice = 3;
    numSides = 21;
    roll = rollDice(numDice, numSides);
    printf("Rolling %i dice with %i sides: %i\n", numDice, numSides, roll);
    return 0;
}
