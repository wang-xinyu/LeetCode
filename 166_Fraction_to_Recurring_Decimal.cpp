/**
 * Fraction to Recurring Decimal
 *
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long n = numerator, d = denominator;
        string res;
        if (n < 0 ^ d < 0) res += "-";
        n = labs(n);
        d = labs(d);
        res += to_string(n/d);
        if (n%d == 0) return res;
        res += ".";
        unordered_map<int, int> map;
        for (long r = n%d; r; r %= d) {
            if (map.count(r)) {
                res.insert(res.begin() + map[r], '(');
                res += ")";
                break;
            }
            map[r] = res.size();
            r *= 10;
            res += to_string(r/d);
        }
        return res;
    }
};
