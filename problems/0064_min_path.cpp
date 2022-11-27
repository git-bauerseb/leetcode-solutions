#include <iostream>
#include <vector>
#include <cmath>

class Solution {
    public:
        int minPathSum(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            int c[m][n];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0) {
                        c[i][j] = grid[i][j];
                    } else if (j == 0) {
                        c[i][j] = c[i-1][j] + grid[i][j];
                    } else if (i == 0) {
                        c[i][j] = c[i][j-1] + grid[i][j];
                    } else {
                        c[i][j] = std::min(c[i-1][j], c[i][j-1]) + grid[i][j];
                    }
                }
            }


            return c[m-1][n-1];
        }
};

int main(int argc, char** argv) {

    std::vector<std::vector<int>> grid {};
    grid.push_back({1,3,1});
    grid.push_back({1,5,1});
    grid.push_back({4,2,1});

    Solution solution{};

    int res = solution.minPathSum(grid);

    std::cout << res << "\n";

    return 0;
}