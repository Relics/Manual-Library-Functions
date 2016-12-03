#include <iostream>
#include <set>
#include <functional>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    typedef vector<int> vi;
    
    int dcmp(int x) {
        return !x ? x: (x > 0 ? 1: -1);
    }
    
    int cross(const vi &a, const vi &b) {
        return a[0] * b[1] - a[1] * b[0];
    }
    
    vi minus(const vi &a, const vi &b) {
        return vi({a[0]-b[0], a[1]-b[1]});
    }
    
    bool isConvex(vector<vector<int>>& p) {
        
        int n = p.size();
        //assert(n >= 3);
        p.push_back(p[0]);
        p.push_back(p[1]);
        
        int now = dcmp(cross(minus(p[1], p[0]), minus(p[2], p[1])));
        for (int i = 1; i < n; i++) {
            int next = dcmp(cross(minus(p[i + 1], p[i]), minus(p[i + 2], p[i + 1])));
            if (now * next < 0) {
                return false;
            }
            now = next;
        }
        
        return true;
        
    }
};

vector<string> split(string a, char delim) {
    vector<string> v;
    stringstream ss(a);
    string temp;
    while (getline(ss, temp, delim)) if (temp != "") v.push_back(temp);
    return v;
}



int main()
{
    Solution a;
    string hehe = "/a/b/c/";
    vector<string> ans = split(hehe, '/');
    for (auto i : ans) {
        cout << i << endl;
    }
    cout <<  ans.size() << endl;
    cout << "final" <<endl;
    
    return 0;
}

