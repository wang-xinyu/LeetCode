/**
 * 4Sum
 * Sort first, then pick two numbers and do 2Sum among the numbers on the right.
 * Time complexity: O(n^3)
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int left = j + 1, right = n - 1, t = target - nums[i] -nums[j];
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == t) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        result.push_back(tmp);
                        while (left < right && nums[left] == tmp[2]) left++;
                        while (left < right && nums[right] == tmp[3]) right--;
                    } else if (sum < t) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j + 1 < n - 2 && nums[j+1] == nums[j]) j++;
            }
            while (i + 1 < n - 3 && nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};
