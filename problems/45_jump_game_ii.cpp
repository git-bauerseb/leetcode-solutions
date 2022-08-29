#include <iostream>

#include <vector>

class Solution {
    public:
        int jump(std::vector<int>& nums) {
            int jumps = 0;

            if (nums.size() == 1) {
                return 0;
            }

            for (int i = 0; i < nums.size();) {

                int maxJump = nums[i];
                int maxJumpIdx = i;

                if (nums[i] >= nums.size() - i - 1) {
                    return jumps + 1;
                }

                for (int j = i + 1; j < nums.size() && j < i + nums[i] + 1; j++) {
                    if (j + nums[j] > maxJumpIdx + maxJump) {
                        maxJumpIdx = j;
                        maxJump = nums[j];
                    }
                }

                if (maxJumpIdx == i) {
                    i += nums[i];
                    jumps++;
                    continue;
                }

                jumps++;
                i = maxJumpIdx;
            }

            return jumps;
        }
};

int main(int argc, char** argv) {

    std::vector<int> case_{5,1,6,1,1,1,1,1};
    Solution solution{};

    int min_jumps = solution.jump(case_);
    std::cout << min_jumps << "\n";

    return 0;
}