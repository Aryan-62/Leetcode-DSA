#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    bool zeroOccurrence = dp[i][j - 2];
                    bool charMatches = (p[j - 2] == s[i - 1] || p[j - 2] == '.');
                    bool oneOrMoreOccurrences = charMatches && dp[i - 1][j];
                    dp[i][j] = zeroOccurrence || oneOrMoreOccurrences;
                } else {
                    bool charMatches = (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                    dp[i][j] = charMatches && dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};