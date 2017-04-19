/**
 * Spiral Matrix II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int i = n, p = 0, q = 0, num = 1;
        for (; i > 1; i -= 2) {
            for (int j = 0; j < i-1; j++) res[p][q++] = num++;
            for (int j = 0; j < i-1; j++) res[p++][q] = num++;
            for (int j = 0; j < i-1; j++) res[p][q--] = num++;
            for (int j = 0; j < i-1; j++) res[p--][q] = num++;
            p += 1;
            q += 1;
        }
        if (i) res[p][q] = num;
        return res;
    }
};
