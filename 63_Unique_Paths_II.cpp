/**
 * Unique Paths II
 * dp[m][n] = dp[m-1][n] + dp [m][n-1]
 * Time complexity: O(m*n)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 1;
        vector<vector<int>> dp(m, vector<int> (n));
        dp[m-1][n-1] = obstacleGrid[m-1][n-1] ? 0 : 1;
        for (int i = m-2; i >= 0; i--) dp[i][n-1] = obstacleGrid[i][n-1] ? 0 : dp[i+1][n-1];
        for (int i = n-2; i >= 0; i--) dp[m-1][i] = obstacleGrid[m-1][i] ? 0 : dp[m-1][i+1];
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
