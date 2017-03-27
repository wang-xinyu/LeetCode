/**
 * Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        long m = n;
        if (x == 0) return (m == 0) ? 1 : 0;
        if (m < 0) {
            m = -m;
            x = 1/x;
        }
        double res = 1;
        while (m > 0) {
            if (m & 1) res *= x;
            x *= x;
            m >>= 1;
        }
        return res;
    }
};
