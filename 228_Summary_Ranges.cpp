/**
 * Summary Ranges
 *
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int left = nums[0], right = nums[0];
        for (int i = 1; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == right + 1) right = nums[i];
            else {
                if (left == right) ans.push_back(to_string(left));
                else ans.push_back(to_string(left) + "->" + to_string(right));
                if (i < nums.size()) left = right = nums[i];
            }
        }
        return ans;
    }
};
