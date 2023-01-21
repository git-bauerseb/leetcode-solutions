#include <bits/stdc++.h>

using namespace std;

/*
	Idea:
   		- Sort numbers (and satelite indices)

		- left/right pointer
		while (left != right) {
			if (abs(val[left] - val[right]) <= valueDiff
				&& abs(ind[left] - ind[right]) <= indexDiff) {
				return true;
				}
		}

		Increment right pointer to point to next range

	Example:	
		(1,0), (2,1), (3,2), (1,3)

		Sort:
			(1,0) (1,3) (2,1) (3,2)
*/

bool comp(pair<int,int>& a, pair<int,int>& b) {
	return a.first < b.first;
}

#define ABS_VAL_DIFF(i,j) (abs(nums_idx[i].first - nums_idx[j].first))
#define IND_DIFF(i,j) (abs(nums_idx[i].second - nums_idx[j].second))

class Solution {
	public:
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
			const int n = nums.size();
			
			vector<pair<int,int>> nums_idx(n);

			for (int i = 0; i < n; ++i) {
				nums_idx[i] = {nums[i], i};
			}

			sort(nums_idx.begin(), nums_idx.end(), comp);

			int l, r;

			for (l = 0; l < n-1; ++l)
				for (r = l+1; r < n && ABS_VAL_DIFF(l,r) <= valueDiff; ++r)
					if (IND_DIFF(l,r) <= indexDiff)
						return true;		
			return false;
		}
};

int main() {
	
	vector<int> nums{1,5};


	Solution solution{};
	bool t = solution.containsNearbyAlmostDuplicate(nums, 1,3);
	cout << t << "\n";
	return 0;
}
