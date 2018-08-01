#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Battle;
class Vampire: public Character
{
public:
    Vampire(Battle* battle);

    virtual ~Vampire();
    virtual void attack(Character* opponent);
    virtual int defend(int attackRoll);
    virtual bool specDefend();
    bool charm();

};

#endif
