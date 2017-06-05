/**
 * Find Minimum in Rotated Sorted Array II
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
            if (nums[mid] > nums[i]) i = mid + 1;
            else if (nums[mid] < nums[i]) j = mid;
            else i++;
        }
        return nums[i];
    }
};
