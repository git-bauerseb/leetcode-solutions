#include <bits/stdc++.h>

using namespace std;

/*
    01111
*/

class Solution {
    public:
        int distributeCookies(vector<int>& cookies, int k) {
            const int n = cookies.size();
            vector<int> amount(k, 0);

            return backtrack(cookies, amount, 0);
        }

    private:
        // Backtracking solution
        int backtrack(vector<int>& cookies, vector<int>& childs, int bitmask) {            
            if (bitmask == (1 << cookies.size()) - 1) {
                // Return unfairness
                int max_ = -1;
                for (auto& c : childs) {max_ = max(c, max_);}
                return max_;
            }

            // Search which bag is still available
            int i = 0;
            while (bitmask != 0
                && (bitmask & (1 << i)) != 0) {
                    i++;
            }

            int min_ = 1 << 29;

            for (auto it = childs.begin(); it != childs.end(); it++) {
                *it += cookies[i];
                int val = backtrack(cookies, childs, bitmask | (1 << i));
                *it -= cookies[i];
                min_ = min(val, min_);
            }
            return min_;
        }
};

int main() {

    vector<int> cookies{1,2,3,4,5,6,7,8};
    Solution solution{};

    /*

    */

    int unf = solution.distributeCookies(cookies, 8);
    cout << unf << "\n";

    return 0;
}