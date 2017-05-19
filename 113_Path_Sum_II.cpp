/**
 * Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        pathSum(ans, path, root, sum);
        return ans;
    }
private:
    void pathSum(vector<vector<int>> &ans, vector<int> &path, TreeNode* root, int sum) {
        if (root == NULL) {
            path.push_back(0);
            return;
        }
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            ans.push_back(path);
            return;
        }
        pathSum(ans, path, root->left, sum - root->val);
        path.pop_back();
        pathSum(ans, path, root->right, sum - root->val);
        path.pop_back();
    }
};
