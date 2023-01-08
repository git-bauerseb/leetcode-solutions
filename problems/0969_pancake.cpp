#include <bits/stdc++.h>

using namespace std;

/*

    3,2,4,1

    4,2,3,1
    1,3,2,4

    3,1,2,4
    2,1,3,4
*/

class Solution {
    public:
        vector<int> pancakeSort(vector<int>& arr) {
            vector<int> flips;

            int i = arr.size()-1;

            while (i != 0) {
                int j = i;
                while (arr[j] != i+1) {j--;}
                
                if (j != 0) {flips.push_back(j+1);}
                flips.push_back(i+1);
                
                if (j != 0) {flip(arr, j);}
                flip(arr, i);

                i--;
            }

            return flips;
        }

    private:
        void flip(vector<int>& nums, int k) {
            for (int i = 0; i <= k/2; i++) {
                int tmp = nums[i];
                nums[i] = nums[k - i];
                nums[k-i] = tmp;
            }
        }
};

int main() {

    vector<int> nums{9,8,7,6,5,4,3,2,1};
    Solution solution{};

    vector<int> ops = solution.pancakeSort(nums);
    for (auto& o : ops) 
        cout << o << " ";
    cout << "\n";
    return 0;
}