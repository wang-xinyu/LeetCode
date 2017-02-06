/**
 * 3Sum Closet
 * Sort first, then pick one number and do 2Sum among the numbers on the right.
 * Time complexity: O(n*n)
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(),nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n -2; i++) {
            int left = i + 1, right = n - 1, t = target - nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == t) {
                    return target;
                } else if (sum < t) {
                    if (abs(sum + nums[i] - target) < abs(result - target)) result = sum + nums[i];
                    while (left < right && nums[left] == nums[left+1]) left++;
                    left++;
                } else {
                    if (abs(sum + nums[i] - target) < abs(result - target)) result = sum + nums[i];
                    while (left < right && nums[right] == nums[right-1]) right--;
                    right--;
                }
            }
        }
        return result;
    }
};
