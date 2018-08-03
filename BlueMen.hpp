/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a BlueMen character type. BlueMen 
 * inherits from Character and its attack functions like the other normal 
 * attacking characters. If the BlueMen strength drops below 8 and 4, it loses
 * a defense die.
*******************************************************************************/ 
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class Battle;
class BlueMen: public Character
{
public:
/*******************************************************************************
 * Description: Constructor that initializes member variables to BlueMen values
 * via the Character constructor.
*******************************************************************************/ 
    BlueMen(Battle* battle);


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~BlueMen();


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. 
*******************************************************************************/ 
    virtual void attack(Character* opponent);


/*******************************************************************************
 * Description: This function takes an attack roll as a parameter. It makes
 * a defense roll and calculats the damage to be taken by the player. If
 * the damage exceeds or equals the remaining strength points, strength is set
 * to 0 and game over is called. If the m_strength drops to 8 or below the
 * BlueMen lose a defense die. If it drops to 4 or below, another defense
 * die is lost.
*******************************************************************************/ 
    virtual int defend(int attackRoll);


/*******************************************************************************
 * Description: Returns false. Character has no special defense.
*******************************************************************************/ 
    virtual bool specDefend();

};

#endif

