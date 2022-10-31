#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();
            vector<int> diffs(n-1);
            vector<int> sums(n-1);

            for (int i = 0; i < n-1; i++) {
                diffs[i] = prices[i+1] - prices[i];
            }

            for (auto& e : diffs) {
                cout << e << " ";
            }

            cout << "\n";

            
            int currentSum = 0;
            int bestSum = 0;

            for (int i = 0; i < n-1; i++) {
                currentSum = max(0, currentSum + diffs[i]);
                sums[i] = currentSum;
            }

            for(auto& e : sums) {
                cout << e << " ";
            }

            return 0;
            
        }
};

int main() {

    vector<int> nums{1,2,3,4,5};

    Solution solution{};
    int prof = solution.maxProfit(nums);

    // cout << prof << "\n";

    return 0;
}