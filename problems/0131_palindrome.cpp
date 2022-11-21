#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
    public:
        vector<vector<string>> partition(string s) {
            return partRec(s);
        }

    private:
        vector<vector<string>> partRec(string& s) {
            const int n = s.length();
            
            if (n == 1) {
                return {{s}};
            }

            vector<vector<string>> part;

            for (int i = 1; i < n; i++) {
                string left = s.substr(0, i);
                string right = s.substr(i, (n - i));

                auto leftPartition = partRec(left);
                auto rightPartition = partRec(right);


                for (auto& ai : leftPartition) {
                    vector<string> n_part;
                    
                    for (auto& bj : rightPartition) {
                        n_part.insert(n_part.begin(), ai.begin(), ai.end());
                        n_part.insert(n_part.end(), bj.begin(), bj.end());
                    }


                    part.push_back(n_part);
                }

            }

            return part;
        }
};
*/

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;

            for (int i = 0; i < 1 << (s.length()-1); i++) {
                auto parts = partitionBin(s, i);

                bool valid = true;

                for (auto& sub : parts) {if (!isPalindrome(sub)) {valid = false; break;}}

                if (valid) {result.push_back(parts);}
            }

            return result;
        }


    private:
        vector<string> partitionBin(string& s, int num) {
            const int n = s.length();
            int i = 1;

            int lIdx = 0;
            int cIdx = 1;

            vector<string> strings;

            while (i <= (1 << (n-1))) {
                if (i & num) {
                    strings.push_back(s.substr(lIdx, (cIdx - lIdx)));
                    lIdx = cIdx;
                }

                cIdx++;
                i <<= 1;
            }

            strings.push_back(s.substr(lIdx, n - lIdx));
            return strings;
        }

        bool isPalindrome(string& s) {
            for (int i = 0; i < s.length() / 2; i++) {
                if (s[i] != s[s.length() - 1 - i]) {return false;}
            }
            return true;
        }
};

int main() {

    Solution solution{};
    auto p = solution.partition("aabbddeeffgghhkk");

    for (auto& c : p) {
        for (auto& e : c) cout << e << " ";
        cout << "\n";
    }

    return 0;
}