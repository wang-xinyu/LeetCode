/**
 * Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size(), lb = b.size();
        if (la < lb) return addBinary(b, a);
        string res = a;
        int carry = 0, i = la - 1, j = lb - 1;
        for (; i >= 0 && j >= 0; i--, j--) {
            int num = (int)(a[i] - '0') + (int)(b[j] - '0') + carry;
            res[i] = (num % 2) + '0';
            carry = num/2;
        }
        for (; i >= 0 && carry; i--) {
            int num = (int)(a[i] - '0') + carry;
            res[i] = (num % 2) + '0';
            carry = num/2;
        }
        if (carry) res.insert(res.begin(), '1');
        return res;
    }
};
