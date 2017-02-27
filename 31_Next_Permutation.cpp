/**
 * Next Permutation
 * Time complexity: O(n)
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) break;
        }
        if (i >= 0) {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        for (int p = i + 1, q = n - 1; p < q; p++, q--) {
            swap(nums[p], nums[q]);
        }
    }
};
