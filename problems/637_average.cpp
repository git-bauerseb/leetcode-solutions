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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average;
        average.push_back(root->val);

        traverse_average(root, average);
        return average;
    }

private:
    double traverse_average(TreeNode* current, vector<double>& average) {

        if (current->left == nullptr && current->right == nullptr) {return;}

        double val_left = 0.0;
        double val_right = 0.0;
        double num_vals = 0;
        
        if (current->left != nullptr) {
            val_left = current->left->val;
            num_vals++;
        }

        if (current->right != nullptr) {
            val_right = current->right->val;
            num_vals++;
        }

        average.push_back((val_left + val_right)/num_vals);

        if (current->left != nullptr) {traverse_average(current->left, average);}
        if (current->right != nullptr) {traverse_average(current->right, average);}
    }
};

int main(int argc, char** argv) {

    TreeNode* root = new TreeNode(3);
    TreeNode* l_l1 = new TreeNode(9);
    TreeNode* r_l1 = new TreeNode(20);
    TreeNode* l_l2 = new TreeNode(15);
    TreeNode* r_l2 = new TreeNode(7);

    r_l1->left = l_l2;
    r_l1->right = r_l2;
    root->right = r_l1;
    root->left = l_l1;

    Solution solution{};
    vector<double> avg = solution.averageOfLevels(root);

    for (auto& v : avg) {
        cout << v << "\n";
    }

    return 0;
}