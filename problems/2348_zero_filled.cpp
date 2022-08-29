#include <iostream>

#include <vector>

class Solution {
    public:
        long long zeroFilledSubarray(std::vector<int>& nums) {
            
            // Pair of indices (start, end) of subarray containing only 0's
            std::vector<std::pair<int, int>> sub{};

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    int s = i;
                    int e = s + 1;

                    while (e < nums.size() && nums[e] == 0) {e++;}

                    sub.push_back({s, e});

                    i = e - 1;
                }
            }

            long long num_subs = 0;

            for(auto& p : sub) {
                long long k = p.second - p.first;
                num_subs += (k * (k + 1) / 2);
            }

            return num_subs;
        }
};

int main(int argc, char** argv) {

    std::vector<int> test_case{1,3,0,0,2,0,0,4};

    Solution solution{};
    long long num = solution.zeroFilledSubarray(test_case);

    std::cout << num << "\n";

    return 0;
}