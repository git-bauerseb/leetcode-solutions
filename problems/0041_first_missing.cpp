#include <bits/stdc++.h>

using namespace std;

#define IS_SANE_ELEMENT(i) ((nums[i] != numeric_limits<int>::min() && nums[i] != numeric_limits<int>::max()))

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int n = nums.size();

            // Swap elements until at correct position
            // Although this loop looks not like O(n) [because i is decremented], a simple observation shows that every element is swapped
            // at most 1 time (because then it's at its correct position) and thus this loop runs at most 2n times => O(n)
            for (int i = 0; i < n; i++) {
                // Stupid error because of integer overflow so add this check to make Leetcode happy :)
                if (IS_SANE_ELEMENT(i) && nums[i]-1 >= 0 && nums[i]-1 < n) {
                    if (nums[i]-1 != i && nums[nums[i]-1] != nums[i]) {
                        swap(nums[i], nums[nums[i]-1]);
                        i--;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (nums[i] != i+1) {
                    return i+1;
                }
            }

            return n+1;
        }
};

int main() {

    vector<int> nums{6,5,4,3,2,1};

    Solution solution{};
    int missing = solution.firstMissingPositive(nums);

    cout << missing << "\n";

    return 0;
}