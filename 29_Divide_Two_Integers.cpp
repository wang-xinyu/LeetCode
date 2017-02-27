/**
 * Divide Two Integers
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        long int result = 0, tmp, mul, dvd = labs(dividend), dvs = labs(divisor);
        while (dvd >= dvs) {
            tmp = dvs;
            mul = 1;
            while ((tmp << 1) <= dvd) {
                tmp <<= 1;
                mul <<= 1;
            }
            dvd -= tmp;
            result += mul;
        }
        return (dividend < 0 && divisor > 0 || dividend >= 0 && divisor < 0) ? -result : result;
    }
};
