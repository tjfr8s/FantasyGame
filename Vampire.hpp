/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a Vampire character. It has 1 armor, 18
 * strength, and 2d6 defense and 1d12 attack. It has a 50 percent chance of
 * charming an attacker into not attacking.
*******************************************************************************/ 
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Battle;
class Vampire: public Character
{
public:

/*******************************************************************************
 * Description: Constructor that initializes member variables to Vampire values
 * via the Character constructor.
*******************************************************************************/ 
    Vampire(Battle* battle);


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~Vampire();


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
 * Description: charm is a funciton that has a 50% chance of returning true.
*******************************************************************************/ 
    bool charm();

/*******************************************************************************  
 * Description: specDefend returns true if charm activates.
*******************************************************************************/ 
    virtual bool specDefend();

};

#endif
