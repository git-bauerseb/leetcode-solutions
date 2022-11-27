#include <bits/stdc++.h>

using namespace std;

class NumArray {

    public:

        NumArray(vector<int> a) {
            m_n = a.size();
            m_bit.resize(m_n);
            m_nums = a;

            for (size_t i = 0; i < a.size(); i++) {
                for (int idx = i; idx < m_n; idx = idx | (idx + 1)) {
                    m_bit[idx] += m_nums[i];
                }
            }
        }


        void update(int index, int new_value) {
            int o_idx = index;
            int delta = new_value - m_nums[index];

            for (; index < m_n; index = index | (index + 1)) {
                m_bit[index] += delta;
            }

            m_nums[o_idx] = new_value;
        }


        int sumRange(int l, int r) {
            l -= 1;

            int sum = 0;

            for (; r >= 0; r = (r & (r + 1)) - 1) {
                sum += m_bit[r];
            }

            for (; l >= 0; l = (l & (l + 1)) - 1) {
                sum -= m_bit[l];
            }

            return sum;
        }

    private:
        vector<int> m_bit;
        vector<int> m_nums;
        int m_n;
};

int main() {

    vector<int> nums{9,-8};
    NumArray array(nums);

    array.update(0,3);

    cout << array.sumRange(1,1) << "\n";
    cout << array.sumRange(0,1) << "\n";
    array.update(1,-3);
    cout << array.sumRange(0,1) << "\n";

    
    return 0;
}