/**
 * Remove Duplicates from Sorted Array 
 * Time complexity: O(n)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), j = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) j++;  // j: number of duplicates ahead
            else nums[i-j] = nums[i];
        }
        return n - j;
    }
};
