/**
 * Jump Game II
 * BFS
 * Time complexity: O(n)
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int currentMax = 0, nextMax = 0, i = 0, level = 0;
        while (i <= currentMax) {
            level++;
            for (; i <= currentMax; i++) {
                nextMax = max(nextMax, i + nums[i]);
                if (nextMax >= n - 1) return level;
            }
            currentMax = nextMax;
        }
        return 0;
    }
};
