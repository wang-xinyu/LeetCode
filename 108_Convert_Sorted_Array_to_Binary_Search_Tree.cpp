/**
 * Convert Sorted Array to Binary Search Tree
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int m, int n) {
        if (m > n) return NULL;
        int rootIndex = (m + n + 1) >> 1;
        TreeNode *root = new TreeNode(nums[rootIndex]);
        root->left = sortedArrayToBST(nums, m, rootIndex-1);
        root->right = sortedArrayToBST(nums, rootIndex+1, n);
        return root;
    }
};
