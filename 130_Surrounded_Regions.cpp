/**
 * Surrounded Regions
 * 
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m < 2) return;
        int n = board[0].size();
        if (n < 2) return;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') regionTraversal(board, i, 0, m, n);
            if (board[i][n-1] == 'O') regionTraversal(board, i, n-1, m, n);
        }
        for (int j = 1; j < n-1; j++) {
            if (board[0][j] == 'O') regionTraversal(board, 0, j, m, n);
            if (board[m-1][j] == 'O') regionTraversal(board, m-1, j, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
private:
    void regionTraversal(vector<vector<char>>& board, int i, int j, int &m, int &n) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'A';
        if (i > 1) regionTraversal(board, i-1, j, m, n);
        if (i < m-2) regionTraversal(board, i+1, j, m, n);
        if (j > 1) regionTraversal(board, i, j-1, m, n);
        if (j < n-2) regionTraversal(board, i, j+1, m, n);
    }
};
