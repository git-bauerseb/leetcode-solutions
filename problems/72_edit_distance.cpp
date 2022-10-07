#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();

        if (n == 0) {return m;}
        if (m == 0) {return n;}

        vector<vector<int>> dist(m+1, vector<int>(n+1));

        for (int i = 0; i < m+1; i++) {dist[i][0] = i;}
        for (int j = 0; j < n+1; j++) {dist[0][j] = j;}

        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                int cost = a[j-1] == b[i-1] ? 0 : 1;
                dist[i][j] = min(dist[i-1][j] + 1, 
                            min(dist[i][j-1] + 1, dist[i-1][j-1] + cost));
            }
        }

        return dist[m][n];
    }
};

int main(int argc, char** argv) {

    Solution solution{};
    int dist = solution.minDistance("horse", "ros");

    cout << dist << "\n";

    return 0;
}