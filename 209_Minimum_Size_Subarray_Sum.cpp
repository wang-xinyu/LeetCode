/**
 * Minimum Size Subarray Sum
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, end = 0, sum = 0, minLen = INT_MAX;
        while (end < n) {
            while (end < n && sum < s) sum += nums[end++];
            if (sum < s) break;
            while (start < end && sum >= s) sum -= nums[start++];
            if (end - start + 1 < minLen) minLen = end - start + 1;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
