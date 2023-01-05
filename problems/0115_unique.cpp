#include <bits/stdc++.h>

using namespace std;


/*
// Recursive solution
class Solution {
    public:
        int numDistinct(string s, string t) {
            return recSol(s, t, t.length()-1, s.length());
        }

    private:
        int recSol(string& s, string& t, int tInd, int tFirst) {
            if (tInd == 0) {
                int occ = 0;
                for (int i = 0; i < tFirst; i++) {
                    if (s[i] == t[tInd]) {occ++;}
                }

                return occ;
            }

            int ways = 0;

            for (int i = tFirst-1; i >= 0; i--) {
                if (s[i] == t[tInd]) {
                    ways += recSol(s,t,tInd-1, i);
                }
            }

            return ways;
        }


        unordered_map<int,int> m_memo;
};
*/

class Solution {
    public:
        int numDistinct(string s, string t) {
            const int n = s.size();
            const int m = t.size();

            if (m > n) {return 0;}
            if (m == n) {return s == t ? 1 : 0;}

            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

            for (int i = 0; i <= n; i++) {
                dp[i][0] = 1;
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s[i-1] == t[j-1]) {
                        long sum = (static_cast<long>(dp[i-1][j]) % numeric_limits<int>::max()) + (static_cast<long>(dp[i-1][j-1]) % numeric_limits<int>::max());
                        dp[i][j] = static_cast<int>(sum);
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

            return dp[n][m];
        }
};

int main() {

    Solution solution{};
    int nums = solution.numDistinct("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo",
    "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");
    cout << nums << "\n";

    return 0;
}