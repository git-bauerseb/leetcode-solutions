#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            set<int> nums;
            while (true) {
                if (n == 1 || n == 7) {return true;}
                if (nums.count(n) > 0) {break;}
                nums.insert(n);
                n = digitSquared(n);
            }


            return false;
        }

    private:
        inline int digitSquared(int x) {
            int sum = 0;

            while (x > 0) {
                int digit = x % 10;
                sum += digit * digit;
                x /= 10;
            }

            return sum;
        }
};

int main() {
    Solution solution{};

    for (int i = 1; i <= 1000; i++) {
        bool happy = solution.isHappy(i);
        if (happy) {
            cout << i << "\n";
        }
    }
    return 0;
}