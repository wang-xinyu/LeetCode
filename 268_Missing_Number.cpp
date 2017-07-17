/**
 * Missing Number
 *
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (0 + n)*(n + 1)/2;
        for (auto i : nums) sum -= i;
        return sum;
    }
};
