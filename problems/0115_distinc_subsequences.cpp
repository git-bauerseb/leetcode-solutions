#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int numDistinct(string s, string t) {

            int n = s.size();
            int m = t.size();

            m_s = s;
            m_t = t;

            return recursiveCount(0, 0, n, m);
        }

    private:
        int recursiveCount(int sIdx, int tIdx, int n, int m) {
            if (sIdx > n) {return 0;}
            else if (tIdx == m) { return 1;}

            char current = m_t[tIdx];
            int count = 0;

            for (int i = sIdx; i < n; i++) {
                if (m_s[i] == current) {
                    count += recursiveCount(i+1, tIdx+1, n,m);
                }
            }

            return count;
        }

        string m_s;
        string m_t;
};

int main() {

    /*
        babgbag

        b  2*a 2 *g -> 2 * 1 + 1 = 3
         b 1*a 2*g -> 1 * 1 = 1 
         b 1*a 1*g -> 1 * 1 = 1
    */


    Solution solution{};
    int count = solution.numDistinct("babgbag", "bag");
    cout << count << "\n";

    return 0;
}