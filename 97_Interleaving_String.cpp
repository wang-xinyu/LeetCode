/**
 * Interleaving String
 * DP
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        if (n1 == 0 || n2 == 0 || n3 == 0) return (s1+s2 == s3) ? true : false;
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1));
        dp[n1][n2] = true;
        for (int i = n1-1; i >= 0; i--) dp[i][n2] = (i+n2 < n3 && s1[i] == s3[i+n2]) ? dp[i+1][n2] : false;
        for (int j = n2-1; j >= 0; j--) dp[n1][j] = (j+n1 < n3 && s2[j] == s3[j+n1]) ? dp[n1][j+1] : false;
        for (int i = n1-1; i >= 0; i--) {
            for (int j = n2-1; j >= 0; j--) {
                int k = i+j;
                if (s1[i] == s3[k] && s2[j] == s3[k]) {
                    dp[i][j] = dp[i+1][j] | dp[i][j+1];
                } else if (s1[i] == s3[k]) {
                    dp[i][j] = dp[i+1][j];
                } else if (s2[j] == s3[k]) {
                    dp[i][j] = dp[i][j+1];
                } else dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};
