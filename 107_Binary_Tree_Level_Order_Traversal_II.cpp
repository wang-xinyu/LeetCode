/**
 * Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<TreeNode*> levelNodes;
        levelNodes.push_back(root);
        while (!levelNodes.empty()) {
            int n = levelNodes.size();
            vector<int> levelValues(n)
            for (int i = 0; i < n; i++) {
                levelValues[i] = levelNodes[i]->val;
                if (levelNodes[i]->left) levelNodes.push_back(levelNodes[i]->left);
                if (levelNodes[i]->right) levelNodes.push_back(levelNodes[i]->right);
            }
            ans.insert(ans.begin(), levelValues);
            levelNodes.erase(levelNodes.begin(), levelNodes.begin()+n);
        }
        return ans;
    }
};
