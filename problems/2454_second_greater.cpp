#include <bits/stdc++.h>

using namespace std;

struct Comparator {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.first > b.first;
    }
};

/*
    2,4,0,9,6

    Stack:          Indc:
        2
        4           2
        4,0         2
        9           4,0

*/
class Solution {
    public:
        vector<int> secondGreaterElement(vector<int>& nums) {
            const int n = nums.size();

            vector<int> result(n, -1);
            priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator> pq;


            // Save indices of elements less than the current element
            stack<int> mon_stack;

            // Error! Dont compare indices for greater

            // O(n)
            for (int i = 0; i < n; i++) {
                while (!pq.empty()) {
                    auto top = pq.top();
                    if (top.first >= nums[i]) {break;}
                    else {pq.pop(); result[top.second] = nums[i];}
                }

                while (mon_stack.size() > 0 && nums[mon_stack.top()] < nums[i]) {
                    int top_idx = mon_stack.top();
                    mon_stack.pop();
                    pq.push({nums[top_idx], top_idx});
                }
                mon_stack.push(i);
            }
            
            return result;
        }
};

int main() {
    
    // -1 -1 3 3 -1 -1
    vector<int> nums{11,13,15,12,0,15,12,11,9};

    Solution solution{};
    auto result = solution.secondGreaterElement(nums);

    for (auto& e : result) {cout << e << " ";}
    cout << "\n";
    

    return 0;
}