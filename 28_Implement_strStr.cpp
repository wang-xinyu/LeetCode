/**
 * Implement strStr() 
 * Time complexity: O(m*n)
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            if (needle.compare(haystack.substr(i, n)) == 0) return i;
        }
        return -1;
    }
};
