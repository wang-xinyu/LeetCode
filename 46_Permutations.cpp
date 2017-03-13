/**
 * Permutations
 * Backtracking
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permuted;
        permute(res, permuted, nums);
        return res;
    }
private:
    void permute(vector<vector<int>>& res, vector<int>& permuted, vector<int>& permuting) {
        if (permuting.size() == 0) {
            res.push_back(permuted);
            return;
        }
        for (int i = 0; i < permuting.size(); i++) {
            int num = permuting[i];
            permuting.erase(permuting.begin()+i);
            permuted.push_back(num);
            permute(res, permuted, permuting);
            permuting.insert(permuting.begin()+i, num);
            permuted.pop_back();
        }
    }
};
