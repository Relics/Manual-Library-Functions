#include <iostream>
#include <set>
#include <functional>
using namespace std;

struct Symbol
{
    char name[10];
};

struct SymCmp
{
    bool operator () (const Symbol& x, const Symbol& y) const
    {
        if (strcmp(x.name, y.name) < 0)
            return true;
        else
            return false;
    }
};


set<Symbol, SymCmp> gSet;


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
    
    // Delete
    // gSet.erase(gSet.begin());
    
    for (auto i : gSet) {
        cout << i.name <<endl;
    }
    
    return 0;
}
