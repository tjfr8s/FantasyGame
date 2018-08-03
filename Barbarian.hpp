/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a Barbarian character type. Barbarian
 * inherits from character and its attack and defense functions work like the
 * other characters without special abilities. 
*******************************************************************************/ 
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Battle;
class Barbarian: public Character
{
public:
/*******************************************************************************
 * Description: Constructor that initializes member variables to Barbarian values
 * via the Character constructor.
*******************************************************************************/ 
    Barbarian(Battle* battle);


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~Barbarian();


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
 * to 0 and game over is called. 
*******************************************************************************/ 
    virtual int defend(int attackRoll);


/*******************************************************************************
 * Description: Returns false. Character has no special defense.
*******************************************************************************/ 
    virtual bool specDefend();

};

#endif

