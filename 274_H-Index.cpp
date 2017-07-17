/**
 * H-Index
 *
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> record(n+1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) record[n]++;
            else record[citations[i]]++;
        }
        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += record[i];
            if (total >= i) return i;
        }
        return 0;
    }
};
