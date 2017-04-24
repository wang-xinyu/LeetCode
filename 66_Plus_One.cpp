/**
 * Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1;
        if (n == 0) {
            digits.push_back(1);
            return digits;
        }
        vector<int> res(digits);
        for (int i = n-1; i >= 0 && carry; i--) {
            int num = res[i] + carry;
            res[i] = num % 10;
            carry = num / 10;
        }
        if (carry) res.insert(res.begin(), 1);
        return res;
    }
};
