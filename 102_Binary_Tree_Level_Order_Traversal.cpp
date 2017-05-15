/**
 * Binary Tree Level Order Traversal 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        vector<TreeNode*> levelNodes;
        levelNodes.push_back(root);
        while (!levelNodes.empty()) {
            int n = levelNodes.size();
            vector<int> levelvals(n);
            for (int i = 0; i < n; i++) {
                levelvals[i] = levelNodes[i]->val;
                if (levelNodes[i]->left) levelNodes.push_back(levelNodes[i]->left);
                if (levelNodes[i]->right) levelNodes.push_back(levelNodes[i]->right);
            }
            ans.push_back(levelvals);
            levelNodes.erase(levelNodes.begin(), levelNodes.begin()+n);
        }
        return ans;
    }
};
