#include "Menu.hpp"
/************************************************************
 * Author: Tyler Freitas
 * Date: 07/01/2018
 * Description: This file contains a function for printing a
 * menu and getting a selection from the user and a function
 * for controlling the execution of a program using a menu.
************************************************************/


/************************************************************
 * Description:
 * Preconditions:
 *      Call function.
 * Postconditions:
 *      A menu is printed to the console.
 *      The user's choice is read into a variale and returned.
************************************************************/
int getPlayer()
{
    std::cout << "1. Vampire \n";
    std::cout << "2. Medusa \n";
    std::cout << "3. Barbarian \n";
    std::cout << "4. BlueMen\n";
    std::cout << "5. HarryPotter\n";
    
    int userChoice = intInputValidation(1, 5);

    return userChoice;
}


/************************************************************
 * Description:
 * Preconditions:
 *      Call function.
 * Postcondition:
 *      - The menu is contiuously displayed until the user
 *      chooses to quit.
 *      - The user is asked to enter a number of rows, columns
 *      and steps.
 *      - Langton's ant is simulated using the user input.
 ************************************************************/
void runMenu()
{
    std::cout << "Choose character for player 1:\n " << std::endl;
    int p1Choice = getPlayer();
    std::cout << "Choose character for player 2:\n " << std::endl;
    int p2Choice = getPlayer();
    Battle battle(p1Choice, p2Choice);
    battle.playGame();
    return;
}


