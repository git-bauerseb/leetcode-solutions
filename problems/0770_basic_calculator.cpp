#include <bits/stdc++.h>

using namespace std;

enum Op {
    ADD,
    SUB,
    MUL,
    INT,
    VAR,

    L_PAREN,
    R_PAREN
};

class Token {
    public:
        Token(string name, int value, int type)
            : m_name(name), m_value(value), m_type(type) {}

        Token(int value, int type) : m_value(value), m_type(type) {}

        string m_name;
        int m_value;
        int m_type;
};

class Solution {
    public:
        vector<string> basicCalculatorIV(string expression,
            vector<string>& evalvars, vector<int>& evalints) {
                vector<Token> tokens;
                tokenize(tokens, expression);

            }
};

int main() {

    vector<string> vars;
    vector<int> vals;

    vector<string> expr;
    expr.push_back("1 + 2 * 3");

    Solution solution{};
    auto sol = solution.basicCalculatorIV(expr, vars, vals);

    for (auto& e : sol) cout << e << "\n";
    cout << "\n";

    return 0;
}