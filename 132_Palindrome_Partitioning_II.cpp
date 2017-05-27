/**
 * Palindrome Partitioning II
 * DP
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int r = 0; r <= i && i+r < n && s[i-r] == s[i+r]; r++) {  // odd number palindrome
                cut[i+r+1] = min(cut[i+r+1], 1+cut[i-r]);
            }
            for (int r = 0; r <= i && i+r+1 < n && s[i-r] == s[i+r+1]; r++) {  // even number palindrome
                cut[i+r+2] = min(cut[i+r+2], 1+cut[i-r]);
            }
        }
        return cut[n];
    }
};
