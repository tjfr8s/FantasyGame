#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

Medusa::Medusa(Battle* battle): 
    Character(6, 6, 3, 8,"", Character::MEDUSA, battle, 6, 2, 6, 1)
{}

Medusa::~Medusa()
{}

void Medusa::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\nAttack roll: " << roll << "\n";
    if(roll == 12)
    {
        std::cout << "Medusa used Glare!\n";
        m_battle->gameOver();
    }
    else if(opponent->defend(roll) <= 0)
    {
        m_battle->gameOver();
        m_battle->setWinner(this);
    }

}
int Medusa::defend(int attackRoll)
{
    int defRoll = rollDice(m_defDiceNum, m_defDiceSides);
    std::cout << "Defense roll: " << defRoll << "\n";
    int damage = (attackRoll - defRoll - m_armor);
    std::cout << "Damage: " << damage << "\n";
    if(damage > 0)
    {
        m_strength -= damage;
    }
    return m_strength;
}


bool Medusa::specDefend()
{
    return false;
}

