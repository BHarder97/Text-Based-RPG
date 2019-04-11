#ifndef ITEMS_H
#define ITEMS_H
#include <string>

using std::string;

class Items
{
    public:
        Items(string description);
        string GetName();

    private:
        string m_Name;
};

#endif // ITEMS_H
