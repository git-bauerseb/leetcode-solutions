#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        set<int> s;

        for (int i = 0; i < n; i++) {
            if (s.find(nums[i]) != s.end()) {
                continue;
            }

            auto iter = s.insert(nums[i]);
            if (iter.second && (++iter.first) != s.end()) {
                s.erase(iter.first);
            }
        }

        return s.size();
    }
};

int main(int argc, char** argv) {

    vector<int> nums{0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

    Solution solution{};
    int max_sub = solution.lengthOfLIS(nums);


    cout << max_sub << "\n";

    return 0;
}