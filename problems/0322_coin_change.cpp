#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {

            if (amount == 0) {return 0;}

            vector<int> dp(amount+1, -1);
            dp[0] = 0;

            for (int i = 1; i <= amount; i++) {
                
                int minCoins = (1 << 30);
                for (auto& c : coins) {
                    if (i - c >= 0 && dp[i-c] >= 0)
                        minCoins = min(minCoins, dp[i - c]);
                }

                dp[i] = minCoins == (1 << 30) ? -1 : minCoins + 1;
            }

            return dp[amount];
        }
};

int main() {
    vector<int> coins{186,419,83,408};
    Solution solution{};
    int m = solution.coinChange(coins, 187);
    cout << m << "\n";
    return 0;
}