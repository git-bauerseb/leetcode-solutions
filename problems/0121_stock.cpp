#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();
            
            if (n == 1) {return 0;}
            if (n == 2 && prices[0] < prices[1]) {
                return prices[1] - prices[0];
            } 

            vector<int> diffs(n-1);

            for (int i = 0; i < n-1; i++) {
                diffs[i] = prices[i+1] - prices[i];
            }

            int maxSum = 0;
            int cSum = 0;

            int sIdx = 0;
            int eIdx = 0;

            int bestSIdx = 0;
            int bestEIdx = 0;

            for (int i = 0; i < n-1; i++) {
                eIdx = i;


                if (cSum <= 0) {
                    sIdx = eIdx;
                    cSum = diffs[i];
                } else {
                    cSum += diffs[i];
                }

                if (cSum > maxSum) {
                    maxSum = cSum;
                    bestSIdx = sIdx;
                    bestEIdx = eIdx;
                }

            }


            int bestMargin = prices[bestEIdx+1] - prices[bestSIdx];

            if (bestMargin < 0) {
                return 0;
            }

            return bestMargin;
        }
};


class Solution1 {
    public:
        int maxProfit(vector<int>& prices) {

            const int n = prices.size();

            int min_ = prices[0];
            int profit = 0;


            for (int i = 1; i < n; i++) {
                profit = max(profit, prices[i] - min_);
                min_ = min(min_, prices[i]);
            }

            return profit;
        }
};


int main() {

    vector<int> nums{7,1,9,1,11,24};

    Solution1 solution{};
    int profit = solution.maxProfit(nums);

    cout << profit << "\n";

    return 0;
}