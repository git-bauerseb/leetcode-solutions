#include <iostream>
#include <limits>

class Solution {
public:
    int UPPER = 2147483647;
    int LOWER = -2147483648;

    int reverse(int x) {
        int negative = x < 0 ? -1 : 1;

        if (x == LOWER) {
            return 0;
        }

        x = x < 0 ? -x : x;

        int tmp = x;
        int numDigits = 0;

        while (tmp > 0) {
            tmp /= 10;
            if (tmp > 0) {
                numDigits++;
            }
        }

        int idx = 0;
        int reversed = 0;

        while (numDigits >= 0) {
            int digit = x % 10;

            int expon = 1;
            for (int i = numDigits; i > 0; i--) {expon *= 10;}

            if (expon == 1'000'000'000 && digit >= 3) {
                return 0;
            } 

            // Numerical overflow
            if (UPPER - (digit * expon) <= reversed) {
                return 0;
            }

            reversed += digit * expon;

            idx++;
            numDigits--;
            x /= 10;
        }

        return negative * reversed;
    }
};

int main(int argc, char** argv) {

    Solution solution{};

    // 2'147'483'647
    int reversed = solution.reverse(-2147483412);

    std::cout << reversed << "\n";

    return 0;
}