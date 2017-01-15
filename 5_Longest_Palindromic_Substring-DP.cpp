/**
 * Use DP to find the longest palindromic substring.
 * Time complexity: O(n^2)
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), C = 0, len1, L, R, maxLen = 0;
        for (int i = 0; i < len; i++) {
            L = i;
            R = i;
            while (L >= 0 && R < len && s[L] == s[R]) {  // find the longest odd string, center is i
                L--;
                R++;
            }
            len1 = R - L - 1;
            L = i;
            R = i + 1;
            while (L >= 0 && R < len && s[L] == s[R]) {  // find the longest even string, center is i&(i+1)
                L--;
                R++;
            }
            len1 = max(len1, R - L - 1);
            if (len1 > maxLen) {
                maxLen = len1;
                C = i;
            }
        }
        return s.substr(C - ((maxLen - 1) >> 1), maxLen);
    }
};

