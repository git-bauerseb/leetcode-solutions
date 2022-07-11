#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::vector<std::string> generateParenthesis(int n) {
            std::vector<std::string> res{};
            generateParenthesisAux(res, "", 0, 0, n);
            return res;
        }

    private:
        void generateParenthesisAux(std::vector<std::string>& result, std::string s, int open, int close, int n) {
            if (open == n && close == n) {
                result.push_back(s);
            }

            if (open < n) {
                generateParenthesisAux(result, s + "(", open+1, close, n);
            }

            if (close < open) {
                generateParenthesisAux(result, s + ")", open, close+1, n);
            }
        }
};


int main(int argc, char** argv) {


    Solution solution{};

    std::vector<std::string> paren = solution.generateParenthesis(5);

    std::cout << "[";

    for (int i = 0; i < paren.size()-1; i++) {
        std::cout << "\"" << paren[i] << "\",";
    }

    std::cout << "\"" << paren[paren.size()-1] << "\"]\n";

    return 0;
}