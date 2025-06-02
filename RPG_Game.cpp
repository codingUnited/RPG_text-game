#include "declarations.h"



void printStats(Wizard& wizard)
    // print player's stats
{
    std::cout << "____________________" << '\n';
    std::cout << wizard << '\n';        // there has to be a way where I can do all of this with std::cout << wizard only
    wizard.getHP();
    wizard.printSpells();
    std::cout << "____________________" << '\n';
}

void printMonsterStats(Monster& monster)
    // print Monster stats
{
    std::cout << "____________________" << '\n';
    std::cout << monster.getName() << '\n';
    monster.getHP();
    std::cout << "Base Dmg: " << monster.getDmg() << '\n';
    std::cout << "Gives: " << monster.getXP() << " XP" << '\n';
    std::cout << "____________________" << '\n';
}
//_______________________________________________________________________________
void attackWithSpell(Wizard& player, Monster& npc)
    // choose(not yet) a spell and attack Monster
{
    std::cout << "You attacked the " << npc.getName() << " with " << spells_table[player.getLevel()-1].spell_name()
              << " and did " << spells_table[player.getLevel()-1].spell_dmg() << " damage!" << '\n';
    npc.receiveDamage(spells_table[player.getLevel() - 1]);

    if (npc.isAlive())
    {
        std::cout << "The " << npc.getName() << " attacked you and did " << npc.getDmg() << " damage!" << '\n';
        player.receiveDamage(npc.getDmg());
    }
}

void healOption(Wizard& player)
    // use a heal from your inventory
{
    static int num_potions {3};
    std::cout << "You have " << num_potions << " potions in your inventory." << '\n';
    if (num_potions == 0)       // if no potions, then do nothing
        ;
    else
    {
        int healAmount{4};     // right now default is 4
        std::cout << "Consuming adds " << healAmount << " hp. Would you like to drink a potion? (y/n): ";
        char answer{};
        std::cin >> answer;
        if (answer == 'y')
        {
            std::cout << "You healed by " << healAmount << " hp!" << '\n';
            player.heal(healAmount);
            --num_potions;
        }
    }
}

void end_of_battle_report(Wizard& player, Monster& npc)
    // will one day do an actual formatted battle report. Just threw this together to output something
{
    int numLoot {}; // just a place holder until I introduce an inventory system
    std::cout << '\n';
    std::cout << "__________________________" << '\n'
              << "| BATTLE REPORT:         |" << '\n'
              << "|________________________|" << '\n'
              << "| Killed: " << npc.getName() << "         |" << '\n'
              << "| Items found: " << numLoot << "         |" << '\n'
              << "| XP Gained: +" << npc.getXP() << "         |" << '\n'
              << "|________________________|" << '\n';
    std::cout << '\n';
}

void end_of_battle(Wizard& player, Monster& npc)
    // what happens after a battle is finished
{
    if (!npc.isAlive())
        std::cout << player.getPlayerName() << " has killed the " << npc.getName() << '!' << '\n';

    if (player.isAlive())
    {
        end_of_battle_report(player, npc);
        player.setXP(npc);
        if (player.isLvlUp())
        {
            player.addLevel();
            std::cout << "You have leveled up to level " << player.getLevel() << '!'
                      << " You acquired the knowledge of " << spells_table[player.getLevel()-1].m_name << '\n';
        }
    }
    else
        std::cout << player.getPlayerName() << " has died. I'm sorry adventurer!" << '\n';
}

void hp_stat_block(Wizard& player, Monster& npc)
{
    std::cout << '[' << player.getPlayerName() << ": HP " << player.getCurrentHP() << '/' << player.getMaxHP() << ']'
              << ' ' << '[' << npc.getName() << ": HP " << npc.getCurrentHP() << '/' << npc.getMaxHP() << ']' << '\n';
}

void combatSystem(Wizard& player, Monster& npc)
    // just options to choice what to do while in combat
{

    std::cout << "What would you like to do?" << '\n'
              << "\t1. Cast spell" << '\n'
              << "\t2. Heal" << '\n'
              << "\t3. Check your stats" << '\n'
              << "\t4. Check Monster stats" << '\n';

    while ( player.isAlive() && npc.isAlive() )
    {
        hp_stat_block(player, npc);
        if ( player.getCurrentHP() <= npc.getDmg() )
            std::cout << "WARNING: You're HP is getting low" << '\n';

        std::cout << '>';
        char user_input{};
        std::cin >> user_input;

        switch (user_input)
        {
        case '1':
            attackWithSpell(player, npc);
            break;
        case '2':
            healOption(player);
            break;
        case '3':
            printStats(player);
            break;
        case '4':
            printMonsterStats(npc);
            break;
        case 'y':
            std::cout << "Invalid input!" << '\n';
            break;
        default:
            std::cin.unget();
            std::cin.clear(std::ios::failbit);                                   // goes into an infinite loop, trying to figure out why
            std::cout << "Invalid input, try again!" << '\n';   // turned input into a char because I kept pressing y to heal instead of 2
            break;
        }
    }
    end_of_battle(player, npc);
}

std::string getName()
{
    std::cout << "Hello fellow adventurer! What is your name? ";
    std::string playerName;
    std::getline(std::cin>>std::ws, playerName);
    return playerName;
}
