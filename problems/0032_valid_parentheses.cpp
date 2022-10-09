#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int longest = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                stack<char> v_par = stack<char>();

                int k = i;
                int c_longest = 0;

                while (k <= j) {
                    if (s[k] == '(') {
                        v_par.push('(');
                    } else if (s[k] == ')') {
                        if (v_par.empty() || v_par.top() == ')') {
                            break;
                        } else {
                            v_par.pop();
                        }
                    }

                    c_longest++;
                    k++;
                }

                if (v_par.empty()) {
                    longest = max(longest, c_longest);
                }
            }
        }

        return longest;
    }
};

class Solution1 {
   public:
    int longestValidParentheses(string s) {
        int n = s.size();

        if (n == 0) {return 0;}

        vector<int> max_par(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i - 2 >= 0) {
                        max_par[i] = max_par[i - 2] + 2;
                    } else {
                        max_par[i] = 2;
                    }
                } else {
                    int prev_idx = i - max_par[i - 1] - 1;
                    if (prev_idx >= 0 && s[prev_idx] == '(') {
                        max_par[i] = max_par[i - 2] + 2;
                    } else if (i-2 >= 0) {
                        max_par[i] = max_par[i - 2];
                    }
                }
            }
        }

        return max_par[n - 1];
    }
};

int main() {


    vector<string> inputs{};
    inputs.push_back("");
    inputs.push_back("())");
    inputs.push_back("()()");
    inputs.push_back(")(())");
    inputs.push_back(")()())");
    inputs.push_back("()(())");

    Solution1 solution{};

    for (auto& i : inputs) {
        int longest = solution.longestValidParentheses(i);

        cout << longest << "\n";
    }

    return 0;
}