/**
 * Combinations
 * Backtracking
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        combine(ans, comb, n, 1, k);
        return ans;
    }
private:
    void combine(vector<vector<int>> &ans, vector<int> &comb, int &n, int m, int k) {
        if (k == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = m; i <= n-k+1; i++) {
            comb.push_back(i);
            combine(ans, comb, n, i+1, k-1);
            comb.pop_back();
        }
    }
};
