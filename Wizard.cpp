#include "declarations.h"
#include <iostream>

//_________________________________________________________________________________
// input and output for Wizard

std::ostream& operator<<(std::ostream& os, Wizard& w)
    // output when referencing a Wizard
{
    return os << w.getPlayerName() << '\n'
              << "Level: " << w.getLevel() << '\n'
              << "Exp: " << w.getExp();
}
//________________________________________________________________________________


bool Wizard::isLvlUp()
    // returns true if player can level up
{
    int nextLvlExp{100 * (m_level-1)};

    if (nextLvlExp == 0)
        nextLvlExp = 100;

    if (m_exp > nextLvlExp)
        return true;

    return false;
}

bool Wizard::isValid()                  // Returns false if player's lvl is out of range.
{
    // NOT BEING USED CURRENTLY
    if (m_level < 0 || m_level > 3)
        return false;

    return true;
}

void Wizard::setXP(Monster& monster)
{
    m_exp += monster.getXP();
}


void Wizard::printSpells()              // Goal is to print only available spells for given lvl
{
    std::cout << "Number of spells: " << m_level << '\n';   // this is cheating on how many spells
    std::cout << "SPELL LIST:\n";
    for (int i=0; i < m_level; ++i)
    {
        std::cout << spells_table[i];
    }
}
