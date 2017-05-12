/**
 * Search in Rotated Sorted Array II
 * Find the rotate point and the use the binary search
 * Time complexity: O(n + log(n))
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), lo = 0, hi = n-1, rot = 0;
        while (rot < n-1 && nums[rot] <= nums[rot+1]) rot++;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            int realmid = (rot + mid + 1) % n;
            if (nums[realmid] > target) hi = mid - 1;
            else if (nums[realmid] < target) lo = mid + 1;
            else return true;
        }
        return false;
    }
};
