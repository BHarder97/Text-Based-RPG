#ifndef PLAYER_H
#define PLAYER_H
#include "Items.h"
#include "Room.h"
#include <string>
#include <vector>

using std::string;

class Player
{
    public:
        Player();
        void AddItemToInv(string item);
        void ShowItems();
        bool RemoveItem(string name);
        void ReadFromDat();
        void GetValues();
        string statsArray[5];
        bool HasSword;
        bool HasShield;
        int currentHP;
        int currentMana;
        int playerHandDmg;
        int playerSwordDmg;
        int playerExperience;
        std::vector<Items> m_Inventory;
        bool FirstCheck;
        bool HasItem(string name);
        void LevelUp();

    private:
        int baseHP;
        int baseMana;
        string playerName;
        string Class;
        string Race;
        int pickClass;
        int pickRace;
        int playerLevel;



};

#endif // PLAYER_H
