#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        // Edge case
        if (numRows == 1 || numRows == s.length())
        {
            return s;
        }

        std::vector<char> chars{};

        int dist = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < s.size(); j += dist)
            {
                if (i == 0 || i == numRows - 1)
                {
                    chars.push_back(s[j]);
                }
                else
                {
                    chars.push_back(s[j]);

                    if ((j - i) + dist - i >= 0 && (j - i) + dist - i < s.length())
                    {
                        chars.push_back(s[(j - i) + dist - i]);
                    }
                }
            }
        }

        return std::string(chars.begin(), chars.end());
    }
};

int main(int argc, char **argv)
{
    Solution soluton{};

    /*
        0 1 2 3 4 5 6 7 8 9 10 11 12 13
        P A Y P A L I S H I R  I  N  G

        P A H N A L I G Y
    */

    std::string result = soluton.convert("PAYPALISHIRING", 3);

    std::cout << result << "\n";

    return 0;
}