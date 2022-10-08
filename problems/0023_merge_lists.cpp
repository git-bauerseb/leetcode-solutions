#include <iostream>

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
        ListNode* mergeKLists(std::vector<ListNode*>& lists) {

            if (lists.size() == 0) {
                return nullptr;
            }

            bool remaining = true;

            ListNode* head = nullptr;
            ListNode* curr = nullptr;

            while (remaining) {

                // Find least element of lists
                int idx = -1;
                int minVal = 1 << 27;

                for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] != nullptr && lists[i]->val < minVal) {
                        minVal = lists[i]->val;
                        idx = i;
                    }
                }

                if (idx < 0) {
                    remaining = false;
                } else {
                    lists[idx] = lists[idx]->next;
                
                    if (head == nullptr) {
                        head = new ListNode();
                        head->val = minVal;
                        curr = head;
                    } else {
                        ListNode* tmp = new ListNode();
                        tmp->val = minVal;
                        curr->next = tmp;
                        curr = curr->next;
                    }
                }
            }

            return head;
        }
};

ListNode* construct_list(std::vector<int> values) {

    if (values.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode();
    head->val = values[0];

    ListNode* curr = head;

    for (int i = 1; i < values.size(); i++) {
        ListNode* tmp = new ListNode();
        tmp->val = values[i];

        curr->next = tmp;
        curr = curr->next;
    }

    return head;
}

void print_list(ListNode* l) {
    while (l != nullptr) {
        std::cout << " " << l->val << " ";
        l = l->next;
    }

    std::cout << "\n";
}

int main(int argc, char** argv) {

    std::vector<ListNode*> test_case{};

    /*
    test_case.push_back(construct_list({1,4,5}));
    test_case.push_back(construct_list({1,3,4}));
    test_case.push_back(construct_list({2,6}));
    */

    test_case.push_back(construct_list({7,11,13}));
    test_case.push_back(construct_list({12,14}));
    test_case.push_back(construct_list({}));

    Solution solution{};

    ListNode* node = solution.mergeKLists(test_case);
    print_list(node);

    return 0;
}