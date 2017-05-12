/**
 * Subsets II
 * Backtracking
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; i++) subsetsWithDup(ans, nums, subset, n, 0, i);
        return ans;
    }
private:
    void subsetsWithDup(vector<vector<int>> &ans, vector<int> &nums, vector<int> &subset, int &n, int head, int len) {
        if (len == 0) {
            ans.push_back(subset);
            return;
        }
        for (int i = head; i <= n-len; i++) {
            subset.push_back(nums[i]);
            subsetsWithDup(ans, nums, subset, n, i+1, len-1);
            subset.pop_back();
            while (i < n && nums[i] == nums[i+1]) i++;
        }
    }
};
