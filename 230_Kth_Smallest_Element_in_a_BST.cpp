/**
 * Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        traversal(root, k, res);
        return res;
    }
    void traversal(TreeNode* root, int &k, int &res) {
        if (root == NULL) return;
        traversal(root->left, k, res);
        if (--k == 0) {
            res = root->val;
            return;
        }
        traversal(root->right, k, res);
    }
};
