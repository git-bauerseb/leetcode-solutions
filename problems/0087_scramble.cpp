#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isScramble(string s1, string s2) {
            return recSol(s1, s2);
        }


        bool recSol(string& s1, string& s2) {
            const int n = s1.length();
            const int m = s2.length();

            if (memo.count(s1+s2) > 0) {return memo[s1+s2];}

            if (n != m) {return false;}
            if (n == 1) {return s1[0] == s2[0];}

            auto pairs = splitSame(s1, s2);
            
            for (auto& p : pairs) {
                if (recSol(p.first.first, p.first.second) && recSol(p.second.first, p.second.second)) {
                    memo.insert({s1+s2, true});
                    return true;
                }
            }   

            memo.insert({s1+s2, false});
            return false; 
        }

        // Split the string s1 and s2 such that the corresponding substrings contain the same
        // characters. Because there are multiple splits possible, it returns a collection
        // of such pairs
        vector<pair<pair<string,string>,pair<string,string>>> splitSame(const string& s1, const string& s2) {
            const int n = s1.length();

            vector<pair<pair<string,string>, pair<string,string>>> ret;

            for (int i = 0; i < n-1; i++) {
                string s11 = s1.substr(0, i+1);
                string s12 = s1.substr(i+1, n - (i+1));


                for (int j = 0; j < n-1; j++) {
                    string s21 = s2.substr(0, j+1);
                    string s22 = s2.substr(j+1, n - (j+1));

                    if ((isPerm(s11, s21) && isPerm(s12, s22))) {
                        ret.push_back({{s11, s21}, {s12, s22}});
                    } else if ((isPerm(s11, s22) && isPerm(s12, s21))) {
                        ret.push_back({{s11, s22}, {s12, s21}});
                    }
                }
            }

            return ret;
        }

        // Returns true if s2 is a permutation of the characters
        // in string s1
        bool isPerm(string s1, string s2) {
            if (s1.length() != s2.length()) {return false;}

            char chs[26] = {};

            for (auto& c : s1) {chs[c - 'a']++;}
            for (auto& c : s2) {chs[c - 'a']--;}

            for (int i = 0; i < 26; i++) {
                if (chs[i] != 0) {return false;}
            }

            return true;
        }

    private:
        map<string, bool> memo;
};

int main() {

    vector<pair<string,string>> cases;
    cases.push_back({"abc", "cab"});                                                            // 1
    cases.push_back({"abcdefghijklmnopqrstuvwxyz", "stuvyzabcdefghijklwxmnopqr"});              // 0
    cases.push_back({"ghj", "jhg"});                                                            // 1
    cases.push_back({"eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd"});
    

    Solution solution{};

    for (auto& c : cases) {
        auto b = solution.isScramble(c.first, c.second);
        cout << b << "\n";
    }
    return 0;
}