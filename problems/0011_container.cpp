#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

class Solution {
    public:
        int maxArea(std::vector<int>& height) {

            // Edge cases
            if (height.size() == 0 || height.size() == 1) {
                return 0;
            }

            if (height.size() == 2) {
                return std::min(height[0], height[1]);
            }

            int maxVolume = std::numeric_limits<int>::min();

            int i = 0;
            int j = height.size() - 1;

            while(i < j) {

                int h1 = height[i];
                int h2 = height[j];

                int vol = std::min(h1, h2) * (j - i);

                if (vol > maxVolume) {
                    maxVolume = vol;
                }

                if (h1 < h2) {
                    i++;
                } else {
                    j--;
                }

            }        

            return maxVolume;
        }
};

int main(int argc, char** argv) {

    std::vector<int> heights{1,8,6,2,5,4,8,3,7};

    Solution solution{};
    int vol = solution.maxArea(heights);

    std::cout << vol << "\n";

    return 0;
}