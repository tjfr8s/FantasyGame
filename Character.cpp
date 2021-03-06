#include "Character.hpp"
#include <iostream>

Character::Character(int attack,
                     int defense, 
                     int armor,
                     int strength,
                     std::string traits,
                     CharType type,
                     Battle* battle,
                     int defDiceSides,
                     int defDiceNum,
                     int atkDiceSides,
                     int atkDiceNum):
    m_attack(attack),
    m_defense(defense),
    m_armor(armor),
    m_strength(strength),
    m_traits(traits),
    m_type(type),
    m_battle(battle),
    m_defDiceSides(defDiceSides),
    m_defDiceNum(defDiceNum),
    m_atkDiceSides(atkDiceSides),
    m_atkDiceNum(atkDiceNum)
{}

Character::~Character()
{}

std::ostream& operator<<(std::ostream& out, Character* character)
{
    out << "\nAttack: " << character->m_attack << "\nDefense: " << 
        character->m_defense << "\nArmor: " << character->m_armor << 
        "\nStrength: " << character->m_strength << "\nTraits: " <<
        character->m_traits << "\nType: " << character->m_type << 
        "\nBattle: " << character->m_battle <<  "\nDefense dice: " << 
        character->m_defDiceSides << " " << character->m_defDiceNum <<
        "\nAttack dice: " << character->m_atkDiceSides << " " << 
        character->m_atkDiceNum;

    return out;
}



