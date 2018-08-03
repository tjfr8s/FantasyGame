/*******************************************************************************
 * Author: Tyler Freitas
 * Date: 20180802
 * Description: This class describes a HarryPotter character type. HarryPotter
 * inherits from character and its attack and defense functions work like the
 * other characters without special abilities. The first time that 
 *HarryPotters strength drops to 0, he revies with 20 strength. 
*******************************************************************************/ 
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class Battle;
class HarryPotter: public Character
{
private:
    bool m_hogwarts = true;
public:
/*******************************************************************************
 * Description: Constructor that initializes member variables to HarryPotter
 * values via the Character constructor.
*******************************************************************************/ 
    HarryPotter(Battle* battle);


/*******************************************************************************    
 * Description: Virtual destructor.
*******************************************************************************/ 
    virtual ~HarryPotter();


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
 * to 0 and game over is called. The first time Harry Potter's health drops
 * to 0, he revives with 20 strength.
*******************************************************************************/ 
    virtual int defend(int attackRoll);
    

/*******************************************************************************
 * Description: Sets HP's strength to 20 if m_hogwarts = true
*******************************************************************************/ 
    void hogwarts();


/*******************************************************************************
 * Description: Returns false. Character has no special defense.
*******************************************************************************/ 
    virtual bool specDefend();

};

#endif

