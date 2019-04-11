#include "NPCDialogue.h"
#include <iostream>
#include <string>

using namespace std;

NPCDialogue::NPCDialogue(string obj) : m_object(obj), m_next(NULL), m_prev(NULL), m_child(NULL){
    //ctor
    //cout << "NPCDialogue node created!" << endl;
}

NPCDialogue::~NPCDialogue(){
    //dtor
    m_prev = NULL;

        if(m_child != NULL){
            delete m_child;
        }

        if(m_next != NULL){
            delete m_next;
        }

        m_child = NULL;
        m_next = NULL;

        cout << "NPCDialogue deleted!" << endl;
}

void NPCDialogue::AddChild(NPCDialogue *NPCDialogue){
    //if no children currently exist for this NPCDialogue...
    if(m_child == NULL){
        m_child = NPCDialogue;
    }else{
        m_child->AddSibling(NPCDialogue);
    }
}

void NPCDialogue::AddSibling(NPCDialogue *npcdialogue){
    NPCDialogue *ptr = m_next;

    if(m_next == NULL){
       m_next = npcdialogue;
        npcdialogue->m_prev = this;
    }else{
        while(ptr->m_next != NULL){
            ptr = ptr->m_next;
        }

        ptr->m_next = npcdialogue;
        npcdialogue->m_prev = ptr;
    }
}

string NPCDialogue::ReturnObject(){
    return m_object;
}


void NPCDialogue::Dialogue(){
    //root:
    NPCDialogue *root = new NPCDialogue("Hello mortal.  What brings you to this prison cell?");

    //exit
    NPCDialogue *Exit = new NPCDialogue("(exit)");

    //SubTree1:
    NPCDialogue *Tree1 = new NPCDialogue("None of your business skeleton.");

    NPCDialogue *NPC1 = new NPCDialogue("Oh, testy I see.");

    //Left Path:
    NPCDialogue *Choice1 = new NPCDialogue("Do you know the way out of here?");
    NPCDialogue *Talk1 = new NPCDialogue("Yes, I do.");

        NPCDialogue *Choice4 = new NPCDialogue("Tell me.");
        NPCDialogue *Talk4 = new NPCDialogue("You already know how to get out of here.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice5 = new NPCDialogue("Please tell me.");
        NPCDialogue *Talk5 = new NPCDialogue("You already know how to get out of here.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice6 = new NPCDialogue("Tell me before I turn your bones into ashes.");
        NPCDialogue *Talk6 = new NPCDialogue("You already know how to get out of here.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

    //Middle Path:
    NPCDialogue *Choice2 = new NPCDialogue("This matter does not concern you skeleton.");
    NPCDialogue *Talk2 = new NPCDialogue("Everything in this cell concerns me.");

        NPCDialogue *Choice7 = new NPCDialogue("Mind your own business.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

    //Right Path:
    NPCDialogue *Choice3 = new NPCDialogue("Shut up you talking pile of bone.");
    NPCDialogue *Talk3 = new NPCDialogue("As you wish mortal human.  May you slowly rot away.");

        NPCDialogue *Choice8 = new NPCDialogue("I do wish.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice9 = new NPCDialogue("Good.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice10 = new NPCDialogue("I'm tired of you talking.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");


    //SubTree2:
    NPCDialogue *Tree2 = new NPCDialogue("I got caught in the wrong place at the wrong time.");

    NPCDialogue *NPC2 = new NPCDialogue("Ahh, what a shame.");

    //Left Path:
    NPCDialogue *Choice11 = new NPCDialogue("Yes, it is quite a shame.");
    NPCDialogue *Talk11 = new NPCDialogue("So what will you do now?");

        NPCDialogue *Choice14 = new NPCDialogue("I will wait out my time.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice15 = new NPCDialogue("I'm going to find a way out.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice16 = new NPCDialogue("I'm going to end my life.");
        //NPCDialogue *Exit = new NPCDialogue("(exit)");

    //Middle Path:
    NPCDialogue *Choice12 = new NPCDialogue("I had it coming, I have done some bad things to people before.");
    NPCDialogue *Talk12 = new NPCDialogue("What kinds of things?");

        NPCDialogue *Choice17 = new NPCDialogue("A few years ago I killed a man and they never had any evidence at the time.");
        NPCDialogue *Talk17 = new NPCDialogue("Ohh?  Interesting.  Tell me more.");

            NPCDialogue *Choice20 = new NPCDialogue("He was drunk and was being annoying, so I ended him.");
            NPCDialogue *Talk20 = new NPCDialogue("How exciting!!!");

                NPCDialogue *Choice21 = new NPCDialogue("Yes, well it's all over now.");
                //NPCDialogue *Exit = new NPCDialogue("(exit)");

                NPCDialogue *Choice22 = new NPCDialogue("Yes, now excuse me.");
                //NPCDialogue *Exit = new NPCDialogue("(exit)");

                NPCDialogue *Choice23 = new NPCDialogue("Sorry, not in the mood.");
                //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice18 = new NPCDialogue("I stole a few cows from a neighboring farmer.");
        NPCDialogue *Talk18 = new NPCDialogue("I don't see as why you ended up here then.");

            NPCDialogue *Choice24 = new NPCDialogue("I will find out why I'm here.");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");

            NPCDialogue *Choice25 = new NPCDialogue("I know.");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice19 = new NPCDialogue("A friend told me to keep quiet about something, but I didn't listen.");
        NPCDialogue *Talk19 = new NPCDialogue("What thing did he tell you to keep quiet about?");

            NPCDialogue *Choice26 = new NPCDialogue("About how he killed some guys in a back alley.");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");
            NPCDialogue *Choice27 = new NPCDialogue("I can't tell you, sorry.");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");

    //Right Path:
    NPCDialogue *Choice13 = new NPCDialogue("I should not be here right now!");
    NPCDialogue *Talk13 = new NPCDialogue("Oh?  And why is that?");

        NPCDialogue *Choice28 = new NPCDialogue("I did nothing wrong!");
        NPCDialogue *Talk28 = new NPCDialogue("So why are you here?");

            NPCDialogue *Choice30 = new NPCDialogue("I don't know!!");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");
            NPCDialogue *Choice31 = new NPCDialogue("I'm going to find out.");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");

        NPCDialogue *Choice29 = new NPCDialogue("I did nothing illegal or wrong to be accused of.");
        NPCDialogue *Talk29 = new NPCDialogue("So how did you end up here?");

            NPCDialogue *Choice32 = new NPCDialogue("I don't know!!");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");
            NPCDialogue *Choice33 = new NPCDialogue("I'm going to find out.");
            //NPCDialogue *Exit = new NPCDialogue("(exit)");

    //root
    root->AddChild(Tree1);
    root->AddChild(Tree2);

    //subtree1
    Tree1->AddChild(NPC1);

    NPC1->AddChild(Choice1);
    NPC1->AddChild(Choice2);
    NPC1->AddChild(Choice3);
    //Left Path
    Choice1->AddChild(Talk1);

    Talk1->AddChild(Choice4);
    Talk1->AddChild(Choice5);
    Talk1->AddChild(Choice6);

    Choice4->AddChild(Talk4);
    Choice5->AddChild(Talk5);
    Choice6->AddChild(Talk6);

    Talk4->AddChild(Exit);
    Talk5->AddChild(Exit);
    Talk6->AddChild(Exit);
    //Middle Path
    Choice2->AddChild(Talk2);

    Talk2->AddChild(Choice7);

    Choice7->AddChild(Exit);
    //Right Path
    Choice3->AddChild(Talk3);

    Talk3->AddChild(Choice8);
    Talk3->AddChild(Choice9);
    Talk3->AddChild(Choice10);

    Choice8->AddChild(Exit);
    Choice9->AddChild(Exit);
    Choice10->AddChild(Exit);

    //subtree2
    Tree2->AddChild(NPC2);

    NPC2->AddChild(Choice11);
    NPC2->AddChild(Choice12);
    NPC2->AddChild(Choice13);
    //Left Path
    Choice11->AddChild(Talk11);

    Talk11->AddChild(Choice14);
    Talk11->AddChild(Choice15);
    Talk11->AddChild(Choice16);

    Choice14->AddChild(Exit);
    Choice15->AddChild(Exit);
    Choice16->AddChild(Exit);

    //Middle Path
    Choice12->AddChild(Talk12);

    Talk12->AddChild(Choice17);
    Talk12->AddChild(Choice18);
    Talk12->AddChild(Choice19);

    Choice17->AddChild(Talk17);

    Talk17->AddChild(Choice20);

    Choice20->AddChild(Talk20);

    Talk20->AddChild(Choice21);
    Talk20->AddChild(Choice22);
    Talk20->AddChild(Choice23);

    Choice21->AddChild(Exit);
    Choice22->AddChild(Exit);
    Choice23->AddChild(Exit);

    Choice18->AddChild(Talk18);

    Talk18->AddChild(Choice24);
    Talk18->AddChild(Choice25);

    Choice24->AddChild(Exit);
    Choice25->AddChild(Exit);

    Choice19->AddChild(Talk19);

    Talk19->AddChild(Choice26);
    Talk19->AddChild(Choice27);

    Choice26->AddChild(Exit);
    Choice27->AddChild(Exit);

    //Right Path:
    Choice13->AddChild(Talk13);

    Talk13->AddChild(Choice28);
    Talk13->AddChild(Choice29);

    Choice28->AddChild(Talk28);

    Talk28->AddChild(Choice30);
    Talk28->AddChild(Choice31);

    Choice30->AddChild(Exit);
    Choice31->AddChild(Exit);

    Choice29->AddChild(Talk29);

    Talk29->AddChild(Choice32);
    Talk29->AddChild(Choice33);

    Choice32->AddChild(Exit);
    Choice33->AddChild(Exit);

    //root->DisplayTree();

    //Need to implement this into an actual use for talking to the NPC
    //Need to make the player be able to choose the option they want and then proceed from there

    int input;
    string display;
    cout << "\n\n\n\n\n\n";
    //beginning
    do{
    display = root->ReturnObject();
    cout << display << "root" << endl;
    cout << "1. "; display = Tree1->ReturnObject(); cout << display << endl;
    cout << "2. "; display = Tree2->ReturnObject(); cout << display << endl;
    cin >> input;
    }while(input != 1 && input != 2);

    //Tree1
    if(input == 1){
        do{
            display = NPC1->ReturnObject(); cout << display << endl;
            display = Choice1->ReturnObject(); cout << "1. " << display << endl;
            display = Choice2->ReturnObject();cout << "2. " << display << endl;
            display = Choice3->ReturnObject();cout << "3. " << display << endl;
            cin >> input;
        }while(input == 1 && input == 2 && input == 3);

        //Left Path
        if(input == 1){
            do{
                display = Talk1->ReturnObject(); cout << display << endl;
                display = Choice4->ReturnObject(); cout << "1. " << display << endl;
                display = Choice5->ReturnObject(); cout << "2. " << display << endl;
                display = Choice6->ReturnObject(); cout << "3. " << display << endl;
                cin >> input;
            }while(input != 1 && input != 2 && input != 3);

            if(input == 1){
                display = Talk4->ReturnObject(); cout << display << endl;
                display = Exit->ReturnObject(); cout << display << endl;

            }else if(input == 2){
                display = Talk5->ReturnObject(); cout << display << endl;
                display = Exit->ReturnObject(); cout << display << endl;

            }else if(input == 3){
                display = Talk6->ReturnObject(); cout << display << endl;
                display = Exit->ReturnObject(); cout << display << endl;
            }

        //Middle Path
        }else if(input == 2){
            display = Choice7->ReturnObject(); cout << display << endl;
            display = Exit->ReturnObject(); cout << display << endl;

        //Right Path
        }else if(input == 3){
            do{
                display = Talk3->ReturnObject(); cout << display << endl;
                display = Choice8->ReturnObject(); cout << "1. " << display << endl;
                display = Choice9->ReturnObject(); cout << "2. " << display << endl;
                display = Choice10->ReturnObject(); cout << "3. " << display << endl;
                cin >> input;
            }while(input != 1 && input != 2 && input != 3);

            if(input == 1){
                display = Exit->ReturnObject(); cout << display << endl;
            }else if(input == 2){
                display = Exit->ReturnObject(); cout << display << endl;
            }else if (input == 3){
                display = Exit->ReturnObject(); cout << display << endl;
            }
        }

    //Tree2
    }else if(input == 2){
        do{
        display = NPC2->ReturnObject(); cout << display << endl;
        display = Choice11->ReturnObject(); cout << "1. " << display << endl;
        display = Choice12->ReturnObject(); cout << "2. " << display << endl;
        display = Choice13->ReturnObject(); cout << "3. " << display << endl;
        cin >> input;
        }while(input != 1 && input != 2 && input != 3);

        //Left Path
        if(input == 1){
            do{
                display = Talk11->ReturnObject(); cout << display << endl;
                display = Choice14->ReturnObject(); cout << "1. " << display << endl;
                display = Choice15->ReturnObject(); cout << "2. " << display << endl;
                display = Choice16->ReturnObject(); cout << "3. " << display << endl;
                cin >> input;
            }while(input != 1 && input != 2 && input != 3);

            if(input == 1){
                display = Exit->ReturnObject(); cout << display << endl;

            }else if(input == 2){
                display = Exit->ReturnObject(); cout << display << endl;

            }else if(input == 3){
                display = Exit->ReturnObject(); cout << display << endl;
            }

        //Middle Path
        }else if(input == 2){
            do{
                display = Talk12->ReturnObject(); cout << display << endl;
                display = Choice17->ReturnObject(); cout << "1. " << display << endl;
                display = Choice18->ReturnObject(); cout << "2. " << display << endl;
                display = Choice19->ReturnObject(); cout << "3. " << display << endl;
                cin >> input;
            }while(input != 1 && input != 2 && input != 3);

            if(input == 1){
                display = Talk17->ReturnObject(); cout << display << endl;
                do{
                display = Choice20->ReturnObject(); cout << display << endl;
                display = Talk20->ReturnObject(); cout << display << endl;
                display = Choice21->ReturnObject(); cout << "1. " << display << endl;
                display = Choice22->ReturnObject(); cout << "2. " << display << endl;
                display = Choice23->ReturnObject(); cout << "3. " << display << endl;
                cin >> input;
                }while(input != 1 && input != 2 && input != 3);

                if(input == 1){
                display = Exit->ReturnObject(); cout << display << endl;
            }else if(input == 2){
                display = Exit->ReturnObject(); cout << display << endl;
            }else if (input == 3){
                display = Exit->ReturnObject(); cout << display << endl;
            }

            }else if(input == 2){
                do{
                display = Talk18->ReturnObject(); cout << display << endl;
                display = Choice24->ReturnObject(); cout << "1. " << display << endl;
                display = Choice25->ReturnObject(); cout << "2. " << display << endl;
                cin >> input;
                }while(input != 1 && input != 2);

                if(input == 1){
                display = Exit->ReturnObject(); cout << display << endl;
            }else if(input == 2){
                display = Exit->ReturnObject(); cout << display << endl;
            }

            }else if(input == 3){
                do{
                display = Talk19->ReturnObject(); cout << display << endl;
                display = Choice26->ReturnObject(); cout << "1. " << display << endl;
                display = Choice27->ReturnObject(); cout << "2. " << display << endl;
                cin >> input;
                }while(input != 1 && input != 2);

                if(input == 1){
                display = Exit->ReturnObject(); cout << display << endl;
                }else if(input == 2){
                display = Exit->ReturnObject(); cout << display << endl;
                }

            }

        }

        //Right Path
        }else if(input == 3){
            do{
                display = Talk13->ReturnObject(); cout << display << endl;
                display = Choice25->ReturnObject(); cout << "1. " << display << endl;
                display = Choice29->ReturnObject(); cout << "2. " << display << endl;
                cin >> input;
                }while(input != 1 && input != 2);
                if(input == 1){
                    do{
                        display = Talk28->ReturnObject(); cout << display << endl;
                        display = Choice30->ReturnObject(); cout << "1. " << display << endl;
                        display = Choice31->ReturnObject(); cout << "2. " << display << endl;
                        cin >> input;
                    }while(input != 1 && input != 2);

                    if(input == 1){
                        display = Exit->ReturnObject(); cout << display << endl;
                    }else if(input == 2){
                        display = Exit->ReturnObject(); cout << display << endl;
                    }

                }else if(input == 2){
                    do{
                        display = Talk29->ReturnObject(); cout << display << endl;
                        display = Choice32->ReturnObject(); cout << "1. " << display << endl;
                        display = Choice33->ReturnObject(); cout << "2. " << display << endl;
                        cin >> input;
                    }while(input != 1 && input != 2);

                    if(input == 1){
                        display = Exit->ReturnObject(); cout << display << endl;
                    }else if(input == 2){
                        display = Exit->ReturnObject(); cout << display << endl;
                    }
                }

            }
}
