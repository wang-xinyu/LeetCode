/**
 * Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        vector<TreeNode*> levelNodes;
        levelNodes.push_back(root);
        while (!levelNodes.empty()) {
            int n = levelNodes.size();
            for (int i = 0; i < n; i++) {
                if (levelNodes[i]->left) levelNodes.push_back(levelNodes[i]->left);
                if (levelNodes[i]->right) levelNodes.push_back(levelNodes[i]->right);
            }
            ans.push_back(levelNodes[n-1]->val);
            levelNodes.erase(levelNodes.begin(), levelNodes.begin()+n);
        }
        return ans;
    }
};
