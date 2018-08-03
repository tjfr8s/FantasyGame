/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a Medusa character type. Medusa inherits
 * from Character and attacks like the other characters. If Medusa rolls
 * a 12 while attacking it activates Glare which sets the opponents strength
 * to 0. 
*******************************************************************************/ 
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Battle;
class Medusa: public Character
{
public:
/*******************************************************************************
 * Description: Constructor that initializes member variables to Medusa values
 * via the Character constructor.
*******************************************************************************/ 
    Medusa(Battle* battle);


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~Medusa();


/*******************************************************************************
 * Description: This function  accepts a Character* parameter pointing to the
 * opponent. It then simulates a dice roll and calls the opponent's defend
 * function, passing it the attack roll. If medusa rolls a 12 it calls the 
 * opponents die function.
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

