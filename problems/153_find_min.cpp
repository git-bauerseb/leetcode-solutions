#include <bits/stdc++.h>

using namespace std;

/**
 *  n elements
 *  [ a[j], ..., a[n-1], a[0], ..., a[j-1] ]
 *    <- n - 1 - j + 1 ->
 * 
 *  [0,1,2,4,5,6,7]
 *      Rotate 1: [7,0,1,2,4,5,6]
 *      Rotate 2: [6,7,0,1,2,4,5]
 *      Rotate 8: [7,0,1,2,4,5,6]
 * 
 * 
 *      Rotate 5: [2,4,5,6,7,0,1]
 *  
 *  Idea:
 *      - find degree of rotation (j) via binary search
 *      - then compute smallest element with:
 *          
 * 
 */

class Solution {
    public:
        int findMin(vector<int>& nums) {

            if (nums.size() == 1) {
                return nums[0];
            }

            if (nums.size() == 2) {
                return nums[0] < nums[1] ? nums[0] : nums[1];
            }

            int n = nums.size();

            int toCompare = nums[0];

            int l = 1;
            int r = n - 1;

            while (l < r) {
                int m = (r + l) / 2;

                if (nums[m] > toCompare) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            if (l == r && l < (n-1) && nums[l] > nums[r+1]) {
                return nums[r+1];
            } else if (l == (n-1) && nums[l] > toCompare) {
                return nums[0];
            }

            return nums[l];
        }
};


int main() {


    vector<int> nums{4,5,1,2,3};

    Solution solution{};
    int min = solution.findMin(nums);

    cout << min << "\n";

    return 0;
}