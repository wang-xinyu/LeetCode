/**
 * Recover Binary Search Tree
 * Inorder traversal (while for O(1) space, should use Morris travesal)
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
    void recoverTree(TreeNode* root) {
        prv = new TreeNode(INT_MIN);
        first = second = NULL;
        searchSwappedElement(root);
        swap(first->val, second->val);
    }
private:
    TreeNode *prv, *first, *second;
    void searchSwappedElement(TreeNode *cur) {
        if (cur == NULL) return;
        searchSwappedElement(cur->left);
        if (first == NULL && prv->val >= cur->val) first = prv;
        if (first != NULL && prv->val >= cur->val) second = cur;
        prv = cur;
        searchSwappedElement(cur->right);
    }
};
