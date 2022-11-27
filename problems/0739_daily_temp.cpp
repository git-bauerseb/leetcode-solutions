#include <bits/stdc++.h>

using namespace std;

/*

    Used:
        - monotonic stack

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
                while (stack.size() > 0 && temperatures[*(stack.end()-1)] < temperatures[i]) {
                    int top = stack[*(stack.end()-1)];
                    stack.pop_back();

                    bigger[top] = (i - top);
                }


                stack.push_back(i);
            }

            return bigger;
        }
};


/*
    Used:
        - monotonic queue

*/
class Solution2 {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            const int n = temperatures.size();
             
            vector<int> bigger(n,0);
            vector<int> queue;

            for (int i = n - 1; i >= 0; i--) {
                while (queue.size() > 0 && temperatures[queue[0]] > temperatures[i]) {
                    int f = queue[0];
                    queue.erase(queue.begin());
                    bigger[i] = (f - i);
                }

                queue.push_back(i);
            }

            return bigger;
        }
};


int main() {

    vector<int> nums{89,62,70,58,47,76,100};

    Solution2 solution{};
    auto r = solution.dailyTemperatures(nums);

    for (auto& e : r) {
        cout << e << " ";
    }

    cout << "\n";

    return 0;
}