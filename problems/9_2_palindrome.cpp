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

            char buffer[len];

            for (int i = 0; i < len; i++) {
                buffer[i] = (x % 10) + '0';
                x /= 10;
            }

            // Check
            for (int i = 0; i < len / 2; i++) {
                if (buffer[i] != buffer[len - i - 1]) {
                    return false;
                }
            }


            return true;
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