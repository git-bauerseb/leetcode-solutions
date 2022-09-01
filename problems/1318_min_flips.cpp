#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {

        if ((a | b) == c) {return 0;}

        int min_flips = 0;
        
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;

            if ((c & mask) && !((a & mask) || (b & mask))) {min_flips++;}
            else if (!(c & mask) && (a & mask) && !(b & mask)) {min_flips++;}
            else if (!(c & mask) && !(a & mask) && (b & mask)) {min_flips++;}
            else if (!(c & mask) && (a & mask) && (b & mask)) {min_flips += 2;}
        }

        return min_flips;
    }
};


int main(int argc, char** argv) {

    int a = 1;
    int b = 2;
    int c = 3;


    Solution solution{};
    int min_flips = solution.minFlips(a,b,c);

    cout << min_flips << "\n";

    return 0;
}