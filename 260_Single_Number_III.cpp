/**
 * Single Number III
 *
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res = {0, 0};
        int diff = 0;
        for (int num : nums) diff ^= num; // get (res1 ^ res2)        
        diff &= -diff; // get the lowest '1' bit
        for (int num : nums) {
            if ((num & diff) == 0) res[0] ^= num;
            else res[1] ^= num;
        }
        return res;
    }
};
