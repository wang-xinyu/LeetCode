/**
 * N-Queens 
 * Use Backtracking Algorithm
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.'-1);
        vector<string> sol(n, s);
        solveNQueens(res, sol, n, 0);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (res[i][j][k] != 'Q') res[i][j][k] = '.';
                }
            }
        }
        return res;
    }
private:
    void solveNQueens(vector<vector<string>>& res, vector<string>& sol, int& n, int count) {
        if (count == n) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (sol[count][i] == ('.'-1)) {
                fillAttackArea(sol, n, count, i, 'Q', 1);
                solveNQueens(res, sol, n, count+1);
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
