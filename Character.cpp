/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This abstract class describes a generic character for a fantasy 
 * game. It has data members for the characters armor, strength, traits, type,
 * battle, and dice. 
*******************************************************************************/ 
#include "Character.hpp"
#include <iostream>

/*******************************************************************************
 * Description: Constructor that takes the following parameters:
 * - armor
 * - strength
 * - traits
 * - type
 * - battle
 * - defDiceNum
 * - defDiceSides
 * - atkDiceNum
 * -atkDiceSides
 * the constructor initializes data members to the values of the passed 
 * parameters.
*******************************************************************************/ 
Character::Character(int armor,
                     int strength,
                     std::string traits,
                     CharType type,
                     Battle* battle,
                     int defDiceSides,
                     int defDiceNum,
                     int atkDiceSides,
                     int atkDiceNum):
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


/*******************************************************************************
 * Description: virtual desctuctor.
*******************************************************************************/ 
Character::~Character()
{}



std::string Character::getTypeString()
{
    std::string type;
    switch(m_type)
    {
        case VAMPIRE:
            type = "VAMPIRE";
            break;
        case MEDUSA:
            type = "MEDUSA";
            break;
        case BARBARIAN:
            type = "BARBARIAN";
            break;
        case BLUEMEN:
            type = "BLUEMEN";
            break;
        case HARRYPOTTER:
            type = "HARRYPOTTER";
            break;
    }
    return type;
}


/*******************************************************************************
 * Description: Function that sets the characters strength equal to 0.
*******************************************************************************/ 
void Character::die()
{
    m_strength = 0;
}


std::ostream& operator<<(std::ostream& out, Character* character)
{
    out << "\nArmor: " << character->m_armor << 
        "\nStrength: " << character->m_strength << "\nTraits: " <<
        character->m_traits << "\nType: " << character->getTypeString() << 
        "\nDefense dice: " << 
        character->m_defDiceSides << " " << character->m_defDiceNum <<
        "\nAttack dice: " << character->m_atkDiceSides << " " << 
        character->m_atkDiceNum;

    return out;
}


