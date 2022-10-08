#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

// 1 if positive, 0 if negative
#define SIGN(x) (((x >> 31) & 1) != 1)

#define MAX (2147483647)
#define MIN (-2147483648)

class Solution {

    public:
        int divide(int dividend, int divisor) {

            if (divisor == 1) {return dividend;}
            if (divisor == -1) {return dividend == MIN ? MAX : -dividend;}

            if (divisor == MIN) {
                return dividend == MIN  ? 1 : 0;
            }

            if (dividend == MIN) {
                if (divisor == MIN) {
                    return 1;
                }

                dividend++;
            }


            if (divisor == 1) {return dividend;}
            if (divisor == -1) {return -dividend;}
            if (std::abs(dividend) < std::abs(divisor)) {return 0;}

            int s_dividend = dividend;
            int s_div = divisor;
            
            int temp = 1;
            int qu = 0;

            dividend = std::abs(dividend);
            divisor = std::abs(divisor);

            while (divisor <= dividend) {
                divisor <<= 1;
                temp <<= 1;
            }

            //printf("%d %d\n",de,temp,nu);
            while (temp > 1) {
                divisor >>= 1;
                temp >>= 1;

                if (dividend >= divisor) {
                    dividend -= divisor;
                    qu += temp;
                }
            }

            if ((SIGN(s_dividend) && !SIGN(s_div)) || 
                (!SIGN(s_dividend) && SIGN(s_div))) {
                return -qu;
            } else {
                return qu;
            } 
        }
};

int main(int argc, char** argv) {

    std::vector<std::pair<int,int>> cases{};
    cases.push_back({MAX,2});


    Solution solution{};

    for (auto& p : cases) {
        int div = solution.divide(p.first, p.second);
        std::cout << div << "\n";
    }

    return 0;
}