#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            const int m = s1.length();
            const int n = s2.length();

            if (s3.length() != m + n) {return false;}

            vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
            dp[0][0] = true;

            for (int i = 1; i < n; i++) {dp[0][i] = dp[0][i-1] && (s3[i] == s2[i]);}
            for (int i = 1; i < m; i++) {dp[i][0] = dp[i-1][0] && (s3[i] == s1[i]);}

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = (dp[i][j-1] && (s1[j] == s3[i + j - 1])) 
                        || (dp[i-1][j] && (s2[i] == s3[i - 1 + j]));
                }
            }

            for (int y = 0; y <= m; y++) {
                for (int x = 0; x <= n; x++) {
                    cout << dp[y][x] << " ";
                }

                cout << "\n";
            }

            return dp[m][n];
        }

    private:
        inline bool is_valid(int i, int j, int n, int m) {
            return 0 <= i && i < m && 0 <= j && j < n;
        }
};

int main() {
    Solution solution{};
    bool i = solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    cout << i << "\n";
    return 0;
}