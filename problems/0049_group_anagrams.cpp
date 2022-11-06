#include <bits/stdc++.h>

using namespace std;

static bool compare(const string& a, const string& b) {
    
    const int a_len = a.size();
    const int b_len = b.size();
    if (a_len != b_len) {return false;}

    int occ[26] = {};

    for (int i = 0; i < a_len; i++) {
        occ[a[i]-'a']++;
        occ[b[i]-'a']--;
    }
  
    for (int i = 0; i < 26; i++) {if (occ[i] != 0) {return false;}}
    return true;
}

/*
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            const int n = strs.size();
            
            vector<bool> used(n, false);
            vector<vector<string>> s_;

            for (int i = 0; i < n; i++) {
                if (used[i]) {continue;}
                used[i] = true;
                s_.push_back({});
                s_[s_.size()-1].push_back(strs[i]);

                for (int j = 0; j < n; j++) {
                    if (used[j]) {continue;}
                    if (compare(strs[i], strs[j])) {
                        s_[s_.size()-1].push_back(strs[j]);
                        used[j] = true;
                    }
                }
            }

            return s_;
        }
};
*/

class Solution1 {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {

            unordered_map<string, vector<string>> m;

            // O(n * l * log(l))
            for (auto& e : strs) {
                string key(e);
                sort(key.begin(), key.end());

                m[key].push_back(e);
            }

            vector<vector<string>> result;

            // O(n)
            for (auto& [key,value] : m) {
                result.emplace_back(move(value));
            }

            return result;
        }
};

int main() {    
    vector<string> anagrams{"abc", "bca", "da", "ab", "ad"};

    Solution1 solution{};
    auto groups = solution.groupAnagrams(anagrams);
    for (auto& g : groups) {
        for (auto& e : g) {cout << e << " ";}
        cout << "\n";
    }
    
    return 0;
}