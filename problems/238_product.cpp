#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        if (nums.size() == 2) {
            vector<int> result;
            result.push_back(nums[1]);
            result.push_back(nums[0]);
            return result;
        }

        int n = nums.size();
        
        vector<int> first_list(n-2, 1);
        vector<int> second_list(n-2, 1);

        int prev1 = 1;
        int prev2 = 1;


        // Runtime: O(n)
        for (int i = 0; i < n - 2; i++) {
            prev1 *= nums[i];
            prev2 *= nums[n - i - 1];
            
            first_list[i] = prev1;
            second_list[n - i - 3] = prev2;
        }

        vector<int> output(n, 0);

        output[0] = second_list[0] * nums[1];

        for (int i = 1; i < n - 1; i++) {
            output[i] = first_list[i-1] * second_list[i - 1];
        }

        output[n-1] = first_list[n-3] * nums[n - 2];

        return output;
    }
};

int main() {

    vector<int> nums{-1, 1, 0, -3, 3};

    Solution solution{};
    auto res = solution.productExceptSelf(nums);

    for (auto& e : res) {
        cout << e << " ";
    }

    return 0;
}