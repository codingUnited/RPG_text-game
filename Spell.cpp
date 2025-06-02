#include "declarations.h"
#include <vector>
#include <sstream>
#include <iostream>



Spell import_spell(const std::string& s)
{
    std::istringstream is {s};
    Spell nameDmg;
    std::string name_marker, spell_name;
    char bracket, left_paren, ch, right_paren;
    is >> bracket >> name_marker >> left_paren >> nameDmg.m_name >> ch >> nameDmg.m_dmg >> right_paren;
    spells_table.push_back(nameDmg);
    return nameDmg;
}

void string_of_spell()
{
    auto spell1 = import_spell("{ Spell (Firebolt , 4 )");
    auto spell2 = import_spell("{ Spell (AcidSpray , 6 )");
    auto spell3 = import_spell("{ Spell (ScorchingRay , 8 )");
    auto spell4 = import_spell("{ Spell (MagicMissile , 10 )");
}

// input and output for Spell
std::ostream& operator<<(std::ostream& os, Spell& s)
    // output format for Spells
{
    return os << "Spell Name: " << s.m_name << '\t' << "Spell Damage: " << s.m_dmg << '\n';
    // Figure out a way to format so "Spell Damage" on each new line is aligned
}

std::istream& operator>>(std::istream& is, Spell& s)
    // input in format { Spell (spell_name , spell_dmg)
{
    char ch1{};
    if (is >> ch1 && ch1 != '{')
    {
        is.unget();
        is.clear(std::ios::failbit);        // we failed to read a Spell
        return is;
    }

    std::string maker_name;   // the word Spell
    std::string spell_name;
    int spell_damage{};
    char ch2{}, ch3{}, ch4{};
    is >> maker_name >> ch2 >> spell_name >> ch3 >> spell_damage >> ch4;
    if ( maker_name != "Spell" || ch2 != '(' || ch3 != ',' || ch4 != ')' )
        // error("Incorrect format. The format that's only accepted: (e.g., { Spell (firebolt , 4) )");

            s = Spell { spell_name, spell_damage};
    return is;
}
