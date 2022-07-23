#include <iostream>

#include <algorithm>
#include <vector>

class Solution {
    public:
        void rotate(std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            for (int i = n-1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }

            for (int i = 0; i < n; i++) {
                int j = n - 1;
                for (int k = 0; k < (n / 2); k++, j--) {
                    int tmp = matrix[i][k];
                    matrix[i][k] = matrix[i][j];
                    matrix[i][j] = tmp;
                }
            }
        }
};

void print_mat(std::vector<std::vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            std::cout << mat[i][j] << " ";
        }

        std::cout << "\n";
    }
}

int main(int argc, char** argv) {

    std::vector<std::vector<int>> case_{};
    case_.push_back({1,2,3});
    case_.push_back({4,5,6});
    case_.push_back({7,8,9});
    
    Solution solution{};
    print_mat(case_);
    solution.rotate(case_);

    std::cout << "\n";
    print_mat(case_);

    return 0;
}