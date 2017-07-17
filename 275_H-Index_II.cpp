/**
 * H-Index II
 *
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty() || citations.back() == 0) return 0;
        int n = citations.size(), i = 0, j = n-1;
        while (i < j) {
            int mid = (i+j)/2;
            if (citations[mid] >= n-mid) j = mid;
            else i = mid + 1;
        }
        return n-i;
    }
};
