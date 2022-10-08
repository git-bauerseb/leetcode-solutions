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

        for (auto& c : m_lookup[digits[0]]) {
            res.push_back({c});
        }

        for(int i = 1; i < digits.size(); i++) {
            std::vector<std::string> tmp;
            std::string dig = m_lookup[digits[i]];

            for(auto& d : dig) {
                for (int i = 0; i < res.size(); i++) {
                    tmp.push_back(res[i] + d);
                }
            }

            res.insert(res.end(), tmp.begin(), tmp.end());
        }

        std::vector<std::string> filtered;

        std::copy_if(res.begin(), res.end(), std::back_inserter(filtered),
        [&](std::string s) {return s.size() == digits.size();});

        return filtered;
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