#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {}
    vector<vector<int>>& combinationSum3(int k, int target) {
        for (int i = 1; i <= 9; i++) {m_candidates.push_back(i);}
        m_target = target;
        m_k = k;
        backtrack(0, 0);
        return m_poss;
    }
private:
    void backtrack(int cSum, size_t i) {
        if (cSum == m_target && current.size() == m_k) {
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

    size_t m_k;
    int m_target;
    vector<int> m_candidates;
    vector<int> current;
    vector<vector<int>> m_poss;
};

int main(int argc, char** argv) {

    Solution solution{};
    auto res = solution.combinationSum3(4, 1);

    for (auto& s: res) {
        for (auto& e : s) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}