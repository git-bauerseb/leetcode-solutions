#include <iostream>
#include <string>
#include <cmath>
#include <limits>

class Solution {

    const int MAX = std::numeric_limits<int>::max();
    const int MIN = std::numeric_limits<int>::min();
    

    public:
        int myAtoi(std::string s) {
            
            if (s.size() == 0) {
                return 0;
            }

            int idx = ignoreChar(s, 0, ' ');

            int sign = 1;

            if (idx < s.size() && s[idx] == '-') {
                sign = -1;
                idx++;
            } else if (idx < s.size() && s[idx] == '+') {
                idx++;
            }

            // Skip leading zeros
            idx = ignoreChar(s, idx, '0');

            // Length of digits
            int len = 0;
            int t_idx = idx;

            while (t_idx < s.size() && isdigit(s[t_idx])) {
                t_idx++;
                len++;
            }

            int num = 0;

            while (idx < t_idx) {

                int base = (pow(10, len-1));

                if (base == MAX) {
                    return sign == -1 ? MIN : MAX;
                }

                if (s[idx] - '0' > 2 && (len-1) >= 9) {
                    return sign == -1 ? MIN : MAX;
                }

                if (sign == 1) { 

                    int toAdd = (s[idx] - '0') * base;

                    if (num > MAX - toAdd) {
                        num = MAX;
                        break;
                    }

                    num += toAdd;
                } else {
                    int toSub = (s[idx] - '0') * base;

                    if (num < MIN + toSub) {
                        num = MIN;
                        break;
                    }

                    num -= toSub;
                }
                idx++;
                len--;
            }

            
            return num;
        }

    private:

        int pow(int b, int e) {
            int res = 1;

            if (e > 9) {
                return MAX;
            }

            for (int i = 0; i < e; i++) {
                res = (res * b) % MAX;
            }

            return res;
        }

        int ignoreChar(std::string s, int idx, char toIgnore) {
            while (idx < s.size() && s[idx] == toIgnore) {
                idx++;
            }

            return idx;
        }
};

int main(int argc, char** argv) {


    Solution solution{};

    int num = solution.myAtoi("   0000000000012345678");

    std::cout << num << "\n";

    return 0;
}