/**
 * Word Search
 * Backtracking(DFS)
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0 || word.empty()) return false;
        int n = board[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string &word, int head, int p, int q) {
        if (head == word.size()) return true;
        if (p < 0 || p >= board.size() || q < 0 || q >= board[0].size()) return false;
        if (board[p][q] != word[head]) return false;
        char t = board[p][q];
        board[p][q] = '.';
        head++;
        bool ret =  dfs(board, word, head, p-1, q) || dfs(board, word, head, p, q-1) || dfs(board, word, head, p+1, q) || dfs(board, word, head, p, q+1);
        board[p][q] = t;
        return ret;
    }
};
