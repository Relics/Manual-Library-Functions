#include <iostream>
#include <set>
#include <functional>
#include <vector>
#include <sstream>
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

vector<string> split (string s, char delimiter) {
    string temp;
    stringstream ss(s);
    vector<string> res;
    while (getline(ss, temp, '\n')) res.push_back(temp);
    return res;
}



set<Symbol> gSet;


int main()
{
    string s = "aefawf\nwefawfwa    eawf  awef e\nawefeawfawf\neeeee\nhah  ah  e";
    vector<string> res = split(s, '\n');
    for (auto i : res) cout << i <<endl;
    
    cout << endl;
    
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

