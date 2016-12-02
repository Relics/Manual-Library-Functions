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

int main()
{
    Solution a;
    
    vector<vector<int>> sentence = {{1,1},{2,1},{1,2},{-1,1},{1,-1}};
    if (a.isConvex(sentence)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}

