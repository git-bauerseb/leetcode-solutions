#include <iostream>

#include <string>
#include <cmath>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {

            // Special case
            if (s.size() == 0) {
                return 0;
            }
            
            char* occ = (char*)calloc(256,sizeof(char));

            int start = 0;
            int end = -1;
            int maxLength = -1;

            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (occ[c] == 0) {
                    occ[c]++;
                    end = i;

                    maxLength = std::max(maxLength, end - start + 1);
                } else if (occ[c] == 1) {
                    while (start < s.size() && s[start] != c) {
                        occ[s[start]]--;
                        start++;
                    }

                    start++;
                    end = i;
                }
            }

            free(occ);
            return maxLength;
        }
};

int main(int argc, char** argv) {


    Solution solution{};
    int len = solution.lengthOfLongestSubstring("abcabcbb");

    std::cout << len << "\n";

    return 0;
}