/**
 * Oh, this is ZigZag. (- -)|||
 * n=numRows
 * Δ=2n-2    1                           2n-1                         4n-3
 * Δ=        2                     2n-2  2n                    4n-4   4n-2
 * Δ=        3               2n-3        2n+1              4n-5       .
 * Δ=        .           .               .               .            .
 * Δ=        .       n+2                 .           3n               .
 * Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
 * Δ=2n-2    n                           3n-2                         5n-4
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int i = 0, len = s.size(), idx;
        string sb[numRows];
        while (i < len) {
            for (idx = 0; idx < numRows && i < len; idx++) {  // vertically down
                sb[idx].push_back(s[i++]);
            }
            for (idx = numRows - 2; idx >= 1 && i < len; idx--) {  // obliquely up
                sb[idx].push_back(s[i++]);
            }
        }
        for (idx = 1; idx < numRows; idx++) {
            sb[0].append(sb[idx]);
        }
        return sb[0];
    }
};
