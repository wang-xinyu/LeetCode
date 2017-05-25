/**
 * Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = 0, path = 0;
        dfs(sum, path, root);
        return sum;
    }
private:
    void dfs(int &sum, int &path, TreeNode* root) {
        path = 10*path + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += path;
            path /= 10;
            return;
        }
        if (root->left) {
            dfs(sum, path, root->left);
        }
        if (root->right) {
            dfs(sum, path, root->right);
        }
        path /= 10;
    }
};
