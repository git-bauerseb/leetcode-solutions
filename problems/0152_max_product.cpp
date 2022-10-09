#include <bits/stdc++.h>

using namespace std;

// Divide-and-Conquer approach
// Time complexity: O(nlog(n))
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            m_nums = nums;

            return divideAndConquer(0, m_nums.size()-1);
        }


    private:

        long divideAndConquer(int l, int r) {
            if (l == r) {
                return  m_nums[l];
            } else {
                int m = (r + l) / 2;
                long lMax = divideAndConquer(l, m);
                long rMax = divideAndConquer(m+1, r);
                return max(
                    max(lMax, rMax),
                    maxCrossing(l,m,r)
                );
            }
        }

        long maxCrossing(int l, int m, int r) {
            long maxLeft = (long)numeric_limits<int>::min() - 1;
            long maxRight = (long)numeric_limits<int>::min() - 1;

            long minLeft = 0;
            long minRight = 0;

            long leftProd = 1;
            long rightProd = 1;

            // Calculate maximum sum to the left
            for (int i = m; i >= l; i--) {
                if (i < m && m_nums[i] == 0) {
                    break;
                }

                leftProd *= m_nums[i];


                if (leftProd > maxLeft) {maxLeft = leftProd;}
                if (leftProd < minLeft) {minLeft = leftProd;}
            }

            // Calculate maximum sum to the right
            for (int i = m+1; i <= r; i++) {
                if (i > m+1 && m_nums[i] == 0) {
                    break;
                }

                rightProd *= m_nums[i];
                if (rightProd > maxRight) {maxRight = rightProd;}
                if (rightProd < minRight) {minRight = rightProd;}
            }

            long c_max = max(maxLeft, maxRight);
            c_max = max(c_max, maxRight * maxLeft);
            c_max = max(c_max, minLeft * minRight);
            return c_max;
        }

        vector<int> m_nums;
};

int main() {

    vector<int> nums{-2,3,-4};

    Solution solution{};
    int max = solution.maxProduct(nums);

    cout << max << "\n";

    return 0;
}