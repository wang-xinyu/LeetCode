/**
 * First Missing Positive 
 * Time complexity: O(n)
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i;
        for (i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <=n && nums[nums[i] - 1] != nums[i] && nums[i] != i+1) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) break;
        }
        return (i + 1);
    }
};
