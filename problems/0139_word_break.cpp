#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        vector<bool> dp(n+1, false);

        dp[0] = false;

        for (auto& w : wordDict) {
            if (s.compare(0, w.size(), w) == 0) {
                dp[w.size()] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (auto& w : wordDict) {
                int wLen = w.size();
                if (i - wLen >= 0) {
                    if (s.compare(i - wLen, wLen, w) == 0
                        && dp[i - wLen]) {
                        dp[i] = true;
                    }
                }
            }
        }

        return dp[n];
    }
};


int main() {

    string toSegment("hellomynameis");
    vector<string> dict{"h", "m", "y", "ei", "el", "l", "o", "a", "n", "s"};

    Solution solution{};
    bool canSegment = solution.wordBreak(toSegment, dict);

    cout << canSegment << "\n";

    return 0;
}