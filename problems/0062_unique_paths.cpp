#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int l = min(m, n);

        return binom(m + n - 2,l-1);
    }

    long binom(int n, int k) {

        long n_n_k_max = max(k, n - k);
        long o = (n_n_k_max == k) ? n - k : k;

        long res = 1;
        long o_res = 1;

        for (int i = n, j = 1; i > n_n_k_max; i--, j++) {
            res = res * i;
            o_res = o_res * j;


            int v_gcd = __gcd(res, o_res);

            res /= v_gcd;
            o_res /= v_gcd;
        }

        return res;
    }
};

int main(int argc, char** argv) {

    Solution solution{};
    int paths = solution.uniquePaths(10,10);

    cout << paths << "\n";

    return 0;
}