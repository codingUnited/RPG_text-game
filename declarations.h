//
// Created by stephen on 6/1/25.
//

#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include "HP.h"
#include "Monster.h"
#include "Spell.h"
#include "Wizard.h"

extern std::vector<Spell> spells_table;                 // declarations
Spell import_spell(const std::string& s);
void string_of_spell();
void printStats(Wizard& wizard);
void printMonsterStats(Monster& monster);
void attackWithSpell(Wizard& player, Monster& npc);
void healOption(Wizard& player);
void end_of_battle_report(Wizard& player, Monster& npc);
void end_of_battle(Wizard& player, Monster& npc);
void hp_stat_block(Wizard& player, Monster& npc);
void combatSystem(Wizard& player, Monster& npc);
std::string getName();
std::ostream& operator<<(std::ostream& os, Spell& s);
std::istream& operator>>(std::istream& is, Spell& s);

std::ostream& operator<<(std::ostream& os, Wizard& w);



#endif //DECLARATIONS_H
