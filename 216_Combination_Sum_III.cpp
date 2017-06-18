/**
 * Combination Sum III
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, n, 0, k);
        return ans;
    }
private:
    void dfs(vector<vector<int>> &ans, vector<int> &cur, int &n, int curSum, int k) {
        if (k == 0) {
            if (curSum == n) ans.push_back(cur);
            return;
        }
        if (n - curSum < k || n - curSum > 9*k) return;
        int i = cur.empty() ? 1 : cur.back()+1;
        for (; i <= 9; i++) {
            cur.push_back(i);
            dfs(ans, cur, n, curSum+i, k-1);
            cur.pop_back();
        }
    }
};
