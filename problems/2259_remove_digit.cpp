#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();

        char highest_following = '0';
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (idx < 0 && number[i] == digit) {
                idx = i;
                if (i < (n-1)) {
                    highest_following = number[i+1];
                }
            } else if (number[i] == digit && i < (n-1) 
                && (highest_following < number[i+1] || highest_following < digit)) {
                    idx = i;
                    highest_following = number[i+1];
            } else if (i == n-1 && number[i] == digit) {
                idx = i;
            }
        }

        char n_number[n];
        n_number[n-1] = '\0';

        int n_idx = 0;
        for (int i = 0; i < n; i++) {
            if (i == idx) {continue;}
            n_number[n_idx++] = number[i];
        }

        string s(n_number);

        return s;
    }
};

int main(int argc, char** argv) {

    vector<pair<string, char>> cases{};
    
    cases.push_back({"934345", '3'});
    cases.push_back({"932345", '3'});
    cases.push_back({"19634975", '9'});
    cases.push_back({"19834975", '9'});
    cases.push_back({"22", '2'});
    cases.push_back({"33435", '3'});
    cases.push_back({"333435", '3'});
    cases.push_back({"133235", '3'});
    cases.push_back({"73197", '7'});
    cases.push_back({"1231", '1'});

    Solution solution{};

    for (auto& c : cases) {
        auto s = solution.removeDigit(c.first, c.second);
        cout << s << "\n";
    }

    return 0;
}