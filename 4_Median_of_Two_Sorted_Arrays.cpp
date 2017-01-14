/**
 * Use binary search to find the dividing boundry, then get the median.
 * Time complexity: O(log(min(m,n)))
 */
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        if (n == 0) return 0.0;
        int half_len = (m + n + 1) >> 1, left = 0, right = m, i, j;
        while (left <= right) {
            i = (left + right) >> 1;
            j = half_len - i;
            if (i > 0 && nums1[i-1] > nums2[j]) {  // i>0 -> j<n
                right = i - 1;
            } else if (i < m && nums2[j-1] > nums1[i]) {  // i<m -> j>0
                left = i + 1;
            } else {  // (i == 0 || j == n || nums1[i-1] <= nums2[j]) && (i == m || j == 0 || nums2[j-1] << nums1[i])
                if (i == 0) {
                    left = nums2[j-1];
                } else if (j == 0) {
                    left = nums1[i-1];
                } else {
                    left = max(nums1[i-1], nums2[j-1]);
                }
                
                if ((m + n) & 1) return (double)left;
                break;
            }
        }
        if (i == m) {
            right = nums2[j];
        } else if (j == n) {
            right = nums1[i];
        } else {
            right = min(nums1[i], nums2[j]);
        }
        return (left + right)/2.0;
    }
};

