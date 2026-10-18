#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n = s1.length();
        int m = s2.length();
        
        if (n + m != s3.length()) {
            return false;
        }
        
        // dp[j] represents whether s3[0...i+j-1] can be formed by 
        // s1[0...i-1] and s2[0...j-1]
        std::vector<bool> dp(m + 1, false);
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                // Base case: empty s1 and empty s2 can form an empty s3
                if (i == 0 && j == 0) {
                    dp[j] = true;
                }
                // Only using characters from s1
                else if (i == 0) {
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                }
                // Only using characters from s2
                else if (j == 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                }
                // Using characters from both s1 and s2
                else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || 
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return dp[m];
    }
};