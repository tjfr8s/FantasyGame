/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This function is a driver for testing the functionality of
 * different characters in a battle. It allows the user to choose two characters
 * to battle and prints the result of the fight.
******************************************************************************/ 
#include "Battle.hpp"
#include "Character.hpp"
#include "Dice.hpp"
#include "Menu.hpp"

int main()
{
    srand(time(NULL));
    rand();
    runMenu();
    return 0;
}
