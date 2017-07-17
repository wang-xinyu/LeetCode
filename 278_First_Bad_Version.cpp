/**
 * First Bad Version
 *
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long i = 1, j = n;
        while (i < j) {
            long mid = (i+j)/2;
            if (isBadVersion(mid)) j = mid;
            else i = mid+1;
        }
        return i;
    }
};
