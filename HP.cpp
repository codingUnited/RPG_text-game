#include "declarations.h"

void HP::setMaxHP(int addLvlUpHP)
// sets new HP from level up (but increasing by * 2)
{
    m_maxHP += addLvlUpHP;

    m_currentHP = m_maxHP;
}

bool HP::isAlive()
    // returns true if still alive
{
    if (m_currentHP <= 0)
        return false;

    return true;
}

void HP::receiveDamage(Spell& spell_dmg)
    // Spell damage
{
    if (spell_dmg.m_dmg > m_currentHP)
        m_currentHP = 0;
    else
        m_currentHP -= spell_dmg.m_dmg;
}

void HP::receiveDamage(int damage)
    // Non-spell damage
{
    if (damage > m_currentHP)
        m_currentHP = 0;
    else
        m_currentHP -= damage;
}

void HP::heal(int amount)
    // heal character
{
    if (amount + m_currentHP > m_maxHP)
        m_currentHP = m_maxHP;
    else
        m_currentHP += amount;
}