#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            // Corner case
            if (n == 1) {return {0};}

            // Convert to adjacency list
            vector<vector<int>> adj_list(n);

            // Keep track of how often a node occurs in an edge
            // Pair: (node, count)
            vector<pair<int,int>> node_occ(n);

            // O(n)
            for (int i = 0; i < n; i++) {node_occ[i].first = i;}
            for (auto& e : edges) {
                adj_list[e[0]].push_back(e[1]);
                adj_list[e[1]].push_back(e[0]);

                node_occ[e[0]].second++;
                node_occ[e[1]].second++;
            }

            // O(nlog(n))
            sort(node_occ.begin(), node_occ.end(), [&](pair<int,int>& a, pair<int,int>& b) {
                return a.second > b.second;
            });

            int min_depth = 1 << 29;
            vector<int> result;

            int c_depth, idx = 0;

            while (idx < n && (c_depth = bfs(adj_list, node_occ[idx].first, n)) <= min_depth) {
                result.push_back(node_occ[idx].first);
                min_depth = c_depth;
                idx++;
            }

            return result;
        }

    public:
        // Time complexity: O(|V| + |E|)
        // In this case: O(2n)
        int bfs(vector<vector<int>>& adj_list, int root, int n) {
            int m_depth = 0;
            queue<int> nodes;
            vector<int> dist(n, 0);
            bitset<20> visited;

            nodes.push(root);
            visited[root] = 1;

            while (!nodes.empty()) {
                int c_node = nodes.front();
                nodes.pop();
                visited[c_node] = 1;

                for (auto& n : adj_list[c_node]) {
                    if (visited[n] == 0)
                    nodes.push(n);
                    dist[n] = dist[c_node] + 1;
                    m_depth = max(m_depth, dist[n]);
                }
            }

            return m_depth;
        }
};
*/

/*
    The problem can be reduced to finding the center of the tree.
    This also implies that at most 2 elements can be in the result.

    Algorithm:
        - Successively remove leaf nodes (nodes with one connection)
*/
class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj_list(n);
            for (auto& e : edges) {
                adj_list[e[0]].push_back(e[1]);
                adj_list[e[1]].push_back(e[0]);
            }

            int nodes_remaining = n;

            vector<int> node_degree(n,0);

            for (auto& e : edges) {
                node_degree[e[0]]++;
                node_degree[e[1]]++;
            }

            set<int> nodes;
            for (int i = 0; i < n; i++) {nodes.insert(i);}

            vector<int> to_remove;

            // Center can have at most 2 elements
            while (nodes.size() > 2) {
                for(auto& node : nodes) {
                    if (node_degree[node] == 1) {
                        to_remove.push_back(node);
                    }
                }

                for (auto& n : to_remove) {
                    for (auto& e : adj_list[n]) {
                        node_degree[e]--;
                    }
                    nodes.erase(n);
                }

                to_remove.clear();
            }

           
            return vector<int>(nodes.begin(), nodes.end());
        }
};

int main() {
    vector<vector<int>> edges;
    edges.push_back({1,0});
    edges.push_back({1,2});
    edges.push_back({1,3});

    Solution solution{};
    auto r = solution.findMinHeightTrees(4, edges);
    for (auto& _ : r) {
        cout << _ << " ";
    }
    cout << "\n";

    return 0;
}