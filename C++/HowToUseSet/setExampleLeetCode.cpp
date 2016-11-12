#include <iostream>
#include <bitset>
#include <ctime>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cctype> // For the isDigit
#include <stack>
#include <sstream> // For the change between int and string or any type
#include <set>
//int a=10;
//stringstream ss;
//ss<<a;
//return ss.str();

// typedef long long ll;

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};





int main(){
    TreeNode* root = new TreeNode(1);
    //TreeNode* child1 = new TreeNode(2);
    //TreeNode* child2 = new TreeNode(3);
    //TreeNode* child3 = new TreeNode(4);
    
    //root->left = child1;
    //root->right = child2;
    //root->left->left = child3;
    
    Interval aa(1, 3);
    Interval bb(4, 6);
    Interval cc(5, 7);
    
    pair<int, int> a(0,0);
    pair<int, int> b(1,0);
    pair<int, int> c(2,0);
    
    
    LFUCache test(2);

    /*
    test.set(2, 1);
    test.set(3, 2);
    test.get(3);
    test.get(2);
    test.set(4, 3);
    test.get(2);
    test.get(3);
    test.get(4);
    */
    
    
    
    // cout << test.get(1) << endl;
    /*
    test.set(2, 2);
    test.set(1, 1);
    test.get(2);
    test.get(1);
    test.get(2);
    test.set(3,3);
    test.set(4,4);
    test.get(3);
    test.get(2);
    test.get(1);
    test.get(4);
    */
    
    
    /*
    test.set(1, 1);
    test.set(2, 2);
    test.set(3, 3);
    test.set(4, 4);
    
    test.get(4);
    test.get(3);
    test.get(2);
    test.get(1);
    
    test.set(5, 5);

    
    test.get(1);
    test.get(2);
    test.get(3);
    test.get(4);
    test.get(5);

    */
    
    
    return 0;
}
