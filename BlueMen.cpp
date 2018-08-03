#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "BlueMen.hpp"

BlueMen::BlueMen(Battle* battle): 
    Character(3, 12,"", Character::BLUEMEN, battle, 6, 3, 10, 2)
{}

BlueMen::~BlueMen()
{}

void BlueMen::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\nAttack roll: " << roll << "\n";
    if(opponent->defend(roll) <= 0)
    {
        m_battle->setWinner(this);
    }

}
int BlueMen::defend(int attackRoll)
{
    int defRoll = rollDice(m_defDiceNum, m_defDiceSides);
    std::cout << "Defense roll: " << defRoll << "\n";
    int damage = (attackRoll - defRoll - m_armor);
    if(damage < 0)
    {
        damage = 0;
    }
    std::cout << "Damage: " << damage << "\n";
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
        m_battle->gameOver();
    }

    return m_strength;
}


bool BlueMen::specDefend()
{
    return false;
}
