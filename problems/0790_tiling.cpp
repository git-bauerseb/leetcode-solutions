#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
     int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<vector<long>> dp(n+1, vector<long>(3));
        dp[1][0] = 1; dp[2][0] = 2;
        dp[2][1] = 1;
        dp[2][2] = 1;
        int kmod = (int)1e9 + 7;
        for(int i = 3; i <= n; i++){
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % kmod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % kmod;
            dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % kmod;
        }
        return (int)dp[n][0];
    }
};

int main(int argc, char** argv) {
    Solution solution{};
    int sol = solution.numTilings(5);
    cout << sol << "\n";

    return 0;
}