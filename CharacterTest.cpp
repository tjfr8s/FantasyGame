#include "Character.hpp"
#include "Battle.hpp"
#include "Vampire.hpp"

int main()
{
    Battle* battle = new Battle;

    Vampire vampire(battle);


    delete battle;
    return 0;
}
