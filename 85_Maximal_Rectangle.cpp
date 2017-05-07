/**
 * Maximal Rectangle
 * Take each row as a problem of "84. Largest Rectangle in Histogram"
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int ans = 0;
        vector<int> Histogram(n+1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) Histogram[j] = (matrix[i][j] == '1') ? Histogram[j] + 1 : 0;
            ans = max(ans, largestRectangleArea(Histogram));
        }
        return ans;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), i = 0, j, h, ans = 0;
        stack<int> s;
        while (i < n) {
            if (s.empty() || heights[i] > heights[s.top()]) s.push(i++);
            else {
                h = heights[s.top()];
                s.pop();
                j = s.empty() ? -1 : s.top();
                ans = max(ans, h*(i-j-1));
            }
        }
        return ans;
    }
};
