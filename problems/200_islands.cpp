#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; ) {
                while (x < n && visited[y][x]) {x++;}
                if (x < n && grid[y][x] == '1') {
                    islands++;
                    explore(x, y, m, n, grid, visited);
                }

                x++;
            }
        }

        return islands;
    }

private:

    void explore(int s_x, int s_y, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        
        visited[s_y][s_x] = true;
        queue<pair<int,int>> positions;
        positions.push({s_x,s_y});

        while (positions.size() > 0) {
            pair<int,int> c_pos = positions.front();
            positions.pop();

            // cout << "Visited (" << c_pos.first << "," << c_pos.second << ")\n";

            for (auto& d : directions) {
                int x = c_pos.first + d.first;
                int y = c_pos.second + d.second;

                // Bounds check
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (grid[y][x] == '1' && !visited[y][x]) {
                        visited[y][x] = true;
                        positions.push({x,y});
                    }
                }
            }
        }
    }

    vector<pair<int,int>> directions = {
        {1,0},  // right
        {-1,0}, // left
        {0,-1}, // up
        {0,1}   // down
    };
};

int main(int argc, char** argv) {

    /*
    vector<vector<char>> grid;
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '1', '0', '0'});
    grid.push_back({'0', '0', '0', '1', '1'});
    */

    /*
    vector<vector<char>> grid;
    grid.push_back({'1', '1', '1', '1', '0'});
    grid.push_back({'1', '1', '0', '1', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '0', '1', '1'});
    */

    vector<vector<char>> grid;
    grid.push_back({'1', '1'});

    Solution solution{};
    int num_islands = solution.numIslands(grid);

    cout << num_islands << "\n";

    return 0;
}