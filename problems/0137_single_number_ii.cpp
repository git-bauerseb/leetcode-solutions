#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int v1 = 0;
        int v2 = 0;

        int v1_tmp, v2_tmp;


        for(auto& a : nums) {
            v2_tmp = (~a & v2 & ~v1) | (a & ~v2 & v1);
            v1_tmp = ((~a & ~v2 & v1) | (a & ~v2 & ~v1));
            v1 = v1_tmp;
            v2 = v2_tmp;
        }

        return v1;
    }
};

int main(int argc, char** argv) {

    vector<int> nums{2,3,3,3,5,5,5,4,4,4};

    Solution solution{};
    int result = solution.singleNumber(nums);

    cout << result << "\n";

    return 0;
}