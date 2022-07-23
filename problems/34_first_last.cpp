#include <iostream>

#include <cmath>
#include <vector>

class Solution {
    public:
        std::vector<int> searchRange(std::vector<int>& nums, int target) {
            if (nums.size() == 0) {
                return {-1, -1};
            } else if (nums.size() == 1) {
                if (target == nums[0]) {
                    return {0,0};
                } else {
                    return {-1, -1};
                }
            }

            return {binary_search_leftmost(&nums[0], nums.size(), target),
                    binary_search_rightmost(&nums[0], nums.size(), target)};
        }

    private:

        int binary_search_rightmost(int* begin, int n, int target) {
            int l = 0;
            int r = n;

            while (l < r) {
                int m = std::floor((l + r) / 2.0);

                if (begin[m] > target) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }

            if (begin[r-1] == target) {
                return r-1;
            }

            return -1;
        }

        int binary_search_leftmost(int* begin, int n, int target) {
            int l = 0;
            int r = n;

            while (l < r) {
                int m = std::floor((l + r) / 2.0);

                if (begin[m] < target) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            if (begin[l] == target) {
                return l;
            }

            return -1;
        }
};

int main(int argc, char** argv) {

    std::vector<int> case_{6,6};

    Solution solution{};


    std::vector<int> res = solution.searchRange(case_, 6);
    std::cout << res[0] << " " << res[1] << "\n";
    return 0;
}