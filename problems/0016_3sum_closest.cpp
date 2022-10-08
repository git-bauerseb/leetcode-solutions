#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int sum = 0;
        int best_diff = 1 << 30;
        int best_sum = 1 << 30;

        int lower = 0;
        int higher = 0;

        for (int i = 0; i < n-2; i++) {
            lower = i+1;
            higher = n-1;

            while (lower < higher) {
                sum = nums[i] + nums[lower] + nums[higher];
                int diff = abs(target - sum);

                if (diff < best_diff) {
                    best_diff = diff;
                    best_sum = sum;
                    if (diff == 0) {return sum;}
                }
                
                if (sum > target) {
                    higher--;
                } else {
                    lower++;
                }
            }
        }

        return best_sum;
    }
};

int main(int argc, char** argv) {
    vector<int> nums{1,2,3,4,5};
    Solution solution{};

    int closest = solution.threeSumClosest(nums, 1);
    cout << closest << "\n";
    return 0;
}