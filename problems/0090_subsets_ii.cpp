#include <bits/stdc++.h>

using namespace std;


class Solution {
public:


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        set<vector<int>> result;
        result.insert({{}});
        
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

            result.insert(subset);

            bits++;
        }

        vector<vector<int>> v_result(result.begin(), result.end());
        
        return v_result;
    }
private:
    bool found(vector<int>& new_, vector<vector<int>>& sets) {
        for (auto& s : sets) {
            if (new_.size() == s.size()) {
                bool eq = true;
                for (int i = 0; i < new_.size(); i++) {
                    if (new_[i] != s[i]) {
                        eq = false;
                        break;
                    }
                }

                if (eq) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {

    vector<int> test{1,2,2};

    Solution solution{};

    auto res = solution.subsetsWithDup(test);

    for (auto& s : res) {
        for (auto& e : s) {
            cout << e << " ";
        }

        cout << "\n";
    }

    return 0;
}