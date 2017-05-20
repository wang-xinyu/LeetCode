/**
 * Binary Tree Maximum Path Sum
 * Time: O(n)
 * Recursively calculate the max single path sum for each node, at the same time record the current maxPathSum.
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum_single(root, ans);
        return ans;
    }
private:
    int maxPathSum_single(TreeNode* root, int &ans) {
        if (root == NULL) return 0;
        int maxL = max(0, maxPathSum_single(root->left, ans));
        int maxR = max(0, maxPathSum_single(root->right, ans));
        ans = max(ans, root->val + maxL + maxR);
        return root->val + max(maxL, maxR);
    }
};
