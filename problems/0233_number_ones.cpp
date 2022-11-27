#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countDigitOne(int n) {

            if (lookup.count(n) > 0) {return lookup[n];}

            int orig = n;

            // Base case
            if (n < 10) {
                return n > 0 ? 1 : 0;
            }

            int l = decLog(n);
            int hP = pows[l];

            int rem = n % hP;
            int ones = ((n / hP) == 1 ? n - hP + 1 : 0) + countDigitOne(rem);

            n = n - (rem + 1);
            rem = n % hP;
            while (n > hP) {
                int fDigit = n / hP;
                if (fDigit == 1) {
                    ones += n - hP + 1;
                }

                ones += countDigitOne(rem);
                n -= hP;
            }

            lookup[orig] = ones + countDigitOne(n);
            return lookup[orig];
        }

    private:
        int decLog(int n) {
            int l = 0;
            while (n >= 10) {
                l++;
                n /= 10;
            }

            return l;
        }

        vector<int> pows{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        map<int,int> lookup;
};

int main() {
    Solution solution{};
    int ones = solution.countDigitOne(999999999);
    cout << ones << "\n";
    return 0;
}