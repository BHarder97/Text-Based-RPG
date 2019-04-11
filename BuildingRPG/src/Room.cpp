#include "Room.h"
#include "Enemies.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using std::cout;
using std::string;
using std::cin;

Room::Room()
{
    //ctor
    cout << "\nGenerating your room and items in the room please wait.\n";
    Sleep(2000);

    Quest1 = "\nLeave the jail cell.";
    Quest2 = "\nKill the Warden and get the key.";
    Quest3 = "\nLeave the prison.";

    Quest1Complete = false;
    Quest2Complete = false;
    Quest3Complete = false;
}

void Room::Help(){
    cout << "If you need any help just type 'help' and this will display a list of input commands you can type to do certain actions.\n";

    //displaying a list of commands that the user can enter
    cout << "\nList of commands: \n";
    cout << "'look' to look around the room and get a description of the room.\n";
    cout << "'move' will open a option box of where you want to move to.\n";
    cout << "'add' will display all items you can pickup in the room.\n";
    cout << "'inv' to see what items are in your inventory.\n";
    cout << "'drop' will open a list of items in your inventory that you can drop.\n";
    cout << "'use' will use specific items in your inventory if they are there to open doors.\n";
}

void Room::CurrentQuests(){
    cout << "\nYou have the following Quests:";
    cout << "\n" << Quest1 << " " << Quest1Complete;
    cout << "\n" << Quest2 << " " << Quest2Complete;
    cout << "\n" << Quest3 << " " << Quest3Complete;
}

string Room::Description1(){
    AddItemToRoom("rock");
    AddItemToRoom("hat");
    AddItemToRoom("soap");
    AddItemToRoom("bucket");
    AddItemToRoom("lockpick");

    ShowItems();

    currentRoom = 1;

    return "\nYou find yourself standing in the middle of a jail cell.\n"
    "\nYou figure the room is about 8 feet wide by 8 feet long and about 10 feet tall.\n"
    "\nOn the north wall is the jail cell door which is locked.\n"
    "There is also a skeleton hanging on the East wall.  It looks as if it is alive.\n";
}

string Room::Description2(){

    if(currentRoom == 1){
        RemoveItem("rock");
        RemoveItem("hat");
        RemoveItem("soap");
        RemoveItem("bucket");
        RemoveItem("lockpick");
    }else if(currentRoom == 3){
        RemoveItem("sword");
        RemoveItem("shield");
    }else if(currentRoom == 4){
        RemoveItem("coffee");
        RemoveItem("lantern");
    }

    ShowItems();

    Quest2Complete = true;

    currentRoom = 2;

    return "\nYou find yourself a long hallway, 10 feet wide by 35 feet long, lined with jail cells.\n"
    "\nAll of which are empty.\n"
    "\nThere are no obtainable items in this room.\n"
    "\nYou see a room to your West and the hallway continues to the East.\n";
}

string Room::Description3(){
    AddItemToRoom("sword");
    AddItemToRoom("shield");

    ShowItems();

    currentRoom = 3;

    return "\nThis room seems like it's where the guards rest after doing a patrol of the cells.\n"
    "\nThe room is empty of all guards at this time.\n"
    "\nThere is a sword and shield just laying on the table.\n";
}

string Room::Description4(){
    AddItemToRoom("coffee");
    AddItemToRoom("lantern");

    ShowItems();

    currentRoom = 4;

    GuardAlive = true;

    return "\nThe hallway comes to an end to the East.\n"
    "\nThere is a wooden table and chair in the far South East corner.\n"
    "\nStanding near the table is a guard.\n"
    "\nYou can see the exit to this place to the North.\n";
}

string Room::Description5(){

    if(currentRoom == 4){
        RemoveItem("coffee");
        RemoveItem("lantern");
    }

    ShowItems();

    currentRoom = 5;

    WardenAlive = true;

    return "You move to the North and are in the last room of the prison.\n"
    "\nThe room is a decent sized room.  10 feet wide by 10 feet long.\n"
    "\nYou can see the door to leave this place.\n"
    "\nYou know that you can pick up the key once the Warden is dead.\n";
}

string Room::Description6(){

    currentRoom = 6;

    Quest3Complete = true;

    return "\nYou open the door leading to the outside.\n"
    "You take a deep breath of the nice outside air.\n"
    "You then take an arrow to the head and die.\n";

}

bool Room::room1Unlocked(bool unlocked){

    unlocked = false;

    if(UsedLockpick == true){
        unlocked = true;
    }else{
        unlocked = false;
    }

    return unlocked;
}

bool Room::room5Unlocked(bool unlocked){

    unlocked = false;

    if(UsedKey == true){
        unlocked = true;
    }else{
        unlocked = false;
    }

    return unlocked;
}

void Room::ChangeRoom(){
    string input;
    Enemies fight;

    do{
        if(currentRoom == 1){
            cout << "\nWhich way would you like to move? North, East, South, or West?\n";
            cin >> input;

            if(input == "North"){
                cout << "You move North out of the current room.\n";
                description = Description2();
            }else if(input == "East"){
                cout << "You cannot move East out of this room.\n";
            }else if(input == "South"){
                cout << "You cannot move South out of this room.\n";
            }else if(input == "West"){
                cout << "You cannot move West out of this room.\n";
            }

        }else if(currentRoom == 2){
            cout << "\nWhich way would you like to move? North, East, South, or West?\n";
            cin >> input;

            if(input == "North"){
                cout << "You cannot move North out of this room.\n";
            }else if(input == "East"){
                cout << "You move East out of the current room.\n";
                description = Description4();
            }else if(input == "South"){
                cout << "You move South out of the current room.\n";
                description = Description1();
            }else if(input == "West"){
                cout << "You move West out of the current room.\n";
                description = Description3();
            }

        }else if(currentRoom == 3){
            cout << "\nWhich way would you like to move? North, East, South, or West?\n";
            cin >> input;

            if(input == "North"){
                cout << "You cannot move North out of this room.\n";
            }else if(input == "East"){
                cout << "You move East out of the current room.\n";
                description = Description2();
            }else if(input == "South"){
                cout << "You cannot move South out of this room.\n";
            }else if(input == "West"){
                cout << "You cannot move West out of this room.\n";
            }

        }else if(currentRoom == 4){
            cout << "\nWhich way would you like to move? North, East, South, or West?\n";
            cin >> input;

            if(input == "North"){
                cout << "You move North out of the current room.\n";
                description = Description5();
            }else if(input == "East"){
                cout << "You cannot move East out of this room.\n";
            }else if(input == "South"){
                cout << "You cannot move South out of this room.\n";
            }else if(input == "West"){
                cout << "You move West out of the current room.\n";
                description = Description2();
            }

        }else if(currentRoom == 5){
            cout << "\nWhich way would you like to move? North, East, South, or West?\n";
            cin >> input;

            if(input == "North"){
                cout << "You move North out of the current room.\n";
                description = Description6();
            }else if(input == "East"){
                cout << "You cannot move East out of this room.\n";
            }else if(input == "South"){
                cout << "You move South out of the current room.\n";
                description = Description4();
            }else if(input == "West"){
                cout << "You cannot move West out of this room.\n";
            }

        }else if(currentRoom == 6){
            cout << "\nIf this shows then buddy, you are already dead!";
        }
    }while(input != "North" && input != "East" && input != "South" && input != "West");



}

void Room::AddItemToRoom(string name){
    if(name == "Key"){
        Quest2Complete = true;
    }

    m_RoomInventory.push_back(Items(name));
}

void Room::ShowItems(){
    for(std::vector<Items>::iterator iter = m_RoomInventory.begin(); iter < m_RoomInventory.end(); iter++){
        cout << iter->GetName() << " | ";
    }

}

bool Room::RemoveItem(string name){
    bool deleted = false;

    for(std::vector<Items>::iterator iter = m_RoomInventory.begin(); iter != m_RoomInventory.end(); iter++){
        if(iter->GetName() == name){
            m_RoomInventory.erase(iter);
            deleted = true;
            break;
        }
    }
    return deleted;
}
