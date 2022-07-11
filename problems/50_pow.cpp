#include <iostream>
#include <vector>
#include <utility>

#include <cmath>

class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) {return 1;}
            if (x == 1.0) {return x;}
            if (x == -1.0) {return n % 2 == 0 ? 1.0 : x;}

            double res = 1.0;

            int sign = (n >> 31 & 1) ? -1 : 1;
            n = std::abs(n);

            while (n > 0) {
                if (n & 1) {
                    res *= x;
                }
                x *= x;
                n >>= 1;
            }

            return sign == -1 ? 1.0 / res : res;
        }
};

int main(int argc, char** argv) {

    
    std::vector<std::pair<double,int>> cases{};
    cases.push_back({2.0, -2});
    cases.push_back({-2, -3});
    cases.push_back({2.10000, 3});
    cases.push_back({2, 10});
    cases.push_back({0.44528, 0});
    cases.push_back({1, 2147483647});
 

    Solution solution{};

    for (auto& case_ : cases) {
        double res = solution.myPow(case_.first, case_.second);
        std::cout << res << "\n";
    }

    return 0;
}