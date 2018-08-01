#include <iostream>
#include "Character.hpp"
#include "Battle.hpp"
#include "Vampire.hpp"

int main()
{
    Battle* battle = new Battle;

    Character* vampire = new Vampire(battle);
    Character* opponent = new Vampire(battle);
    std::cout << vampire << "\n";


    delete opponent;
    delete vampire;
    delete battle;
    return 0;
}
