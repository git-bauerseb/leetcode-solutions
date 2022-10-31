#include <bits/stdc++.h>

using namespace std;

struct CComparator {
    bool operator()(const pair<int,int*> a, const pair<int,int*> b) {
        return *a.second > *b.second;
    }
};


// Time complexity: O(n^2 * log(n))
// Space complexity: O(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        if (n == 1) {
            return matrix[0][0];
        }

        priority_queue<pair<int,int*>, vector<pair<int,int*>>, CComparator> pq;
        for (int i = 0; i < n; i++) {pq.push({i, &matrix[i][0]});}

        while ((k--) > 0) {
            pair<int, int*> p = pq.top();
            pq.pop();


            if (k == 0) {
                return *p.second;
            }

            if ((p.second - &matrix[p.first][0]) < (n-1)) {
                pq.push({p.first, p.second+1});
            }
        }

        return -1;
    }
};

int main() {

    
    vector<vector<int>> matrix;
    matrix.push_back({-5});
    

    Solution solution{};

    for (int i = 1; i <= 1; i++) {
        int s = solution.kthSmallest(matrix, i);
        cout << s << "\n";
    }
    
    return 0;
}