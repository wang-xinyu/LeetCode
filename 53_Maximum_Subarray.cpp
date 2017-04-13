/**
 * Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return INT_MIN;
        int sum = 0, res = nums[0];
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res = max(sum, res);
            sum = max(sum, 0);
        }
        return res;
    }
};
