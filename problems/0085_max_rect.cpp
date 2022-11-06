#include <bits/stdc++.h>

using namespace std;

#define IS_RECT(r) ((r).first != 0 && (r).second != 0)

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {

            const int m = matrix.size();
            const int n = matrix[0].size();

            // Save (width, height) of largest rectangle ending at (i,j)
            vector<vector<pair<int,int>>> dp(m, vector<pair<int,int>>(n, {0,0}));

            dp[0][0].first = dp[0][0].second = matrix[0][0] - '0';

            bool found_any_1 = false;

            // Base case
            for (int y = 1; y < m; y++) {
                if (matrix[y][0] == '1') {
                    dp[y][0].second = dp[y-1][0].second + 1;
                    found_any_1 = true;
                }
            }
            for (int x = 1; x < n; x++) {
                if (matrix[0][x] == '1') {
                    dp[0][x].first = dp[0][x-1].first + 1;
                    found_any_1 = true;
                }
            }
        
            int max_ = found_any_1 ? 1 : 0;

            // Induction step
            for (int y = 1; y < m; y++) {
                for (int x = 1; x < n; x++) {
                    if (matrix[y][x] == '1') {

                        int cMaxArea = 1;

                        int case1Width = 0, case1Height = 0;
                        int case2Width = 0, case2Height = 0;
                        int case3Width, case3Height;

                        if (IS_RECT(dp[y][x-1]) && IS_RECT(dp[y-1][x-1]) && IS_RECT(dp[y-1][x])) {
                            case1Width = min(dp[y][x-1].first, dp[y-1][x-1].first) + 1;
                            case1Height = min(dp[y-1][x].second, dp[y-1][x-1].second) + 1;
                        }

                        if (IS_RECT(dp[y][x-1])) {
                            case2Width = dp[y][x-1].first+1;
                            case2Height = 1;
                        }

                        if (IS_RECT(dp[y-1][x])) {
                            case3Width = 1;
                            case3Height = dp[y-1][x].second + 1;
                        }

                        const int a = case1Width * case1Height;
                        const int b = case2Width * case2Height;
                        const int c = case3Width * case3Height;

                        if (a > b)


                    }
                }
            }

            return max_;
        }
};

int main() {

    Solution solution{};

    return 0;
}