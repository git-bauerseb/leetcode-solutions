#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            m_grid = grid;
            m_grid_height = grid.size();
            m_grid_width = grid[0].size();

            get_starting_position();

            /*
            cout << "Start X " << m_start_position.first << "; Start Y " << m_start_position.second << "\n";
            cout << "End X " << m_end_position.first << "; End Y " << m_end_position.second << "\n";
            cout << "Num obstacles " << num_obstacles << "\n";
            */


            to_visit = m_grid_height * m_grid_width - 1 - num_obstacles;

            m_num_paths = 0;


            vector<vector<bool>> visited(m_grid_height, vector<bool>(m_grid_width, false));
            visited[m_start_position.second][m_start_position.first] = true;
            backtrack(visited, m_start_position.first, m_start_position.second, 0);
        
            return m_num_paths;
        }


    private:

        void backtrack(vector<vector<bool>>& visited, int posX, int posY, int n_visited) {
            
            if (m_grid[posY][posX] == 2) {
                if (n_visited == to_visit) {
                    m_num_paths++;
                }
                return;
            }

            if (m_grid[posY][posX] == -1) {
                return;
            }

            for (auto& d : directions) {
                int nextX = posX + d.first;
                int nextY = posY + d.second;

                if (coords_in_grid(nextX, nextY) && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    backtrack(visited, nextX, nextY, n_visited+1);
                    visited[nextY][nextX] = false;
                }
            }
        }

        void get_starting_position() {
            for (int y = 0; y < m_grid_height; y++) {
                for (int x = 0; x < m_grid_width; x++) {
                    if (m_grid[y][x] == 1) {
                        m_start_position.first = x;
                        m_start_position.second = y;
                    } else if (m_grid[y][x] == 2) {
                        m_end_position.first = x;
                        m_end_position.second = y;
                    } else if (m_grid[y][x] == -1) {
                        num_obstacles++;
                    }
                }
            }
        }

        bool coords_in_grid(int x, int y) {
            return 0 <= x && x < m_grid_width
                && 0 <= y && y < m_grid_height;
        }


        pair<int,int> m_start_position;
        pair<int,int> m_end_position;

        int num_obstacles;

        int m_num_paths;
        int m_grid_height;
        int m_grid_width;

        int to_visit;

        vector<vector<int>> m_grid;
        vector<pair<int,int>> directions = {
            {1,0},   // Right
            {-1,0},  // Left
            {0,1},   // Up
            {0,-1}   // Down
        };

};

int main() {

    vector<vector<int>> grid;
    grid.push_back({1,0,0,0});
    grid.push_back({0,0,0,0});
    grid.push_back({0,0,0,2});

    Solution solution{};
    int paths = solution.uniquePathsIII(grid);
    cout << paths << "\n";
    return 0;
}