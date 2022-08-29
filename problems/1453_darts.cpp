#include <iostream>

#include <cmath>
#include <vector>

class Solution {
    public:
        int numPoints(std::vector<std::vector<int>>& darts, int r) {

            int max = 0;

            for (int i = 0; i < darts.size(); i++) {
                for (int j = i+1; j < darts.size(); j++) {
                    float centerX, centerY;

                    center(&centerX, &centerY, darts[i][0], darts[i][1], darts[j][0], darts[j][1]);

                    max = std::max(max, numInside(darts, r, i, j, centerX, centerY));
                }
            }

            return max;
        }

    private:

        int numInside(std::vector<std::vector<int>>& darts, int r, int i, int j, float x, float y) {
            int num = 0;
            for (int k = 0; k < darts.size(); k++) {

                float dist = (darts[k][0] - x) * (darts[k][0] - x) + (darts[k][1] - y) * (darts[k][1] - y);
                if (dist <= r * r) {
                    num++;
                }
            }

            return num;
        }

        void center(float* x, float* y, int x1, int y1, int x2, int y2) {
            *x = ((float)x1 - (float)x2) / 2;
            *y = ((float)y1 - (float)y2) / 2;
        }
};

int main(int argc, char** argv) {

    std::vector<std::vector<int>> points;
    points.push_back({-3,0});
    points.push_back({3,0});
    points.push_back({2,6});
    points.push_back({5,4});
    points.push_back({0,9});
    points.push_back({7,8});

    Solution solution{};
    int max_num = solution.numPoints(points, 5);

    std::cout << max_num << "\n";

    return 0;
}