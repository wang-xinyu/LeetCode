/**
 * Longest Increasing Path in a Matrix
 *
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> memory(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, helper(matrix, memory, i, j));
            }
        }
        return ans;
    }
private:
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& memory, int i, int j) {
        if (memory[i][j] > 0) return memory[i][j];
        int ans = 1;
        if (i > 0 && matrix[i][j] < matrix[i-1][j]) ans = max(ans, 1 + helper(matrix, memory, i-1, j));
        if (j > 0 && matrix[i][j] < matrix[i][j-1]) ans = max(ans, 1 + helper(matrix, memory, i, j-1));
        if (i < matrix.size() - 1 && matrix[i][j] < matrix[i+1][j]) ans = max(ans, 1 + helper(matrix, memory, i+1, j));
        if (j < matrix[0].size() - 1 && matrix[i][j] < matrix[i][j+1]) ans = max(ans, 1 + helper(matrix, memory, i, j+1));
        memory[i][j] = ans;
        return ans;
    }
};
