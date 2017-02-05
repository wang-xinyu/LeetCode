/**
 * 3Sum
 * Sort first, then pick one number and do 2Sum among the numbers on the right.
 * Time complexity: O(n*n)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1, target = 0 - nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ans.push_back(tmp);
                    while (left < right && nums[left] == tmp[1]) left++;
                    while (left < right && nums[right] == tmp[2]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
