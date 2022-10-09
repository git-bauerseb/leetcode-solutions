#include <bits/stdc++.h>

using namespace std;


// Divide-and-Conquer approach
// Time complexity: O(nlog(n))
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            m_nums = nums;

            return divideAndConquer(0, m_nums.size()-1);
        }


    private:

        int divideAndConquer(int l, int r) {
            if (l == r) {
                return  m_nums[l];
            } else {
                int m = (r + l) / 2;
                int lMax = divideAndConquer(l, m);
                int rMax = divideAndConquer(m+1, r);
                return max(
                    max(lMax, rMax),
                    maxCrossing(l,m,r)
                );
            }
        }

        int maxCrossing(int l, int m, int r) {
            int maxLeft = -100'005;
            int maxRight = -100'005;
            int leftSum = 0;
            int rightSum = 0;

            // Calculate maximum sum to the left
            for (int i = m; i >= l; i--) {
                leftSum += m_nums[i];

                if (leftSum > maxLeft) {maxLeft = leftSum;}
            }

            // Calculate maximum sum to the right
            for (int i = m+1; i <= r; i++) {


                rightSum += m_nums[i];
                if (rightSum > maxRight) {maxRight = rightSum;}
            }

            return max(max(maxLeft, maxRight), maxLeft + maxRight);
        }

        vector<int> m_nums;
};


// Dynamic-Programming approach
// Time complexity: O(n)
class Solution1 {

    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();

            int currentSum = 0;
            int maxSum = numeric_limits<int>::min();

            for (int i = 0; i < n; i++) {
                currentSum = max(nums[i], currentSum + nums[i]);
                maxSum = max(maxSum, currentSum);
            }

            return maxSum;
        }
};

int main() {

    vector<int> nums{6,-3,7};

    Solution1 solution{};
    int maxS = solution.maxSubArray(nums);

    cout << maxS << "\n";

    return 0;
}