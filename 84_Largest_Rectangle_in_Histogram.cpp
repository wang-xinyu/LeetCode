/**
 * Largest Rectangle in Histogram
 * Use stack. !!!Metaphysical.
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
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
