#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int lcs = longestCommonSubSeq(word1,word2,n,m);
        return n + m - 2*lcs;
    }

private:
    int longestCommonSubSeq(string& x, string& y, int m, int n) {

        int c[m+1][n+1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    c[i][j] = 0;
                else if (x[i - 1] == y[j - 1])
                    c[i][j] = c[i - 1][j - 1] + 1;
                else
                    c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
            }
        }

        return c[m][n];
    }
};

int main(int argc, char** argv) {

    Solution solution{};
    int lcs = solution.minDistance("e", "eat");
    cout << lcs << "\n";
    return 0;
}