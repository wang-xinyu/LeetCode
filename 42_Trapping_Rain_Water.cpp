/**
 * Trapping Rain Water
 * Time complexity: O(n)
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, water = 0, maxleft = 0, maxright = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxleft) {
                    water += (maxleft - height[left]);
                } else {
                    maxleft = height[left];
                }
                left++;
            } else {
                if (height[right] < maxright) {
                    water += (maxright - height[right]);
                } else {
                    maxright = height[right];
                }
                right--;
            }
        }
        return water;
    }
};
