/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a Medusa character type. Medusa inherits
 * from Character and attacks like the other characters. If Medusa rolls
 * a 12 while attacking it activates Glare which sets the opponents strength
 * to 0. 
*******************************************************************************/ 
#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

/*******************************************************************************
 * Description: Constructor that initializes member variables to Vampire values
 * via the Character constructor.
*******************************************************************************/ 
Medusa::Medusa(Battle* battle): 
    Character(3, 8,"", Character::MEDUSA, battle, 6, 1, 6, 2)
{}


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
Medusa::~Medusa()
{}


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. If medusa rolls a 12 it calls the 
 * opponents die function.
*******************************************************************************/ 
void Medusa::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\n3. Attack roll: " << roll << "\n";
    if(roll == 12)
    {
        std::cout << "Medusa used Glare!\n";
        opponent->die();
        opponent->defend(12);
    }
    else if(opponent->defend(roll) <= 0)
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
int Medusa::defend(int attackRoll)
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
bool Medusa::specDefend()
{
    return false;
}

