#include <bits/stdc++.h>

using namespace std;

/*

    [73 74 75 71 69 72 76 73]

    1. 0
    2. 1
    3. 2
    4. 2,3
    5. 2,3,4

    Time complexity: O(n)
    Memory complexity: O(n)
*/
class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {

            const int n = temperatures.size();

            vector<int> stack;
            vector<int> bigger(n, 0);

            for (int i = 0; i < n; i++) {


                while (stack.size() > 0 && temperatures[stack[stack.size()-1]] < temperatures[i]) {
                    int top = stack[stack.size()-1];
                    stack.pop_back();

                    bigger[top] = (i - top);
                }


                stack.push_back(i);
            }

            return bigger;
        }
};


int main() {

    vector<int> nums{30};

    Solution solution{};
    auto r = solution.dailyTemperatures(nums);

    for (auto& e : r) {
        cout << e << " ";
    }

    cout << "\n";

    return 0;
}