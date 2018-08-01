#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class Battle;
class HarryPotter: public Character
{
private:
    bool m_hogwarts = true;
public:
    HarryPotter(Battle* battle);

    virtual ~HarryPotter();
    virtual void attack(Character* opponent);
    virtual int defend(int attackRoll);
    virtual bool specDefend();

};

#endif

