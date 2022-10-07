#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        int a = 0;
        int b = 1;
        int tmp = 0;

        for (int i = 1; i <= n; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }


        return b;
    }
};

int main(int argc, char** argv) {


    Solution solution{};
    int steps = solution.climbStairs(3);

    cout << steps << "\n";

    return 0;
}