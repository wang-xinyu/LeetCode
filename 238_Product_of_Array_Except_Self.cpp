/**
 * Product of Array Except Self 
 *
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        for (int i = 1; i < n; i++) {
            output[i] = output[i-1]*nums[i-1];
        }
        int cur = 1;
        for (int i = n-2; i >= 0; i--) {
            cur *= nums[i+1];
            output[i] *= cur;
        }
        return output;
    }
};
