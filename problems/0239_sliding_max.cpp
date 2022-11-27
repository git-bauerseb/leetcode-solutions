#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            const int n = nums.size();
            vector<int> output;


            pair<int,int> m_idx = maxInWindow(nums,0,k);
            output.push_back(m_idx.first);

            for (int i = 1; i < n - k + 1; i++) {
                if (nums[i + k - 1] >= m_idx.first) {
                    m_idx.first = nums[i + k - 1];
                    m_idx.second = i;
                } else if (i > m_idx.second) {
                    m_idx = maxInWindow(nums, i, k);
                }

                output.push_back(m_idx.first);
            }

            return output;
        }

    private:
        // Returns (maximum, index)
        pair<int,int> maxInWindow(vector<int>& nums, int s, int k) {
            int idx = s;
            int max = nums[s];

            for (int i = s; i < s + k; i++) {
                if (nums[i] > max) {
                    idx = i;
                    max = nums[i];
                }
            }

            return {max, idx};
        }
};

int main() {

    vector<int> nums{1,5,6};
    Solution solution{};

    auto r = solution.maxSlidingWindow(nums, 50000);
    for (auto& e : r) {
        cout << e << " ";
    }

    cout << "\n";
    return 0;
}