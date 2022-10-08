#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        if (root->left == nullptr && root->right == nullptr) {return true;}

        return isValidBSTExtended(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }

private:
    bool isValidBSTExtended(TreeNode* root, long leftVal, long rightVal) {
        if (!(root->val > leftVal && root->val < rightVal)) {
            return false;
        }

        if (root->left != nullptr) {
            if (!isValidBSTExtended(root->left, leftVal, root->val)) {return false;}

        }

        if (root->right != nullptr) {
            if (!isValidBSTExtended(root->right, root->val, rightVal)) {return false;}

        }

        return true;
    }
};

TreeNode* construct_tree(vector<int> nums) {
    int n = nums.size();

    TreeNode* root = nullptr;
    TreeNode** nodes = new TreeNode*[n];

    int idx = 0;
    while (idx < n) {
        TreeNode* current = nullptr;
        
        
        if (nums[idx] != -1) {
            current = new TreeNode(nums[idx]);
        }
        
        nodes[idx] = current;

        int parent = (idx-1) / 2;

        if (idx == 0) {
            root = current;
        } else {
            bool isLeft = (2 * parent + 1) == idx;

            if (isLeft && nodes[parent] != nullptr) {
                nodes[parent]->left = current;
            } else if (nodes[parent] != nullptr) {
                nodes[parent]->right = current;
            }
        }

        idx++;
    }

    return root;
}



int main() {
    TreeNode* root = construct_tree({-2147483647,-1,2147483647});


    Solution solution{};
    bool valid = solution.isValidBST(root);

    cout << valid << "\n";


    return 0;
}