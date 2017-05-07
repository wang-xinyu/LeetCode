/**
 * Sort Colors
 * O(n)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0, q = nums.size() - 1, i;
        for (i = p; i <= q;) {
            if (nums[i] == 0) swap(nums[i], nums[p++]);
            else if (nums[i] == 2) swap(nums[i], nums[q--]);
            else {
                i++;
                continue;
            }
            while(nums[p] == 0) p++;
            while(nums[q] == 2) q--;
            if (i < p) i = p;
        }
    }
};
