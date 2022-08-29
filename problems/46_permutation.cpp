#include <iostream>

#include <map>
#include <vector>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums) {
            std::vector<std::vector<int>> res;
            std::vector<long, 
            permute_helper(res, nums, 0);
            return res;
        }

    private:
        void permute_helper(std::vector<std::vector<int>>& p, std::vector<int>& nums, int start) {

            if (start == nums.size()) {
                std::vector<int> n_nums = nums;
                p.push_back(n_nums);
            } else {
                for (int i = start; i < nums.size(); i++) {
                    std::swap(nums[i], nums[start]);
                    permute_helper(p, nums, start+1);
                    std::swap(nums[i], nums[start]);
                }
            }
        }

        long hash(std::vector<int> nums) {
            
            long hash = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                hash += (nums[i] + 10) << 6;
            }

            return hash;
        }
};

int main(int argc, char** argv) {


    std::vector<int> v{1,2,3,4,5,6};

    Solution solution{};
    auto s = solution.permute(v);

    std::cout << s.size() << "\n";

    for (auto& v : s) {
        for (auto& e : v) {
            std::cout << e << " ";
        }
        std::cout << "\n";
    }


    return 0;
}