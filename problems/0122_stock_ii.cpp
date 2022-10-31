#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();

            int min_ = prices[0];
            int max_ = prices[0];
            int profit = 0;

            for (int i = 1; i < n; i++) {
                if (prices[i] - min_ > 0) {
                    profit += prices[i] - min_;
                    min_ = prices[i];
                }

                min_ = min(min_, prices[i]);
            }

            return profit;
        }
};

int main() {

    vector<int> nums{3,3,5,0,0,3,1,4};

    Solution solution{};
    int prof = solution.maxProfit(nums);

    cout << prof << "\n";

    return 0;
}