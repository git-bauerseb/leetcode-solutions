#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isNumber(string s) {
            const int n = s.length();

            int idx = 0;

            // Parse decimal number or integer
            if (parseDecimal(s,idx)) {
                if (idx < s.length() && (s[idx] == 'e' || s[idx] == 'E')) {
                    idx++;
                    return parseInteger(s, idx) && (idx == n);
                }

                if (idx == n) {
                    return true;
                }
            } 

            idx = 0;
            if (parseInteger(s,idx)) {
               if (idx < s.length() && (s[idx] == 'e' || s[idx] == 'E')) {
                    idx++;
                    return parseInteger(s, idx) && (idx == n);
                }

                if (idx == n) {
                    return true;
                }
            }
            

            return false;
        }


    private:
        bool parseDecimal(string& s, int& idx) {
            if (s[idx] == '-' || s[idx] == '+' || s[idx] == '.' || isDigit(s[idx])) {
                if (idx < s.length() && s[idx] == '.') {
                    idx++;
                    return parseInteger(s, idx);
                }

                if (!parseInteger(s, idx)) {return false;}

                if (idx < s.length() && s[idx] == '.') {idx++; return parseInteger(s,idx) || true;}

                return true;
            }

            return false;
        }

        bool parseInteger(string& s, int& idx) {
            if (idx < s.length()) {
                    if (s[idx] == '-' || s[idx] == '+' || isDigit(s[idx])) {
                        bool found_digit = isDigit(s[idx]);
                        idx++;
                        while (idx < s.length() && isDigit(s[idx])) {found_digit = true; idx++;}
                        return found_digit;
                    }
                }

            return false;
        }

        bool isDigit(char c) {
            return c >= '0' && c <= '9';
        }
};

int main() {

    vector<string> ss {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};

    Solution solution{};

    for (auto& s : ss) {
        bool isNum = solution.isNumber(s);
        cout << isNum << "\n";
    }
    return 0;
}