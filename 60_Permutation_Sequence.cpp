/**
 * Permutation Sequence
 * Time complexity: O(n)
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        int m = 0, num = 1;
        vector<int> fact(n);
        while (num < k) {
            fact[m] = num;
            num *= (++m);
        }
        string numstr = "123456789", res = numstr.substr(0, n-m), permuting = numstr.substr(n-m);
        k -= 1;
        for (int i = m - 1; i >= 0; i--) {
            int a = k/fact[i];
            res.push_back(permuting[a]);
            permuting.erase(permuting.begin()+a);
            k %= fact[i];
        }
        return res;
    }
};
