#include <iostream>
#include <vector>

#include <string>

class Solution {
    public:
        int minPartitions(std::string n) {

            int len = n.size();

            if (len == 1) {
                return n[0] - '0';
            }

            int num = 0;

            while (n[0] > '0') {
                for (int i = 0; i < len; i++) {
                    if (n[i] != '0') {
                        n[i] = n[i] - 1;
                    }

                }

                num++;
            }

            std::string sub = n.substr(1, len);

            return num + minPartitions(sub);
        }
};

int main(int argc, char** argv) {

    std::vector<std::string> cases {};
    cases.push_back("32");
    cases.push_back("82734");
    cases.push_back("27346209830709182346");
    cases.push_back("10000000000010101010");
    cases.push_back("3232222223222223233223333233332223333333233222223332332323223232322223323332322232332223333232332232322233232223332332232322322232323323332232333223223322323223322323332223332333222323223222233322222222333223332223333333223223222222232322233322332233322322222223332333233322333223323222323323323223223233322223333222232333223233323232333322332332323233222322322323233222222322232222323332232333333222232333223323223323333222233323332333323332323232333332222323232333232333233232223322323232333322322323322222232232232232333322333322332332322323322332323223233333");
    Solution solution {};

    for (auto& c : cases) {
        int n = solution.minPartitions(c);
        std::cout << c << ": " << n << "\n";
    }

    return 0;
}