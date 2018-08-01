#include "Character.hpp"

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



