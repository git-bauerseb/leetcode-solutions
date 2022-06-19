#include <iostream>
#include <cmath>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int transfer = 0;

            ListNode* current = nullptr;
            ListNode* first = nullptr;

            while (l1 != nullptr && l2 != nullptr) {
                int n_val = l1->val + l2->val + transfer;
                if (n_val >= 10) {
                    transfer = 1;
                    n_val -= 10;
                } else {
                    transfer = 0;
                }

                ListNode* tmp = createNode(n_val, nullptr);

                if (current == nullptr) {
                    first = tmp;
                    current = tmp;
                } else {
                    current->next = tmp;
                    current = tmp;
                }

                l1 = l1->next;
                l2 = l2->next;
            }

            ListNode* remaining = l1 == nullptr ? (l2 == nullptr ? nullptr : l2) : l1;

            // Add remaining numbers
            while (remaining != nullptr) {

                int n_val = remaining->val + transfer;
                if (n_val >= 10) {
                    transfer = 1;
                    n_val -= 10;
                } else {
                    transfer = 0;
                }

                ListNode* tmp = createNode(n_val, nullptr);

                if (current == nullptr) {
                    first = tmp;
                    current = tmp;
                } else {
                    current->next = tmp;
                    current = tmp;
                }

                remaining = remaining->next;
            }

            // Add transfer if > 0
            if (transfer > 0) {
                current->next = createNode(transfer, nullptr);
            }

            return first;
        }

    private:
        ListNode* createNode(int val, ListNode* next) {
            ListNode* node = new ListNode(val, next);
            return node;
        }
};

ListNode* createNodeFromVec(std::vector<int> nums) {
    ListNode* current = nullptr;
    ListNode* head;

    int idx = 0;

    while (idx < nums.size()) {
        if (current == nullptr) {
            current = new ListNode(nums[idx]);
            head = current;
        } else {
            ListNode* tmp = new ListNode(nums[idx]);
            current->next = tmp;
            current = tmp;
        }
        idx++;
    }

    return head;
}

int main(int argc, char** argv) {

   
    ListNode* first = createNodeFromVec({2,4,3});
    ListNode* second = createNodeFromVec({5,6,4});

    Solution solution{};
    ListNode* node = solution.addTwoNumbers(first, second);

    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }

    return 0;
}
