#include <iostream>

#include <string>

class Solution {
    public:
            std::string multiply(std::string num1, std::string num2) {
                // Reserve
                std::string output(num1.size() + num2.size(), '0');


                for (int i = num2.size() - 1; i >= 0; i--) {
                    int carry = 0;
                    int sum = 0;
                    for (int j = num1.size() - 1; j >= 0; j--) {
                        int val = (carry) + (num1[j] - '0') * (num2[i] - '0') + (output[i + j+1] - '0');
                        carry = val / 10;

                        output[i + j+1] = (val % 10) + '0';

                        sum = i + j;
                    }

                    output[sum] = carry + '0';
                }

                int start = 0;

                while (output[start] == '0') {start++;}

                std::string ret = output.substr(start, num1.size() + num2.size() - start + 1);

               
                return ret.size() == 0 ? "0" : ret;
            }
};

int main(int argc, char** argv) {

    std::string n1{"901293183291283012983019230198320917230919238092138019230198230918230982103918203120398123718246124193221301298301283012"};
    std::string n2{"299298347234927391981729371948179247129478192847129847912831923192471982479128471829487194268716418723198237192738"};

    Solution solution{};
    std::string ret{solution.multiply(n1, n2)};

    std::cout << ret << "\n";

    return 0;
}

/*
269755560133187482256529096724016241850921714972887631961133920507526865402714004893903694760407128477232441208144750542756824084504145583491409141800555182396951016651142241561472921671377625582666148230032518319277154748442529166856
269755560133187482256529096724016241850921714972887631961133920507526865402714004893903694760407128477232441208144750542756824084504145583491409141800555182396951016651142241561472921671377625582666148230032518319277154748442529166856
*/