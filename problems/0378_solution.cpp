#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(n * log(n))
// Space complexity: O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        int less = 0;

        for (; l < r; ) {
            less = 0;
            // Very important here
            // NOT m = (l + h) / 2
            int m = l + (r - l) / 2;

            for (int i = 0, j = n - 1; i < n; i++) {
                if (matrix[i][n-1] < m) {
                    less += n;
                } else {
                    while (j >= 0 && matrix[i][j] > m) {
                        j--;
                    }
                    
                    less += (j+1);
                }
            }

            if (less < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
};

int main() {

    /*
        vector<vector<int>> matrix;
        matrix.push_back({-5, -4});
        matrix.push_back({-5, -4});
        

        Solution solution{};

        int s = solution.kthSmallest(matrix, 2);
        cout << s << "\n";
    */

    int l = -5;
    int r = -4;

    cout << (l + r) / 2 << "\n";
    cout << l + (r-l) / 2 << "\n";

    return 0;
}