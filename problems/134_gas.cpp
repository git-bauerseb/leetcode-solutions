#include <iostream>

#include <vector>

class Solution {
    public:
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
            int n = gas.size();
            int idx = 0;
            int sum_tot = 0;
            int tank = 0;
            int diff = 0;

            for (int i = 0; i < n; ++i) {
                diff = gas[i] - cost[i];
                tank += diff;
                sum_tot += diff;
                
                if (tank < 0) {
                    tank = 0;
                    idx = i+1;
                }
            }

            return sum_tot < 0 ? -1 : idx;
        }
};

int main(int argc, char** argv) {

    std::vector<int> gas_case{3,1,1};
    std::vector<int> cost_case{1,2,2};

    Solution solution{};
    int start_idx = solution.canCompleteCircuit(gas_case, cost_case);


    std::cout << start_idx << "\n";

    return 0;
}