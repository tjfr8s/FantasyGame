#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Battle;
class Vampire: public Character
{
public:
    Vampire(Battle* battle);

    virtual void attack(Character* opponent);
    virtual void defend(int attackRoll);
    virtual bool specDefend();

};

#endif
