/**
 * House Robber II
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int a = nums[0], b = max(a, nums[1]);
        for (int i = 2; i < n-1; i++) {
            if (i%2 == 0) {
                a = max(a + nums[i], b);
            } else {
                b = max(b + nums[i], a);
            }
        }
        int c = nums[n-1], d = max(c, nums[n-2]), e = (n-1)%2;
        for (int i = n-3; i >= 1; i--) {
            if (i%2 == e) {
                c = max(c + nums[i], d);
            } else {
                d = max(d + nums[i], c);
            }
        }
        return max(max(a, b), max(c, d));
    }
};
