#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> result{};

            if (nums.size() < 3) {
                return result;
            }

            for (int i = 0; i < nums.size() - 2; i++) {
                int a = nums[i];

                
                int lower = i + 1;
                int upper = nums.size() - 1;

                while (lower < upper) {
                    int b = nums[lower];
                    int c = nums[upper];

                    int sum = a + b + c;

                    if (sum == 0) {

                        bool found = false;

                        for (auto& t: result) {
                            if (t[0] == a && t[1] == b && t[2] == c) {
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            std::vector<int> triple {a,b,c};
                            result.push_back(triple);
                        }
                        
                        lower++;
                    } else if (sum < 0) {
                        lower++;
                    } else {
                        upper--;
                    }
                }
            }

            return result;
       }
};

int main(int argc, char** argv) {

    Solution solution{};
    std::vector<int> nums{-2,0,1,1,2};
    std::vector<std::vector<int>> triples = solution.threeSum(nums); 

    for(auto& vec : triples) {
        std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";
    }

    return 0;
}