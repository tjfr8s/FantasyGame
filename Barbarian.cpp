/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a Barbarian character type. Barbarian
 * inherits from character and its attack and defense functions work like the
 * other characters without special abilities. 
*******************************************************************************/ 
#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"

/*******************************************************************************
 * Description: Constructor that initializes member variables to Barbarian values
 * via the Character constructor.
*******************************************************************************/ 
Barbarian::Barbarian(Battle* battle): 
    Character(0, 12,"", Character::BARBARIAN, battle, 6, 2, 6, 2)
{}


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
Barbarian::~Barbarian()
{}


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. 
*******************************************************************************/ 
void Barbarian::attack(Character* opponent)
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
int Barbarian::defend(int attackRoll)
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
 * Description: Returns false. Character has no special defense.
*******************************************************************************/ 
bool Barbarian::specDefend()
{
    return false;
}
