#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {

            const int m = matrix.size();
            const int n = matrix[0].size();

            // pair<int,int>: width, height

            vector<vector<int>> dp(m, vector<int>(n,0));
            bool found_any = false;

            if (matrix[0][0] == '1') {
                dp[0][0] = 1;
            }

            for (int x = 0; x < n; x++) { if (matrix[0][x] == '1') {dp[0][x] = 1; found_any = true;}}
            for (int y = 0; y < m; y++) {if (matrix[y][0] == '1') {dp[y][0] = 1; found_any = true;}}

            int max_ = found_any ? 1 : 0;

            for (int y = 1; y < m; y++) {
                for (int x = 1; x < n; x++) {
                    if (matrix[y][x] == '1') {
                        int width = dp[y-1][x-1];

                        if (width > 0) {
                            dp[y][x] = min(min(width, dp[y][x-1]), dp[y-1][x]) + 1;
                        } else {
                            dp[y][x] = 1;
                        }

                        if (dp[y][x] * dp[y][x] > max_) {
                            max_ = dp[y][x] * dp[y][x];
                        }
                    }
                }
            }

            return max_;
        }
};

int main() {

    vector<vector<char>> matrix;
    matrix.push_back({'1'});

    Solution solution{};
    int max_ = solution.maximalSquare(matrix);
    cout << max_ << "\n";
    return 0;
}