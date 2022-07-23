#include <iostream>

#include <vector>
#include <cmath>

class Solution {
    public:
        int minCostClimbingStairs(std::vector<int>& cost) {
            int arr[cost.size()];
            
            arr[0] = cost[0];
            arr[1] = cost[1];

            for (int i = 2; i < cost.size(); i++) {
                arr[i] = std::min(arr[i-2] + cost[i], arr[i-1] + cost[i]);
            }

            return std::min(arr[cost.size()-1], arr[cost.size()-2]);
        }
};

int main(int argc, char** argv) {

    std::vector<std::vector<int>> cases{};
    cases.push_back({10,15,20});
    cases.push_back({10,15,20, 2});
    cases.push_back({2,20,15,10});
    cases.push_back({1,100,1,1,1,100,1,1,100,1});
    cases.push_back({1,2,3,4,5});

    Solution solution{};

    for(auto& case_ : cases) {
        int val = solution.minCostClimbingStairs(case_);
        std::cout << val << "\n";
    }

    return 0;
}