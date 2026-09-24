#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the start or end cell has an obstacle, no path is possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        // dp[j] represents the number of paths to the current cell in column j
        std::vector<long long> dp(n, 0);
        dp[0] = 1; // 1 way to be at the starting cell

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle blocks all incoming paths
                } else if (j > 0) {
                    // dp[j] before update is the value from the top cell (dp[i-1][j])
                    // dp[j-1] is the value from the left cell (dp[i][j-1])
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};