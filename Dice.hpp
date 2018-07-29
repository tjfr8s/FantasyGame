/*******************************************************************************
 * Description: This file describes a dice function that takes an integer 
 * number of dice and integer number of sides as parameters. The function
 * simulates rolling the dice and returns the value of the roll.
*******************************************************************************/ 
#ifndef DICE_HPP
#define DICE_HPP
#include <cstdlib>
#include <time.h>

/*******************************************************************************
 * Description: This function simulates a roll of dice and returns the value
 * of the roll
*******************************************************************************/ 
int rollDice(int numDice, int numSides);

#endif
