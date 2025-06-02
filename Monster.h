#ifndef MONSTER_H
#define MONSTER_H
#include "HP.h"
#include <string>

class Monster : public HP {
public:
    Monster(std::string name, int hp, int dmg, int xp)
        : HP(hp, hp)
        , m_name{name}, m_dmg{dmg}, m_receiveXP{xp} {}

    std::string getName() { return m_name; }
    int getDmg() { return m_dmg; }
    int getXP() { return m_receiveXP; }
private:
    std::string m_name{};
    int m_dmg{};
    int m_receiveXP{};
};

#endif
