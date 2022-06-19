#include <iostream>
#include <string>

class Solution {
    public:
        int longestCommonSubsequence(std::string text1, std::string text2) {
            char* s1 = &text1[0];
            char* s2 = &text2[0];

            return longestCommonSubSeq(s1, s2, text1.length(), text2.length());
        }

    private:
        int longestCommonSubSeq(char* x, char* y, int m, int n) {

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

    std::string s1 {"abcde"};
    std::string s2 {"ace"};
    Solution solution{};

    int len = solution.longestCommonSubsequence(s1, s2);
    std::cout << len << "\n";

    return 0;
}