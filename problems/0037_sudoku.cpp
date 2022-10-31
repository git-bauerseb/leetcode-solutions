#include <iostream>

#include <vector>

class Solution {
    public:
        void solveSudoku(std::vector<std::vector<char>>& board) {
            solveBacktrack(board);
        }

        bool solveBacktrack(std::vector<std::vector<char>>& board) {
            int next_x = 0;
            int next_y = 0;
            nextPosition(board, next_x, next_y);

            // No position available
            if (next_x == -1 && next_y == -1) {
                return isValid(board);
            } else {
                for (int i = 0; i < 9; i++) {
                    char num = (i + 1) + '0';
                    board[next_x][next_y] = num;

                    if (isValid(board)) {
                        if (solveBacktrack(board)) {
                            return true;
                        }
                    }

                    board[next_x][next_y] = '.';
                }

                return false;
            }
        }

    private:

        void nextPosition(std::vector<std::vector<char>> board, int& x, int & y) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            x = -1;
            y = -1;
        }

        bool checkNums(char* nums) {
            int occ[10];

            for (int i = 0; i < 9; i++) {occ[i] = 0;}

            for (int i = 0; i < 9; i++) {
                char c = nums[i];
                if (c == '.') {
                    continue;
                }

                int idx = (c - '1');

                if (occ[idx] > 0) {
                    return false;
                }

                occ[idx] += 1;
            }

            return true;
        }

        bool isValid(std::vector<std::vector<char>>& board) {
            // Check each row
            for (auto& row : board) {
                if (!checkNums(&row[0])) {
                    return false;
                }
            }

            char c[9];

            // Check each column
            for (int i = 0; i < 9; i++) {
                c[0] = board[0][i];
                c[1] = board[1][i];
                c[2] = board[2][i];
                c[3] = board[3][i];
                c[4] = board[4][i];
                c[5] = board[5][i];
                c[6] = board[6][i];
                c[7] = board[7][i];
                c[8] = board[8][i];

                if (!checkNums(c)) {
                    return false;
                }
            }

            // Check boxes
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    c[0] = board[3*i][3*j];
                    c[1] = board[3*i][3*j+1];
                    c[2] = board[3*i][3*j+2];
                    c[3] = board[3*i+1][3*j];
                    c[4] = board[3*i+1][3*j+1];
                    c[5] = board[3*i+1][3*j+2];
                    c[6] = board[3*i+2][3*j];
                    c[7] = board[3*i+2][3*j+1];
                    c[8] = board[3*i+2][3*j+2];

                    if (!checkNums(c)) {
                        return false;
                    }
                }
            }

            return true;
        }
};


int main(int argc, char** argv) {

    /*
    std::vector<std::vector<char>> case_{};
    case_.push_back({'5', '3', '.', '.', '7', '.', '.', '.', '.'});
    case_.push_back({'6', '.', '.', '1', '9', '5', '.', '.', '.'});
    case_.push_back({'.', '9', '8', '.', '.', '.', '.', '6', '.'});
    case_.push_back({'8', '.', '.', '.', '6', '.', '.', '.', '3'});
    case_.push_back({'4', '.', '.', '8', '.', '3', '.', '.', '1'});
    case_.push_back({'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    case_.push_back({'.', '6', '.', '.', '.', '.', '2', '8', '.'});
    case_.push_back({'.', '.', '.', '4', '1', '9', '.', '.', '5'});
    case_.push_back({'.', '.', '.', '.', '8', '.', '.', '7', '9'});
    */

    std::vector<std::vector<char>> case_{};

    for (int i = 0; i < 9; i++) {
        case_.push_back({});
        for (int j = 0; j < 9; j++) {
            char c;
            std::cin >> c;

            case_[i].push_back(c);
        }
    }

    Solution solution{};
    solution.solveSudoku(case_);

    for (auto& row : case_) {
        for (auto& c : row) {
            std::cout << c << " ";
        }

        std::cout << "\n";
    }
}

/*
.84.3.......6.9..1..3........91..7........4.5.61..4........3.847..2...9.8........
9 8 4 5 3 1 6 7 2 
2 5 7 6 4 9 8 3 1 
6 1 3 8 2 7 5 4 9 
4 2 9 1 8 5 7 6 3 
3 7 8 9 6 2 4 1 5 
5 6 1 3 7 4 9 2 8 
1 9 6 7 5 3 2 8 4 
7 4 5 2 1 8 3 9 6 
8 3 2 4 9 6 1 5 7 
*/