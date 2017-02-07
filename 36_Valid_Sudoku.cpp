/**
 * Valid Sudoku
 * Time complexity: O(n) n represents the number of number in the table
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !check(board, i, j, board[i][j])) return false;
            }
        }
        return true;
    }
private:
    bool check(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] != '.' && board[row][i] == val) return false;
            if (i != row && board[i][col] != '.' && board[i][col] == val) return false;
        }
        int m = row - row%3, n = col - col%3;
        for (int i = m; i < m + 3; i++) {
            for (int j = n; j < n + 3; j++) {
                if ((i != row || j != col) && board[i][j] != '.' && board[i][j] == val) return false;
            }
        }
        return true;
    }
}
