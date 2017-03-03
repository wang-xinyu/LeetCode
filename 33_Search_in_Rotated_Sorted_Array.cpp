/**
 * Search in Rotated Sorted Array 
 * Find the rotate point and the use the binary search
 * Time complexity: O(log(n))
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi)/2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        int rot = lo;
        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            int realmid = (rot + mid)%n;
            if (nums[realmid] == target) return realmid;
            else if (nums[realmid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};
