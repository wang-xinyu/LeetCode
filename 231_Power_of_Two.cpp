/**
 * Power of Two
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 1; i != 0x80000000; i<<=1) {
            if (n == i) return true;
        }
        return false;
    }
};
