#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            const int n = nums.size();

            vector<int> amount(n+2, 0);

            for (int i = 0; i < n; i++) {
                amount[i+2] = max(amount[i+1], nums[i] + amount[i]);
            }


            return amount[n+1];
        }
};

int main() {

    vector<int> nums{0};
    Solution solution{};

    int amount = solution.rob(nums);
    cout << amount << "\n";

    return 0;
}