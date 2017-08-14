/**
 * Patching Array
 *
 */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long upper = 1;
        int i = 0, ans = 0;
        while (upper <= n) {
            if (i < nums.size() && nums[i] <= upper) {
                upper += nums[i++];
            } else {
                upper += upper;
                ans++;
            }
        }
        return ans;
    }
};
