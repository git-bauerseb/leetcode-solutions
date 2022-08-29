#include <bits/stdc++.h>

using namespace std;

struct CustomCompare {
    // Less-than comparison
    bool operator()(const string& l, const string& r) {
        return l + r < r + l;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, CustomCompare> pq;

        for(auto& e : nums) {
            pq.push(to_string(e));
        }

        string result;

        int pq_s = pq.size();
        for(int i = 0; i < pq_s; i++) {
            string s = pq.top();
            result += s;
            pq.pop();
        }

        result.erase(0, min(result.find_first_not_of('0'), result.size()-1));

        return result;
    }

};

int main(int argc, char** argv) {

    Solution solution{};

    vector<int> nums{0,0};
    string s = solution.largestNumber(nums);   
    cout << s << "\n";

    return 0;
}