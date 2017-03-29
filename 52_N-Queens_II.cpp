/**
 * N-Queens II
 * Use Backtracking Algorithm
 */
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<string> sol(n, string(n, '.'-1));
        totalNQueens(res, sol, n, 0);
        return res;
    }
private:
    void totalNQueens(int& res, vector<string>& sol, int& n, int count) {
        if (count == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (sol[count][i] == ('.'-1)) {
                fillAttackArea(sol, n, count, i, 'Q', 1);
                totalNQueens(res, sol, n, count+1);
                fillAttackArea(sol, n, count, i, '.'-1, -1);
            }
        }
    }
    void fillAttackArea(vector<string>& sol, int& n, int x, int y, char c1, int diff) {
        for (int i = 0; i < n; i++) {
            sol[x][i] += diff;
            sol[i][y] += diff;
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) sol[i][j] += diff;
        for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--) sol[i][j] += diff;
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) sol[i][j] += diff;
        for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++) sol[i][j] += diff;
        sol[x][y] = c1;
    }
};
