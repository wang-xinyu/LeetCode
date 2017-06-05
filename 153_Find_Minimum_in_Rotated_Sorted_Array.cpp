/**
 * Find Minimum in Rotated Sorted Array
 *
 * Binary search
 */ 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, mid;
        while (i < j) {
            if (nums[i] < nums[j]) return nums[i];
            mid = (i+j)/2;
            if (nums[mid] >= nums[i]) i = mid + 1;
            else j = mid;
        }
        return nums[i];
    }
};
