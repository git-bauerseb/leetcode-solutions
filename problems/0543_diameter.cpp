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
        int diameterOfBinaryTree(TreeNode* root) {
            m_maxLength = 0;

            dfs(root);

            return m_maxLength;
        }

    private:

        int dfs(TreeNode* root) {
            if (root->left == nullptr && root->right == nullptr) {
                return 1;
            }

            int leftMax = 0;
            int rightMax = 0;

            if (root->left != nullptr) {
                leftMax = dfs(root->left);
            }

            if (root->right != nullptr) {
                rightMax = dfs(root->right);
            }

            if (leftMax + rightMax > m_maxLength) {

                m_maxLength = leftMax + rightMax;
            }

            return max(leftMax, rightMax) + 1;
        }

        int m_maxLength;
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

    TreeNode* root = construct_tree({1,2,3,4,6,-1,-1,7,-1,-1,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,-1});

    Solution solution{};


    cout << solution.diameterOfBinaryTree(root) << "\n";

    return 0;
}