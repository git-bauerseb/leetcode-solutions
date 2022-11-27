#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string removeDuplicateLetters(string s) {
            const int n = s.length();
            vector<char> stack;
            string o;

            for (int i = 0; i < n; i++) {
                while (stack.size() > 0 
                    && s[stack[stack.size()-1]] >= s[i]) {
                    int t = stack[stack.size()-1];
                    stack.pop_back();
                }

                stack.push_back(i);
            }

            for (auto& e : stack) {
                o += s[e];
            }

            return o;
        }
};


int main() {
    Solution solution{};
    auto s = solution.removeDuplicateLetters("cbacdcbc");
    cout << s << "\n";
    return 0;
}