#include <iostream>

#include <string>

class Solution {
    public:
        int longestValidParentheses(std::string s) {
            int open = 0;
            int closed = 0;
            
        }
};

int main(int argc, char** argv) {


    Solution solution{};

    int max_length = solution.longestValidParentheses(")()())");
    std::cout << max_length << "\n";

    return 0;
}