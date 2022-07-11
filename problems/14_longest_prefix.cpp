#include <iostream>

#include <vector>
#include <string>

class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            
            int i = 0;

            for(auto& s : strs) {
                if (s.size() <= i) {
                    return i;
                } else {
                    
                }
            }

        }
};

int main(int argc, char** argv) {

    return 0;
}