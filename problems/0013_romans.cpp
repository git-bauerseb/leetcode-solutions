#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i = s.length()-1;
        int val = 0;
        while (i >= 0) {
            char c = s[i];

            if (c == 'V' && i > 0 && s[i-1] == 'I') {val += 4; i -= 2; continue;}
            if (c == 'X' && i > 0 && s[i-1] == 'I') {val += 9; i -= 2; continue;}

            if (c == 'L' && i > 0 && s[i-1] == 'X') {val += 40; i -= 2; continue;}
            if (c == 'C' && i > 0 && s[i-1] == 'X') {val += 90; i -= 2; continue;}

            if (c == 'D' && i > 0 && s[i-1] == 'C') {val += 400; i -= 2; continue;}
            if (c == 'M' && i > 0 && s[i-1] == 'C') {val += 900; i -= 2; continue;}

            val += m_literals[c];
            i--;
        }

        return val;
    }

private:
    map<char, int> m_literals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};

int main(int argc, char** argv) {

    Solution solution{};
    int n = solution.romanToInt("LVIII");

    cout << n << "\n";

    return 0;
}