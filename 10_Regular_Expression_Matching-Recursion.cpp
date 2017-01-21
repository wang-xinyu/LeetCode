/**
 * dp[i][j]: if s[0,...,i-1] matchs p[0,..,j-1]
 * 1, If p.charAt(j-1) != '*'
 *    here are two sub conditions:
 *                1   If p.charAt(j-1) == s.charAt(i-1) :  dp[i][j] = dp[i-1][j-1];
 *                2   If p.charAt(j-1) == '.' : dp[i][j] = dp[i-1][j-1];
 * 2, If p.charAt(j-1) == '*': 
 *    here are two sub conditions:
 *                1   If p.charAt(j-2) != s.charAt(i-1) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
 *                2   If p.charAt(j-2) == s.charAt(i-1) or p.charAt(i-2) == '.':
 *                               dp[i][j] = dp[i-1][j]  // in this case, a* counts at least 1 times
 *                            or dp[i][j] = dp[i][j-2]  // in this case, a* counts as empty
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[1] != '*') {
            return (s.size() > 0 && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1)));
        } else {
            return (isMatch(s, p.substr(2)) || s.size() > 0 && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        }
    }
};
