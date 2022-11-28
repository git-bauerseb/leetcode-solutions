#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
    public:
        int nthUglyNumber(int n) {
            int dp[n];
            dp[0] = 1;
            int c_idx = 0;
            int n_idx = 1;
            while (n_idx < n) {
                for (auto it = factors.begin(); it != factors.end() && n_idx < n; it++) {
                    dp[n_idx++] = dp[c_idx] * (*it);
                }

                c_idx += 17;
            }

            return dp[n-1];
        }

    private:
        vector<int> factors{2,3,4,5,6,8,9,10,12,15,16,18,20,24,25,27,30};
};
*/

class Solution {
    public:
        int nthUglyNumber(int n) {
            long dp[n];
            dp[0] = 1;

            for (int i = 1; i < n; i++) {
                long minMax = (1L << 33);
                for (int j = i-1; j >= 0; j--) {
                    long p2 = dp[j] * 2;
                    long p3 = dp[j] * 3;
                    long p5 = dp[j] * 5;

                    if (p2 > dp[i-1]) {minMax = p2;}
                    if (p3 > dp[i-1]) {minMax = min(minMax, p3);}
                    if (p5 > dp[i-1]) {minMax = min(minMax, p5);}
                }

                dp[i] = minMax;
            }

            return dp[n-1];
        }
};

class Solution {
    public:
        int nthUglyNumber(int num) {
            vector<int> dp(num);
            dp[0] = 1;
            int i2 = 0, i3 = 0, i5 = 0;
            for(int i = 1; i<num; i++){
                dp[i] = min(2*dp[i2], min(3*dp[i3], 5*dp[i5]));
                if(dp[i] == 2*dp[i2]) i2++;
                if(dp[i] == 3*dp[i3]) i3++;
                if(dp[i] == 5*dp[i5]) i5++;
            }
            return dp[num-1];
        }
};

int main() {
    Solution solution{};
    int s = solution.nthUglyNumber(1690);
    cout << s << "\n";
    return 0;
}