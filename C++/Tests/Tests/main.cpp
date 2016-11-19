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
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int size = (int)sentence.size();
        if (size == 0) return 0;
        
        // Calculate the complete len's length
        int len = 0;
        for (int i=0; i<size; ++i) {
            len += (int)sentence[i].size() + 1;
        }
        
        int ans = 0; int index = 0;
        unordered_map<int, pair<int, int>> umap; // first - this string' index, second - <next row's beginning string's index and how many passes for this row>
        while (rows--) {
            if (umap.count(index)) {
                ans += umap[index].second;
                index = umap[index].first;
            } else {
                int maxCols = cols;
                int i = index;
                int pass = 0;
                if ((maxCols-len)/len) {
                    pass = (maxCols-len)/len;
                    maxCols -= pass*len;
                    ans += pass;
                }
                while (true) {
                    if (maxCols >= (int)sentence[i].size()) {
                        maxCols = maxCols - (int)sentence[i].size() - 1;
                        ++i;
                        if (i == size) {
                            i = 0; ++pass; ++ans;
                        }
                    } else break;
                }
                umap[index].first = i; umap[index].second = pass;
                index = i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    
    vector<string> sentence = {"h"};
    cout << a.wordsTyping(sentence, 2, 3) << endl;
    
    return 0;
}

