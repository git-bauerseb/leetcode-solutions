#include <vector>
#include <map>
#include <iostream>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {

            std::vector<int> indices{};
            std::map<int, int> lookup{};

            for (int i = 0; i < nums.size(); i++) {
                if (lookup.count(nums[i])) {
                    indices.push_back(i);
                    indices.push_back(lookup[nums[i]]);
                    break;
                } else {
                    lookup.insert(std::pair<int, int>(target - nums[i], i));
                }
            }

            return indices;
        }
};

int main(int argc, char** argv) {

    Solution s;

    std::vector<int> nums{2,7,11,15};

    std::vector<int> indices = s.twoSum(nums, 9);
    std::cout << indices[0] << ", " << indices[1] << "\n";
    return 0;
}