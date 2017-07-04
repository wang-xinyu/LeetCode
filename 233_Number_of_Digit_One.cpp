/**
 * Number of Digit One
 */
class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        int ans = 0;
        long i;
        for (i = 10; i/10 <= n; i *= 10) {
            int num1 = n/i*i/10;
            int num2 = (n%i)/(i/10);
            int num3 = n%(i/10);
            if (num2 == 1) num1 += num3 + 1;
            else if (num2 > 1) num1 += i/10;
            ans += num1;
        }
        return ans;
    }
};
