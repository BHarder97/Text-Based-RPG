#include "Enemies.h"
#include<iostream>
#include<string>
#include <ctime>
#include <stdlib.h>

using namespace std;


Enemies::Enemies()
{
    //ctor
    GuardHP = 25;
    WardenHP = 50;
    GuardDMG = 5;
    WardenDMG = 10;
}

int Enemies::FightingGuard(int playerHP, bool HasShield, bool HasSword, int HandDmg, int SwordDmg){
    int choice;

    HandDmg = 5;
    SwordDmg = 10;
    GuardDMG = 5;
    GuardHP = 25;

    cout << "\nYou are now fighting the Guard who only has a sword and no shield.";
    cout << "\nYou will always have the first move.";
    cout << "\nSince the Guard has no shield he cannot block.";
    cout << "\nYou have two choices while fighting, block or attack.";

    do{
        cout << "\nYou have " << playerHP << " health";
        cout << "\nChoose your choice:";
        cout << "\n1.  Attack.";
        cout << "\n2.  Block.\n";
        cin >> choice;

        if(choice == 1){
            if(HasSword == true){
                cout << "\nYou swing your sword at the Guard and hit him for " << SwordDmg << " damage.";
                GuardHP -= SwordDmg;
            }else if(HasSword == false){
                cout << "\nYou swing with a right hook at the Guard and do " << HandDmg << " damage.";
                GuardHP -= HandDmg;
            }
        }else if (choice == 2){
            if(HasShield == true){
                cout << "\nYou ready your shield blocking the next attack from the Guard.";
            }else if (HasShield == false){
                cout << "\nYou ready yourself for the Guards attack reducing all damage by half.";
            }
        }

        if(GuardHP <= 0){
            cout << "\nYou have killed the Guard.";
            return playerHP;
        }

        cout << "\nThe Guard swings at you with his sword.";
        if(choice == 2 && HasShield == true){
            cout << "\nYou block the Guard's attack.";
            playerHP -= 0;
        }else if(choice == 2 && HasShield == false){
            cout << "\nYou block most of the Guards attack but still take " << (GuardDMG / 2 )<< " damage.";
            playerHP -= (GuardDMG / 2);
        }else if(choice == 1){
            cout << "\nYou did not block the Guards attack and take " << GuardDMG << " damage.";
            playerHP -= GuardDMG;
        }

        if(playerHP == 0){
            return playerHP;
        }

    }while(GuardHP != 0 && playerHP != 0);

    return playerHP;

}

int Enemies::FightingWarden(int playerHP, bool HasShield, bool HasSword, int HandDmg, int SwordDmg){
    int choice;
    int hit;

    HandDmg = 5;
    SwordDmg = 10;
    WardenDMG = 10;
    WardenHP = 50;

    cout << "\nYou are now fighting the Warden who has a sword and a shield..";
    cout << "\nYou will always have the first move.";
    cout << "\nThe Warden is able to block and attack.";
    cout << "\nYou have two choices while fighting, block or attack.";

    do{

        cout << "\nYou have " << playerHP << " health";
        cout << "\nChoose your choice:";
        cout << "\n1.  Attack.";
        cout << "\n2.  Block.\n";
        cin >> choice;

        srand((unsigned)time(NULL));
        hit = ((rand() % 2) + 1);

        if(choice == 1){
            if(HasSword == true){
                cout << "\nYou swing your sword at the Warden.";
                if(hit == 2){
                    cout << "\nThe Warden blocks your attack.";
                    WardenHP -= 0;
                }else{
                    cout << "\nThe Warden doesn't block and takes " << SwordDmg << " damage.";
                    WardenHP -= SwordDmg;
                }

            }else if(HasSword == false){
                cout << "\nYou swing with a right hook at the Warden.";
                if(hit == 2){
                    cout << "\nThe Warden blocks your attack.";
                    WardenHP -= 0;
                }else{
                    cout << "\nThe Warden doesn't block and takes " << HandDmg << " damage.";
                    WardenHP -= HandDmg;
                }

            }
        }else if (choice == 2){
            if(HasShield == true){
                cout << "\nYou ready your shield blocking the next attack from the Warden.";
            }else if (HasShield == false){
                cout << "\nYou ready yourself for the Wardens attack reducing all damage by half.";
            }
        }

        if(WardenHP <= 0){
            cout << "\nYou have killed the Warden.";
            return playerHP;
        }

        if(hit == 1){
            cout << "\nThe Warden swings at you with his sword.";
            if(choice == 2 && HasShield == true){
                cout << "\nYou block his attack with your shield.";
                playerHP -= 0;
            }else if(choice == 2 && HasShield == false){
                cout << "\nYou block most the damage while guarded but still take " << (WardenDMG/2) << " damage.";
                playerHP -= (WardenDMG / 2);
            }else if(choice == 1){
                cout << "\nSince you didn't ready yourself you took full damage of " << WardenDMG << " points.";
                playerHP -= WardenDMG;
            }
        }else if(hit == 2){
            //Warden blocks your attack
        }

        if(playerHP == 0){
            return playerHP;
        }

    }while(GuardHP != 0 && playerHP != 0);

    return playerHP;
}
