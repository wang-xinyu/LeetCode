/**
 * Binary Tree Preorder Traversal 
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> v;
        TreeNode *p = root;
        v.push(NULL);
        while (p) {
            ans.push_back(p->val);
            if (p->left) {
                if (p->right) v.push(p->right);
                p = p->left;
            } else if (p->right) {
                p = p->right;
            } else {
                p = v.top();
                v.pop();
            }
        }
        return ans;
    }
};
