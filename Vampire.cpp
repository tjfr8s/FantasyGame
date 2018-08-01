#include "Battle.hpp"
#include "Character.hpp"
#include "Vampire.hpp"

Vampire::Vampire(Battle* battle): 
    Character(12, 6, 1, 18,"", Character::VAMPIRE, battle, 6, 1, 12, 1)
{}

void Vampire::attack(Character* opponent)
{}
void Vampire::defend(int attackRoll)
{}
bool Vampire::specDefend()
{
    return true;
}
