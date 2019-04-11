#include <iostream>
#include <windows.h>
#include <string>
#include "Player.h"
#include "Room.h"
#include "Items.h"
#include "NPCDialogue.h"
#include "Enemies.h"

using namespace std;

int main()
{
    cout << "\t\t\tWelcome to this RPG!" << endl;
    cout << "\t\t\tLet us set up your character." << endl;

    Player player;

    system("pause");
    system("CLS");

    //creating a variable for what the user inputs
    string userInput = "";

    Room room;
    Enemies fight;
    NPCDialogue talk("Kevin");

    system("CLS");
    room.description = room.Description1();
    cout << room.description;
    system("pause");
    system("CLS");
    room.Help();
    system("pause");
    system("CLS");
    bool doorUnlocked;
    bool hasItem;

    //main game loop??
    do{
        cout << "\nWhat do you want to do?  ";
        cin >> userInput;

        if(userInput == "look"){
           cout << room.description;

        }else if(userInput == "move"){
            if(room.currentRoom == 1){
                doorUnlocked = room.room1Unlocked(doorUnlocked);
                if(doorUnlocked == false){
                    cout << "\nYou cannot move out of this room without unlocking the jail door.";
                }else{
                    room.ChangeRoom();
                    cout << room.description;
                }
            }else if(room.currentRoom == 5){
                doorUnlocked = room.room5Unlocked(doorUnlocked);
                if(doorUnlocked == false){
                    cout << "\nYou cannot move out of this room without unlocking the door with the Warden's Key.";
                }else{
                    room.ChangeRoom();
                    cout << room.description;
                }
            }else if(room.currentRoom == 2){
                room.ChangeRoom();
                cout << room.description;
            }else if(room.currentRoom == 3){
                room.ChangeRoom();
                cout << room.description;
            }

            if(room.currentRoom == 4){
                if(room.GuardAlive == true){
                    cout << "\n\nYou must kill the Guard to do anything.";
                    player.currentHP = fight.FightingGuard(player.currentHP, player.HasShield, player.HasSword, player.playerHandDmg, player.playerSwordDmg);
                    if(player.currentHP > 0){
                        room.GuardAlive = false;
                        player.playerExperience += 50;
                        player.LevelUp();
                    }else if(player.currentHP <= 0){
                        cout << "\nYou have died to the Guard.";
                        return 0;
                    }
                }else{
                    room.ChangeRoom();
                    cout << room.description;
                }
            }else if(room.currentRoom == 5){
                if(room.WardenAlive == true){
                    cout << "\n\nYou must kill the Warden to do anything.";
                    player.currentHP = fight.FightingWarden(player.currentHP, player.HasShield, player.HasSword, player.playerHandDmg, player.playerSwordDmg);
                    if(player.currentHP > 0){
                        room.WardenAlive = false;
                        player.playerExperience += 100;
                        player.AddItemToInv("Key");
                        player.LevelUp();
                    }else if(player.currentHP <= 0){
                        cout << "\nYou have died to the Warden.";
                        return 0;
                    }
                }else{
                    room.ChangeRoom();
                    cout << room.description;
                }
            }else if(room.currentRoom == 6){
                return 0;
            }

        }else if(userInput == "quests"){
            room.CurrentQuests();

        }else if(userInput == "add"){
            cout << "\n";
            room.ShowItems();
            cout << "\nWhat item do you want to pick up?  ";
            cin >> userInput;
            if(room.RemoveItem(userInput)){
                player.AddItemToInv(userInput);
            }else{
                cout << "\nItem was not found.";
            }

        }else if(userInput == "help"){
            room.Help();

        }else if(userInput == "talk"){
            if(room.currentRoom == 1){
               talk.Dialogue();
            }else{
                cout << "\nNo NPC to talk to.";
            }
        }else if(userInput == "inv"){
            player.ShowItems();

        }else if(userInput == "use"){
            if(room.currentRoom == 1){
                hasItem = player.HasItem("lockpick");
                if(hasItem == true){
                    cout << "\nYou use the lockpick on the jail door and unlock it.";
                    room.UsedLockpick = true;
                }else{
                    cout << "\nYou do not have the lockpick and cannot unlock the jail door.";
                }
            }else if(room.currentRoom == 5){
                hasItem = player.HasItem("Key");
                if(hasItem == true){
                    cout << "\nYou use the Warden's Key on the door and unlock the door to the outside.";
                    room.UsedKey = true;
                }else{
                    cout << "\nYou do not have the Warden's Key and cannot unlock the door to the outside.";
                }
            }else{
                cout << "\nThere is nothing you can use in this room.";
            }

        }else if (userInput == "drop"){
            cout << "\n";
            player.ShowItems();
            cout << "\nWhat item would you like to drop?  ";
            cin >> userInput;
            if(player.RemoveItem(userInput)){
                room.AddItemToRoom(userInput);
            }else{
                cout << "\nItem was not found.";
            }
        }else if(userInput == "suicide"){
            cout << "\nYou have chosen the cowardly way out of life.";
            cout << "\nYou have commited suicide.";
            return 0;
        }

    }while(userInput != "quit");


    return 0;
}
