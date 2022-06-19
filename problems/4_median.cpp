#include <vector>
#include <cmath>
#include <iostream>

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            std::vector<int> merged{};

            int num1Ptr = 0;
            int num2Ptr = 0;

            if (nums1.size() == 0) {
                return singleArrayMedian(nums2);
            }

            if (nums2.size() == 0) {
                return singleArrayMedian(nums1);
            }

            for (int i = 0; i < nums1.size() + nums2.size(); i++) {
                if (num1Ptr < nums1.size() && num2Ptr < nums2.size()) {
                    if (nums1[num1Ptr] <= nums2[num2Ptr]) {
                        merged.push_back(nums1[num1Ptr]);
                        num1Ptr++;
                    } else if (nums2[num2Ptr] < nums1[num1Ptr]) {
                        merged.push_back(nums2[num2Ptr]);
                        num2Ptr++;
                    }
                }
            }

            // Append remaining elements
            for (int i = num1Ptr; i < nums1.size(); i++) {
                merged.push_back(nums1[i]);
            }

            for (int i = num2Ptr; i < nums2.size(); i++) {
                merged.push_back(nums2[i]);
            }

            return singleArrayMedian(merged);
        }

    private:
        double singleArrayMedian(std::vector<int>& a) {

            if (a.size() == 0) {
                return 0.0;
            }

            if (a.size() % 2 == 0) {
                return (a[(a.size() >> 1)] + a[(a.size() >> 1) - 1]) / 2.0;
            }

            return a[a.size() >> 1];
        }
};

int main(int argc, char** argv) {

    Solution solution{};

    std::vector<int> first {-1,1};
    std::vector<int> second {1,1};


    double median = solution.findMedianSortedArrays(first, second);

    std::cout << median << "\n";

    return 0;
}