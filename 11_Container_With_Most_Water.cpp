/**
 * Container With Most Water
 * Time complexity: O(n)
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int water = 0; 
        while (i < j) {
            water = max(water, (j - i)*min(height[i], height[j]));
            if (height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return water;
    }
};

