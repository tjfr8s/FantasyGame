/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a HarryPotter character type. HarryPotter
 * inherits from character and its attack and defense functions work like the
 * other characters without special abilities. The first time that 
 *HarryPotters strength drops to 0, he revies with 20 strength. 
*******************************************************************************/ 
#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"

/*******************************************************************************
 * Description: Constructor that initializes member variables to HarryPotter
 * values via the Character constructor.
*******************************************************************************/ 
HarryPotter::HarryPotter(Battle* battle): 
    Character(0, 10,"", Character::HARRYPOTTER, battle, 6, 2, 6, 2)
{}


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
HarryPotter::~HarryPotter()
{}


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. 
*******************************************************************************/ 
void HarryPotter::attack(Character* opponent)
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
 * to 0 and game over is called. The first time Harry Potter's health drops
 * to 0, he revives with 20 strength.
*******************************************************************************/ 
int HarryPotter::defend(int attackRoll)
{
    int defRoll = rollDice(m_defDiceNum, m_defDiceSides);
    std::cout << "4. Defense roll: " << defRoll << "\n";
    int damage = (attackRoll - defRoll - m_armor);
    if(damage < 0)
    {
        damage = 0;
    }
    std::cout << "5. Damage: " << damage << "\n";
    if(damage < 0)
    {
        damage = 0;
    }
    if(damage > 0)
    {
        m_strength -= damage;
    }
    if(m_strength <= 0 && m_hogwarts == true)
    {
        std::cout << "\nHogwarts!\n";
        hogwarts();
    }
    if(m_strength <= 0)
    {
        m_strength = 0;
        m_battle->gameOver();
    }
    return m_strength;
}

/*******************************************************************************
 * Description: Sets HP's strength to 20 if m_hogwarts = true
*******************************************************************************/ 
void HarryPotter::hogwarts()
{
    m_strength = 20;
    m_hogwarts = false;
}


/*******************************************************************************
 * Description: Returns false. Character has no special defense.
*******************************************************************************/ 
bool HarryPotter::specDefend()
{
    return false;
}
