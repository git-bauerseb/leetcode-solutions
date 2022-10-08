#include <bits/stdc++.h>

using namespace std;

class Solution {
  
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prereq) {
            for (auto& e : prereq) {
                m_prereq[e[0]].push_back(e[1]);
            }
        
            for (int i = 0; i < numCourses; i++) {
                if (!dfs(i)) {
                    return false;
                }
            }

            return true;
        }

    private:

        bool dfs(int start) {

            // Node has already been visited
            if (m_visited.find(start) != m_visited.end()) {
                return false;
            }

            // All prerequisits are fulfilled
            if (m_prereq[start].size() == 0) {
                return true;
            }

            m_visited.insert(start);

            for (auto& prereq : m_prereq[start]) {
                if (!dfs(prereq)) {
                    return false;
                }
            }


            m_prereq[start].clear();
            m_visited.erase(start);
            return true;
        }

        unordered_map<int, vector<int>> m_prereq;
        unordered_set<int> m_visited;
};

int main() {

    vector<vector<int>> prereq;
    prereq.push_back({0,1});
    prereq.push_back({1,0});

    Solution solution{};
    bool canFinish = solution.canFinish(2, prereq);

    cout << canFinish << "\n";

    return 0;
}