#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            const int o_len = n;
            vector<int> nums;
            for (int i = 1; i <= n; i++) {nums.push_back(i);}

            vector<int> perm;

            while (nums.size() > 1) {
                int c_fac = fac[n-2];
                int digit = 0;

                while (c_fac < k) {
                    digit++;
                    c_fac += fac[n-2];
                }

                k -= (c_fac - fac[n-2]);

                perm.push_back(nums[digit]);
                nums.erase(nums.begin() + digit);
                n--;
            }

            perm.push_back(nums[0]);


            string s;

            for (auto& d : perm) {
                s += d + '0';
            }

            return s;
        } 

        // 1, 2, 3, 4, 5, 6, 7, 8, 9
        vector<int> fac{1,2,6,24,120,720,5040, 40320, 362880, 3628800};
};

int main() {
    Solution solution{};
    for (int i = 1; i <= 20; i++) {
        auto s = solution.getPermutation(9,i);
        cout << s << "\n";
    }
    return 0;
}