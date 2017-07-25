/**
 * Super Ugly Number 
 * 
 * Trick: same method as Ugly Number II
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> lastIndex(k, 0), superUglyNums(n);
        superUglyNums[0] = 1;
        for (int i = 1; i < n; i++) {
            superUglyNums[i] = superUglyNums[lastIndex[0]]*primes[0];
            for (int j = 1; j < k; j++) {
                superUglyNums[i] = min(superUglyNums[i], superUglyNums[lastIndex[j]]*primes[j]);
            }
            for (int j = 0; j < k; j++) {
                if (superUglyNums[lastIndex[j]]*primes[j] == superUglyNums[i]) lastIndex[j]++;
            }
        }
        return superUglyNums[n-1];
    }
};
