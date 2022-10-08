#include <iostream>
#include <vector>

#include <string>

class Solution {
    public:
        bool isValid(std::string s) {

            char stack[s.length()];
            int idx = 0;

            for (char& c : s) {

                switch (c) {
                    case '(':
                        stack[idx++] = c;
                        break;
                    case ')':
                        if (idx == 0 || stack[idx-1] != '(') {return false;}
                        idx--;
                        break;
                    case '[':
                        stack[idx++] = c;
                        break;
                    case ']':
                        if (idx == 0 || stack[idx-1] != '[') {return false;}
                        idx--;
                        break;
                    case '{':
                        stack[idx++] = c;
                        break;
                    case '}':
                        if (idx == 0 || stack[idx-1] != '{') {return false;}
                        idx--;
                        break;                    
                    default:
                        break;
                }
            }

            return idx == 0;
        }
};

int main(int argc, char** argv) {

    std::vector<std::string> testCases{};
    testCases.push_back("()[]{}");
    testCases.push_back("([)]");
    testCases.push_back("(]");
    testCases.push_back("{[](()[])}");
    testCases.push_back("{{}{}");

    Solution solution{};

    for (auto& c_ : testCases) {
        bool valid = solution.isValid(c_);
        std::cout << valid << "\n";
    }


    return 0;
}