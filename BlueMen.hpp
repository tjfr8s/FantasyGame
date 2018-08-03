#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class Battle;
class BlueMen: public Character
{
public:
    BlueMen(Battle* battle);

    virtual ~BlueMen();
    virtual void attack(Character* opponent);
    virtual int defend(int attackRoll);
    virtual bool specDefend();

};

#endif

