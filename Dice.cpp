#include "Dice.hpp"

int rollDice(int numDice, int numSides)
{
    int roll(0);
    for(int i = 0; i < numDice; i++)
    {
        roll += (rand() % numSides) + 1;
    }
    return roll;
}
