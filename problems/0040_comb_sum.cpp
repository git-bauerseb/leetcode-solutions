#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {}
    vector<vector<int>>& combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        m_target = target;
        m_candidates = candidates;

        backtrack(0, 0);

        return m_poss;
    }
private:
    void backtrack(int cSum, size_t i) {
        if (cSum == m_target) {
            vector<int> coins;
            for(auto& e : current) {coins.push_back(e);}
            m_poss.push_back(coins);
        }

        if (i >= m_candidates.size() || cSum > m_target) {
            return;
        }

        int cand = m_candidates[i];
        if (cand + cSum > m_target) { return;}

        size_t next = i;
        while (next < m_candidates.size() && m_candidates[next] == cand) {next++;}

        current.push_back(cand);
        backtrack(cSum + cand, i+1);
        current.pop_back();

        if (next < m_candidates.size()) {
            backtrack(cSum, next);
        }
    }

    int m_target;
    vector<int> m_candidates;
    vector<int> current;
    vector<vector<int>> m_poss;
};

int main(int argc, char** argv) {

    vector<int> cand{2,5,2,1,2};

    Solution solution{};
    auto res = solution.combinationSum2(cand, 5);

    for (auto& s: res) {
        for (auto& e : s) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}