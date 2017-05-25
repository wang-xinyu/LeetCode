/**
 * Longest Consecutive Sequence
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        sort(nums.begin(), nums.end());
        int ans = 1, temp = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] == nums[i]) continue;
            if (nums[i+1] == nums[i] + 1) temp++;
            else {
                ans = max(ans, temp+1);
                temp = 0;
            }
        }
        if (nums[n-1] == nums[n-2] || nums[n-1] == nums[n-2] + 1) ans = max(ans, temp+1);
        return ans;
    }
};
