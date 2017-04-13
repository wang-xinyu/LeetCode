/**
 * Spiral Matrix
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        else if (m == 1) return matrix[0];
        int n = matrix[0].size();
        if (n == 0) return res;
        else if (n == 1) for (int i = 0; i < m; i++) res.push_back(matrix[i][0]);
        int loop = min(m, n) - 1;
        for (int i = 0; i < loop; i++) {
            int p = i, q = i;
            while (q < n-i) res.push_back(matrix[p][q++]);
            p = i+1;
            q = n-i-1;
            while (p < m-i) res.push_back(matrix[p++][q]);
            p = m-i-1;
            q = n-i-2;
            if (p <= i || q < i) continue;
            while (q >= i) res.push_back(matrix[p][q--]);
            p = m-i-2;
            q = i;
            while (p > i) res.push_back(matrix[p--][q]);
        }
        return res;
    }
};
