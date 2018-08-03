#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"

HarryPotter::HarryPotter(Battle* battle): 
    Character(0, 10,"", Character::HARRYPOTTER, battle, 6, 2, 6, 2)
{}

HarryPotter::~HarryPotter()
{}

void HarryPotter::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\nAttack roll: " << roll << "\n";
    if(opponent->defend(roll) <= 0)
    {
        m_battle->setWinner(this);
    }

}
int HarryPotter::defend(int attackRoll)
{
    int defRoll = rollDice(m_defDiceNum, m_defDiceSides);
    std::cout << "Defense roll: " << defRoll << "\n";
    int damage = (attackRoll - defRoll - m_armor);
    if(damage < 0)
    {
        damage = 0;
    }
    std::cout << "Damage: " << damage << "\n";
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

void HarryPotter::hogwarts()
{
    m_strength = 20;
    m_hogwarts = false;
}

bool HarryPotter::specDefend()
{
    return false;
}
