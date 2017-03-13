/**
 * Permutations II
 * Backtracking
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permuted;
        sort(nums.begin(), nums.end());
        permuteUnique(res, permuted, nums);
        return res;
    }
private:
    void permuteUnique(vector<vector<int>>& res, vector<int>& permuted, vector<int>& permuting) {
        if (permuting.size() == 0) {
            res.push_back(permuted);
            return;
        }
        for (int i = 0; i < permuting.size(); i++) {
            if (i > 0 && permuting[i] == permuting[i-1]) continue;
            int num = permuting[i];
            permuting.erase(permuting.begin()+i);
            permuted.push_back(num);
            permuteUnique(res, permuted, permuting);
            permuting.insert(permuting.begin()+i, num);
            permuted.pop_back();
        }
    }
};
