#include <bits/stdc++.h>

using namespace std;

// O(nlog(n))
class Solution {

    public:
        int destroyTargets(vector<int>& nums, int space) {

            // Save: (num_elements, minimum)
            unordered_map<int, pair<int,int>> elements;

            // O(nlog(n))
            for (const auto& e : nums) {
                int m = e % space;
                if (elements.count(m) > 0) {
                    elements[m].first = elements[m].first+1;
                    elements[m].second = min(elements[m].second, e);
                } else {
                    elements.insert({m, {1,e}});
                }
            }

            
            int max_len = 0;
            int min_elem = 0;

            // O(n)
            for (const auto& [k,v] : elements) {
                if (v.first > max_len) {
                    max_len = v.first;
                    min_elem = v.second;
                } else if (v.first == max_len && v.second < min_elem) {
                    min_elem = v.second;
                }
            }

            return min_elem;
        }

};

int main() {

    vector<int> nums{6,2,5};

    Solution solution{};
    int max = solution.destroyTargets(nums, 100);
    cout << max << "\n";
    return 0;
}