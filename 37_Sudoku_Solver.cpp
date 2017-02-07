/**
 * Sudoku Solver
 * Use Backtracking Algorithm
 * Time complexity: O(9^n) n represents the number of '.' in the table
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solvedSudoku(board);
    }
private:
    bool solvedSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (check(board, i, j, k)) {
                            board[i][j] = k;
                            if (solvedSudoku(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;  // All 1-9 don't work, which means last item is wrong. 
                }
            }
        }
        return true;
    }
    bool check(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.' && board[row][i] == val) return false;
            if (board[i][col] != '.' && board[i][col] == val) return false;
        }
        int m = row - row%3, n = col - col%3;
        for (int i = m; i < m + 3; i++) {
            for (int j = n; j < n + 3; j++) {
                if (board[i][j] != '.' && board[i][j] == val) return false;
            }
        }
        return true;
    }
};
