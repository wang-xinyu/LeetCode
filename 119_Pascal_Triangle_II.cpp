/**
 * Pascal's Triangle II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow = {1};
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> thisRow(i+1);
            thisRow[0] = thisRow[i] = 1;
            for (int j = 1; j < i; j++) {
                thisRow[j] = lastRow[j-1] + lastRow[j];
            }
            lastRow = thisRow;
        }
        return lastRow;
    }
};
