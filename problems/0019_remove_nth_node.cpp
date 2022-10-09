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
        ListNode* removeNthFromEnd(ListNode* head, int n) {

            ListNode* tmp = head;
            int i = 1;

            while (i <= n) {
                tmp = tmp->next;
                i++;
            }

            ListNode* startNode = head;
            ListNode* prevNode = nullptr;

            // Iterate to the end
            for (; tmp != nullptr; tmp = tmp->next) {
                prevNode = startNode;
                startNode = startNode->next;
            }

            if (prevNode == nullptr) {
                head = head->next;
            } else {
                prevNode->next = startNode->next;
            }


            return head;
        }
};

int main() {

    /*
    ListNode* five = new ListNode(5, nullptr);
    ListNode* four = new ListNode(4, five);
    ListNode* three = new ListNode(3, four);
    ListNode* two = new ListNode(2, three);
    */
    ListNode* one = new ListNode(1, nullptr);


    Solution solution{};
    ListNode* n_list = solution.removeNthFromEnd(one, 1);

    while (n_list != nullptr) {
        cout << n_list->val << " ";
        n_list = n_list->next;
    }

    cout << "\n";

    return 0;
}