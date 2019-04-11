#ifndef ROOM_H
#define ROOM_H
#include "Player.h"
#include "Items.h"
#include <string>
#include <vector>

using std::string;

class Room
{
    public:
        Room();
        void Help();
        string Description1();
        string Description2();
        string Description3();
        string Description4();
        string Description5();
        string Description6();
        void CurrentQuests();
        void AddItemToRoom(string name);
        string description;
        void ShowItems();
        bool RemoveItem(string name);
        void ChangeRoom();
        int currentRoom;
        bool GuardAlive;
        bool WardenAlive;
        string Quest1;
        bool Quest1Complete;
        string Quest2;
        bool Quest2Complete;
        string Quest3;
        bool Quest3Complete;
        bool room1Unlocked(bool unlocked);
        bool room5Unlocked(bool unlocked);
        bool UsedLockpick = false;
        bool UsedKey = false;


    private:
        std::vector<Items> m_RoomInventory;
};

#endif // ROOM_H
