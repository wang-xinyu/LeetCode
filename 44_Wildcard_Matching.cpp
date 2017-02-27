/**
 * Wildcard Matching
 * Time complexity: O(m+n)
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, si = 0, star = -1;
        while (s[i]) {
            if (s[i] == p[j] || p[j] == '?') {
                i++;
                j++;
                continue;
            } else if (p[j] == '*') {
                star = j;
                si = i;
                j++;
                continue;
            } else if (star >= 0) {
                si++;
                i = si;
                j = star + 1;
                continue;
            }
            return false;
        }
        while (p[j] == '*') j++;
        return (p[j] == '\0');
    }
};
