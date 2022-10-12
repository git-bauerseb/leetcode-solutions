#include <bits/stdc++.h>

using namespace std;

#define MATCHES(s_i,p_i) ((p[p_i] == '?') || (s[s_i] == p[p_i]))

class Solution {

    public:
        bool isMatch(string s, string p) {
            int s_len = s.size();
            int p_len = p.size();

            if (p_len == 0) {return s_len == 0;}

            if (s_len == 0) {
                for (int i = 0; i < p_len; i++) {
                    if (p[i] != '*') {return false;}
                }

                return true;
            }

            vector<bool> matches((p_len+1)*(s_len+1), false);

            // s[0] matches p[0]
            matches[0] = true;

            for (int j = 1; j < p_len + 1; j++) {
                if (p[j-1] == '*') {
                    matches[j * (s_len + 1)] = matches[(j-1) * (s_len + 1)];
                }
            }

            for (int i = 1; i < s_len+1; i++) {
                for (int j = 1; j < p_len+1; j++) {
                    bool matched = false;
                    matched |= (matches[(j-1) * (s_len + 1) + i - 1] && MATCHES(i-1,j-1));
                    matched |= (matches[j * (s_len + 1) + i - 1] && p[j-1] == '*');
                    matched |= (matches[(j-1) * (s_len + 1) + i] && p[j-1] == '*'); 

                    matches[j * (s_len + 1) + i] = matched;
                }
            }

            return matches[p_len * (s_len + 1) + s_len];
        }
};

class Solution1 {
    public:
        bool isMatch(string inp, string pat) {
            const char* s = &inp[0];
            const char* p = &pat[0];
            const char* star=NULL;
            const char* ss=s;
            while (*s){
                //advancing both pointers when (both characters match) or ('?' found in pattern)
                //note that *p will not advance beyond its length 
                if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

                // * found in pattern, track index of *, only advancing pattern pointer 
                if (*p=='*'){star=p++; ss=s;continue;} 

                //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
                //only advancing pattern pointer
                if (star){ p = star+1; s=++ss;continue;} 

            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
                return false;
            }

        //check for remaining characters in pattern
            while (*p=='*'){p++;}

            return !*p;  
        }
};

int main() {

    vector<pair<string,string>> cases;

    cases.push_back({"aa", "*"});
    cases.push_back({"mississippi", "mis*si?pi"});
    cases.push_back({"mississippi", "mis*si?ppi"});
    cases.push_back({"ab", "?*"});
    cases.push_back({"", ""});
    cases.push_back({"a", ""});
    cases.push_back({"", "?"});
    cases.push_back({"abcd", "?????"});
    cases.push_back({"abcdefghijklmnopqrstuvwxyz", "abc*yz"});
    cases.push_back({"abcdefghijklmnopqrstuvwxyz", "abc*zy"});

    Solution1 solution{};

    for (auto& case_ : cases) {
        bool matched = solution.isMatch(case_.first, case_.second);
        cout << matched << "\n";
    }

    return 0;
}