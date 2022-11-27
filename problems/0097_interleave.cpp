#include <bits/stdc++.h>

using namespace std;


/*
// Recursive solution
// Time complexity: Exponential
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            return rec(s1, s2, s3, 0, 0, 0);
        }


    private:
        bool rec(string& s1, string& s2, string& s3, int i, int j, int k) {
            if (k == s3.length() && i == s1.length() && j == s2.length()) {
                return true;
            }

            if (i < s1.length() && k < s3.length() && s1[i] == s3[k]) {
                if (rec(s1, s2, s3, i+1, j, k+1)) {return true;}
            }

            if (j < s2.length() && k < s3.length() && s2[j] == s3[k]) {
                if (rec(s1, s2, s3, i, j+1, k+1)) {return true;}
            }

            return false;
        }
};
*/

// Dynamic programming solution
// Time complexity: O(n*m)
// Space complexity: O(n + m)
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            
            const int n = s1.length();
            const int m = s2.length();

            if (n + m != s3.length()) {return false;}

            bool dp[n+1][m+1];
            dp[0][0] = true;

            for (int i = 1; i <= n; i++) {dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];}
            for (int i = 1; i <= m; i++) {dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];}

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i + j - 1])
                            || (dp[i][j-1] && s2[j-1] == s3[i + j - 1]);
                }
            }
            
            return dp[n][m];
        }
};


int main() {

    Solution solution{};
    bool res = solution.isInterleave("", "", "a");
    cout << res << "\n";
    return 0;
}