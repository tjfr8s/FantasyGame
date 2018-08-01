#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Battle;
class Medusa: public Character
{
public:
    Medusa(Battle* battle);

    virtual ~Medusa();
    virtual void attack(Character* opponent);
    virtual int defend(int attackRoll);
    virtual bool specDefend();

};

#endif

