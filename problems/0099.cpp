#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void print();
};

void TreeNode::print() {
    cout << " " << this->val << " ";
    if (this->left != nullptr) {
        this->left->print();
    }
    if (this->right != nullptr) {
        this->right->print();
    }
}
 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(x,y);
    }

    void inorder(TreeNode* root) {

        if (root == nullptr) {return;}

        inorder(root->left);

        if (pred && root->val < pred->val) {
            y = root;

            if (!x) {
                x = pred;
            } else {
                return;
            }
        }

        pred = root;


        inorder(root->right);
    }

    void swap(TreeNode* x, TreeNode* y) {
        const int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }

private:
    TreeNode* pred = nullptr;
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
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

    TreeNode* root = construct_tree({1,3,2});

    root->print();
    cout << "\n";

    Solution solution{};
    solution.recoverTree(root);


    cout << "\n";
    root->print();


    return 0;
}