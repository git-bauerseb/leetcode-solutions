#include <iostream>
#include <vector>
#include <cmath>

class Solution {
    public:
        int minimumTotal(std::vector<std::vector<int>>& triangle) {
            
            int m = triangle.size();

            int c[m][m];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j <= i; j++) {
                    if (i == 0 && j == 0) {
                        c[i][j] = triangle[i][j];
                    } else if (j == 0) {
                        c[i][j] = c[i-1][j] + triangle[i][j];
                    } else if (j == i) {
                        c[i][j] = c[i-1][j-1] + triangle[i][j];
                    } else {
                        c[i][j] = std::min(c[i-1][j-1], c[i-1][j]) + triangle[i][j];
                    }
                }
            }

            // Return minimum of last line
            int min = 1 << 19;

            for (int i = 0; i < m; i++) {
                if (c[m-1][i] < min) {
                    min = c[m-1][i];
                }
            }

            return min;
        }
};


int main(int argc, char** argv) {

    std::vector<std::vector<int>> triangle{};
    // triangle.push_back({2});
    // triangle.push_back({3,4});
    // triangle.push_back({6,5,7});
    // triangle.push_back({4,1,8,3});
    triangle.push_back({-11});

    Solution solution{};

    int minPath = solution.minimumTotal(triangle);

    std::cout << minPath << "\n";

    return 0;
}