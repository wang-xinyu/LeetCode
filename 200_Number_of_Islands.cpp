/**
 * Number of Islands
 *
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int ans = 0;
        vector<vector<char>> island(grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (island[i][j] == '1') {
                    ans++;
                    stretch(island, m, n, i, j);
                }
            }
        }
        return ans;
    }
private:
    void stretch(vector<vector<char>>& island, int &m, int &n, int i, int j) {
        island[i][j] = '.';
        if (i >= 1 && island[i-1][j] == '1') stretch(island, m, n, i-1, j);
        if (i <= m-2 && island[i+1][j] == '1') stretch(island, m, n, i+1, j);
        if (j >= 1 && island[i][j-1] == '1') stretch(island, m, n, i, j-1);
        if (j <= n-2 && island[i][j+1] == '1') stretch(island, m, n, i, j+1);
    }
};
