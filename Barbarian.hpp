#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Battle;
class Barbarian: public Character
{
public:
    Barbarian(Battle* battle);

    virtual ~Barbarian();
    virtual void attack(Character* opponent);
    virtual int defend(int attackRoll);
    virtual bool specDefend();

};

#endif

