#include <iostream>
#include <string>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            int n = s.size();
            bool c[n][n];

            
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j <= i; j++) {
                    int k = i - j;
                    int i2 = n -j - 1;

                    if (k == i2) {
                        c[k][i2] = true;
                    } else if (i2 - k == 1) {
                        c[k][i2] = (s[k] == s[i2]);
                    } else if (k < (n-1) && i2 > 0) {
                        c[k][i2] =  c[k+1][i2-1] && s[k] == s[i2];
                    }
                }
            }
            
            // Find longest palindrome
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    int k = i - j;
                    int i2 = n -j - 1;
                    if (c[k][i2]) {
                        return s.substr(k, i2-k+1);
                    }
                }
            }

        return std::string{};
    }
};

int main(int argc, char** argv) {

    std::string input{"chelcoocleha"};
    Solution solution{};

    std::string longest = solution.longestPalindrome(input);
    std::cout << longest << "\n";

    return 0;
}