/**
 * Search a 2D Matrix
 * Binary Search
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = 0, j = m-1, mid, p = 0, q = n-1;
        while (i + 1 < j) {
            mid = (i+j)/2;
            if (matrix[mid][0] > target) j = mid;
            else i = mid;
        }
        if (target < matrix[i][0] || target > matrix[j][n-1] || target > matrix[i][n-1] && target < matrix[j][0]) return false;
        else if (target >= matrix[j][0]) i = j;
        //cout << "line: " << i << endl;
        while (p <= q) {
            mid = (p+q)/2;
            if (matrix[i][mid] > target) q = mid - 1;
            else if (matrix[i][mid] < target) p = mid + 1;
            else return true;
        }
        return false;
    }
};
