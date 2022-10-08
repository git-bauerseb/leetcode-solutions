#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 1) {
            return strs[0];
        }
        bool eq = strs[0].size() == strs[1].size();
        int commonIdx = binary_search(strs[0], strs[1]) + (eq ? 0 : 1);

        for (int i = 2; i < strs.size(); i++) {

            bool eq = strs[0].size() == strs[i].size();
            int binIdx = binary_search(strs[0], strs[i]);
            commonIdx = min(
                commonIdx,
                binIdx + (eq ? 0 : 1)
            );
        }

        return strs[0].substr(0, commonIdx);
    }

private:
    int binary_search(const string& a, const string& b) {
        if (a.size() == 0 || b.size() == 0) {return 0;}
        int l = 0;
        int r = min(a.size()-1, b.size()-1);

        while (l < r) {
            int m = l + (r - l) / 2;

            if (a[m] == b[m]) {
                l = m+1;
            } else {
                r = m;
            }
        }

        return l;
    }
};

int main(int argc, char** argv) {
    vector<string> strs {"reflower", "flow", "flight"};

    Solution solution{};
    string pref = solution.longestCommonPrefix(strs);

    cout << pref << "\n";
    

    return 0;
}