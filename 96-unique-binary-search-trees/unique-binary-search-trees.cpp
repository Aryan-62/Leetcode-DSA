#include <vector>

class Solution {
public:
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs that can be formed using i nodes
        std::vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // An empty tree is 1 unique configuration
        dp[1] = 1; // A single node tree is 1 unique configuration
        
        // Fill dp table for trees of size 2 up to n
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                int leftCount = dp[root - 1];
                int rightCount = dp[nodes - root];
                dp[nodes] += leftCount * rightCount;
            }
        }
        
        return dp[n];
    }
};