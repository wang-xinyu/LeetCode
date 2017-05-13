/**
 * Unique Binary Search Trees
 * G(n): total number of structures given 1, 2, 3, ..., n
 * F(i, n): when i is the root node, total number of structures.
 * F(i, n) = G(i-1)*G(n-i)
 * G(n) = F(1, n) + F(2, n) + ... + F(n, n)
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};
