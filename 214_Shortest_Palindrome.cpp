/**
 * Shortest Palindrome
 * KMP algo
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string pat = s + "#" + rev;
        vector<int> next(pat.size(), 0);
        for (int i = 1; i < pat.size(); i++) {
            int t = next[i-1];
            while (t > 0 && pat[t] != pat[i]) t = next[t-1];
            next[i] = (pat[t] == pat[i]) ? t+1 : t;
        }
        return rev.substr(0, s.size() - next.back()) + s;
    }
};
