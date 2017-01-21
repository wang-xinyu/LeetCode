/**
 * Reverse digits of an integer. 123 -> 321.
 * return 0 once overflow.
 */
class Solution {
public:
    int reverse(int x) {
        long y = 0;
        while (x != 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (y > 0x7FFFFFFF || y < (int)0x80000000)
            return 0;
        return (int)y;
    }
};
