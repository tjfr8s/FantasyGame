#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"

Barbarian::Barbarian(Battle* battle): 
    Character(0, 12,"", Character::BARBARIAN, battle, 6, 2, 6, 2)
{}

Barbarian::~Barbarian()
{}

void Barbarian::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\n3. Attack roll: " << roll << "\n";
    if(opponent->defend(roll) <= 0)
    {
        m_battle->setWinner(this);
    }

}
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


bool Barbarian::specDefend()
{
    return false;
}
