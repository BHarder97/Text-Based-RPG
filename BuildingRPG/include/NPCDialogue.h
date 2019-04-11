#ifndef NPCDIALOGUE_H
#define NPCDIALOGUE_H
#include<string>

using namespace std;

class NPCDialogue
{
    public:
        NPCDialogue(string obj);
        ~NPCDialogue();
        void AddChild(NPCDialogue *NPCDialogue);
        void AddSibling(NPCDialogue *npcdialogue);
        string ReturnObject();
        void Dialogue();


    protected:

    private:
    string m_object;
    NPCDialogue *m_next, *m_prev, *m_child;
};

#endif // NPCDIALOGUE_H
