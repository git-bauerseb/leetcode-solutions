#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string numberToWords(int num) {

        }
    
    private:
        void num2WordRec(string& s, int num) {
            if (num < 10) {
                switch (num) {
                    case 1: s += "One"; break;
                    case 2: s += "Two"; break;
                    case 3: s += "Three"; break;
                    case 4: s += "Four"; break;
                    case 5: s += "Five"; break;
                    case 6: s += "Six"; break;
                    case 7: s += "Seven"; break;
                    case 8: s += "Eight"; break;
                    case 9: s += "Nine"; break;  
                    default: break;
                }
            } else {
                int l = decLog(num);

                // Number is in the range 10, ..., 99
                if (l < 2) {

                    
                    switch (num / 10) {
                    case 1:
                        /* code */
                        break;
                    
                    default:
                        break;
                    }
                }
            }
        }

        int decLog(int n) {
            int l = 0;
            while (n >= 10) {
                l++;
                n /= 10;
            }
            return l;
        }
};