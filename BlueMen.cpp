/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a BlueMen character type. BlueMen 
 * inherits from Character and its attack functions like the other normal 
 * attacking characters. If the BlueMen strength drops below 8 and 4, it loses
 * a defense die.
*******************************************************************************/ 
#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "BlueMen.hpp"


/*******************************************************************************
 * Description: Constructor that initializes member variables to BlueMen values
 * via the Character constructor.
*******************************************************************************/ 
BlueMen::BlueMen(Battle* battle): 
    Character(3, 12,"", Character::BLUEMEN, battle, 6, 3, 10, 2)
{}


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
BlueMen::~BlueMen()
{}


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. 
*******************************************************************************/ 
void BlueMen::attack(Character* opponent)
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
 * to 0 and game over is called. If the m_strength drops to 8 or below the
 * BlueMen lose a defense die. If it drops to 4 or below, another defense
 * die is lost.
*******************************************************************************/ 
int BlueMen::defend(int attackRoll)
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

    if(m_strength <= 4)
    {
        m_defDiceNum = 1;
    }
    else if(m_strength <= 8)
    {
        m_defDiceNum = 2;
    }
    if(m_strength <= 0)
    {
        m_strength = 0;
        m_battle->gameOver();
    }

    return m_strength;
}


/*******************************************************************************
 * Description: Returns false. Character has no special defense.
*******************************************************************************/ 
bool BlueMen::specDefend()
{
    return false;
}
