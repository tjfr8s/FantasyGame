/************************************************************
 * Author: Tyler Freitas
 * Date: 07/01/2018
 * Description: This file contains a function for simulating 
 * Langton's ant to the user's specifications.
************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "Battle.hpp"
#include "IntegerValidation.hpp"
/************************************************************
 * Description:
 * Preconditions:
 *      Call function.
 * Postconditions:
 *      A menu is printed to the console.
 ************************************************************/
int  getMenu();


/************************************************************
 * Description:
 * Preconditions:
 *      Call function.
 * Postcondition:
 *      The menu is contiuously displayed until the user
 *      chooses to quit.
 ************************************************************/
void runMenu();


#endif
