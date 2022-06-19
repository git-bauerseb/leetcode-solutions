#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#include <ctype.h>

class SetChars {
    public:
        SetChars() : m_chars{} {}

        void addChar(char c) {
            m_chars.push_back(std::string{1,c});
        }

        void addStr(std::string s) {
            m_chars.push_back(s);
        }

        void addSet(SetChars& s) {
            for(auto& c : s.m_chars) {
                m_chars.push_back(c);
            }
        }

        void crossProduct(SetChars& second) {

            std::vector<std::string> new_m_chars;

            for(auto& s1: m_chars) {
                for (auto& s2: second.m_chars) {
                    new_m_chars.push_back(s1 + s2);
                }
            }

            m_chars = new_m_chars;
        }

        void print() {
            for(auto& s : m_chars) {
                std::cout << s << "\n";
            }
        }

        std::vector<std::string> getStrings() {
            return m_chars;
        }

    private:
        std::vector<std::string> m_chars;
};

class Solution {
    public:
        std::vector<std::string> braceExpansionII(std::string expression) {
            SetChars set{};
            parseExpression(expression, 0, set);
            std::vector<std::string> words = set.getStrings();
            std::vector<std::string> output {};

            std::sort(words.begin(), words.end());
            for (auto a = words.begin(), b = a; a != words.end(); a = b) {
                b = std::find_if(b, words.end(), [&](std::string s) {return *b != s;});
                if (std::distance(a, b) >= 1) {
                    output.push_back(*a);
                }
            }

            return output;
        }

        int parseExpression(std::string& s, int idx, SetChars& chars) {
            int n_idx = parseTerm(s, idx, chars);

            if (n_idx < s.size() && s[n_idx] == ',') {
                SetChars second {};
                n_idx = parseExpression(s, ++n_idx, second);
                chars.addSet(second);
            }

            return n_idx;
        }

        int parseTerm(std::string& s, int idx, SetChars& chars) {
            int n_idx = parseElement(s, idx, chars);            
            if (n_idx < s.size() && s[n_idx] != ',' && s[n_idx] != '}') {
                SetChars  second{};
                n_idx = parseTerm(s, n_idx, second);
                chars.crossProduct(second);
            }

            return n_idx;
        }

        int parseElement(std::string& s, int idx, SetChars& chars) {
            // Parse characters
            if (idx < s.size() && islower(s[idx])) {
                int start = idx;
                int end = idx;

                while (islower(s[end])) {end++;}

                std::string sub = s.substr(start, end - start);

                chars.addStr(sub);
                return end;
            }

            // Parse bracket
            if (idx < s.size() && s[idx] == '{') {
                int n_idx = parseExpression(s, ++idx, chars);

                if (n_idx > s.size() || s[n_idx] != '}') {
                    std::cout << "Unmatched bracket\n";
                }

                return n_idx + 1;
            }

            return -1;
        }
};

int main(int argc, char** argv) {

    Solution solution{};

    std::vector<std::string> words = solution.braceExpansionII("{{a,z},a{b,c},{ab,z}}");

    for (auto& s : words) {
        std::cout << s << "\n";
    }

    return 0;
}