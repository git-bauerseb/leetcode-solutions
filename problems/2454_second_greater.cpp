#include <bits/stdc++.h>

using namespace std;

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
            set<int> indc;

            // Save indices of elements less than the current element
            stack<int> mon_stack;

            // O(n)
            for (int i = 0; i < n; i++) {

                if (indc.size() > 0) {
                    for (auto it = indc.begin(); it != indc.end();) {
                        if (nums[*it] < nums[i]) {
                            result[*it] = nums[i];
                            it = indc.erase(it);
                        } else {
                            it++;
                        }
                    }
                }

                while (mon_stack.size() > 0 
                    && nums[mon_stack.top()] < nums[i]) {
                    int top_idx = mon_stack.top();
                    mon_stack.pop();
                    indc.insert(top_idx);
                }
                mon_stack.push(i);
            }
            
            return result;
        }
};

int main() {
    // -1 -1 3 3 -1 -1
    vector<int> nums{2,4,0,9,6};

    Solution solution{};
    auto result = solution.secondGreaterElement(nums);

    for (auto& e : result) {cout << e << " ";}
    cout << "\n";
    return 0;
}