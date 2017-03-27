/**
 * Rotate Image
 * (i, j) -> (n-1-j, i), rotate the first quarter
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), p, q;
        p = n/2;
        q = (n%2 == 0) ? (n/2) : (n/2 + 1);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
        }
    }
};
