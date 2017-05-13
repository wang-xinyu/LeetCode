/**
 * Decode Ways
 * DP and Recursion
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        dp[n-1] = (s[n-1] == '0') ? 0 : 1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '1' || s[i] == '2' && s[i+1] <= '6') {
                dp[i] = dp[i+1] + dp[i+2];
            } else if (s[i] == '0' || s[i+1] == '0' && s[i] > '2'){
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        return _numDecodings(s, 0);
    }
private:
    int _numDecodings(string &s, int head) {
        int n = s.size() - head;
        if (n == 0) return 1;
        if (s[head] == '0') return 0;
        if (n == 1) return 1;
        if (s[head+1] == '0' && s[head] > '2') return 0;
        return (s[head] == '1' || s[head] == '2' && s[head+1] <= '6') ? _numDecodings(s, head+1) + _numDecodings(s, head+2) : _numDecodings(s, head+1);
    }
};
