/**
 * Range Sum Query 2D - Immutable
 * 
 */
class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        sum.assign(matrix.begin(), matrix.end());
        for (int i = 0; i < sum.size(); i++) {
            for (int j = 0; j < sum[0].size(); j++) {
                if (i > 0) sum[i][j] += sum[i-1][j];
                if (j > 0) sum[i][j] += sum[i][j-1];
                if (i > 0 && j > 0) sum[i][j] -= sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];
        if (row1 > 0) ans -= sum[row1-1][col2];
        if (col1 > 0) ans -= sum[row2][col1-1];
        if (row1 > 0 && col1 > 0) ans += sum[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
