/*      A big work in progress. I'm applying what I'm learning as I go along.
 *      Revision 2, 24-May-2025: Added Monsters
 *                               Added HP
 *                               Level up system working
 *                               Combat System added.
 *                               Removed File Input function
 *
 *      Revision 1, 30-Apr-2025: Removed inheritance between Spell and Wizard.
 *                               Added a global vector to store all Spells in the game
 *                               Removed HP for now
 *                               Added a level up system
 *
 *      future plans: add a way to select a Spell to use against a Monster
 *                    add Stats (hp[completed], mana, etc.)
 *                    add option to have the ability to select which spell you get each lvl.
 *                    add spell slots to make weaker spells still viable.
 *                    add Inventory system
 */



#include <iostream>
#include <sstream>
#include "declarations.h"
#include <string_view>

std::vector<Spell> spells_table;

//______________________________________________________________________________
// ERROR FUNCTIONS
void error(std::string_view error_message, std::string name = "")
{
    std::cerr << error_message << name << '\n';
}
//_________________________________________________________________________________

int main()
{
    string_of_spell();
    std::string playerName { getName() };
    Wizard player{ playerName };
    Monster goblin {"Goblin", 6, 2 , 25 };
    Monster warg { "Warg", 8, 4, 80};
    Monster orc { "Orc", 10, 7, 95 };
    Monster nazgul { "Nazgul", 18, 12, 200 };

    combatSystem(player, goblin);
    combatSystem(player, warg);
    combatSystem(player, orc);
    combatSystem(player, nazgul);

    return 0;
}

