#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            const int n = heights.size();

            if (n == 1) {
                return heights[0];
            } else if (n == 2) {
                return max(heights[0], max(heights[1], 2 * min(heights[0], heights[1])));
            }

            vector<int> s1;
            vector<int> s2;

            vector<int> smaller_right(n, -1);
            vector<int> smaller_left(n, -1);

            // Find first smaller right
            for (int i = 0; i < n; i++) {
                int j = n - i - 1;

                while (s1.size() > 0 && heights[s1[s1.size()-1]] >= heights[i]) {
                    int top = s1[s1.size()-1];
                    s1.pop_back();
                    smaller_right[top] = i;
                }

                while (s2.size() > 0 && heights[s2[s2.size()-1]] >= heights[j]) {
                    int top = s2[s2.size()-1];
                    s2.pop_back();
                    smaller_left[top] = j;
                }

                s1.push_back(i);
                s2.push_back(j);
            }

            int max_ = 0;

            for (int i = 0; i < n; i++) {

                int l = smaller_left[i];
                int r = smaller_right[i];

                if (l >= 0 && r >= 0) {
                    max_ = max(max_, heights[i] * (r - l));
                } else {
                    max_ = max(max_, max(heights[i], heights[i] * abs(i - max(l, r))));
                }
            }
          

            return max_;
        }
};

int main() {

    vector<int> nums{2,1,5,6,2,3,3,3,2,5};

    Solution solution{};
    int sol = solution.largestRectangleArea(nums);
    cout << sol << "\n";
    return 0;
}