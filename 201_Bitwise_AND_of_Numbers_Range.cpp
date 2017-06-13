/**
 * Bitwise AND of Numbers Range
 *
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m > n) return 0;
        return (n > m) ? rangeBitwiseAnd(m>>1, n>>1) << 1 : n;
    }
};
