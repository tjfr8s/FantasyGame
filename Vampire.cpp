#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Vampire.hpp"

Vampire::Vampire(Battle* battle): 
    Character(12, 6, 1, 18,"", Character::VAMPIRE, battle, 6, 1, 12, 1)
{}

void Vampire::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\n****attack****\n" << roll << "\n**************\n";
    if(opponent->defend(roll) <= 0)
    {
        std::cout <<"\nGameOver\n";
        // m_battle->gameOver();
    }

}
int Vampire::defend(int attackRoll)
{
    int defRoll = rollDice(m_defDiceNum, m_defDiceSides);
    std::cout << "\n*****defn*****\n" << defRoll << "\n**************\n\n";
    int damage = (attackRoll - defRoll - m_armor);
    if(damage > 0)
    {
        m_strength -= damage;
    }
    return m_strength;
}


bool Vampire::charm()
{
    int charmed = rand() % 2;
    if(charmed == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Vampire::specDefend()
{
    return charm();
}
