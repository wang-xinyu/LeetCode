/**
 * Jump Game
 * Time complexity: O(n)
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, n = nums.size();
        if (n < 1) return false;
        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]);
            if (reach >= n-1) return true;
        }
        return false;
    }
};
