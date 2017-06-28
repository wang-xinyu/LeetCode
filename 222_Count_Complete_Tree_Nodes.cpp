/**
 * Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *l = root, *r = root;
        int h = 0;
        while (r != NULL) {
            l = l->left;
            r = r->right;
            h++;
        }
        if (l == NULL) return (1 << h) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
