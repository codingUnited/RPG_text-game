#ifndef WIZARD_H
#define WIZARD_H
#include "HP.h"
#include "Monster.h"
#include "Spell.h"

class Wizard : public HP {
public:
    Wizard(std::string& name)
        : HP(BASEMAXHP, BASECURHP)
        , m_playerName{name}, m_level{m_level=1}, m_exp{m_exp=0} {}
    // Construct player's Wizard.

    int getLevel() const { return m_level; }            // returns player's current level
    int getExp() const { return m_exp; }                // returns player's current experience points
    std::string getPlayerName() const { return m_playerName; }  // returns player's name

    bool isValid();                                     // I changed the program some. NOT USED CURRENTLY
    bool isLvlUp();                                     // returns true when enough xp to lvl up.

    void setXP(Monster& monster);                       // receive XP after killing a Monster

    void addLevel()                                     // add level
    {
        setMaxHP(5);
        ++m_level;
    }

    void printSpells();                                 // print spells

private:
    // just messing around right now. May add full character's stats later
    static const int BASEMAXHP = 10;
    static const int BASECURHP = 10;
    std::string m_playerName{};
    int m_level{};
    int m_exp{};
};

#endif //WIZARD_H
