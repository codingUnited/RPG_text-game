#ifndef HP_H
#define HP_H
#include <iostream>
#include "Spell.h"

class HP {
public:
    // constructor
    HP() : m_currentHP{ 1 }, m_maxHP{ 1 } {}
    HP(int currentHP, int maxHP) : m_currentHP{ currentHP }, m_maxHP{ maxHP } {}

    // setters
    void setMaxHP(int maxHP);                           // set new HP when lvling up.
    bool isAlive();                                     // returns true if hp isn't 0
    void receiveDamage(Spell& spell_dmg);               // to receive spell damage
    void receiveDamage(int damage);                     // to receive non-spell damage.

    int getCurrentHP() { return m_currentHP; }
    int getMaxHP() { return m_maxHP; }

    void getHP()
    {
        std::cout << "HP: " << m_currentHP << '/' << m_maxHP << '\n';
    }
    void heal(int amount);                              // heal player

private:
    int m_currentHP{};
    int m_maxHP{};
};

#endif
