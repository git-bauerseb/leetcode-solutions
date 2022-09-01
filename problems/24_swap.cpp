#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Case for length 0
        if (head == nullptr) {
            return nullptr;
        }

        // Case for length 1
        if (head->next == nullptr) {
            return head;
        }

        ListNode* current, *next, *tmp, *new_head, *prev;

        current = head;
        next = current->next;
        tmp = next->next;


        new_head = next;

        current->next = tmp;
        next->next = current;



        while (tmp != nullptr) {
            prev = current;

            // Assign new position
            current = tmp;

            if (current == nullptr || next == nullptr) {
                break;
            }

            if (current != nullptr) {
                next = current->next;
            } else {
                break;
            }

            if (next != nullptr) {
                tmp = next->next;
            } else {
                break;
            }


            current->next = tmp;
            next->next = current;
            prev->next = next;
        }
        return new_head;
    }
};

ListNode* construct_list(vector<int> vec) {
    if (vec.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(vec[0]);
    ListNode* tmp = head;

    for (int i = 1; i < vec.size(); i++) {
        ListNode* n_node = new ListNode(vec[i]);
        tmp->next = n_node;
        tmp = tmp->next;
    }

    return head;
}

int main(int argc, char** argv) {

    ListNode* head = construct_list({1,2,3,4,5});

    Solution solution{};
    ListNode* n_head = solution.swapPairs(head);


    ListNode* tmp = n_head;

    while (tmp != nullptr) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    return 0;
}