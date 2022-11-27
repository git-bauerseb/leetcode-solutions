#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        result.push_back({});
        
        int bits = 1;
        int n = nums.size();
        int subs = 1 << n;
        while (bits < subs) {

            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (bits & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            result.push_back(subset);

            bits++;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {

    vector<int> test{1,2,3};

    Solution solution{};

    auto res = solution.subsets(test);

    for (auto& s : res) {
        for (auto& e : s) {
            cout << e << " ";
        }

        cout << "\n";
    }

    return 0;
}