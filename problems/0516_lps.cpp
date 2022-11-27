#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            const int n = s.length();
            vector<pair<int,int>> dp(n);

            dp[0] = {1,0};

            for (int i = 1; i < n; i++) {
                char current = s[i];
                int maxJ = -1;
                int maxLen = 1;

                for (int j = i - 1; j >= 0; j--) {
                    pair<int,int> prev = dp[j];

                    if (s[prev.second] == current) {
                        if (prev.first >= maxLen) {
                            maxJ = j;
                            maxLen = prev.first + 1;
                        }
                    }

                    dp[i] = {maxJ >= 0 ? maxLen : 1, maxJ >= 0 ? dp[maxJ].second : i};
                }
            }

            return dp[n-1].first;
        }
};
*/

/*
// Recursive solution
// Exponential runtime
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            return rec(s, 0, s.length()-1);
        }

    private:
        int rec(string s, int i, int j) {
            if (j < i) {return 0;}
            if (i == j) {return 1;}
            if (s[i] == s[j]) {
                return 2 + rec(s, i + 1, j - 1);
            } else {
                return max(
                    rec(s, i + 1, j),
                    rec(s, i, j - 1)
                );
            }
        }
};
*/

class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            int n = s.length();

            int dp[n][n];

            // Substrings of length 1 are palindroms of length 1
            for (int i = 0; i < n; i++) {dp[i][i] = 1;}

            // Empty substrings are palindroms of length 0
             for (int i = 0; i < n; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    dp[i][j] = 0;
                }
            }


            for (int i = n-2; i >= 0; i--) {
                for (int j = i+1; j < n; j++) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }


            return dp[0][n-1];
        }
};

int main() {

    vector<string> cases;
    cases.push_back("bbbab");   // 4
    cases.push_back("abcb");    // 3
    cases.push_back("ccbb");    // 2
    cases.push_back("a");       // 1
    

    Solution solution{};
    for (auto& c : cases) {
        int l = solution.longestPalindromeSubseq(c);
        cout << l << "\n";
    }
    return 0;
}