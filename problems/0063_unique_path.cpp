#include <bits/stdc++.h>

using namespace std;

class Solution {
    
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {


            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();


            if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {return 0;}

            vector<vector<int>> u_paths(m, vector<int>(n, 0));

            // Initialize border
            for (int i = 0; i < m; i++) {
                if (obstacleGrid[i][0] == 1) {
                    u_paths[i][0] = 0;
                    break;
                } else {
                    u_paths[i][0] = 1;
                }
            }
            for (int i = 0; i < n; i++) {
                if (obstacleGrid[0][i] == 1) {
                    u_paths[0][i] = 0;
                    break;
                }
                else {
                    u_paths[0][i] = 1;
                }
            }

            for (int y = 1; y < m; y++) {
                for (int x = 1; x < n; x++) {
                    // If there is an obstacle, no path possible
                    if (obstacleGrid[y][x] == 1) {u_paths[y][x] = 0;}
                    else {
                        u_paths[y][x] = u_paths[y][x-1] + u_paths[y-1][x];
                    }
                }
            }


            return u_paths[m-1][n-1];
        }

};

int main() {

    vector<vector<int>> grid;
    grid.push_back({0,0,0});
    grid.push_back({0,1,0});
    grid.push_back({0,0,0});


    Solution solution{};

    int paths = solution.uniquePathsWithObstacles(grid);
    cout << paths << "\n";

    return 0;
}