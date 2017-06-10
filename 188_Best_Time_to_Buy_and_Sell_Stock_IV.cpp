/**
 * Best Time to Buy and Sell Stock IV
 *
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), ans = 0;
        if (k >= n/2) {
            for (int i = 1; i < n; i++) {
                ans += max(prices[i] - prices[i-1], 0);
            }
            return ans;
        }
        vector<vector<int>> dp(k+1, vector<int>(n));
        // dp[i][j] = max(dp[i][j-1], prices[j] - prices[jj] + dp[i-1][jj])
        //          = max(dp[i][j-1], prices[j] + max(dp[i-1][jj] - prices[jj]))
        // localmax = max(dp[i-1][jj] - prices[jj]) {jj = 0:j-1}
        for (int i = 1; i <= k; i++) {
            int localmax = 0 - prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j-1], prices[j] + localmax);
                localmax = max(localmax, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }
};
