#include <bits/stdc++.h>

using namespace std;

/*
    [2,3,4,5,5,4,3,2,2,3,4,5,6]

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;

        for(auto& v : nums) {
            val ^= v;
        }

        return val;
    }
};

int main(int argc, char** argv) {

    vector<int> nums{-1, -2, -3, -2, -3};

    Solution solution{};
    int result = solution.singleNumber(nums);

    cout << result << "\n";

    return 0;
}