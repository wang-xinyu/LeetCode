/**
 * Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode *p = root, *temp = root->right;
        flatten(root->left);
        root->right = root->left;
        root->left = NULL;
        while (p->right) p = p->right;
        flatten(temp);
        p->right = temp;
    }
};
