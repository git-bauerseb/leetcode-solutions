#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums) {
            
            int fac = 1;

            for (int i = 2; i <= nums.size(); i++) {
                fac *= i;
            }

            int** p = new int*[fac];
            for (int i = 0; i < fac; i++) {
                p[i] = new int[nums.size()];
            }

            permuteAuxiliary(p, nums, 0, 0);


            std::vector<std::vector<int>> perm{};

            for (int i = 0; i < fac; i++) {
                std::vector<int> v{};
                for (int j = 0; j < nums.size(); j++) {
                    v.push_back(p[i][j]);
                }
                perm.push_back(v);
            }

            return perm;
        }

    private:
        void permuteAuxiliary(int** p, std::vector<int>& nums, int n, int j) {

            if (n == nums.size() - 1) {
                p[j][n] = nums[nums.size()-1];
            }

            for (int i = n; i < nums.size(); i++) {
                permuteAuxiliary(p, nums, n+1, i+j);
                p[i][n] = nums[i];
            }
        }
};

int main(int argc, char** argv) {

    std::vector<int> nums {1,2,3};
    Solution solution{};

    std::vector<std::vector<int>> perms = solution.permute(nums);

    for(auto& c : perms) {
        for (auto& e : c) {
            std::cout << e << " ";
        }

        std::cout << "\n";
    }

    return 0;
}