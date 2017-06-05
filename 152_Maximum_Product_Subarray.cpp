/**
 * Maximum Product Subarray
 *
 * Record the curMin and curMax
 */ 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), curMax = nums[0], curMin = nums[0], ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= 0) {
                curMax = max(curMax*nums[i], nums[i]);
                curMin = min(curMin*nums[i], nums[i]);
            } else {
                int t = curMax;
                curMax = max(curMin*nums[i], nums[i]);
                curMin = min(t*nums[i], nums[i]);
            }
            ans = max(ans, curMax);
        }
        return ans;
    }
};
