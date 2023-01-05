#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :
        val(x), left(left), right(right) {}
};

class Solution {

    public:
        TreeNode* sortedListToBST(ListNode* head) {
            vector<int> nums;
            while (head != nullptr) {
                nums.push_back(head->val);
                head = head->next;
            }

            m_root = nullptr;

            if (nums.size() == 0) {return m_root;}

            recInsert(nums, 0, nums.size()-1);
            return m_root;
        }

    private:
        void insert(TreeNode* x, int val) {
            if (x == nullptr) {
                x = new TreeNode(val);
                if (m_root == nullptr) {
                    m_root = x;
                }
            } else {
                if (x->val > val) {
                    if (x->left == nullptr) {
                        x->left = new TreeNode(val);
                    } else {
                        insert(x->left, val);
                    }
                } else {
                    if (x->right == nullptr) {
                        x->right = new TreeNode(val);
                    } else {
                        insert(x->right, val);
                    }
                }
            }
        }

        void recInsert(vector<int>& nums, int s, int e) {
            if (s == e) {
                insert(m_root, nums[s]);
                return;
            }

            if (s == e - 1) {
                insert(m_root, nums[s+1]);
                insert(m_root, nums[s]);
                return;
            }

            int m = s + ((e - s) / 2);
            insert(m_root, nums[m]);

            recInsert(nums, s, m-1);
            recInsert(nums, m+1, e);
        }


        TreeNode* m_root;
};

void inorder(TreeNode* n) {
    cout << n->val << " ";
    if (n->left != nullptr) {inorder(n->left);}
    if (n->right != nullptr) {inorder(n->right);}
}

int main() {

    ListNode* n = new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9)))));

    Solution solution{};
    TreeNode* tree = solution.sortedListToBST(n);
    inorder(tree);

    return 0;
}