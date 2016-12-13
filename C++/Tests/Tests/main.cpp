#include <iostream>
#include <set>
#include <functional>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 * Complete the function below.
 */

class Name {
    string firstName;
    string romanLastName;
    int lastName;
    Name(string firstName, int lastName, string romanLastName) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->romanLastName = romanLastName;
    }
    const bool operator < (Name& another) const {
        if (this->firstName != another.firstName) {
            return this->firstName < another.firstName;
        }
        return this->lastName < another.lastName;
    }
};

int romanToInteger(string s) {
    unordered_map<char, int> umap;
    umap['I'] = 1, umap['V'] = 5, umap['X'] = 10, umap['L'] = 50;
    int ans = 0, size = (int)s.size();
    for (int i=0; i<size; ++i) {
        if (i == 0) ans += umap[s[i]];
        else {
            if (umap[s[i]] > umap[s[i-1]]) {
                ans += umap[s[i]] - 2*umap[s[i-1]];
            } else {
                ans += umap[s[i]];
            }
        }
    }
    return ans;
}

vector <string> getSortedList(vector <string> names) {
    vector<Name> n;
    vector<string> ans;
    for (string str : n) {
        if (str == "") continue; // Empty string detect
        int i = 0;
        while (str[i] != ' ') ++i;
        string first = str.substr(0, i);
        string roman = str.substr(i+1);
        int romanNum = romanToInteger(roman);
        Name newOne(first, romanNum, roman);
        n.push_back(newOne);
    }
    sort(n.begin(), n.end());
    for (Name temp : names) {
        ans.push_back(temp.firstName + " " + temp.romanLastName);
    }
    return ans;
}









int main()
{
    Solution a;
    
    int dp[101][101] = {0};
    for (int i = 0; i < 100; ++i){
        for (int j=0 ; j<100; ++j)
            cout << dp[i][j] ;
    }

    string hehe = "/a/b/c/";
    vector<string> ans = split(hehe, '/');
    for (auto i : ans) {
        cout << i << endl;
    }
    cout <<  ans.size() << endl;
    cout << "final" <<endl;
    
    return 0;
}

