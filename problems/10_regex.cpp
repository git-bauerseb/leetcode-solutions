#include <iostream>

#include <map>
#include <string>

#define MAX_LEN 20 + 30

class Solution {
    public:
        bool isMatch(std::string s, std::string p) {
            return isMatchRecursive(s,p,0,0);
        }


    private:
        std::map<int, bool> cache;

        bool isMatchRecursive(std::string s, std::string p, int i, int j) {
            if (cache.find(MAX_LEN * j + i) != cache.end()) {
                return cache[MAX_LEN * j + i];
            }

            if (j >= s.length() && i >= p.length()) {
                cache[MAX_LEN * j + i] = true;
                return true;
            } else if (i >= p.length()) {
                cache[MAX_LEN * j + i] = false;
                return false;
            }

            bool current_match = false;
            
            if (j < s.length()) {
                current_match = s[j] == p[i] || p[i] == '.';
            }

            // '*' case
            if (i < p.size() - 1 && p[i+1] == '*') {
                cache[MAX_LEN * j + i] = isMatchRecursive(s, p, i + 2, j) ||    // No expansion of '*'
                    (current_match && isMatchRecursive(s, p, i, j + 1));        // Expansion of '*'
                return cache[MAX_LEN * j + i];
            } else {
                cache[MAX_LEN * j + i] = current_match && isMatchRecursive(s, p, i + 1, j + 1);
                return cache[MAX_LEN * j + i];
            }

            cache[MAX_LEN * j + i] = false;
            return false;
        }
};

int main(int argc, char** argv) {


    Solution solution{};
    bool matched = solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c");

    std::cout << matched << "\n";

    return 0;
}

