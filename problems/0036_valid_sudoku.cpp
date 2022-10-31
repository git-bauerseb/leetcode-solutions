#include <iostream>

#include <vector>

class Solution {
    public:
        bool isValidSudoku(std::vector<std::vector<char>>& board) {
            return isValid(board);
        }

    private:

        bool checkNums(char* nums) {
            int occ[9] = {0,0,0,0,0,0,0,0,0};

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

    Solution solution{};

    bool valid = solution.isValidSudoku(case_);

    std::cout << valid << "\n";

    return 0;
}