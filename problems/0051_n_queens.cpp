#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        if (n == 1) {
            return {{"Q"}};
        }

        vector<pair<int, int>> queens;
        vector<bool> cols(n, false);
        vector<bool> diag1(n*n-1, false);
        vector<bool> diag2(n*n-1, false);

        vector<vector<string>> boards;
        n_queens(queens, cols, diag1, diag2, n, 0, boards);
        return boards;
    }

private:
    void n_queens(vector<pair<int,int>>& queens,
                vector<bool>& cols,
                vector<bool>& diag1,
                vector<bool>& diag2,
                int n, int y, vector<vector<string>>& positions) {
        if (y == n) {
            vector<string> board{};
            for(auto& q : queens) {
                string s(n, '.');
                s[q.first] = 'Q';
                board.push_back(s);
            }
            positions.push_back(board);
        } else {
            for (int x = 0; x < n; x++) {
                if (cols[x] || diag1[x+y] || diag2[x-y+n-1]) {continue;}
                cols[x] = diag1[x+y] = diag2[x-y+n-1] = true;
                queens.push_back({x,y});
                n_queens(queens, cols, diag1, diag2, n, y+1, positions);
                queens.pop_back();
                cols[x] = diag1[x+y] = diag2[x-y+n-1] = false;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution solution{};
    auto res = solution.solveNQueens(1);

    cout << res.size() << "\n";
    return 0;
}