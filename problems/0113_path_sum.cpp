#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {

    public:
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

            if (!root) {return paths;}

            m_target = targetSum;
            vector<TreeNode*> path;
            backtrack(root, path, 0);

            return paths;
        }

    private:
        void backtrack(TreeNode* root, vector<TreeNode*>& path, int currentSum) {
            if (!root->left && !root->right) {
                if (currentSum + root->val == m_target) {

                    vector<int> n_path;
                    for (vector<TreeNode*>::iterator i = path.begin(); i != path.end(); i++) {
                        n_path.push_back((*i)->val);
                    }
                    n_path.push_back(root->val);
                    paths.push_back(n_path);
                }
            } else {
                path.push_back(root);
               
                if (root->left) {backtrack(root->left, path, currentSum + root->val);}
                if (root->right) {backtrack(root->right, path, currentSum + root->val);}

                path.pop_back();
            }
        }

        int m_target;
        vector<vector<int>> paths;
};

TreeNode* construct_tree(vector<int> nums) {
    int n = nums.size();

    TreeNode* root = nullptr;
    TreeNode** nodes = new TreeNode*[n];


    for (int i = 0; i < n; i++) {
        if (nums[i] != -1) {
            nodes[i] = new TreeNode(nums[i]);
        } else {
            nodes[i] = nullptr;
        }
    }

    int idx = 0;
    while (idx < n / 2) {
        TreeNode* current = nodes[idx];
        if (current) {
            if (2 * idx + 1 < n) {
                current->left = nodes[2 * idx + 1];
            }

            if (2 * idx + 2 < n) {
                current->right = nodes[2 * idx + 2];
            }
        }

        idx++;
    }

    root = nodes[0];

    return root;
}

int main() {

    TreeNode* root = construct_tree({5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1});
    // TreeNode* root = construct_tree({0,1,1});
    
    Solution solution{};
    auto sums = solution.pathSum(root, 22);

    for (auto& sum : sums) {
        for (auto& e : sum) {
            cout << e << " ";
        }

        cout << "\n";
    }

    return 0;
}