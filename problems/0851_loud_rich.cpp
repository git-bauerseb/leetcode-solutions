#include <bits/stdc++.h>

using namespace std;

// Solution leads to timeout
/*
class Solution {
    public:
        vector<int> loudAndRich(vector<vector<int>>& richer,
            vector<int>& quiet) {
            const int n = quiet.size();
            vector<vector<int>> adj_list(n);

            vector<bool> used(n, false);

            // Add reverse edge (a -> b) <=> (b -> a)
            for (auto& edge : richer) {adj_list[edge[1]].push_back(edge[0]);}

            vector<int> result(n);
            for (int i = 0; i < n; i++) { 
                // If there is no richer person then the least quiet person is 
                // the person itself
                if (adj_list[i].empty() && !used[i]) {
                    result[i] = i;
                    used[i] = true;
                    continue;
                }

                if (!used[i])
                    bfs(adj_list, quiet, used, result, i);

            }

            return result;
        }

    public:
        void bfs(vector<vector<int>>& adjlist, vector<int>& quiet, vector<bool>& used, vector<int>& result, int start) {
            queue<int> nodes;
            nodes.push(start);

            vector<int> parent(quiet.size(), 0);

            int lq_n = start;
            int lq = quiet[start];

            parent[start] = -1;

            while (!nodes.empty()) {
                int c_node = nodes.front();
                nodes.pop();

                for (auto& neigh : adjlist[c_node]) {
                    nodes.push(neigh);
                    parent[neigh] = c_node;
                    if (quiet[neigh] < lq) {
                        lq_n = neigh;
                        lq = quiet[neigh];
                    }

                }
            }

            int c_node = parent[lq_n];

            result[start] = lq_n;
            used[start] = true;

            while (c_node != -1 && c_node != start) {
                result[c_node] = lq_n;
                used[c_node] = true;
                c_node = parent[c_node];   
            }
        }
};
*/


class Solution {
    public:
        vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
            const int n = quiet.size();
            vector<vector<int>> adjlist(n);

            vector<int> result(n,0);
            vector<bool> used(n, false);
            
            for (auto& edge : richer) {
                adjlist[edge[1]].push_back(edge[0]);
            }

            for (int i = 0; i < n; i++) {
                if (!used[i]) dfs(i, adjlist, quiet, result, used);
            }

            return result;
        }


    private:
        int dfs(int start, vector<vector<int>>& adjlist, vector<int>& quiet, vector<int>& result, vector<bool>& used) {
            
            if (used[start])
                return result[start];

            int quietN = quiet[start];
            int quietNIdx = start;
            
            for (auto& neigh : adjlist[start]) {
                int dfsR = dfs(neigh, adjlist, quiet, result, used);
                if (quiet[dfsR] < quietN) {
                    quietN = quiet[dfsR];
                    quietNIdx = dfsR;
                }
            }

            result[start] = quietNIdx;
            used[start] = true;
            return quietNIdx;
        }
};

int main() {
    vector<vector<int>> richer;
    richer.push_back({1,0});
    richer.push_back({2,1});
    richer.push_back({3,1});
    richer.push_back({3,7});
    richer.push_back({4,3});
    richer.push_back({5,3});
    richer.push_back({6,3});
    vector<int> quiet {3,2,5,4,6,1,7,0};


    Solution solution{};
    auto r = solution.loudAndRich(richer, quiet);
    for (auto & e : r) cout << e << " ";
    cout << "\n";
    return 0;
}