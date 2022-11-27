#include <bits/stdc++.h>

using namespace std;

#define ADD_IF_POS(x) (x & (1 << 31) ? 0 : x)

class Solution {
    public:
        int trap(vector<int>& heights) {
            int n = heights.size();
            int trapped = 0;

            vector<int> max_height_right(n, 0);
            vector<int> max_height_left(n, 0);

            max_height_left[0] = heights[0];
            max_height_right[n-1] = heights[n-1];

            // Compute maximum heights for left side
            for (int i = 1; i < n; i++) {
                max_height_left[i] = max(heights[i], max_height_left[i-1]);
                max_height_right[n-i-1] = max(heights[n-i-1], max_height_right[n-i]);
            }
            
            for (int i = 0; i < n; i++) {
                trapped += ADD_IF_POS(
                        min(max_height_right[i], max_height_left[i]) - heights[i]);
            }


            return trapped;
        }
};


int main() {

    vector<int> heights{04,2,0,3,2,5};

    Solution solution{};
    int trap = solution.trap(heights);
    cout << trap << "\n";

    return 0;
}