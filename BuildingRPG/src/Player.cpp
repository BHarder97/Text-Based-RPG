#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Player.h"

using namespace std;

Player::Player()
{
        cout << "Checking to see if you have already created a character.\n";
        system("pause");

        ifstream myfile ( "player.dat" );

        if(myfile.is_open()){
            ReadFromDat();
            return;
        }else{
            //setting base health and stamina
            baseHP = 100;
            currentHP = 100;
            baseMana = 100;
            currentMana = 100;
            playerHandDmg = 5;
            playerSwordDmg = 10;
            HasSword = false;
            HasShield = false;
            playerExperience = 0;
            playerLevel = 1;

            //creating a variable for class and race selection
            char classChoice;
            char raceChoice;

            cout << "You do not already have an existing character.  Lets create one.\n";

            cout << "What name do you want for your character?    ";
            cin >> playerName;

            do{
            cout << "\nWhat race would you like to be? (1-6)\n";
            cout << "1 -- Human" << "\n";
            cout << "2 -- Orc" << "\n";
            cout << "3 -- Dwarf" << "\n";
            cout << "4 -- Elf" << "\n";
            cout << "5 -- Gnome" << "\n";
            cout << "6 -- Tiefling" << "\n";
            cin >> raceChoice;
            }while(raceChoice != '1' && raceChoice != '2' && raceChoice != '3' && raceChoice != '4' && raceChoice != '5' && raceChoice != '6');

            do{
            cout << "\nWhat class would you like to be? (1-6)\n";
            cout << "1 -- Paladin" << "\n";
            cout << "2 -- Cleric" << "\n";
            cout << "3 -- Rogue" << "\n";
            cout << "4 -- Archer" << "\n";
            cout << "5 -- Wizard" << "\n";
            cout << "6 -- Summoner" << "\n";
            cin >> classChoice;
            }while(classChoice != '1' && classChoice != '2' && classChoice != '3' && classChoice != '4' && classChoice != '5' && classChoice != '6');

            switch(raceChoice){
                case '1':
                    Race = "Human";
                    break;
                case '2':
                    Race = "Orc";
                    break;
                case '3':
                    Race = "Dwarf";
                    break;
                case '4':
                    Race = "Elf";
                    break;
                case '5':
                    Race = "Gnome";
                    break;
                case '6':
                    Race = "Tiefling";
                    break;
            }

            switch(classChoice){
                case '1':
                    Class = "Paladin";
                    break;
                case '2':
                    Class = "Cleric";
                    break;
                case '3':
                    Class = "Rogue";
                    break;
                case '4':
                    Class = "Archer";
                    break;
                case '5':
                    Class = "Wizard";
                    break;
                case '6':
                    Class = "Summoner";
                    break;
            }

            cout << "\nYour character information is: \n";
            cout << "Name: " << playerName << "\n";
            cout << "Health: " << currentHP << "/" << baseHP << "\n";
            cout << "Mana: " << currentMana<< "/" << baseMana << "\n";
            cout << "Class: " << Class << "\n";
            cout << "Race: " << Race << "\n";

            ofstream myfile( "player.dat" );

            myfile << "Name: " << playerName << "\n";
            myfile << "Health: " << baseHP << "\n";
            myfile << "Mana: " << baseMana << "\n";
            myfile << "Class: " << Class << "\n";
            myfile << "Race: " << Race;

        }

}

void Player::AddItemToInv(string name){
    if(name == "sword"){
        HasSword = true;
    }else if(name == "shield"){
        HasShield = true;
    }

    m_Inventory.push_back(Items(name));
}


void Player::ShowItems(){
    for(std::vector<Items>::iterator iter = m_Inventory.begin(); iter < m_Inventory.end(); iter++){
        cout << iter->GetName() << " | ";
    }

}

bool Player::RemoveItem(string name){
        bool deleted = false;

        if(name == "sword"){
            HasSword = false;
        }else if(name == "shield"){
            HasShield = false;
        }

    for(std::vector<Items>::iterator iter = m_Inventory.begin(); iter != m_Inventory.end(); iter++){
        if(iter->GetName() == name){
            m_Inventory.erase(iter);
            deleted = true;
            break;
        }
    }
    return deleted;
}

bool Player::HasItem(string name){
    for(std::vector<Items>::iterator iter = m_Inventory.begin(); iter != m_Inventory.end(); iter++){
        if(iter->GetName() == name){
            return true;
        }
    }

    return false;

}


void Player::ReadFromDat(){
    int i = 0;

    ifstream myfile ( "player.dat" );

    string line;

    cout << "\nYou already have a character with the following stats:\n";

    while( getline (myfile,line) ){
        cout << line << "\n";
        statsArray[i] = line;
        i++;
    }

    GetValues();
}

void Player::GetValues(){
    int checker;

    for(int i = 0; i < 5; i++){
        checker = (statsArray[i].find(":") + 2);

        statsArray[i] = statsArray[i].substr(checker);
    }

    playerName = statsArray[0];
    baseHP = 100;
    currentHP = 100;
    baseMana = 100;
    currentMana = 100;
    Class = statsArray[3];
    Race = statsArray[4];

}

void Player::LevelUp(){
    if(playerExperience >= 300 && playerExperience <= 350){
        system("CLS");
        cout << "\nCongratz! You leveled up to level 2!";
        cout << "\nBase stats improved and you are fully healed!";
        cout << "\nbaseHP = 150";
        cout << "\nbaseMana = 150";
        cout << "\ncurrentHP = 150";
        cout << "\ncurrentMana = 150";

        baseHP = 150;
        baseMana = 150;
        currentHP = 150;
        currentMana = 150;
    }else if(playerExperience >= 1000 && playerExperience <= 1050){
        system("CLS");
        cout << "\nCongratz! You leveled up to level 3!";
        cout << "\nBase stats improved and you are fully healed!";
        cout << "\nbaseHP = 200";
        cout << "\nbaseMana = 200";
        cout << "\ncurrentHP = 200";
        cout << "\ncurrentMana = 200";

        baseHP = 200;
        baseMana = 200;
        currentHP = 200;
        currentMana = 200;
    }else{
        cout << "\nYou did not level up after the battle.";
    }
}
