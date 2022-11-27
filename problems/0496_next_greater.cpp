#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            const int n = nums1.size();
            vector<int> stack;

            for (int i = 0; i < n; i++) {
                nums2[i] = -1;
                while (stack.size() > 0 && nums1[stack[stack.size()-1]] >= nums1[i]) {
                    int top = stack[stack.size()-1];

                    nums2[i] = top;
                }
            }

            for (int i = 0; i < n; i++) {
                if (nums2[i] != -1) {
                    nums2[i] = nums1[nums2[i]];
                }
            }
        }
};

int main() {



    return 0;
}