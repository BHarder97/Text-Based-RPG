#include "Items.h"

Items::Items(string description):m_Name(description)
{
    //ctor
}

string Items::GetName(){
    return m_Name;
}
