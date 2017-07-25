/**
 * Perfect Squares
 *
 */
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while (dp.size() <= n) {
            int m = dp.size();
            int curMin = 4;  // Lagrange's four-square theorem
            for (int i = 1; i*i <= m; i++) {
                curMin = min(curMin, dp[m - i*i] + 1);
            }
            dp.push_back(curMin);
        }
        return dp[n];
    }
};
