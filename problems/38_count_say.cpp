#include <iostream>

#include <vector>
#include <string>

class Solution {
    public:
        std::string countAndSay(int n) {

            std::string s{'1'};



            for (int i = 1; i < n; i++) {
                int idx = 0;
                std::string n{};
                while (idx < s.length()) {

                    char cur = s[idx++];
                    int occ = 1;
                    while (s[idx] == cur && idx < s.length()) {idx++; occ++;}

                    char first = occ + '0';
                    n.push_back(first);
                    n.push_back(cur);
                }
                s = n;
            }

            return s;
        }
};

int main(int argc, char** argv) {


    Solution solution{};
    std::string sol = solution.countAndSay(2);

    std::cout << sol << "\n";

    return 0;
}