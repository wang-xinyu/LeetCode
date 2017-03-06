/**
 * Search for a Range 
 * Time complexity: O(logN)
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> r = {-1,-1};
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi)/2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        if (n == 0 || nums[hi] != target) return r;
        r[0] = hi;
        hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi)/2 + 1;
            if (nums[mid] == target) lo = mid;
            else hi = mid - 1;
        }
        r[1] = hi;
        return r;
    }
};
