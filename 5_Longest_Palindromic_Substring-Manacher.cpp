/**
 * Use Manacher's algorithm to find the longest palindromic substring.
 * Time complexity: O(n)
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string T = s;
        int i;
        for (i = 0; T[i]; i+=2) {
            T.insert(i, "#");
        }
        T = "^" + T + "#$";
        
        int len = T.size(), C = 1, R = 0, i_mirror;
        int *P = new int[len];
        P[1] = 0;
        for (i = 2; i < len - 1; i++) {
            i_mirror = 2*C - i;
            // key part of Manacher’s algorithm:
            // if P[i_mirror] ≤ R – i, P[i] <- P[i_mirror]
            // else P[i] >= R - i
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
                P[i]++;
            }
            if (P[C] < P[i]) {
                C = i;
                R = i + P[i];
            }
        }
        R -= C;
        C = (C - 2) >> 1;
        return s.substr(C - ((R - 1) >> 1), R);
    }
};

