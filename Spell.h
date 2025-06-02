#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <string>
#include <vector>


struct Spell {
    // Stores name and damage of spells
    Spell() = default;
    Spell(std::string name, int dmg) : m_name{name}, m_dmg{dmg} {}

    std::string spell_name() { return m_name; }
    int spell_dmg() { return m_dmg; }

    std::string m_name;
    int m_dmg{};
};

#endif //SPELL_H
