/**
 * Multiply Strings
 * Time complexity: O(n^2)
 * r0 = carry + (0,0)
 * r1 = carry + (0,1) + (1,0)
 * r2 = carry + (0,2) + (1,1) + (2,0)
 * r3 = carry + (0,3) + (1,2) + (2,1) + (3,0)
 * ... ...
 * res[X] = rX % 10
 * carry = rX / 10
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int l1 = num1.size(), l2 = num2.size(), maxl = l1 + l2, lastR = 0;
        if (!l1 || !l2) return res;
        for (int i = 0; i < maxl; i++) {
            int r = lastR;
            for (int j = 0; j <= i; j++) {
                if (j < l1 && (i-j) < l2) {
                    r += (int(num1[l1-j-1] - '0') * int(num2[l2-i+j-1] - '0'));
                }
            }
            lastR = r/10;
            res.insert(res.begin(), '0' + r%10);
        }
        while (res[0] == '0' && res.size() > 1) res.erase(res.begin());
        return res;
    }
};
