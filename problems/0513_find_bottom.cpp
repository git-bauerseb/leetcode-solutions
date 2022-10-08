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

class Solution  {
    public:
        int findBottomLeftValue(TreeNode* root) {
            m_current.push(root);
            return findBottomLeftValueHelper(root);
        }

    private:

        int findBottomLeftValueHelper(TreeNode* root) {
            TreeNode* leftmost = root;

            while (true) {

                int current_size = m_current.size();

                while (m_current.size() > 0) {
                    TreeNode* e = m_current.front();
                    m_current.pop();

                    if (e->left) {
                        m_next.push(e->left);
                    }

                    if (e->right) {
                        m_next.push(e->right);
                    }
                }

                if (m_next.size() == 0) {break;}

                swap(m_current, m_next);
                leftmost = m_current.front();
            }


            return leftmost->val;
        }

        queue<TreeNode*> m_current;
        queue<TreeNode*> m_next;
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

    TreeNode* root = construct_tree({3,-1,5,-1,-1,4,-1,-1});
    Solution solution{};


    cout << solution.findBottomLeftValue(root) << "\n";

    return 0;
}