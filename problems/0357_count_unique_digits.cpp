#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
            return rec(n, 0) + 10;
        }

    private:
        int rec(int n, int i) {
            // 0 <= x < 10^0 = 1
            if (n == 0) {return 1;}
            // 0 <= x < 10^1 = 10
            if (n == 1) {return 10;}
            return 9 * rec(n-1, i+1) - (9-i);
        }
};

/*
    n = 2 => 10^2 = 100

    9: 98,...............,90        => 9
    8: 89,87,............,80        => 9
    7: 79,...,78m76,.....,70        => 9
    5
    4
    3
    2
    2
    1

    9*9 + 10 = 81 + 10 = 91


    n = 3 => 10^3 = 1000


*/

int main() {

    Solution solution{};
    int c = solution.countNumbersWithUniqueDigits(4);
    cout << c << "\n";
    return 0;
}