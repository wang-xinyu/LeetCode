/**
 *  Sqrt(x)
 *  Binary Search
 */
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = 46341, mid, num;
        while (left <= x) {
            mid = (left + right)/2;
            num = mid*mid;
            if (num == x) {
                return mid;
            } else if (num < x) {
                int num1 = num + 2*mid + 1;
                if (num1 > x || num1 < 0) return mid;
                left = mid;
            } else {
                if (num -2*mid + 1 < x) return mid - 1;
                right = mid;
            }
        }
        return INT_MIN;
    }
};
