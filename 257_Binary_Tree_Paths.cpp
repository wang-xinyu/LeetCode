/**
 * Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;
        string cur;
        dfs(ans, cur, root);
        return ans;
    }
private:
    void dfs(vector<string> &ans, string &cur, TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            cur += to_string(root->val);
            ans.push_back(cur);
            return;
        }
        string temp = cur;
        if (root->left) {
            cur += to_string(root->val);
            cur += "->";
            dfs(ans, cur, root->left);
            cur = temp;
        }
        if (root->right) {
            cur += to_string(root->val);
            cur += "->";
            dfs(ans, cur, root->right);
            cur = temp;
        }
    }
};
