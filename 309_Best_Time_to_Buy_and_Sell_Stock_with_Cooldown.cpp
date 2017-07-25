/**
 * Best Time to Buy and Sell Stock with Cooldown
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                int cur = prices[j] - prices[i];
                if (j+2 < n) cur += dp[j+2];
                dp[i] = max(cur, dp[i]);
            }
            dp[i] = max(dp[i], dp[i+1]);
            //cout << i << " " << " " << dp[i] << endl;
        }
        return dp[0];
    }
};
