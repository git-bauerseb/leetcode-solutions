#include <bits/stdc++.h>

using namespace std;

struct Comparator {
    bool operator()(int a, int b) {
        return a > b;
    }
};

class Solution {
    public:
        int minCost(string colors, vector<int>& neededTime) {
            int n = colors.size();
            
            priority_queue<int, vector<int>, Comparator> queue;

            int cost = 0;

            for (int i = 0; i < n;) {
                char c_color = colors[i];
                queue.push(neededTime[i]);
                i++;


                while (i < n && colors[i] == c_color) {
                    queue.push(neededTime[i]);
                    i++;
                }

                int q_size = queue.size();
                for (int i = 0; i < q_size-1; i++) {
                    cost += queue.top();
                    queue.pop();
                }

                queue.pop();
            }

            return cost;
        }
};

int main() {

    vector<int> time{6,5,2,7,2,3,1,9};
    string s("aaaabbaa");

    Solution solution{};
    int minTime = solution.minCost(s, time);

    cout << minTime << "\n";

    return 0;
}