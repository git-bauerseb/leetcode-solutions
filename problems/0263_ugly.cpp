#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isUgly(int n) {
            if (n <= 0) {return false;}

            while (n % 30 == 0) {
                n /= 30;
            }

            while (!(n & 1)) {
                n >>= 1;
            }

            while (n % 3 == 0) {
                n /= 3;
            }

            while (n % 5 == 0) {
                n /= 5;
            }

            return n == 1;
        }
};