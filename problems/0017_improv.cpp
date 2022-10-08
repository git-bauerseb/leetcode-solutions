#include <iostream>

#include <algorithm>
#include <vector>
#include <string>
#include <map>

class Solution {
public:

    Solution() {
        m_lookup.insert({'2', "abc"});
        m_lookup.insert({'3', "def"});
        m_lookup.insert({'4', "ghi"});
        m_lookup.insert({'5', "jkl"});
        m_lookup.insert({'6', "mno"});
        m_lookup.insert({'7', "pqrs"});
        m_lookup.insert({'8', "tuv"});
        m_lookup.insert({'9', "wxyz"});
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;

        if (digits.size() == 0) {
            return res;
        }

        int size = 1;
        for(int i = 0; i < digits.size(); i++) {
            size *= m_lookup[digits[i]].size();
        }

        char combs[size][digits.size()+1];

        for (int i = 0; i < digits.size(); i++) {
            std::string letters = m_lookup[digits[i]];
            int rep = letters.size() - i;

            int l_idx = 0;
            char c = letters[l_idx];


            for (int j = 0; j < size; j++) {
                if (j % rep == 0 && j > 0) {
                    c = letters[++l_idx];
                }

                combs[j][i] = c;
                combs[j][digits.size()] = '\0';
            }
        }

        for (int i = 0; i < size; i++) {
            std::string s {combs[i]};
            res.push_back(s);
        }

        return res;
    }

    private:
        std::map<char, std::string> m_lookup;
};

int main(int argc, char** argv) {

    std::vector<std::string> cases{};
    cases.push_back("23");
    cases.push_back("956");

    Solution solution{};

    for(auto& case_ : cases) {
        std::vector<std::string> comb = solution.letterCombinations(case_);

        for(auto& c : comb) {
            std::cout << c << " ";
        }

        std::cout << "\n";
    }

    return 0;
}