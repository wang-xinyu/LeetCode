/**
 * Valid Palindrome
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            if (s[i] < '0' || s[i] > '9' && s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z') {
                i++;
                continue;
            }
            if (s[j] < '0' || s[j] > '9' && s[j] < 'A' || s[j] > 'Z' && s[j] < 'a' || s[j] > 'z') {
                j--;
                continue;
            }
            if (s[i] > 'Z') s[i] -= 32;
            if (s[j] > 'Z') s[j] -= 32;
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
