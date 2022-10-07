#include <bits/stdc++.h>

using namespace std;

#define DISTINCT(a,b,c,d) ((a) != (b) && (b) != (c) && (c) != (d))

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        if (nums.size() < 4) {
            return result;
        }

        for (int i = 0; i < nums.size(); i++) {

            int j = nums.size() - 1;

            while (j > i) {

                int a = nums[i];
                int b = nums[j];

                int k = i + 1;
                int l = j - 1;

                while (k < l) {

                    int c = nums[k];
                    int d = nums[l];

                    int sum = a + b;

                    // Overflow check
                    if (sum > 0 && c > numeric_limits<int>::max() - sum) {
                        break;
                    }

                    // Underflow check
                    if (sum < 0 && c < numeric_limits<int>::min() - sum) {
                        break;
                    }

                    sum += c;

                    // Overflow check
                    if (sum > 0 && d > numeric_limits<int>::max() - sum) {
                        break;
                    }

                    // Underflow check
                    if (sum < 0 && d < numeric_limits<int>::min() - sum) {
                        break;
                    }

                    sum += d;


                    bool found = false;

                    for (auto& e : result) {
                        if (e[0] == a && e[1] == b && e[2] == c && e[3] == d) {
                            found = true;
                            break;
                        }
                    }

                    if (!found && sum == target && (DISTINCT(i,j,k,l))) {
                        vector<int> quadruple({a, b, c, d});
                        result.push_back(quadruple);
                        k++;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l --;
                    }
                }

                j--;
            }
        }

        return result;
    }
};

int main() {

    vector<vector<int>> cases;
    cases.push_back({1,0,-1,0,-2,2});
    cases.push_back({2,2,2,2,2});
    cases.push_back({1000000000,1000000000,1000000000,1000000000});
    cases.push_back({0,0,0});
    cases.push_back({0,0,0,0});

    vector<int> targets{0, 8, 0, 0, 0};

    Solution solution{};

    int idx = 0;
    for (auto& case_ : cases) {
        auto res = solution.fourSum(case_, targets[idx]);

        for (auto& e : res) {
            for (auto& el : e) {
                cout << el << " ";
            }
            cout << "\n";
        }

        idx++;
    }


    return 0;
}