struct Node {
    int start, end, sum;
    Node* left;
    Node* right;
    Node(int a, int b): start(a), end(b), sum(0), left(NULL), right(NULL){}
};

class NumArray {
private:
    Node* root;
public:
    NumArray(vector<int> &nums) {
        int size = (int)nums.size();
        root = build(nums, 0, size-1);
    }
    Node* build(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        Node* root = new Node(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        } else {
            int mid = start + (end-start) / 2;
            root->left = build(nums, start, mid);
            root->right = build(nums, mid+1, end);
            root->sum = root->left->sum + root->right->sum;
            return root;
        }
    }
    void update(int i, int val) {
        update(i, val, root);
    }
    int update(int i, int val, Node* root) {
        if (!root) return 0;
        int diff;
        if (root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (i > mid) {
                diff = update(i, val, root->right);
            } else {
                diff = update(i, val, root->left);
            }
            root->sum = root->sum + diff;
            return diff;
        }
    }
    
    int sumRange(int i, int j) {
        return sumRange(i, j, root);
    }
    int sumRange(int i, int j, Node* root) {
        if (!root) return 0;
        if (root->start == i && root->end == j) {
            return root->sum;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (i > mid) {
                return sumRange(i, j, root->right);
            } else if (j <= mid) {
                return sumRange(i, j, root->left);
            } else {
                return sumRange(i, mid, root->left) + sumRange(mid+1, j, root->right);
            }
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);