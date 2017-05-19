/**
 * Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return _hasPathSum(root, sum);
    }
private:
    bool _hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return sum == 0;
        if (root->left == NULL) return _hasPathSum(root->right, sum - root->val);
        if (root->right == NULL) return _hasPathSum(root->left, sum - root->val);
        return _hasPathSum(root->left, sum - root->val) || _hasPathSum(root->right, sum - root->val);
    }
};
