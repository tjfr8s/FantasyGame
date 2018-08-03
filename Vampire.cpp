/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a Vampire character. It has 1 armor, 18
 * strength, and 2d6 defense and 1d12 attack. It has a 50 percent chance of
 * charming an attacker into not attacking.
*******************************************************************************/ 
#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Vampire.hpp"


/*******************************************************************************
 * Description: Constructor that initializes member variables to Vampire values
 * via the Character constructor.
*******************************************************************************/ 
Vampire::Vampire(Battle* battle): 
    Character(1, 18,"", Character::VAMPIRE, battle, 6, 1, 12, 1)
{}


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
Vampire::~Vampire()
{}


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. 
*******************************************************************************/ 
void Vampire::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\n3. Attack roll: " << roll << "\n";
    if(opponent->defend(roll) <= 0)
    {
        m_battle->setWinner(this);
    }

}


/*******************************************************************************
 * Description: This function takes an attack roll as a parameter. It makes
 * a defense roll and calculats the damage to be taken by the player. If
 * the damage exceeds or equals the remaining strength points, strength is set
 * to 0 and game over is called.  
*******************************************************************************/ 
int Vampire::defend(int attackRoll)
{
    int defRoll = rollDice(m_defDiceNum, m_defDiceSides);
    std::cout << "4. Defense roll: " << defRoll << "\n";
    int damage = (attackRoll - defRoll - m_armor);
    if(damage < 0)
    {
        damage = 0;
    }
    std::cout << "5. Damage: " << damage << "\n";
    if(damage > 0)
    {
        m_strength -= damage;
    }

    if(m_strength <= 0)
    {
        m_strength = 0;
        m_battle->gameOver();
    }
    return m_strength;
}


/*******************************************************************************
 * Description: charm is a funciton that has a 50% chance of returning true.
*******************************************************************************/ 
bool Vampire::charm()
{
    int charmed = rand() % 2;
    if(charmed == 1)
    {
        std::cout << "\nVampire used charm!";
        return true;
    }
    else
    {
        return false;
    }
}


/*******************************************************************************  
 * Description: specDefend returns true if charm activates.
*******************************************************************************/ 
bool Vampire::specDefend()
{
    return charm();
}
