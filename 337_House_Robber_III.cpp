/**
 * House Robber III
 *
 * Trick: recursively
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
    int rob(TreeNode* root) {
        return rob(root, true);
    }
private:
    int rob(TreeNode* root, bool canRob) {
        if (root == NULL) return 0;
        int ans = 0;
        if (canRob) ans = root->val + rob(root->left, false) + rob(root->right, false);
        return max(ans, rob(root->left, true) + rob(root->right, true));
    }
};
