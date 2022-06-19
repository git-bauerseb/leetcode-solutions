#include <string>
#include <vector>
#include <map>
#include <iostream>

class Solution {
    public:
        int minDeletions(std::string s) {
            std::map<char, int> occ {};
            std::vector<char> chars {};

            for (auto& c : s) {

                if (occ.count(c) <= 0) {
                    chars.push_back(c);
                }

                occ[c] += 1;
            }

            for (int i = 0; i < chars.size(); i++) {
                for (int j = i + 1; j < chars.size(); j++) {
                    if ()
                }
            }

            int deletions = 0;

        }
};

int main(int argc, char** argv) {
    std::string s{"aaabbbcc"};

    Solution solution{};
    int occurrences = solution.minDeletions(s);

    std::cout << occurrences << "\n";

    return 0;
}