#include <iostream>
#include <vector>

#include <string>

class Solution {
    const int VALUES[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    const char* REPR[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    public:
        std::string intToRoman(int num) {
            char output[24];

            int idx = 0;

            while (num > 0) {
                for (int i = 12; i >= 0; i--) {
                    if (num >= VALUES[i]) {

                        if (i % 2 == 1) {
                            output[idx++] = REPR[i][0];
                            output[idx++] = REPR[i][1];
                        } else {
                            output[idx++] = REPR[i][0];
                        }

                        num -= VALUES[i];
                        break;
                    }
                }
            }

            output[idx] = '\0';
            std::string ret(output);

            return ret;
        }
};

int main(int argc, char** argv) {

    std::vector<int> testVec{};
    testVec.push_back(20);

    Solution solution{};

    for (auto& c : testVec) {
        std::string roman = solution.intToRoman(c);
        std::cout << roman << "\n";
    }

    return 0;
}