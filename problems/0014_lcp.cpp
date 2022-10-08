#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        // Compute longest common prefix of first two strings
        int max_len = 0;

        int i = 0;

        while (i < min(strs[0].size(), strs[1].size()) && strs[0][i] == strs[1][i]) {
            i++;
        }

        max_len = i;

        if (max_len == 0) {
            return "";
        }

        for (int idx = 2; idx < strs.size(); idx++) {
            i = 0;
            while (i < min(strs[0].size(), strs[idx].size()) && i < max_len && strs[0][i] == strs[idx][i]) {
                i++;
            }

            max_len = min(max_len, i);

            if (max_len == 0) {
                return "";
            }
        }

        string s = strs[0].substr(0, max_len);

        return s;
    }
};

int main(int argc, char **argv) {

    vector<string> strings;
    strings.push_back("dog");
    strings.push_back("racecar");
    strings.push_back("car");

    Solution solution{};
    string lcp = solution.longestCommonPrefix(strings);

    cout << lcp << "\n";

    return 0;
}