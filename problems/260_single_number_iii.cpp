#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;

        long v = 0;

        for(auto& n : nums) {
            v ^= n;
        }

        long mask = v & -v;

        long r = 0;

        for(auto& n : nums) {
            if ((n & mask) == 0) {
                r ^= n;
            }
        }

        result.push_back(r);
        result.push_back(v^r);

        return result;
    }
};

int main(int argc, char** argv) {

    
    vector<int> nums{1,1,0,-2147483648};
    Solution solution{};

    auto r = solution.singleNumber(nums);
    
    for(auto& e : r) {
        cout << e << " ";
    }
    

    

    return 0;
}