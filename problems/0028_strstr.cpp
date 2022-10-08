#include <iostream>

#include <string>

class Solution {
    public:
        int strStr(std::string haystack, std::string needle) {
            int idx = -1;

            for (int i = 0; i < haystack.size();) {

                int j = i;
                int pos = 0;

                while (j < haystack.size() && pos < needle.size() && haystack[j] == needle[pos]) {
                    j++;
                    pos++;
                }

                if (pos == needle.size()) {
                    return i;
                } else if (j == i) {
                    i++;
                } else {
                    i = j;
                }
            }


            return idx;
        }
};

int main(int argc, char** argv) {


    Solution solution{};
    int idx = solution.strStr("aaaaab", "ba");

    std::cout << idx << "\n";

    return 0;
}