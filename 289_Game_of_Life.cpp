/**
 * Game of Life
 * 
 * Trick: Use the other bits in vector->board items to store next state
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] |= nextState(board, m, n, i, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
private:
    int nextState(vector<vector<int>>& board, int &m, int &n, int i, int j) {
        int lives = 0;
        for (int p = max(0, i-1); p <= min(m-1, i+1); p++) {
            for (int q = max(0, j-1); q <= min(n-1, j+1); q++) {
                lives += board[p][q] & 1;
            }
        }
        lives -= board[i][j];
        return (lives == 3 || lives == 2 && (board[i][j] & 1)) ? 2 : 0;
    }
};
