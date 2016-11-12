#include <iostream>
#include <set>
#include <functional>
using namespace std;

struct Symbol
{
    char name[10];
    bool operator< (const Symbol& r) const
    {
        if (strcmp(name, r.name) < 0)
            return true;
        else
            return false;
    }
    
};


set<Symbol> gSet;


int main()
{
    Symbol s1 = { "hi" };
    Symbol s2 = { "girls" };
    Symbol s3 = { "aaa" };
    
    gSet.insert(s1);
    gSet.insert(s2);
    gSet.insert(s1);
    gSet.insert(s2);
    gSet.insert(s3);
    
    for (auto i : gSet) {
        cout << i.name <<endl;
    }
    
    return 0;
}

