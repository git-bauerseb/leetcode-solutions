#include <iostream>
#include <vector>

#include <cmath>


class Solution {
    public:
        int POWERS[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }

            if (x < 10 && x >= 0) {
                return true;
            }


            int len = 0;
            int tmp = x;

            while (tmp > 0) {
                len++;
                tmp /= 10;
            }

            int exp = len - 1;

            for (int i = 0; i < len/2, exp > -1; i++) {

                int first = x / POWERS[exp];
                int last = x % 10;

                if (first != last) {
                    return false;
                }

                x -= first * pow(10, exp);
                x /= 10;

                exp -= 2;
            }

            return true;
        }

    private:
        int pow(int b, int e) {
            int r = 1;

            for (int i = 0; i < e; i++) {
                r *= b;
            }

            return r;
        }
};

int main(int argc, char** argv) {

    std::vector<int> instances{121, 1221, 12321, 12211, 123321, 1234321, 928};

    Solution solution{};

    for (auto& c : instances) {
        bool palin = solution.isPalindrome(c);
        std::cout << "[" << c << "] Palindrom: " << palin << "\n";
    }


    return 0;
}