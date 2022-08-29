#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(n)
class Solution {
public:
    // O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> r;
        unordered_set<int> i;
        // O(n)
        for(auto& e : nums1) {r.insert(e);}
        // O(n)
        for(auto& e : nums2) {if (r.count(e) > 0) {i.insert(e);}}
        
        vector<int> result(i.begin(), i.end());
        return result;
    }
};

// Best solution on leetcode
// Time complexity: O(nlog(n)), O(n) solution is slower
// Runtime: > 97.00%
// Memory: > 97.27%
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int res_size = 0;

        size_t i1 = 0, i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size()) {
            int a = nums1[i1];
            int b = nums2[i2];
            if (a == b) {
                if (res_size <= 0 || res[res_size-1] != a) {
                    res.push_back(nums1[i1]);
                    res_size++;
                }
                i1++;
                i2++;
            } else if (a < b) {
                i1++;
            } else {
                i2++;
            }
        }

        return res;
    }
};

class Solution3 {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> set{begin(nums1), end(nums1)};
    for (const int num : nums2){
      if (set.erase(num)){
        ans.push_back(num);
      }
    }
    return ans;
  }
};

int main(int argc, char** argv) {

    Solution3 solution{};

    vector<pair<vector<int>, vector<int>>> cases;
    cases.push_back({{1,2,2,1}, {2,2}});
    cases.push_back({{4,9,5}, {9,4,9,8,4}});


    for (auto& e : cases) {
        vector<int> inter = solution.intersection(e.first, e.second);
        for (auto& e : inter) {cout << e << "\n";}
        cout << "\n";
    }

    return 0;
}