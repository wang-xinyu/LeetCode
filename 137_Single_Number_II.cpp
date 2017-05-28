/**
 * Single Number II
 * 
 * [one][two] count the number of bit 1:
 * 00 -> 10 -> 01 -> 00 (0 -> 1 -> 2 -> 0)
 * 
 * one i two one' two'
 *  0  0  0   0    0
 *  0  0  1   0    1
 *  0  1  0   1    0
 *  0  1  1   0    0
 *  1  0  0   1    0
 *  1  1  0   0    1
 *  
 * one' = (one ^ i) & ~two;
 * two' = (two ^ i) & ~one';
 */ 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones(0), twos(0);
        for (auto i : nums) {
            ones = (ones ^ i) & ~twos;
            twos = (twos ^ i) & ~ones;
        }
        return ones;
    }
};
