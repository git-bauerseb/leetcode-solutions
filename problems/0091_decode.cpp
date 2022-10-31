#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            int n = s.size();
            vector<int> numWays(n+1, 0);

            numWays[0] = 1;
            numWays[1] = s[0] - '0' > 0 ? 1 : 0;

            for (int i = 1; i < n; i++) {
                int oneSub = s[i] - '0';
                int twoSub = twoSub = 10 * (s[i-1] - '0') + (s[i] - '0');

                if (oneSub > 0) {
                    numWays[i+1] += numWays[i];
                }

                if (twoSub > 0 && twoSub <= 26 && s[i-1] != '0') {
                    numWays[i+1] += numWays[i-1];
                }
            }

            return numWays[n];
        }
};

int main() {

    /*
        262626

            26 26 26
            2 6 2 6 26
            2 6 2 6 2 6
            2 6 26 26

            26 2 6 26
            26 2 6 2 6
            26 26 2 6

            26 26 2 6


            2626026

            2 6 2 60 26

    */


    Solution solution{};
    int numWays = solution.numDecodings("000000000020020000");
    cout << numWays << "\n";
    return 0;
}