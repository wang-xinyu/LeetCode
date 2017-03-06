/**
 * Search Insert Position
 * Time complexity: O(logN)
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi)/2;
            if (nums[mid] < target) lo = mid + 1;
            else if (nums[mid] > target) hi = mid - 1;
            else return mid;
        }
        return (nums[lo] < target) ? ++lo : lo;
    }
};
