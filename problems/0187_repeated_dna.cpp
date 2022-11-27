#include <bits/stdc++.h>

using namespace std;

struct CHash {
    size_t operator() (const pair<int, char*>& p) const {
        return p.first;
    }
};

struct CComp {
    bool operator()(const pair<int, char*>& f, const pair<int, char*>& s) const {
        return f.first == s.first;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> result;
        map<int, bool> m;
        unordered_set<pair<int, char*>, CHash, CComp> duplicates;

        if (s.length() < 10) {
            return result;
        }

        char* begin = &s[0];
        char* end = &s[9];

        int hash = hash_subseq(begin, end);
        m.insert({hash, false});

        end++;

        while (end < &s[s.length()]) {
            int repr = 0;
            if (*end == 'C') {repr = 1;}
            else if (*end == 'G') {repr = 2;}
            else if (*end == 'T') {repr = 3;}

            hash = (hash >> 2) | (repr << 18);
            if (m.count(hash) == 1) {
                duplicates.insert({hash, end});
            } else {
                m.insert({hash, false});
            }

            end++;
        }

        for (auto& e : duplicates) {
            string sub = s.substr(e.second - begin - 9, 10);
            result.push_back(sub);
        }

        return result;
    }

private:

    char m_lookup[4] = {'A', 'C', 'G', 'T'};

    int hash_subseq(char* begin, char* end) {
        char* ptr = begin;

        int hash = 0;
        int idx = 0;

        while (ptr <= end) {

            int repr = 0;
            if (*ptr == 'C') {repr = 1;}
            else if (*ptr == 'G') {repr = 2;}
            else if (*ptr == 'T') {repr = 3;}

            hash |= (repr << idx);

            idx += 2;
            ptr++;
        }

        return hash;
    }
};




int main(int argc, char** argv) {

    string s ("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

    Solution solution{};
    auto res = solution.findRepeatedDnaSequences(s);

    for (auto& r : res) {
        cout << r << "\n";
    }

    return 0;
}