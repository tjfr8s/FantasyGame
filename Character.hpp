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
        VAMPIRE,
        MEDUSA,
        BARBARIAN,
        BLUEMEN,
        HARRYPOTTER,
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
    Character(int armor,
              int strength,
              std::string traits,
              CharType type,
              Battle* battle,
              int defDiceSides,
              int defDiceNum,
              int atkDiceSides,
              int atkDiceNum);

    virtual ~Character();
    virtual std::string getType();

    virtual void attack(Character* opponent) = 0;
    virtual int defend(int attackRoll) = 0;
    virtual bool specDefend() = 0;
    virtual void die();
    friend  std::ostream& operator<<(std::ostream& out, Character* character);
};

std::ostream& operator<<(std::ostream& out, Character* character);

#endif
