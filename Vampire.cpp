#include <iostream>
#include "Battle.hpp"
#include "Character.hpp"
#include "Vampire.hpp"

Vampire::Vampire(Battle* battle): 
    Character(1, 18,"", Character::VAMPIRE, battle, 6, 1, 12, 1)
{}

Vampire::~Vampire()
{}

void Vampire::attack(Character* opponent)
{
    int roll = rollDice(m_atkDiceNum, m_atkDiceSides); 
    std::cout << "\n3. Attack roll: " << roll << "\n";
    if(opponent->defend(roll) <= 0)
    {
        m_battle->setWinner(this);
    }

}
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
bool Vampire::specDefend()
{
    return charm();
}
