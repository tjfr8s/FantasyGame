/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This abstract class describes a generic character for a fantasy 
 * game. It has data members for the characters armor, strength, traits, type,
 * battle, and dice. 
*******************************************************************************/ 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Dice.hpp"

class Battle;
class Character
{
public:
    enum CharType
    {
        VAMPIRE = 1,
        MEDUSA = 2,
        BARBARIAN = 3,
        BLUEMEN = 4,
        HARRYPOTTER = 5,
    };
protected:
    int m_armor;
    int m_strength;
    std::string m_traits;
    CharType m_type;
    Battle* m_battle;
    int m_defDiceSides;
    int m_defDiceNum;
    int m_atkDiceSides;
    int m_atkDiceNum;
    
public:
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
    Character(int armor,
              int strength,
              std::string traits,
              CharType type,
              Battle* battle,
              int defDiceSides,
              int defDiceNum,
              int atkDiceSides,
              int atkDiceNum);


/*******************************************************************************
 * Description: virtual desctuctor.
*******************************************************************************/ 
    virtual ~Character();

    
/*******************************************************************************
 * Description: Function that sets the characters strength equal to 0.
*******************************************************************************/ 
    virtual void die();


    virtual std::string getTypeString();


    virtual void attack(Character* opponent) = 0;
    virtual int defend(int attackRoll) = 0;
    virtual bool specDefend() = 0;

    int getArmor(){return m_armor;}
    int getStrength(){return m_strength;}
    friend  std::ostream& operator<<(std::ostream& out, Character* character);
};

std::ostream& operator<<(std::ostream& out, Character* character);

#endif
