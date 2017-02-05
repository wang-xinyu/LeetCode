/**
 * Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        int l = strs[0].size();
        int i, j;
        char tmp;
        for (i = 0; i < l; i++) {
            tmp = strs[0][i];
            for (j = 1; j < n; j++) {
                if (tmp != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
