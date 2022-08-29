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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int size = 0;
        ListNode* t_head = head;
        while (t_head != nullptr) {size++; t_head = t_head->next;}

        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* tmp = head;
        ListNode* last = head;
        ListNode* t_next = last->next;
        ListNode* temp_head = head;

        for (int i = 0; i < size / k; i++) {
            int num = 0;

            while (num < (k-1)) {
                last = t_next;
                t_next = t_next->next;
                last->next = tmp;
                tmp = last;
                num++;
            }

            if (prev != nullptr) {
                prev->next = last;
            } else {
                prev = last->next;
                head = last;
            }

            temp_head->next = t_next;

            tmp = last;
            first = last;
            last = last;
            temp_head = last;

            if (last != nullptr) {
                t_next = last->next;
            }
        }

        return head;
    }
};

ListNode* build_list(std::vector<int> vec) {
    if (vec.size() == 0) {
        return nullptr;
    } else {
        ListNode* head = new ListNode(vec[0]);
        ListNode* tmp = head;
        for (int i = 1; i < vec.size(); i++) {
            ListNode* n_node = new ListNode(vec[i]);
            tmp->next = n_node;
            tmp = tmp->next;
        }

        return head;
    }
}

void print_list(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << "\n";
}

int main(int argc, char** argv) {

    std::vector<int> case_{1,2,3,4,5,6};

    ListNode* l = build_list(case_);
    Solution solution{};

    ListNode* n_l = solution.reverseKGroup(l, 2);
    print_list(n_l);

    return 0;
}