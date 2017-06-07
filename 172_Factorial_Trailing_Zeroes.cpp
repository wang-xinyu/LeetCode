/**
 * Factorial Trailing Zeroes
 *
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (long i = n/5; i; i /= 5) {
            ans += i;
        }
        return ans;
    }
};
