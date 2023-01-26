#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int findKthLargest(vector<int>& nums, int k) {
			return divConq(nums, 0, nums.size()-1, k);
		}

	public:
		int divConq(vector<int>& nums, int l, int u, int k) {
			if (l == u) return nums[l];
			int pos = partition(nums, l, u);
			int i = u - pos + 1;		// nums[pos] is ith largest element
			if (i == k)
				return nums[pos];
			else if (i < k)
				return divConq(nums, l, pos-1, k-i);
			else
				return divConq(nums, pos+1, u, k);		
		}


		int partition(vector<int>& nums, int l, int u) {
			int pivot = nums[u];
			int i = l - 1;
			for (int j = l; j < u; j++) {
				if (nums[j] <= pivot) {i++; swap(nums[i], nums[j]);}
			}

			swap(nums[i+1], nums[u]);
			return i+1;
		}
};

int main() {
	vector<int> nums{4,4,4,4,4,2,2,2,2,3};
	Solution solution{};
	for (int i = 1; i <= nums.size(); ++i) {
		int e = solution.findKthLargest(nums, i);
		cout << e << "\n";
	}

	return 0;
}
