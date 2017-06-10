/**
 * Reverse Bits
 *
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        for (uint32_t l = 0x00010000, r = 0x00008000; r != 0; l <<= 1, r >>= 1) {
            if (r & n) x |= l;
            if (l & n) x |= r;
        }
        return x;
    }
};
