#include <iostream>

#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.size() != 1) {
            
            int k = -1;
            
            for (int i = nums.size() - 2; i >= 0; i--) {
                if (nums[i+1] > nums[i]) {
                   k = i;
                   break;
                }
            }

            // Permutation is largest
            if (k == -1) {
                std::sort(nums.begin(), nums.end());
                return;
            }

            int l = -1;

            for (int i = nums.size() - 1; i > k; i--) {
                if (nums[k] < nums[i]) {
                    l = i;
                    break;
                }
            }

            int tmp = nums[k];
            nums[k] = nums[l];
            nums[l] = tmp;

            std::reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

int main(int argc, char** argv) {

    std::vector<std::vector<int>> cases{};
    // cases.push_back({1,2,3});
    // cases.push_back({3,2,1});
    // cases.push_back({1,1,5});
    cases.push_back({1,3,2});

    Solution solution{};

    for (int i = 0; i < 24; i++) {
        solution.nextPermutation(cases[0]);

        for(auto& e : cases[0]) {
            std::cout << e << " ";
        }

        std::cout << "\n";
    }

    return 0;
}