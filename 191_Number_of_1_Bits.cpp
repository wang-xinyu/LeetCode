/**
 * Number of 1 Bits
 *
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0, t = n; i <= 31; i++, t >>= 1) {
            if (t & 1) ans++;
        }
        return ans;
    }
};
