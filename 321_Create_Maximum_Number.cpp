/**
 * Create Maximum Number
 *
 * Trick: find the max of one array and merge two.
 */
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(k);
        for (int i = max(0, k-m); i <= n && i <= k; i++) {
            vector<int> temp(k), temp1(i), temp2(k-i);
            maxArray(temp1, nums1);
            maxArray(temp2, nums2);
            merge(temp, temp1, temp2, k);
            if (greater(temp, 0, ans, 0)) ans.assign(temp.begin(), temp.end());
        }
        return ans;
    }
private:
    void merge(vector<int>& ans, vector<int>& nums1, vector<int>& nums2, int k) {
        for (int i = 0, j = 0, r = 0; r < k; r++) {
            ans[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
    }
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
    void maxArray(vector<int>& ans, vector<int>& nums) {
        int n = nums.size(), k = ans.size();
        for (int i = 0, j = 0; i < n; i++) {
            while (n-i > k-j && j > 0 && ans[j-1] < nums[i]) j--;
            if (j < k) ans[j++] = nums[i];
        }
    }
};
