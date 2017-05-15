/**
 * Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
private:
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;
        return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
    }
};
