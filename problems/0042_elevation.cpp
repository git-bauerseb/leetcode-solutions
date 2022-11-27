#include <iostream>
#include <vector>
#include <cmath>

class Solution {
    public:
        int trap(std::vector<int>& height) {

            int totalVol = 0;
            
            for (int i = 0; i < height.size() - 1;) {

                if (i == 0 && height[i] == 0) {
                    i++;
                    continue;
                }

                if (i == height.size()-1 && height[height.size() - 1] == 0) {
                    i++;
                    continue;
                }

                // Skip adjacent blocks that are greater or the same size because no water can be
                // trapped there
                while (height[i+1] >= height[i]) {i++;}

                // Find next bigger block  
                int j = i + 1;

                int carvedOut = 0;

                while (j < height.size() && height[j] < height[i]) {
                    carvedOut += height[j];
                    j++;
                }

                // If we found no block of equal or greater size, skip it
                if (j == height.size()) {
                    i++;
                    continue;
                }

                totalVol += (j - i - 1) * std::min(height[i], height[j]) - carvedOut;
                i = j;
            }

            return totalVol;
        }
};

int main(int argc, char** argv) {

    std::vector<int> height{4,2,3};
    Solution solution{};

    int waterBlocks = solution.trap(height);

    std::cout << waterBlocks << "\n";

    return 0;
}