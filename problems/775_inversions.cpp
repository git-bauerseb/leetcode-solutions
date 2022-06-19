#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

class Solution {
    public:
        bool isIdealPermutation(std::vector<int>& nums) {
            
            if (nums.size() == 0 || nums.size() == 1) {
                return true;
            }

            int* arr = &nums[0];
            return inversions(arr, 0, nums.size()-1);
        }

        bool countInversions(int* const arr, int p, int q, int r) {
            // Include 'q' into first array
            int n1 = q - p + 1;
            int n2 = r - q;

            int* L = new int[n1];
            int* R = new int[n2];

            for (int i = 0; i < n1; i++) {
                L[i] = arr[p+i];
            }

            for (int j = 0; j < n2; j++) {
                R[j] = arr[q+j+1];
            }

            int i = 0;
            int j = 0;
            int glob_inv = 0;
            for (int k = p; k <= r; k++) {
                if (i == n1) {
                    arr[k] = R[j];
                    j = j + 1;
                } else if (j == n2) {
                    arr[k] = L[i];
                    i = i + 1;
                } else if (L[i] < R[j]) {
                    arr[k] = L[i];
                    i = i + 1;
                } else {
                    if (n1 - i > 1) {
                        return false;
                    }
                    arr[k] = R[j];
                    j = j + 1;
                }
            }

            delete[] L;
            delete[] R;

            return true;
        }


        bool inversions(int* const arr, int p, int r) {
            if (p < r) {
                int q = std::floor((p+r) / 2);

                auto a = inversions(arr, p, q);

                if (!a) {
                    return false;
                }

                auto b = inversions(arr, q+1, r);

                if (!b) {
                    return false;
                }

                auto c = countInversions(arr, p, q, r);

                return c;
            }

            return true;
        }
};

int main(int argc, char** argv) {

    std::vector<int> perm{2,0,1};
    Solution solution{};

    bool same = solution.isIdealPermutation(perm);

    std::cout << same << "\n";

    return 0;
}