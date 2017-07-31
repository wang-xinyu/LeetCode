/**
 * Count of Range Sum
 *
 * Trick: use multiset.lower_bound() .upper_bound() and distance()
 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long> ms;
        ms.insert(0);
        int ans = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += distance(ms.lower_bound(sum-upper), ms.upper_bound(sum-lower));
            ms.insert(sum);
        }
        return ans;
    }
};
